#pragma once

#include "CoreMinimal.h"
#include "03_Collision/C00_TextRenderBase.h"
#include "C06_Cubes.generated.h"

UCLASS()
class U04_CPPBASICSYNTAX_API AC06_Cubes : public AC00_TextRenderBase
{
	GENERATED_BODY()

public:
	AC06_Cubes();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void OnStartFalling(int32 InIndex, FLinearColor InColor);
	
private:
	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* Cubes[3];

private:
	FVector FirstLocations[3];
};
