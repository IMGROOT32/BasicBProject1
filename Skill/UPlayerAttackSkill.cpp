#include "UPlayerAttackSkill.h"
#include "../Character/Character.h"
#include <string>

UPlayerAttackSkill::UPlayerAttackSkill(ACharacter* NewOwner)
	: USkill(NewOwner)
{

}
void UPlayerAttackSkill::Play(ACharacter* Target)
{
	int Damage = Owner->GetAtk();
	bool bCritical = Owner->GetRandomInt() < Owner->GetCritical();
	if (bCritical)
	{
		Damage = static_cast<int>(Damage * 1.5f);
	}

	int FinalDamage = Target->TakeDamage(Damage);
	FDamageResult result;
	result.Attacker = Owner;
	result.Target = Target;
	result.Damage = FinalDamage;
	result.bCritical = bCritical;

	string AttackMessage = " 이(가) 검으로 공격합니다";
	if (result.bCritical)
	{
		AttackMessage = "이(가) 검으로 급소를 찔렀습니다.";
	}
	result.PrintMessage(AttackMessage);
	}
