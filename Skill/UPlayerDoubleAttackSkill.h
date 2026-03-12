#pragma once
#include "Skill.h"
using namespace std;

class UPlayerDoubleAttackSkill : public USkill
{
public:
	UPlayerDoubleAttackSkill(ACharacter* NewOwner);

	void OnPlay(ACharacter* Target) override;
};

