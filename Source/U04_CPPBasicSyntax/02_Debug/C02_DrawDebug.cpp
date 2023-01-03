#include "C02_DrawDebug.h"
#include "Global.h"

AC02_DrawDebug::AC02_DrawDebug()
{
	PrimaryActorTick.bCanEverTick = true;

	RelativeLocation[0] = FVector(500, 0, 0);
	RelativeLocation[1] = FVector(0, 500, 0);
	RelativeLocation[2] = FVector(-500, 0, 0);
	RelativeLocation[3] = FVector(-1000, 0, 0);
}

void AC02_DrawDebug::BeginPlay()
{
	Super::BeginPlay();

	FBox box = FBox(FVector(-50, -100, -50), FVector(+50, +100, +50));

	DrawDebugBox
	(
		GetWorld(),
		GetActorLocation() + box.GetCenter(),
		box.GetExtent(),
		FColor::Red,
		true
	);
}

void AC02_DrawDebug::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (int32 i = 0; i < 4; i++)
		WorldLocation[i] = GetActorLocation() + RelativeLocation[i];

	FBox box = FBox(FVector(-50, -100, -50), FVector(+50, +100, +50));
	DrawDebugSolidBox(GetWorld(), WorldLocation[0], box.GetExtent(), FColor::Emerald);
	DrawDebugPoint(GetWorld(), WorldLocation[1], 10.f, FColor::Cyan);
	DrawDebugSphere(GetWorld(), WorldLocation[2], 100.f, 20.f, FColor::Green);
	DrawDebugCircle(GetWorld(), WorldLocation[3], 100.f, 100.f, FColor::Green);
	DrawDebugDirectionalArrow(GetWorld(), WorldLocation[1], WorldLocation[3], 100.f, FColor::Red, false, -1.f, 0, 10.f);
}
