#include "C14_ExplosionTrigger.h"
#include "Global.h"
#include "C13_Explosion.h"

void AC14_ExplosionTrigger::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AC13_Explosion::StaticClass(), actors);
	if (actors.Num() < 1) return;

	AC13_Explosion* explosion = Cast<AC13_Explosion>(actors[0]);
	if (explosion == nullptr) return;

	OnActorBeginOverlap.AddDynamic(explosion, &AC13_Explosion::OnExplosion);
}