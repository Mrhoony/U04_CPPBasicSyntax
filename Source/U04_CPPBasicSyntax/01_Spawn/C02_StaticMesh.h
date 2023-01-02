#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C02_StaticMesh.generated.h"

UCLASS()
class U04_CPPBASICSYNTAX_API AC02_StaticMesh : public AActor
{
	GENERATED_BODY()
	
public:	
	AC02_StaticMesh();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void ChangeParameter();

protected:
	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* Mesh;

private:
	class UMaterialInstanceDynamic* DynamicMaterial;
};
