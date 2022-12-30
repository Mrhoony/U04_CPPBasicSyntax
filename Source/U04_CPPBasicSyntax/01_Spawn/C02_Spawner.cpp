#include "C02_Spawner.h"
#include "C02_StaticMesh.h"

AC02_Spawner::AC02_Spawner()
{
}

void AC02_Spawner::BeginPlay()
{
	Super::BeginPlay();
	
	for (int32 i = 0; i < 4; i++)
	{
		FTransform transform;
		transform.SetLocation(FVector(100 * i, 0, 0));

		Meshes[i] = GetWorld()->SpawnActor<AC02_StaticMesh>(SpawnClasses[i], transform);

		//Meshes[i]->
	}
}
