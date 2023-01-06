#include "C00_BoxBase.h"
#include "Components/BoxComponent.h"

AC00_BoxBase::AC00_BoxBase()
{
	Box = CreateDefaultSubobject<UBoxComponent>("Box");
	Box->SetupAttachment(Scene);

	Box->SetRelativeScale3D(FVector(3));
	Box->bHiddenInGame = false;
}