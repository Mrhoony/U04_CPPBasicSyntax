#include "C01_ActorOverlap.h"
#include "Global.h"

void AC01_ActorOverlap::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &AC01_ActorOverlap::ActorBeginOverlap);
}

void AC01_ActorOverlap::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	PrintLine();
	CLog::Print(OtherActor->GetName() + " Is Come in...");
}
