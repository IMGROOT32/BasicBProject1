#include "Monster.h"

AMonster::AMonster(const string& NewName, const FUnitStat& NewStat) 
	: ACharacter(NewName, NewStat)
{
	

};

void AMonster::Attack(ACharacter* Target)
{
	cout << "크아앙!" << Name << "이(가) 이빨로 물어뜯습니다!" << endl;

	Target->TakeDamage(Stat.Atk);
}