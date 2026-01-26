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
	//int float bool <- 복사 /참조 비용 동일 = Pointer(* &)랑 크기가 비슷...
	// string, 구조체, 클래스 -> & * 등으로 전달... 
	ACharacter(const string& NewName, const FUnitStat& NewStat);
	// 가상 소멸자 - 따로 공부 필요.
	// ACharacter* pCharacter = new APlayer();
	// delete pCharacter;
	//virtual 소멸자() : 자식 소멸자 호출 -> 부모 소멸자
	virtual ~ACharacter();
	
protected:
	string Name;
	FUnitStat Stat;
	
public:
	void Attack(ACharacter* Target);
	void TakeDamage(int DamageAmount);
	bool IsDead() { return Stat.Hp <= 0; }
};
