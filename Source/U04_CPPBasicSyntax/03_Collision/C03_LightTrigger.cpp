#include "C03_LightTrigger.h"
#include "Global.h"

void AC03_LightTrigger::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &AC03_LightTrigger::ActorBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &AC03_LightTrigger::ActorEndOverlap);
}

void AC03_LightTrigger::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OnBoxBeginOverlap.IsBound())
		OnBoxBeginOverlap.Execute();
	// BroadCast ดย Multicast ภüฟ๋
}

void AC03_LightTrigger::ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OnBoxEndOverlap.IsBound())
		OnBoxEndOverlap.Execute();

	//TODO: Deligate Binding
}
