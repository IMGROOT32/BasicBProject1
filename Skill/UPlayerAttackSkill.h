#pragma once

#include "Skill.h"

class UPlayerAttackSkill : public USkill
{
public:
    UPlayerAttackSkill(ACharacter* NewOwner);

    void OnPlay(ACharacter* Target) override;
};
