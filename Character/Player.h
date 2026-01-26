#pragma once
#include <iostream>
#include <string> 
#include "Character.h"

using namespace std;

class APlayer : public ACharacter
{
	
public:
	APlayer(const string& NewName, const FUnitStat& NewStat);

	void UseItem() {}
	void LevelUp() {}
	
	//Get 접두사 - 게터
	//Set 접두사 - 세터
	
	//플레이어는 레벨과 EXP를 받아올 필요가 없음.
	// Level 1부터, Exp = 0

private :
	int Level;
	int Exp;
};

