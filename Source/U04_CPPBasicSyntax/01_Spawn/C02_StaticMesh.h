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
	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* Mesh;
};
