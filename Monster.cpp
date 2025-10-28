#include "Monster.h"
#include "World.h"

AMonster::AMonster()
{
	ZOrder = 1001;
	bIsCollision = true;
	bIsOverlap = true;
	Color = { 0,0,255,0 };
}
AMonster::~AMonster()
{
}

void AMonster::Tick()
{
	int KeyCode = rand() % 4;
	FVector2D SaveLocation;
	SaveLocation = Location;

	if (KeyCode == 0)
	{
		Location.Y--;
	}
	else if (KeyCode == 1)
	{
		Location.Y++;
	}
	else if (KeyCode == 2)
	{
		Location.X--;
	}
	else if (KeyCode == 3)
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
