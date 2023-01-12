#include "CPhysicsCube.h"
#include "Global.h"
#include "Components/StaticMeshComponent.h"

ACPhysicsCube::ACPhysicsCube()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;

	ConstructorHelpers::FObjectFinder<UStaticMesh> meshAsset(TEXT("StaticMesh'/Game/Meshes/SM_Cube.SM_Cube'"));
	if (meshAsset.Succeeded())
		Mesh->SetStaticMesh(meshAsset.Object);

	Mesh->SetRelativeScale3D(FVector(0.75f));
	Mesh->SetSimulatePhysics(true);
	Mesh->SetCollisionObjectType(ECollisionChannel::ECC_PhysicsBody);
}

void ACPhysicsCube::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPhysicsCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

