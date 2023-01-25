#include "CRifle.h"
#include "Global.h"
#include "Characters/IRifle.h"
#include "Characters/CPlayer.h"
#include "CBullet.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/DecalComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Animation/AnimMontage.h"
#include "Engine/StaticMeshActor.h"
#include "Sound/SoundCue.h"
#include "Particles/ParticleSystem.h"
#include "Materials/MaterialInstanceConstant.h"

ACRifle::ACRifle()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>("Mesh");
	RootComponent = Mesh;

	ConstructorHelpers::FObjectFinder<USkeletalMesh> meshAsset(TEXT("SkeletalMesh'/Game/Weapons/Meshes/AR4/SK_AR4.SK_AR4'"));
	Mesh->SetSkeletalMesh(meshAsset.Object);

	ConstructorHelpers::FObjectFinder<UAnimMontage> grabMontageAsset(TEXT("AnimMontage'/Game/Character/Montages/Rifle_Grab_Montage.Rifle_Grab_Montage'"));
	if (grabMontageAsset.Succeeded())
		GrabMontage = grabMontageAsset.Object;
	ConstructorHelpers::FObjectFinder<UAnimMontage> ungrabMontageAsset(TEXT("AnimMontage'/Game/Character/Montages/Rifle_Ungrab_Montage.Rifle_Ungrab_Montage'"));
	if (ungrabMontageAsset.Succeeded())
		UngrabMontage = ungrabMontageAsset.Object;
	
	ConstructorHelpers::FClassFinder<UCameraShake> cameraShakeAsset(TEXT("Blueprint'/Game/Weapons/BP_CameraShake.BP_CameraShake_C'"));
	if (cameraShakeAsset.Succeeded())
		CameraShakeClass = cameraShakeAsset.Class;

	ConstructorHelpers::FClassFinder<ACBullet> bulletClassAsset(TEXT("Blueprint'/Game/Weapons/BP_CBullet.BP_CBullet_C'"));
	if (bulletClassAsset.Succeeded())
		BulletClass = bulletClassAsset.Class;

	ConstructorHelpers::FObjectFinder<UParticleSystem> flashParticleAsset(TEXT("ParticleSystem'/Game/Particles_Rifle/Particles/VFX_Muzzleflash.VFX_Muzzleflash'"));
	if (flashParticleAsset.Succeeded())
		FlashParticle = flashParticleAsset.Object;

	ConstructorHelpers::FObjectFinder<UParticleSystem> EjectParticleAsset(TEXT("ParticleSystem'/Game/Particles_Rifle/Particles/VFX_Eject_bullet.VFX_Eject_bullet'"));
	if (EjectParticleAsset.Succeeded())
		EjectParticle = EjectParticleAsset.Object;

	ConstructorHelpers::FObjectFinder<UParticleSystem> ImpactParticleAsset(TEXT("ParticleSystem'/Game/Particles_Rifle/Particles/VFX_Impact_Default.VFX_Impact_Default'"));
	if (ImpactParticleAsset.Succeeded())
		ImpactParticle = ImpactParticleAsset.Object;

	ConstructorHelpers::FObjectFinder<USoundCue> fireSoundCueAsset(TEXT("SoundCue'/Game/Sounds/S_RifleShoot_Cue.S_RifleShoot_Cue'"));
	if (fireSoundCueAsset.Succeeded())
		FireSoundCue = fireSoundCueAsset.Object;

	ConstructorHelpers::FObjectFinder<UMaterialInstanceConstant> decalAsset(TEXT("MaterialInstanceConstant'/Game/Materials/M_Decal_Inst.M_Decal_Inst'"));
	if (decalAsset.Succeeded())
		DecalMaterial = decalAsset.Object;
}

ACRifle* ACRifle::Spawn(UWorld* InWorld, ACharacter* InOwnerCharacter)
{
	FActorSpawnParameters spawnParam;
	spawnParam.Owner = InOwnerCharacter;
	return InWorld->SpawnActor<ACRifle>(spawnParam);
}

void ACRifle::Begin_Aiming()
{
	bAiming = true;
}

void ACRifle::End_Aiming()
{
	bAiming = false;
}

void ACRifle::Equip()
{
	if (bEquipped == true) return;
	if (bEquipping == true) return;

	bEquipping = true;

	OwnerCharacter->PlayAnimMontage(GrabMontage, 1.75);
}

void ACRifle::Begin_Equip()
{
	bEquipped = true;
	AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), HandSocket);
}

void ACRifle::End_Equip()
{
	bEquipping = false;

	OwnerCharacter->bUseControllerRotationYaw = true;
	OwnerCharacter->GetCharacterMovement()->bOrientRotationToMovement = false;
}

void ACRifle::Unequip()
{
	if (bEquipped == false) return;
	if (bEquipping == true) return;

	bEquipping = true;

	OwnerCharacter->PlayAnimMontage(UngrabMontage, 1.75);

	End_Fire();
}

void ACRifle::Begin_Unequip()
{
	bEquipped = false;
	AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), HolsterSocket);

	OwnerCharacter->bUseControllerRotationYaw = false;
	OwnerCharacter->GetCharacterMovement()->bOrientRotationToMovement = true;
}

void ACRifle::End_Unequip()
{
	bEquipping = false;
}

void ACRifle::Begin_Fire()
{
	if (bEquipped == false) return;
	if (bEquipping == true) return;
	//if (bAiming == false) return;
	if (bFiring == true) return;

	bFiring = true;

	CurrentPitch = 0.f;

	if (bAutoFire == true)
	{
		GetWorld()->GetTimerManager().SetTimer(AutoFireTimer, this, &ACRifle::Firing, 0.1f, true);

		return;
	}

	Firing();
}

void ACRifle::End_Fire()
{
	bFiring = false;

	if (bAutoFire == true)
		GetWorld()->GetTimerManager().ClearTimer(AutoFireTimer);
}

void ACRifle::Firing()
{
	// Get Aim Info
	IIRifle* rifleInterface = Cast<IIRifle>(OwnerCharacter);
	if (rifleInterface == nullptr) return;

	FVector start, end, direction;
	rifleInterface->GetAimInfo(start, end, direction);

	// Camera Shake
	ACPlayer* player = Cast<ACPlayer>(OwnerCharacter);
	if (player != nullptr)
	{
		APlayerController* controller = player->GetController<APlayerController>();

		if(CameraShakeClass != nullptr)
		controller->PlayerCameraManager->PlayCameraShake(CameraShakeClass);
	}

	// Spawn Bullet
	FVector muzzleLocation = Mesh->GetSocketLocation("MuzzleFlash");
	if(BulletClass != nullptr)
		GetWorld()->SpawnActor<ACBullet>(BulletClass, muzzleLocation, direction.Rotation());

	// Play Effect
	UGameplayStatics::SpawnEmitterAttached(FlashParticle, Mesh, "MuzzleFlash", FVector::ZeroVector, FRotator::ZeroRotator, EAttachLocation::KeepRelativeOffset);
	UGameplayStatics::SpawnEmitterAttached(EjectParticle, Mesh, "EjectBullet", FVector::ZeroVector, FRotator::ZeroRotator, EAttachLocation::KeepRelativeOffset);
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), FireSoundCue, muzzleLocation);

	// Raising Pitch
	CurrentPitch -= PitchSpeed * GetWorld()->GetDeltaSeconds();
	OwnerCharacter->AddControllerPitchInput(CurrentPitch);

	// LineTrace(Visibility)
	FHitResult hitResult;
	FCollisionQueryParams collisionQueryParams;
	collisionQueryParams.AddIgnoredActor(this);
	collisionQueryParams.AddIgnoredActor(OwnerCharacter);
	if (GetWorld()->LineTraceSingleByChannel(hitResult, start, end, ECollisionChannel::ECC_Visibility, collisionQueryParams))
	{
		AStaticMeshActor* staticMeshActor = Cast<AStaticMeshActor>(hitResult.GetActor());
		if (staticMeshActor != nullptr)
		{
			UStaticMeshComponent* staticMeshComp = Cast<UStaticMeshComponent>(staticMeshActor->GetRootComponent());
			if (staticMeshComp != nullptr)
			{
				//Spawn Decal & Impact Particle
				FRotator decalRotator = hitResult.ImpactNormal.Rotation();
				UDecalComponent* decalComp = UGameplayStatics::SpawnDecalAtLocation(GetWorld(), DecalMaterial, FVector(5), hitResult.Location, decalRotator, 10.f);
				decalComp->SetFadeScreenSize(0);
				UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactParticle, hitResult.Location, decalRotator, true);

				if (staticMeshComp->BodyInstance.bSimulatePhysics == true)
				{
					direction = staticMeshActor->GetActorLocation() - OwnerCharacter->GetActorLocation();
					direction.Normalize();
					staticMeshComp->AddImpulseAtLocation(direction * 30000.f, OwnerCharacter->GetActorLocation());
					return;
				} // if (staticMeshComp->BodyInstance.bSimulatePhysics == true)
			} // if (staticMeshComp != nullptr)
		} // if (staticMeshActor != nullptr)
	} // if (GetWorld()->LineTraceSingleByChannel(hitResult, start, end, ECollisionChannel::ECC_PhysicsBody, collisionQueryParams))
}

void ACRifle::BeginPlay()
{
	Super::BeginPlay();

	OwnerCharacter = Cast<ACharacter>(GetOwner());
	
	AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), HolsterSocket);
}

void ACRifle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bAiming == false) return;

	IIRifle* rifleInterface = Cast<IIRifle>(OwnerCharacter);
	if (rifleInterface == nullptr) return;

	FVector start, end, direction;
	rifleInterface->GetAimInfo(start, end, direction);
	//DrawDebugLine(GetWorld(), start, end, FColor::Red);

	FHitResult hitResult;
	FCollisionQueryParams collisionQueryParams;
	collisionQueryParams.AddIgnoredActor(this);
	collisionQueryParams.AddIgnoredActor(OwnerCharacter);
	if (GetWorld()->LineTraceSingleByChannel(hitResult, start, end, ECollisionChannel::ECC_PhysicsBody, collisionQueryParams))
	{
		AStaticMeshActor* staticMeshActor = Cast<AStaticMeshActor>(hitResult.GetActor());
		if (staticMeshActor != nullptr)
		{
			UStaticMeshComponent* staticMeshComp = Cast<UStaticMeshComponent>(staticMeshActor->GetRootComponent());
			if (staticMeshComp != nullptr)
			{
				if (staticMeshComp->BodyInstance.bSimulatePhysics == true)
				{
					rifleInterface->OnTarget();
					return;
				} // if (staticMeshComp->BodyInstance.bSimulatePhysics == true)
			} // if (staticMeshComp != nullptr)
		} // if (staticMeshActor != nullptr)
	} // if (GetWorld()->LineTraceSingleByChannel(hitResult, start, end, ECollisionChannel::ECC_PhysicsBody, collisionQueryParams))

	rifleInterface->OffTarget();
}
