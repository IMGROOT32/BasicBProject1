
#include "Character.h"
#include <cstdlib>
#include <ctime>
#include <random>


ACharacter::ACharacter(string NewName, int NewHp, int NewAtk, int NewDef, float NewCritical)
{
	Name = NewName;
	Hp = NewHp;
	Atk = NewAtk;
	Def = NewDef;
	Critical = NewCritical;

	cout << "[생성] " << Name << "가 전장에 나타났습니다! (HP: " << Hp << ")" << endl;
}
ACharacter::~ACharacter()
{
	cout << "ACharacter 이 소멸되었습니다." << endl;
}

void ACharacter::Attack(ACharacter *target)
{
	if (target == nullptr)
	{
		return;
	}
	
	//[총평] 코드 작성 후, 전반적으로 꼼꼼하게 코드를 검토하지 못한 느낌이 듭니다.  
	
	float DamageAmount = Atk;

	int r = rand() % 100;
	if (r < 10)
	{
		DamageAmount *= 1.5f;
		//크리티컬인 경우, TakeDamage()가 호출되지 않아요. 
	}
	else
	{
		//float 값을, TakeDamage에 넣기 전에 int로 바꿔주세요.
		target->TakeDamage(DamageAmount);
	}
	
	cout << Name << "가 공격합니다! (공격력 : " << Atk << ")" << endl;
}

//HP는 int니까 int damage를 받는게 좋아요.
void ACharacter::TakeDamage(float DamageAmout)
{
	// HP에 Def를 더하는게 아니에요.
	// 받을 Damage에서 Def를 제거하는거에요.
	// 결과적으로 동일한 작동일 지라도, 이런 경우 코드 리딩에 문제가 생깁니다.
	
	Hp += Def;
	
	// 탭 정리
		if (Hp - DamageAmout <= 0)
		{
			//Hp == 0;
			Hp = 0;
		}
		else
		{
			Hp -= DamageAmout;
		}


	cout << Name << "가 " << DamageAmout << "의 피해를 입었습니다." << endl;
	cout << "   -> 남은 체력: " << Hp << endl;
}

int ACharacter::GetHp()
{
	return Hp;
}

bool ACharacter::IsDead()
{
	return Hp <= 0;
}
