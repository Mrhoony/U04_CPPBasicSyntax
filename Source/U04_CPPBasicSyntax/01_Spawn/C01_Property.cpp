#include "C01_Property.h"
#include "Components/TextRenderComponent.h"

AC01_Property::AC01_Property()
	: Charlie(30)
{
	//PrimaryActorTick.bCanEverTick = true;
	Text = CreateDefaultSubobject<UTextRenderComponent>("TextRender");
	if (Text == nullptr) return;

	RootComponent = Text;
	Text->SetText(GetName());
}

void AC01_Property::BeginPlay()
{
	Super::BeginPlay();
	
	/*GLog->Log("Hello World 1");
	UE_LOG(LogTemp, Error, TEXT("%s"), L"Hello World 2");*/

	if (bVisible == false) return;

	FString str;
	str.Append("Alpha : ");
	str.Append(FString::FromInt(Alpha));
	str.Append("Bravo : ");
	str.Append(FString::FromInt(Bravo));
	str.Append("Charlie : ");
	str.Append(FString::FromInt(Charlie));
	str.Append("Delta : ");
	str.Append(FString::FromInt(Delta));
	str.Append("Echo : ");
	str.Append(FString::FromInt(Echo));
	str.Append("Foxtrot : ");
	str.Append(FString::FromInt(Foxtrot));
	str.Append("Golf : ");
	str.Append(FString::FromInt(Golf));

	GLog->Log(str);
}

void AC01_Property::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
