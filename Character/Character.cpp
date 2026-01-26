
#include "Character.h"
#include <cstdlib>
#include <random>


ACharacter::ACharacter(const string& NewName, const FUnitStat& NewStat)
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

	float DamageAmount = Stat.Atk;
	int r = rand() % 100;
	if (r < Stat.Critical)
	{
		DamageAmount *= 1.5f;
	}
	
	target->TakeDamage(static_cast<int>(DamageAmount));
	cout << Name << "가 공격합니다! (공격력 : " << Stat.Atk << ")" << endl;
}

void ACharacter::TakeDamage(int DamageAmount)
{
	DamageAmount -= Stat.Def;
	
	// DamageAmount 보다 방어력이 높을때, 피가 회복이 되는걸 막기 위함.
	// DamageAmount는 최소 0이상이어야 함. 
	DamageAmount = std::max(DamageAmount, 0);
	
	Stat.Hp -= DamageAmount;
	Stat.Hp = std::max(Stat.Hp, 0);
	
	cout << Name << "가 " << DamageAmount << "의 피해를 입었습니다." << endl;
	cout << "   -> 남은 체력: " << Stat.Hp << endl;
}