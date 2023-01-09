#include "C04_TwoLights.h"
#include "Global.h"
#include "C03_LightTrigger.h"
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

void AC04_TwoLights::BeginPlay()
{
	Super::BeginPlay();

	PointLight1->SetVisibility(false);
	PointLight2->SetVisibility(false);

	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AC03_LightTrigger::StaticClass(), actors);
	if (actors.Num() < 1) return;

	AC03_LightTrigger* trigger = Cast<AC03_LightTrigger>(actors[0]);
	if (trigger == nullptr) return;

	trigger->OnBoxBeginOverlap.BindUFunction(this, "OnLight");
	trigger->OnBoxEndOverlap.BindUFunction(this, "OffLight");	
	trigger->OnBoxBeginRandomLightColor.BindUFunction(this, "OnRandomLightColor");
}

void AC04_TwoLights::OnLight()
{
	PointLight1->SetVisibility(true);
}

void AC04_TwoLights::OffLight()
{
	PointLight1->SetVisibility(false);
	PointLight2->SetVisibility(false);
}

FString AC04_TwoLights::OnRandomLightColor(FLinearColor InColor)
{
	PointLight2->SetVisibility(true);
	PointLight2->SetLightColor(InColor);

	return InColor.ToString();
}
