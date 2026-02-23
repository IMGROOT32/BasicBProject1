#pragma once
#include "Skill.h"
using namespace std;

class UMonsterDrainSkill : public USkill
{
public:
	UMonsterDrainSkill(ACharacter* NewOwner);

	void Play(ACharacter* Target) override;
};

