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
	cout << "푸슉 " << Name << AttackMessage<<"데미지 : " << result.Damage<<endl;
	cout << Target->GetName() << "남은 HP : " << Target->GetHp() << endl;
	return result;
}