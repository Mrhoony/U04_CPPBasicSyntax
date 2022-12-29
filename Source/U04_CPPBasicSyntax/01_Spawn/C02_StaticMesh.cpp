#include "C02_StaticMesh.h"
#include "Components/StaticMeshComponent.h"

AC02_StaticMesh::AC02_StaticMesh()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;
}

void AC02_StaticMesh::BeginPlay()
{
	Super::BeginPlay();
	
}
