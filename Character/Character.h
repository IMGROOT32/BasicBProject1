
#pragma once
#include <iostream>
#include <string> 

using namespace std;

class ACharacter
{
public:
    ACharacter(); // 헤더에 선언만 되어 있고 구현부가 없어요.
	// 사용하는 곳이 없어서 에러가 났을거에요.
	
    ACharacter(string NewName, int NewHp, int NewAtk, int NewDef, float NewCritical);
    ~ACharacter();
	
	//일반적으로, 타입 옆에 *(애스터리스크)를 붙여줘야 해요. 변수 이름 옆에 붙이지 않아요. 
    void Attack(ACharacter *Target);
	//오타 수정
    void TakeDamage(float DamageAmout);

	// 간단한 게터는 헤더에 구현해주세요.
    int GetHp();
    bool IsDead();

protected:
      string Name;
      int Hp;
      int Atk;
      int Def;
      float Critical;
};