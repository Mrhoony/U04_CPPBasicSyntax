#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CAnimInstance.generated.h"

UCLASS()
class U04_CPPBASICSYNTAX_API UCAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Animation")
		float Speed;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Animation")
		float Direction;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Animation")
		float Pitch;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Animation")
		bool bEquipped;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Animation")
		bool bAiming;

private:
	class ACharacter* OwnerCharacter;
};
