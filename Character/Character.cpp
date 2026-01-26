
#include "Character.h"
#include <cstdlib>
#include <ctime>
#include <random>


ACharacter::ACharacter(string NewName, const FUnitStat& NewStat)
{
	Name = NewName;
	Stat = NewStat;

	cout << "[생성] " << Name << "가 전장에 나타났습니다! (HP: " << Stat.Hp << ")" << endl;
}
ACharacter::~ACharacter()
{
	cout << "ACharacter 이 소멸되었습니다." << endl;
}

void ACharacter::Attack(ACharacter* target)
{
	if (target == nullptr)
	{
		return;
	}

	//[총평] 코드 작성 후, 전반적으로 꼼꼼하게 코드를 검토하지 못한 느낌이 듭니다.  

	float DamageAmount = Stat.Atk;

	int r = rand() % 100;
	if (r < 10)
	{
		DamageAmount *= 1.5f;
		//크리티컬인 경우, TakeDamage()가 호출되지 않아요. 
	}
	else
	{
		target->TakeDamage(DamageAmount);
	}

	cout << Name << "가 공격합니다! (공격력 : " << Stat.Atk << ")" << endl;
}

void ACharacter::TakeDamage(int DamageAmount)
{

	DamageAmount -= Stat.Def;

	if (Stat.Hp - DamageAmount <= 0)
	{
		Stat.Hp == 0;
	}
	else
	{
		Stat.Hp -= DamageAmount;
	}


	cout << Name << "가 " << DamageAmount << "의 피해를 입었습니다." << endl;
	cout << "   -> 남은 체력: " << Stat.Hp << endl;
}