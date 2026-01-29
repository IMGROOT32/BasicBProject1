#pragma once

#include <iostream>
#include <string>

using namespace std;

struct FUnitStat
{
	int MaxHp;
	int MaxMp;

	int Hp = 0;
	int Mp = 0;

	int Atk;
	int Def;
	int Critical;

	FUnitStat()
	{

	}

	FUnitStat(int MaxHp, int MaxMp, int Atk, int Def, int Critical)
	{
		this->MaxHp = MaxHp;
		this->MaxMp = MaxMp;

		this->Atk = Atk;
		this->Def = Def;
		this->Critical = Critical;
	}
};

struct FDamageResult
{
	int Damage;
	bool bCritical ;
};

class ACharacter
{
public:
	ACharacter(const string& NewName, const FUnitStat& NewStat);
	virtual ~ACharacter();
	
	virtual FDamageResult Attack(ACharacter* Target);
	int TakeDamage(int DamageAmount);
	bool IsDead() { return Stat.Hp <= 0; }
	string GetName() { return Name; }
	int GetHp() { return Stat.Hp; }
protected:
	string Name;
	FUnitStat Stat;
	

};
