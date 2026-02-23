#include "UMonsterAttackSkill.h"
#include "../Character/Character.h"
#include <string>

UMonsterAttackSkill::UMonsterAttackSkill(ACharacter* NewOwner)
	: USkill(NewOwner)
{

}

void UMonsterAttackSkill::Play(ACharacter* Target)
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

	string AttackMessage = " 이(가) 몸통박치기를 합니다";
	if (result.bCritical)
	{
		AttackMessage = "이(가) 머리의 뿔로 급소를 찔렀습니다.";
	}

	result.PrintMessage(AttackMessage);

}