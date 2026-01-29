#include "Monster.h"

AMonster::AMonster(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{


};

void AMonster::Attack(ACharacter* Target)
{
	cout << "와다다다 " << Name << "이(가) 달려와 몸통박치기를 합니다." << endl;

	ACharacter::Attack(Target);

}