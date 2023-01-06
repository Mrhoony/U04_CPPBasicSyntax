#pragma once

#include "CoreMinimal.h"
#include "03_Collision/C00_BoxBase.h"
#include "C02_ComponentOverlap.generated.h"

UCLASS()
class U04_CPPBASICSYNTAX_API AC02_ComponentOverlap : public AC00_BoxBase
{
	GENERATED_BODY()

public:
	AC02_ComponentOverlap();

protected:
	void BeginPlay() override;

private:
	UFUNCTION()
		void ComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
		void ComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:
	UPROPERTY(VisibleDefaultsOnly)
		class UPointLightComponent* PointLight;
};
