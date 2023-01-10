#include "C10_BlueprintOverride.h"

void AC10_BlueprintOverride::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &AC10_BlueprintOverride::ActorBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &AC10_BlueprintOverride::ActorEndOverlap);
}

void AC10_BlueprintOverride::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	SetBodyColor();
}

void AC10_BlueprintOverride::ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
}
