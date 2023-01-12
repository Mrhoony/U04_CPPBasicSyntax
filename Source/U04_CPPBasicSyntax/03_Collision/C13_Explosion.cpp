#include "C13_Explosion.h"
#include "Global.h"
#include "Characters/CPlayer.h"
#include "Particles/ParticleSystemComponent.h"

AC13_Explosion::AC13_Explosion()
{
	Particle = CreateDefaultSubobject<UParticleSystemComponent>("Particle");
	Particle->SetupAttachment(Scene);
	Particle->bAutoActivate = false;

	ConstructorHelpers::FObjectFinder<UParticleSystem> particleAsset(TEXT("ParticleSystem'/Game/Particles/P_Impact_FireBall.P_Impact_FireBall'"));
	if (particleAsset.Succeeded())
		Particle->SetTemplate(particleAsset.Object);
}

void AC13_Explosion::OnExplosion(AActor* OverlappedActor, AActor* OtherActor)
{
	ACPlayer* player = Cast<ACPlayer>(OtherActor);
	if (player == nullptr) return;

	//SphereTrace
	FVector start = GetActorLocation();
	FVector end = FVector(start.X, start.Y, start.Z + 100);

	TArray<TEnumAsByte<EObjectTypeQuery>> objectTypes;
	objectTypes.Add(EObjectTypeQuery::ObjectTypeQuery4);

	TArray<AActor*> ignoresActors;
	TArray<FHitResult> hitResults;

	if (UKismetSystemLibrary::SphereTraceMultiForObjects
	(
		GetWorld(),
		start,
		end,
		1000,
		objectTypes,
		false,
		ignoresActors,
		EDrawDebugTrace::ForDuration,
		hitResults,
		true
	))
	{
		Particle->ResetParticles();
		Particle->SetActive(true);

		for (const FHitResult& hitResult : hitResults)
		{
			UStaticMeshComponent* meshComp = Cast<UStaticMeshComponent>(hitResult.GetActor()->GetRootComponent());
			if (!!meshComp)
				meshComp->AddRadialImpulse(start, 1000, 15e6 / meshComp->GetMass(), ERadialImpulseFalloff::RIF_Linear);
		}
	}
}
