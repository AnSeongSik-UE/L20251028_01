#include <Windows.h>

#include "PaperFlipComponent.h"
#include "Vector.h"
#include "Actor.h"

UPaperFlipComponent::UPaperFlipComponent()
{
}
UPaperFlipComponent::~UPaperFlipComponent()
{
}

void UPaperFlipComponent::Tick()
{
}
void UPaperFlipComponent::Render()
{
	COORD Position;
	Position.X = GetOwner()->GetActorLocation().X;
	Position.Y = GetOwner()->GetActorLocation().Y;

	SetConsoleCursorPosition((HANDLE)GetStdHandle(STD_OUTPUT_HANDLE), Position);
	std::cout << Shape;


	SDL_SetRenderDrawColor(GEngine->MyRenderer, Color.r, Color.g, Color.b, Color.a);
	float SizeX = 30.0f;
	float SizeY = 30.0f;
	SDL_FRect DrawRect =
	{
		GetOwner()->GetActorLocation().X * SizeX,
		GetOwner()->GetActorLocation().Y * SizeY,
		SizeX,
		SizeY
	};
	SDL_RenderFillRect(GEngine->MyRenderer, &DrawRect);
	//SDL_RenderDrawPoint(GEngine->MyRenderer, (float)Location.X, (float)Location.Y);
}