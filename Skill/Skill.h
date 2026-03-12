#pragma once

#include <string>

class ACharacter;

class USkill
{
public:
	USkill(ACharacter* NewOwner, const std::string& NewName, int NewMpCost);
	virtual ~USkill() = default;

protected:
	ACharacter* Owner = nullptr;
	std::string Name;
	int MpCost;
	virtual void OnPlay(ACharacter* Target) = 0;

public:
	const std::string& GetName() const { return Name; }
	int GetMpCost() const { return MpCost; }
	bool CanUse();
	void Play(ACharacter* Target);
};
