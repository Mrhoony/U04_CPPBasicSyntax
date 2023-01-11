#include "C10_BlueprintOverride.h"
#include "Global.h"
#include "Characters/CPlayer.h"

void AC10_BlueprintOverride::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &AC10_BlueprintOverride::ActorBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &AC10_BlueprintOverride::ActorEndOverlap);
}

void AC10_BlueprintOverride::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	SetBodyColor();
}

void AC10_BlueprintOverride::ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	ResetBodyColor();
}

void AC10_BlueprintOverride::ResetBodyColor_Implementation()
{
	ACPlayer* player = Cast<ACPlayer>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (player == nullptr) return;

	FLinearColor originColor = FLinearColor(0.450980, 0.403922, 0.360784, 0.000000);
	player->ChangeBodyColor(originColor, originColor);
}