#include "UPlayerStrikeSkill.h"
#include "../Character/Character.h"
#include <string>

UPlayerStrikeSkill::UPlayerStrikeSkill(ACharacter* NewOwner)
	: USkill(NewOwner)
{

}

void UPlayerStrikeSkill::Play(ACharacter* Target)
{
		FDamageResult result;
		result.Attacker = Owner;
		result.Target = Target;
		result.bCritical = false;

		int FinalDamage = Target->TakeDamage(Owner->GetAtk() * 1.25);
		result.Damage = FinalDamage;
		result.PrintMessage("하늘에서 무한한 검이 쏟아집니다.");

}