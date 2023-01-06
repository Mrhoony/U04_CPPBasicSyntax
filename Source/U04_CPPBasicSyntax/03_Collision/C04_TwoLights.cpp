#include "C04_TwoLights.h"
#include "Components/PointLightComponent.h"

AC04_TwoLights::AC04_TwoLights()
{
	PointLight1 = CreateDefaultSubobject<UPointLightComponent>("PointLight1");
	PointLight2 = CreateDefaultSubobject<UPointLightComponent>("PointLight2");

	PointLight1->SetupAttachment(Scene);
	PointLight2->SetupAttachment(Scene);

	PointLight1->AttenuationRadius = 200;
	PointLight1->Intensity = 1e+4f;
	PointLight1->LightColor = FColor(255, 128, 50);
	
	PointLight2->AttenuationRadius = 200;
	PointLight2->Intensity = 1e+4f;
	PointLight2->LightColor = FColor(255, 128, 50);
	PointLight2->SetRelativeLocation(FVector(0, 200, 0));
}