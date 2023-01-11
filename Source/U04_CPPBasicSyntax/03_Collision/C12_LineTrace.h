#pragma once

#include "CoreMinimal.h"
#include "03_Collision/C00_TextRenderBase.h"
#include "C12_LineTrace.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLineTraceEvent, class AActor*, InActor, FLinearColor, InColor);

UCLASS()
class U04_CPPBASICSYNTAX_API AC12_LineTrace : public AC00_TextRenderBase
{
	GENERATED_BODY()

public:
	AC12_LineTrace();
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	class AC11_LineTracePoint* Cylinders[2];

public:
	UPROPERTY(BlueprintAssignable) // 블루프린트에서 만든 커스텀 이벤트를 바인딩을 할 수 있게 해줌
		FLineTraceEvent OnLineTraceEvent;

private:
	UFUNCTION()
		void Ragdoll(class AActor* InActor, FLinearColor InColor);
};
