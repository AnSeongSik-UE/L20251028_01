#include "Actor.h"

AActor::AActor() : ZOrder(0), Shape(' '), Location(0, 0)
{
}
AActor::~AActor()
{
}

void AActor::Tick()
{
}
void AActor::Render()
{
	COORD Position;
	Position.X = Location.X;
	Position.Y = Location.Y;

	SetConsoleCursorPosition((HANDLE)GetStdHandle(STD_OUTPUT_HANDLE), Position);
	std::cout << Shape;
}
bool AActor::CheckCollision(const AActor* OtherActor)
{
	if (OtherActor->bIsOverlap)
	{
		return false;
	}
	if (this != OtherActor && bIsCollision && OtherActor->bIsCollision &&
		this->Location == OtherActor->Location) //영역 계산
	{
		return true;
	}
	return false;
}
void AActor::ActorBeginOverlap()
{
}
void AActor::Hit()
{
}