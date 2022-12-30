#include "C02_StaticMesh_Cylinder.h"

AC02_StaticMesh_Cylinder::AC02_StaticMesh_Cylinder()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh> meshAsset(TEXT("StaticMesh'/Game/Meshes/SM_Cylinder.SM_Cylinder'"));

	if (meshAsset.Succeeded())
		Mesh->SetStaticMesh(meshAsset.Object);
}
