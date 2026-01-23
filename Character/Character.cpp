
#include "Character.h"
#include <cstdlib>
#include <ctime>
#include <random>


ACharacter::ACharacter(string NewName, int NewHp, int NewAtk, int NewDef, float NewCritical)
{
	Name = NewName;
	Hp = NewHp;
	Atk = NewAtk;
	Def = NewDef;
	Critical = NewCritical;

	cout << "[생성] " << Name << "가 전장에 나타났습니다! (HP: " << Hp << ")" << endl;
}
ACharacter::~ACharacter()
{
	cout << "ACharacter 이 소멸되었습니다." << endl;
}

void ACharacter::Attack(ACharacter *target)
{
	if (target == nullptr)
	{
		return;
	}

	float DamageAmount = Atk;

	int r = rand() % 100;
	if (r < 10)
	{
		DamageAmount *= 1.5f;
	}
	else
	{
		target->TakeDamage(DamageAmount);
	}
	cout << Name << "가 공격합니다! (공격력 : " << Atk << ")" << endl;
}

void ACharacter::TakeDamage(float DamageAmount)
{
	Hp += Def;
	
		if (Hp - DamageAmount <= 0)
		{
			Hp == 0;
		}
		else
		{
			Hp -= DamageAmount;
		}


	cout << Name << "가 " << DamageAmount << "의 피해를 입었습니다." << endl;
	cout << "   -> 남은 체력: " << Hp << endl;
}

int ACharacter::GetHp()
{
	return Hp;
}

bool ACharacter::IsDead()
{
	return Hp <= 0;
}
