#pragma once

#include "CoreMinimal.h"
#include "03_Collision/C00_TextRenderBase.h"
#include "C00_BoxBase.generated.h"

UCLASS()
class U04_CPPBASICSYNTAX_API AC00_BoxBase : public AC00_TextRenderBase
{
	GENERATED_BODY()
	
public:
	AC00_BoxBase();

protected:
	UPROPERTY(VisibleDefaultsOnly)
		class UBoxComponent* Box;
};
