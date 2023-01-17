#include "CRifle.h"
#include "Global.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Character.h"
#include "Animation/AnimMontage.h"

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
}

void ACRifle::Unequip()
{
	if (bEquipped == false) return;
	if (bEquipping == true) return;

	bEquipping = true;

	OwnerCharacter->PlayAnimMontage(UngrabMontage, 1.75);
}

void ACRifle::Begin_Unequip()
{
	bEquipped = false;
	AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), HolsterSocket);
}

void ACRifle::End_Unequip()
{
	bEquipping = false;
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

}
