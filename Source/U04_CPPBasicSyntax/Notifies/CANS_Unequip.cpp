#include "CANS_Unequip.h"
#include "Global.h"
#include "Characters/IRifle.h"
#include "Weapons/CRifle.h"

FString UCANS_Unequip::GetNotifyName_Implementation() const
{
	return "Equip";
}

void UCANS_Unequip::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);
	if (MeshComp == nullptr) return;

	IIRifle* rifleInterface = Cast<IIRifle>(MeshComp->GetOwner());
	if (rifleInterface == nullptr) return;

	rifleInterface->GetRifle()->Begin_Unequip();
}

void UCANS_Unequip::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);
	if (MeshComp == nullptr) return;

	IIRifle* rifleInterface = Cast<IIRifle>(MeshComp->GetOwner());
	if (rifleInterface == nullptr) return;

	rifleInterface->GetRifle()->End_Unequip();
}