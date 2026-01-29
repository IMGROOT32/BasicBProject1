
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
int GetRandomInt()
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 100);
	return dis(gen);
}

FDamageResult ACharacter::Attack(ACharacter* Target)
{
	int Damage = Stat.Atk;
	bool bCritical = GetRandomInt() < Stat.Critical;
	if (bCritical)
	{
		Damage = static_cast<int>(Damage * 1.5f);
	}

	int FinalDamage = Target->TakeDamage(Damage);
	FDamageResult result;
	result.Damage = FinalDamage;
	result.bCritical = bCritical;
	return result;
}

int ACharacter::TakeDamage(int DamageAmount)
{
	DamageAmount -= Stat.Def;
	
	// DamageAmount 보다 방어력이 높을때, 피가 회복이 되는걸 막기 위함.
	// DamageAmount는 최소 0이상이어야 함. 
	DamageAmount = std::max(DamageAmount, 0);
	
	Stat.Hp -= DamageAmount;
	Stat.Hp = std::max(Stat.Hp, 0);

	return DamageAmount;
}