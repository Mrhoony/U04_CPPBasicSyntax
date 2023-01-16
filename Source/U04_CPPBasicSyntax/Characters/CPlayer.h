#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "IRifle.h"
#include "CPlayer.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInteractEvent);

UCLASS()
class U04_CPPBASICSYNTAX_API ACPlayer : public ACharacter, public IIRifle
{
	GENERATED_BODY()

public:
	ACPlayer();

	FORCEINLINE class ACRifle* GetRifle() override { return Rifle; };

	UFUNCTION(BlueprintCallable)
		void ChangeBodyColor(FLinearColor InBodyColor, FLinearColor InLogoColor);

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// Axis Mapping
	void OnMoveForward(float InAxis);
	void OnMoveRight(float InAxis);
	
	void OnHorizontalLook(float InAxis);
	void OnVerticalLook(float InAxis);

	// Action Mapping
	void OnRun();
	void OffRun();
	void OnInteract();
	void OnRifle();

private:
	UPROPERTY(VisibleDefaultsOnly)
		class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleDefaultsOnly)
		class UCameraComponent* Camera;

private:
	class UMaterialInstanceDynamic* BodyMaterialDynamic;
	class UMaterialInstanceDynamic* LogoMaterialDynamic;

public:
	FInteractEvent OnInteractEvent;

private:
	class ACRifle* Rifle;
};
