#include "Player.h"

APlayer::APlayer(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
	Level = 1;
	Exp = 0;
}

FDamageResult APlayer::Attack(ACharacter* Target)
{
	FDamageResult result = ACharacter::Attack(Target);
	string AttackMessage = " 이(가) 검으로 공격합니다";
	if (result.bCritical)
	{
		AttackMessage = "이(가) 검으로 급소를 찔렀습니다.";
	}
	result.PrintMessage(AttackMessage);
	return result;
}

void APlayer::UseSkill(ACharacter* Target)
{
	FDamageResult result;
	result.Attacker = this;
	result.Target = Target;
	result.bCritical = false;

	if (Stat.Mp < 10)
	{
		return;
	}

	Stat.Mp -= 10;
	int FinalDamage = Target->TakeDamage(Stat.Atk * 2);
	result.Damage = FinalDamage;
	result.PrintMessage("하늘에서 무한한 검이 쏟아집니다.");
	
}