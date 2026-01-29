#pragma once
#include <iostream>
#include <string> 
#include "Character.h"

using namespace std;

class AMonster : public ACharacter
{
public :
	AMonster(const string& NewName, const FUnitStat& NewStat);

	void DropItem() {}
	FDamageResult Attack(ACharacter* Target) override;
private :

};

