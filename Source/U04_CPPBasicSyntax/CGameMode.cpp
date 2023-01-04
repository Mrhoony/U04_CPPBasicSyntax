#include "CGameMode.h"
#include "Characters/CPlayer.h"

ACGameMode::ACGameMode()
{
	ConstructorHelpers::FClassFinder<APawn> pawnClass(TEXT("Blueprint'/Game/Player/BP_CPlayer.BP_CPlayer_C'"));
	//ConstructorHelpers::FClassFinder<APawn> PawnClass(TEXT("/Game/Player/BP_CPlayer"));
	
	if (pawnClass.Succeeded())
		DefaultPawnClass = pawnClass.Class;
}
