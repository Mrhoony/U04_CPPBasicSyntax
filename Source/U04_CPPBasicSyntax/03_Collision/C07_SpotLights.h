#pragma once

#include "CoreMinimal.h"
#include "03_Collision/C00_TextRenderBase.h"
#include "C07_SpotLights.generated.h"

UCLASS()
class U04_CPPBASICSYNTAX_API AC07_SpotLights : public AC00_TextRenderBase
{
	GENERATED_BODY()

public:
	AC07_SpotLights();

protected:
	void BeginPlay() override;

private:
	UFUNCTION()
		void OnRandomLightColor(int32 InIndex, FLinearColor InColor);

private:
	class USpotLightComponent* SpotLights[3];

};
