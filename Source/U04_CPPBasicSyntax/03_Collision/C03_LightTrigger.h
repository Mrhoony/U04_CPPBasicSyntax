#pragma once

#include "CoreMinimal.h"
#include "03_Collision/C00_BoxBase.h"
#include "C03_LightTrigger.generated.h"

DECLARE_DELEGATE(FBoxBeginOverlap); // void __()
DECLARE_DELEGATE(FBoxEndOverlap); // void __()

UCLASS()
class U04_CPPBASICSYNTAX_API AC03_LightTrigger : public AC00_BoxBase
{
	GENERATED_BODY()

protected:
	void BeginPlay() override;

private:
	UFUNCTION()
		void ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
		void ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor);

public: // 일반적으로 델리게이트 변수는 퍼블릭 영역에 지정 Get/Set 해도 되지만 복잡해진다
	FBoxBeginOverlap OnBoxBeginOverlap;
	FBoxEndOverlap OnBoxEndOverlap;
};
