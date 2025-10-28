#include "Engine.h"

//FEngine* GEngine = nullptr;

FEngine* FEngine::Instance = nullptr;

FEngine::FEngine() : World(nullptr)
{

}
FEngine::~FEngine()
{

}

void FEngine::Init()
{
	srand((unsigned int)time(nullptr));
	World = new UWorld;

	std::ifstream MapFile("Level01.map");

	if (MapFile.is_open())
	{
		char Buffer[1024] = { 0, };
		int Y = 0;
		while (MapFile.getline(Buffer, 80))
		{
			std::string Line = Buffer;
			for (int X = 0; X < Line.size(); ++X)
			{
				if (Line[X] == '*')
				{
					AActor* NewActor = new AWall();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'P')
				{
					AActor* NewActor = new APlayer();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'M')
				{
					AActor* NewActor = new AMonster();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'G')
				{
					AActor* NewActor = new AGoal();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}

				{
					AActor* NewActor = new AFloor();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape(' ');
					World->SpawnActor(NewActor);
				}
			}
			Y++;
		}
	}
	//1.
	//std::sort(World->GetAllActors().begin(),
	//	World->GetAllActors().end(),
	//	[](const AActor* A, const AActor* B) {
	//		return A->GetZOrder() > B->GetZOrder();
	//	});
	//2. 정렬 로직 구현
	//selection sort
	World->SortActor();

	MapFile.close();

	//UE Gameplay Framework
	World->SpawnActor(new AGameMode());
}
void FEngine::Run()
{
	while (bIsRunning)
	{
		Input();
		Tick();
		Render();
	}
}
void FEngine::Term()
{

}
void FEngine::Input()
{
	KeyCode = _getch();
}
void FEngine::Tick()
{
	GetWorld()->Tick();
}
void FEngine::Render()
{
	//system("cls");
	GetWorld()->Render();
}