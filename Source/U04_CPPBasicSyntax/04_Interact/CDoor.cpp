#include "CDoor.h"
#include "Global.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

ACDoor::ACDoor()
{
	// Create Components
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>("Scene");
	RootComponent = Scene;

	DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>("DoorFrame");
	DoorFrame->SetupAttachment(Scene);

	Door = CreateDefaultSubobject<UStaticMeshComponent>("Door");
	Door->SetupAttachment(DoorFrame);

	Box = CreateDefaultSubobject<UBoxComponent>("Box");
	Box->SetupAttachment(Scene);

	// Set Components
	ConstructorHelpers::FObjectFinder<UStaticMesh> doorFrameAsset(TEXT("StaticMesh'/Game/DoorMesh/Props/SM_DoorFrame.SM_DoorFrame'"));
	if (doorFrameAsset.Succeeded())
		DoorFrame->SetStaticMesh(doorFrameAsset.Object);
}

void ACDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

