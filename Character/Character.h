
#pragma once
#include <iostream>
#include <string> 

using namespace std;

struct FUnitStat
{
    int Hp;
    int Atk;
    int Def;
    int Critical;
};

class ACharacter
{
public:
    ACharacter(); // 헤더에 선언만 되어 있고 구현부가 없어요.
	// 사용하는 곳이 없어서 에러가 났을거에요.
	
    ACharacter(string NewName,const FUnitStat& NewStat);
    ~ACharacter();
	
    void Attack(ACharacter* Target);
	
    void TakeDamage(int DamageAmount);

    int GetHp()
    {
        return Stat.Hp;
    }
    int GetAtk()
    {
        return Stat.Atk;
    }
    int GetDef()
    {
        return Stat.Def;
    }
    int GetCritical()
    {
        return Stat.Critical;
    }
    bool IsDead()
    {
        return Stat.Hp <= 0;
    }

protected:
      string Name;
      FUnitStat Stat;
};