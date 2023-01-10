#pragma once

#include "CoreMinimal.h"
#include "03_Collision/C00_TextRenderBase.h"
#include "C09_Particles.generated.h"

UCLASS()
class U04_CPPBASICSYNTAX_API AC09_Particles : public AC00_TextRenderBase
{
	GENERATED_BODY()
	
public:
	AC09_Particles();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void PlayRandomParticle(int32 InIndex);

private:
	class UParticleSystem* Particles[3];
};
