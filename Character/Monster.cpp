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
		cout << "푹! " << Name << AttackMessage << "데미지 : " << result.Damage << endl;
		cout << Target->GetName() << "남은 HP : " << Target->GetHp() << endl;
		return result;
}