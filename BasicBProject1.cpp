#include <iostream>
#include "Character/Character.h"
#include "Character/Player.h"
#include "Character/Monster.h"
#include <Windows.h>

using namespace std;

void WaitForPlayerInput()
{
	system("pause");
	cout << endl;
}

bool BattleTurn(ACharacter* Attacker, ACharacter* Defender)
{
		WaitForPlayerInput();


		Attacker->PlayTurn(Defender);

		Attacker->ShowStat();
		Defender->ShowStat();
		
		if (Defender->IsDead())
		{
			cout << "몬스터가 쓰러졌습니다! 승리!" << endl;
			return true;
		}
		
		if (Attacker->IsDead())
		{
			cout << "플레이어가 쓰러졌습니다... 패배..." << endl;
			return false;
		}
}

int main()
{
	ACharacter* Player = new APlayer("나의 용사", FUnitStat(200, 50, 30, 5, 10));
	ACharacter* Monster = new AMonster("무서운 오크", FUnitStat(100, 30, 20, 3, 10));

	cout << "===  데스매치 시작!  ===" << endl;

	while (true)
	{
		if (BattleTurn(Player, Monster) == true)
		{
			break;
		}

		if (BattleTurn(Monster, Player) == true)
		{
			break;
		}
	}

	WaitForPlayerInput();

	delete Player;
	delete Monster;

	return 0;
}