#pragma once
#include "Skill.h"
using namespace std;

class UPlayerDoubleAttackSkill : public USkill
{
public:
	UPlayerDoubleAttackSkill(ACharacter* NewOwner);

	void Play(ACharacter* Target) override;
};

