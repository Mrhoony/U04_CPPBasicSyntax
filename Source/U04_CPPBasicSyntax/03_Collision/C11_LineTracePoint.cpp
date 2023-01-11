#include "C11_LineTracePoint.h"
#include "Global.h"
#include "Components/StaticMeshComponent.h"

AC11_LineTracePoint::AC11_LineTracePoint()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(Scene);

	ConstructorHelpers::FObjectFinder<UStaticMesh> meshAsset(TEXT("StaticMesh'/Game/Meshes/SM_Cylinder.SM_Cylinder'"));
	if (meshAsset.Succeeded())
		Mesh->SetStaticMesh(meshAsset.Object);


}