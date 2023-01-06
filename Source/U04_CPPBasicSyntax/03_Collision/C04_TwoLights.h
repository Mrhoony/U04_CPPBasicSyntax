#pragma once

#include "CoreMinimal.h"
#include "03_Collision/C00_TextRenderBase.h"
#include "C04_TwoLights.generated.h"

UCLASS()
class U04_CPPBASICSYNTAX_API AC04_TwoLights : public AC00_TextRenderBase
{
	GENERATED_BODY()

public:
	AC04_TwoLights();

private:
	UPROPERTY(VisibleDefaultsOnly)
		class UPointLightComponent* PointLight1;

	UPROPERTY(VisibleDefaultsOnly)
		class UPointLightComponent* PointLight2;
};
