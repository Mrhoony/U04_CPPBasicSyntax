#include "C01_Property.h"

AC01_Property::AC01_Property()
{
	//PrimaryActorTick.bCanEverTick = true;
}

void AC01_Property::BeginPlay()
{
	Super::BeginPlay();
	
	GLog->Log("Hello World 1");
	UE_LOG(LogTemp, Error, TEXT("%s"), L"Hello World 2");
}

void AC01_Property::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
