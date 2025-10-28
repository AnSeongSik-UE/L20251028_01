#pragma once

#include <vector>

#include "Engine.h"
#include "Actor.h"

class AMonster : public AActor
{
public:
	AMonster();
	virtual ~AMonster();

	virtual void Tick() override;
};

