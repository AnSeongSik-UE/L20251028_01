#pragma once

#include "Actor.h"
#include "Engine.h"

class UCollisionComponent;

class APlayer : public AActor
{
public:
	APlayer();
	virtual ~APlayer();

	virtual void Tick() override;

	//overload
	//�Լ����� ���� ���ڰ� �ٸ�
	//name mangling 
	void Jump()
	{

	}
	void Jump(int a)
	{

	}
	void Jump(float b)
	{

	}
	//

	UCollisionComponent* Collision;
};