#pragma once

#include <iostream>
#include <Windows.h>
#include <vector>

#include "Vector.h"
#include "Engine.h"

class UComponent;

class AActor
{
public:
	AActor();
	virtual ~AActor();

	virtual void Tick();

	//inline�� �ش� �ڵ� ��ü�� �ҷ��ͼ� ����
	//inline�� �����Ϸ��� �� ���� ����� ������
	//__force�� �������� �ٷ� ó���ϵ��� ������ / ���־�Ʃ�����
	//const�� �ش� �Լ� ������ �� ������ ����
	__forceinline FVector2D GetActorLocation() const
	{
		return Location;
	}

	void SetActorLocation(FVector2D Value)
	{
		//Location = Value; //��������� �����Ҽ��� ���Ҽ��� ����
		Location.X = Value.X;
		Location.Y = Value.Y;
	}


	//virtual void SimulatePhysics();
	bool CheckCollision(const AActor* Other);

	virtual void ActorBeginOverlap();
	virtual void Hit();

	void AddComponent(UComponent* InComponent);

protected:
	FVector2D Location;

	std::vector<class UComponent*> Components;

public:
	bool bIsCollision = false;
	bool bIsOverlap = true;
};