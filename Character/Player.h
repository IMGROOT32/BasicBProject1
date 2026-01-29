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
	

private :
	int Level;
	int Exp;
};

