#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C01_PrintLog.generated.h"

UCLASS()
class U04_CPPBASICSYNTAX_API AC01_PrintLog : public AActor
{
	GENERATED_BODY()
	
public:	
	AC01_PrintLog();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	float RunningTime;
	bool bVisible;
};
