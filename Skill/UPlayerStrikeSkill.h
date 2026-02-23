#pragma once
#include "Skill.h"
using namespace std;

class UPlayerStrikeSkill : public USkill
{
public:
	UPlayerStrikeSkill(ACharacter* NewOwner);

	void Play(ACharacter* Target) override;
};

