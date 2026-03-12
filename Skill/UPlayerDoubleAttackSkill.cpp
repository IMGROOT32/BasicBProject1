#include "UPlayerDoubleAttackSkill.h"
#include "../Character/Character.h"
#include <string>

UPlayerDoubleAttackSkill::UPlayerDoubleAttackSkill(ACharacter* NewOwner)
	: USkill(NewOwner, "더블 슬래시", 20)
{
}

void UPlayerDoubleAttackSkill::OnPlay(ACharacter* Target)
{
	FDamageResult result;
	result.Attacker = Owner;
	result.Target = Target;
	result.bCritical = false;

	int FinalDamage = Target->TakeDamage(Owner->GetAtk() * 2);
	result.Damage = FinalDamage;
	result.PrintMessage("더블 슬래시를 하여 한곳을 두번 공격합니다.");

}