#pragma once

#include <iostream>

using namespace std;

class ACharacter;

class USkill
{
public:
	USkill(ACharacter* Owner);

	virtual void Play(ACharacter* Target) = 0;

protected:
	ACharacter* Owner = nullptr;
};

