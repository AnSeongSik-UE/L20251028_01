#pragma once
#include "SceneComponent.h"
#include "SDL3/SDL.h"
class UPaperFlipComponent : public USceneComponent
{
public:
	UPaperFlipComponent();
	virtual ~UPaperFlipComponent();

	virtual void Tick() override;

	virtual void Render() override;

	__forceinline char GetShape()
	{
		return Shape;
	}
	void SetShape(char Value)
	{
		Shape = Value;
	}
	__forceinline int GetZOrder() const
	{
		return ZOrder;
	}

protected:
	char Shape;
	int ZOrder;

public:
	SDL_Color Color = { 255, 255, 255, 255 };
};

