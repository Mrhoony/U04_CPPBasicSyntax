#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C00_TextRenderBase.generated.h"

UCLASS()
class U04_CPPBASICSYNTAX_API AC00_TextRenderBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AC00_TextRenderBase();

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Scene;
	UPROPERTY(VisibleDefaultsOnly)
		class UTextRenderComponent* Text;
};
