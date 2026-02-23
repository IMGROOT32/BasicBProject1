#include "UMonsterDrainSkill.h"
#include "../Character/Character.h"
#include <string>

UMonsterDrainSkill::UMonsterDrainSkill(ACharacter* NewOwner)
	: USkill(NewOwner)
{

}

void UMonsterDrainSkill::Play(ACharacter* Target)
{
	FDamageResult result;
	result.Attacker = Owner;
	result.Target = Target;
	result.bCritical = false;

	int FinalDamage = Target->TakeDamage(Owner->GetAtk());
	Owner->Heal(FinalDamage);

	result.Damage = FinalDamage;
	result.PrintMessage("의 피를 마십니다.");
	result.PrintMessage("체력을 회복합니다.");

}
