#include "Actor.h"
#include "Component.h"

AActor::AActor() : Location(0, 0)
{
}
AActor::~AActor()
{
	for (auto Component : Components)
	{
		delete Component;
	}
}

void AActor::Tick()
{
}
void AActor::ActorBeginOverlap()
{
}
void AActor::Hit()
{
}
void AActor::AddComponent(UComponent* InComponent)
{
	Components.push_back(InComponent);
}