#include "C02_StaticMesh.h"
#include "Components/StaticMeshComponent.h"

AC02_StaticMesh::AC02_StaticMesh()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;

	ConstructorHelpers::FObjectFinder<UStaticMesh> meshAsset(TEXT("/Game/Meshes/SM_Cube"));

	if(meshAsset.Succeeded())
	Mesh->SetStaticMesh(meshAsset.Object);
}

void AC02_StaticMesh::BeginPlay()
{
	Super::BeginPlay();
	
}
