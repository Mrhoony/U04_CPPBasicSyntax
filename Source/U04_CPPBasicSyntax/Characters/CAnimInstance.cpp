#include "CAnimInstance.h"
#include "Global.h"
#include "Characters/CPlayer.h"

void UCAnimInstance::NativeBeginPlay()
{
	Player = Cast<ACPlayer>(TryGetPawnOwner());
}

void UCAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	if (Player == nullptr) return;

	Speed = Player->GetVelocity().Size2D();
}
