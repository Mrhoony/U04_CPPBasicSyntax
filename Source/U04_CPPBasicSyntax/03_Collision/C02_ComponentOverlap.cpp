#include "C02_ComponentOverlap.h"
#include "Components/PointLightComponent.h"
#include "Components/BoxComponent.h"

AC02_ComponentOverlap::AC02_ComponentOverlap()
{
	PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLight");
	PointLight->SetupAttachment(Scene);

	PointLight->SetLightColor(FLinearColor::Green);
}

void AC02_ComponentOverlap::BeginPlay()
{
	Super::BeginPlay();

	PointLight->SetVisibility(false);

	Box->OnComponentBeginOverlap.AddDynamic(this, &AC02_ComponentOverlap::ComponentBeginOverlap);
	Box->OnComponentEndOverlap.AddDynamic(this, &AC02_ComponentOverlap::ComponentEndOverlap);
}

void AC02_ComponentOverlap::ComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	PointLight->SetLightColor(FLinearColor::MakeRandomColor());
	PointLight->SetVisibility(true);
}

void AC02_ComponentOverlap::ComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	PointLight->SetVisibility(false);
}
