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

class ACharacter;

struct FDamageResult
{
	int Damage;
	bool bCritical;
	
	ACharacter* Attacker;
	ACharacter* Target;

	void PrintMessage(const string& AttackMessage);
};

class ACharacter
{
public:
	ACharacter(const string& NewName, const FUnitStat& NewStat);
	virtual ~ACharacter();
	
	void PrintName();

	int GetMaxHp() const { return Stat.MaxHp; }
	string GetName() { return Name; }
	int GetHp() { return Stat.Hp; }
	int GetAtk() { return Stat.Atk; }
	int GetCritical() { return Stat.Critical; }

	virtual FDamageResult Attack(ACharacter* Target);
	virtual void UseSkill(ACharacter* Target) = 0;
	int TakeDamage(int DamageAmount);
	bool IsDead() { return Stat.Hp <= 0; }
	void Heal(int amount);
	void PlayTurn(ACharacter* Target);
	void ShowStat();

	int GetRandomInt();
protected:
	string Name;
	FUnitStat Stat;
	

};
