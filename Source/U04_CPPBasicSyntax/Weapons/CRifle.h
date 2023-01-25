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
	FORCEINLINE bool IsAiming() const { return bAiming; }

	FORCEINLINE bool IsFiring() const { return bFiring; }
	FORCEINLINE bool IsAutoFire() const { return bAutoFire; }
	FORCEINLINE void ToggleAutoFire() { bAutoFire = !bAutoFire; }

	void Begin_Aiming();
	void End_Aiming();

	void Equip();
	void Begin_Equip();
	void End_Equip();

	void Unequip();
	void Begin_Unequip();
	void End_Unequip();

	void Begin_Fire();
	void End_Fire();

	void Firing();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Bullet")
		TSubclassOf<class ACBullet> BulletClass;

	UPROPERTY(EditDefaultsOnly, Category = "Bullet")
		float PitchSpeed = 0.25f;

	UPROPERTY(EditDefaultsOnly, Category = "Socket")
		FName HolsterSocket = "Holster_Rifle";
	UPROPERTY(EditDefaultsOnly, Category = "Socket")
		FName HandSocket = "Hand_Rifle";

	UPROPERTY(EditDefaultsOnly, Category = "Montages")
		class UAnimMontage* GrabMontage;
	UPROPERTY(EditDefaultsOnly, Category = "Montages")
		class UAnimMontage* UngrabMontage;

	UPROPERTY(EditDefaultsOnly, Category = "CameraShake")
		TSubclassOf<class UCameraShake> CameraShakeClass;

	// ÃÑ±¸ È­¿°
	UPROPERTY(EditDefaultsOnly, Category = "Effect")
		class UParticleSystem* FlashParticle;
	// ÅºÇÇ
	UPROPERTY(EditDefaultsOnly, Category = "Effect")
		class UParticleSystem* EjectParticle;
	// ÇÇ°Ý ½Ã
	UPROPERTY(EditDefaultsOnly, Category = "Effect")
		class UParticleSystem* ImpactParticle;

	UPROPERTY(EditDefaultsOnly, Category = "Effect")
		class USoundCue* FireSoundCue;
	// µ¥Ä®
	UPROPERTY(EditDefaultsOnly, Category = "Effect")
		class UMaterialInstanceConstant* DecalMaterial;

private:
	UPROPERTY(VisibleDefaultsOnly)
		class USkeletalMeshComponent* Mesh;

private:
	class ACharacter* OwnerCharacter;

	float CurrentPitch;

	bool bEquipped;
	bool bEquipping;
	bool bAiming;
	bool bFiring;
	bool bAutoFire;

	FTimerHandle AutoFireTimer;
};
