#include "World.h"

UWorld::UWorld()
{
}
UWorld::~UWorld()
{
}

void UWorld::GetAllActors(std::vector<AActor*>& OutActors) const
{
	OutActors = Actors;
}
//팩토리 패턴(생성도 이 함수가 함)
AActor* UWorld::SpawnActor(AActor* NewActor)
{
	Actors.push_back(NewActor);

	return NewActor;
}
void UWorld::SortActor()
{
	//for (int j = 0; j < Actors.size(); ++j)
	//{
	//	for (int i = 0; i < Actors.size(); ++i)
	//	{
	//		if (Actors[j]->GetZOrder() < Actors[i]->GetZOrder())
	//		{
	//			AActor* Temp = Actors[j];
	//			Actors[j] = Actors[i];
	//			Actors[i] = Temp;
	//		}
	//	}
	//}
}
void UWorld::Tick()
{
	for (auto Actor : Actors)
	{
		//다형성 - runtime시에 결정됨. 오류 검출 불가
		Actor->Tick();
	}
}
void UWorld::Render()
{
	for (auto Actor : Actors)
	{
		//Actor->Render();
	}
}