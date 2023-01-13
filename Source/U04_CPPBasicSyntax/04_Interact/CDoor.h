#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CDoor.generated.h"

UCLASS()
class U04_CPPBASICSYNTAX_API ACDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	ACDoor();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void ActorBeginOverlap(class AActor* OverlappedActor, class AActor* OtherActor);
	UFUNCTION()
		void ActorEndOverlap(class AActor* OverlappedActor, class AActor* OtherActor);
	UFUNCTION()
		void Interact();


public:	
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Scene;
	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* DoorFrame;
	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* Door;
	UPROPERTY(VisibleDefaultsOnly)
		class UBoxComponent* Box;

private:
	UPROPERTY(EditAnywhere)
		bool bHiddenCollision;

	UPROPERTY(EditAnywhere)
		float MaxDegree = 90.f;

	UPROPERTY(EditAnywhere)
		float Speed = 90.f;

private:
	class ACPlayer* Player;

	float Direction; // -1, +1
	float DirectionMaxDergree; // -90, +90
	float YawPerTick;

	bool bClosed = true; // Open or Close
	bool bClosing; // Tick
	bool bOpening; // Tick	
};
