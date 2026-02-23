#pragma once
#include "Skill.h"

using namespace std;

class UMonsterAttackSkill : public USkill
{
public:
	UMonsterAttackSkill(ACharacter* NewOwner);

	void Play(ACharacter* Target) override;
};

