#include "C00_TextRenderBase.h"
#include "Global.h"
#include "Components/TextRenderComponent.h"

AC00_TextRenderBase::AC00_TextRenderBase()
{
	Scene = CreateDefaultSubobject<USceneComponent>("Scene");
	RootComponent = Scene;

	Text = CreateDefaultSubobject<UTextRenderComponent>("Text");
	Text->SetupAttachment(Scene);

	Text->SetRelativeRotation(FRotator(0, 180, 0));
	Text->SetRelativeLocation(FVector(0, 0, 100));
	Text->SetTextRenderColor(FColor::Black);
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	Text->SetText(FText::FromString(GetName()));
}

void AC00_TextRenderBase::BeginPlay()
{
	Super::BeginPlay();
}
