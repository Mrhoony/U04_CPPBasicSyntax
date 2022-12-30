#include "C02_StaticMesh_Cone.h"

AC02_StaticMesh_Cone::AC02_StaticMesh_Cone()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh> meshAsset(TEXT("StaticMesh'/Game/Meshes/SM_Cone.SM_Cone'"));

	if (meshAsset.Succeeded())
		Mesh->SetStaticMesh(meshAsset.Object);
}
