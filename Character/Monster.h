#pragma once
#include <iostream>
#include <string> 
#include "Character.h"

using namespace std;

class Monster : public ACharacter
{
public :
	Monster(const string& NewName, const FUnitStat& NewStat);

	void DropItem() {}

private :

};

