#pragma once
#include <iostream>
#include <string> 
#include "Character.h"

using namespace std;

class Player : public ACharacter
{
	
public:
	Player(const string& NewName, const FUnitStat& NewStat, int NewLevel, int NewExp);

	void GetItem() {}
	void GetLeveUp() {}

private :
	int level;
	int exp;

};

