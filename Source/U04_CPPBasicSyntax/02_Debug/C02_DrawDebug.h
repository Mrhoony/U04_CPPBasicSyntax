#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C02_DrawDebug.generated.h"

UCLASS()
class U04_CPPBASICSYNTAX_API AC02_DrawDebug : public AActor
{
	GENERATED_BODY()

public:
	AC02_DrawDebug();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category = "DrawDebug")
		FVector RelativeLocation[4];


	FVector WorldLocation[4];

};
