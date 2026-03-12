#include "UPlayerStrikeSkill.h"
#include "../Character/Character.h"

UPlayerStrikeSkill::UPlayerStrikeSkill(ACharacter* NewOwner)
    : USkill(NewOwner, "무한의 검", 20)
{
}

void UPlayerStrikeSkill::OnPlay(ACharacter* Target)
{
    FDamageResult result;
    result.Attacker = Owner;
    result.Target = Target;
    result.bCritical = false;

    int FinalDamage = Target->TakeDamage(Owner->GetAtk() * 2);
    result.Damage = FinalDamage;

    result.PrintMessage("하늘에서 무한의 검이 쏟아집니다.");
}
