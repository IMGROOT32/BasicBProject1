#include <iostream>
#include "Character/Character.h"
#include <Windows.h>

using namespace std;

int main()
{

	FUnitStat PlayerStat;
	PlayerStat.Hp = 200;
	PlayerStat.Atk = 30;
	PlayerStat.Def = 10;
	PlayerStat.Critical = 0.1f;

	FUnitStat MonsterStat;
	MonsterStat.Hp = 100;
	MonsterStat.Atk = 20;
	MonsterStat.Def = 15;
	MonsterStat.Critical = 0.1f;

	// ACharacter 생성 대신 APlayer, AMonster로 생성
	// 대산 포인터는 ACharacter*로 그대로 유지한다.
	ACharacter* Player = new ACharacter("나의 용사", PlayerStat);
	ACharacter* Monster = new ACharacter("무서운 오크", MonsterStat);

	cout << "===  데스매치 시작!  ===" << endl;
	Sleep(1000);

	while (!Player->IsDead() && !Monster->IsDead())
	{
		Player->Attack(Monster);
		if (Monster->IsDead())
		{
			cout << "몬스터가 쓰러졌습니다! 승리!" << endl;
			break;
		}

		Sleep(500);
		Monster->Attack(Player);
		if (Player->IsDead())
		{
			cout << "플레이어가 쓰러졌습니다... 패배..." << endl;
			break;
		}

		Sleep(1000);
	}

	delete Player;
	delete Monster;
	return 0;
}