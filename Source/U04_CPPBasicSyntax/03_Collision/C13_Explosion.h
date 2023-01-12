#pragma once

#include "CoreMinimal.h"
#include "03_Collision/C00_TextRenderBase.h"
#include "C13_Explosion.generated.h"

UCLASS()
class U04_CPPBASICSYNTAX_API AC13_Explosion : public AC00_TextRenderBase
{
	GENERATED_BODY()
	
public:
	AC13_Explosion();

	UFUNCTION()
		void OnExplosion(class AActor* OverlappedActor, class AActor* OtherActor);

private:
	UPROPERTY(VisibleDefaultsOnly)
		class UParticleSystemComponent* Particle;
};
