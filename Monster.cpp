#include "Monster.h"
#include "World.h"
#include "SDL3/SDL.h"
#include "PaperFlipBookComponent.h"
#include "CollisionComponent.h"

AMonster::AMonster()
{
	//ZOrder = 1001;
	//bIsCollision = true;
	//bIsOverlap = true;
	//Color = { 0,0,255,0 };

	UPaperFlipBookComponent* Paper = new UPaperFlipBookComponent();
	Paper->SetShape('M');
	Paper->SetOwner(this);
	Paper->ZOrder = 1001;
	Paper->Color = SDL_Color{ 0, 0, 255, 0 };
	AddComponent(Paper);

	Collision = new UCollisionComponent();
	Collision->SetOwner(this);
	Collision->bIsCollision = true;
	Collision->bIsOverlap = true;
	AddComponent(Collision);
}
AMonster::~AMonster()
{
}

void AMonster::Tick()
{
	TotalTime += (float)GEngine->GetWorldDeltaSeconds();
	if (TotalTime <= ExecuteTime)
	{
		return;
	}
	TotalTime = 0.f;

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
		for (auto OtherComponent : OtherActor->Components)
		{
			UCollisionComponent* OtherCollision = dynamic_cast<UCollisionComponent*>(OtherComponent);
			if (OtherCollision)
			{
				if (Collision->CheckCollision(OtherCollision))
				{
					bFlag = true;
					break;
				}
			}
		}
	}

	if (bFlag)
	{
		Location = SaveLocation;
	}
}
