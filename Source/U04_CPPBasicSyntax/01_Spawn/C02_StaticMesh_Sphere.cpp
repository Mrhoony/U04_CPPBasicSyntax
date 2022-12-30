// Fill out your copyright notice in the Description page of Project Settings.


#include "C02_StaticMesh_Sphere.h"

AC02_StaticMesh_Sphere::AC02_StaticMesh_Sphere()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh> meshAsset(TEXT("StaticMesh'/Game/Meshes/SM_Sphere.SM_Sphere'"));

	if (meshAsset.Succeeded())
		Mesh->SetStaticMesh(meshAsset.Object);
}
