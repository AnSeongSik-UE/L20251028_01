#include <iostream>
#include "Player.h"

APlayer::APlayer()
{
	ZOrder = 1003;
	bIsCollision = true;
	bIsOverlap = true;
}
APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	int KeyCode = GEngine->GetKeyCode();
	FVector2D SaveLocation;
	SaveLocation = Location;

	if (KeyCode == 'w')
	{
		Location.Y--;
	}
	else if(KeyCode == 's')
	{
		Location.Y++;
	}
	else if (KeyCode == 'a')
	{
		Location.X--;
	}
	else if (KeyCode == 'd')
	{
		Location.X++;
	}

	std::vector<AActor*> AllActors;
	GEngine->GetWorld()->GetAllActors(AllActors);

	bool bFlag = false;

	for (auto OtherActor : AllActors)
	{
		if (CheckCollision(OtherActor))
		{
			bFlag = true;
			break;
		}
	}

	if (bFlag)
	{
		Location = SaveLocation;
	}
}