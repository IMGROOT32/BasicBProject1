#include "Player.h"

APlayer::APlayer(const string& NewName, const FUnitStat& NewStat) 
	: ACharacter(NewName, NewStat)
{
	Level = 1;
	Exp = 0;
}

void APlayer::Attack(ACharacter* Target)
{
	cout << "검을 빼들고 " << Name << "이(가) 급소를 찌릅니다." << endl;

	ACharacter::Attack(Target);
}