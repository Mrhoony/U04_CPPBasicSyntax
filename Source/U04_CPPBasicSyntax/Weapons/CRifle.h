#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CRifle.generated.h"

UCLASS()
class U04_CPPBASICSYNTAX_API ACRifle : public AActor
{
	GENERATED_BODY()
	
public:	
	ACRifle();

	static ACRifle* Spawn(class UWorld* InWorld, class ACharacter* InOwnerCharacter);
	
	FORCEINLINE bool IsEquipped() const { return bEquipped; }
	FORCEINLINE bool IsEquipping() const { return bEquipping; }

	void Equip();
	void Unequip();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Socket")
		FName HolsterSocket = "Holster_Rifle";
	UPROPERTY(EditDefaultsOnly, Category = "Socket")
		FName HandSocket = "Hand_Rifle";

	UPROPERTY(EditDefaultsOnly, Category = "Montages")
		class UAnimMontage* GrabMontage;
	UPROPERTY(EditDefaultsOnly, Category = "Montages")
		class UAnimMontage* UngrabMontage;

private:
	UPROPERTY(VisibleDefaultsOnly)
		class USkeletalMeshComponent* Mesh;

private:
	class ACharacter* OwnerCharacter;

	bool bEquipped;
	bool bEquipping;
};
