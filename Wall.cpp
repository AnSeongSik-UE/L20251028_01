#include "Wall.h"
#include "SDL3/SDL.h"
#include "PaperFlipBookComponent.h"
#include "CollisionComponent.h"

AWall::AWall()
{
	//ZOrder = 1000;
	//bIsCollision = true;
	//bIsOverlap = false;
	//Color = { 128,128,128,0 };

	UPaperFlipBookComponent* Paper = new UPaperFlipBookComponent();
	Paper->SetShape('*');
	Paper->SetOwner(this);
	Paper->ZOrder = 1000;
	Paper->Color = SDL_Color{ 128, 128, 128, 0 };
	AddComponent(Paper);

	UCollisionComponent* Collision = new UCollisionComponent();
	Collision->SetOwner(this);
	Collision->bIsCollision = true;
	Collision->bIsOverlap = false;
	AddComponent(Collision);
}
AWall::~AWall()
{
}