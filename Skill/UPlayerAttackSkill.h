#pragma once

#include "Skill.h"
using namespace std;


class UPlayerAttackSkill : public USkill
{
public:
	UPlayerAttackSkill(ACharacter* NewOwner);

	void Play(ACharacter* Target) override;
};

