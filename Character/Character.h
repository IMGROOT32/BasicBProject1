
#pragma once
#include <iostream>
#include <string> 

using namespace std;

class ACharacter
{
public:
    ACharacter();
    ACharacter(string NewName, int NewHp, int NewAtk, int NewDef, float NewCritical);
    ~ACharacter();

    void Attack(ACharacter *Target);
    void TakeDamage(float DamageAmout);

    int GetHp();
    bool IsDead();

protected:
      string Name;
      int Hp;
      int Atk;
      int Def;
      float Critical;
};