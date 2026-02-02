#include "Monster.h"

AMonster::AMonster(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{


};

FDamageResult AMonster::Attack(ACharacter* Target)
{
	FDamageResult result = ACharacter::Attack(Target);
	string AttackMessage = " 이(가) 몸통박치기를 합니다";
	if (result.bCritical)
	{
		AttackMessage = "이(가) 머리의 뿔로 급소를 찔렀습니다.";
	}

	result.PrintMessage(AttackMessage);
	
	return result;
}


void AMonster::UseSkill(ACharacter* Target)
{
	FDamageResult result;
	result.Attacker = this;
	result.Target = Target;
	result.bCritical = false;

	if (Stat.Mp < 10)
	{
		return;
	}
	
	int FinalDamage = Target->TakeDamage(Stat.Atk);
	Stat.Mp -= 10;
	Heal(FinalDamage);

	result.Damage = FinalDamage;
	result.PrintMessage("의 피를 마십니다.");
	result.PrintMessage("체력을 회복합니다.");

}