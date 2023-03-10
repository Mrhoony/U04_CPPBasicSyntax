#include "CANS_Equip.h"
#include "Global.h"
#include "Characters/IRifle.h"
#include "Weapons/CRifle.h"

FString UCANS_Equip::GetNotifyName_Implementation() const
{
	return "Equip";
}

void UCANS_Equip::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);
	if (MeshComp == nullptr) return;

	IIRifle* rifleInterface = Cast<IIRifle>(MeshComp->GetOwner());
	if (rifleInterface == nullptr) return;

	rifleInterface->GetRifle()->Begin_Equip();
}

void UCANS_Equip::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);
	if (MeshComp == nullptr) return;

	IIRifle* rifleInterface = Cast<IIRifle>(MeshComp->GetOwner());
	if (rifleInterface == nullptr) return;

	rifleInterface->GetRifle()->End_Equip();
}