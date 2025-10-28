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

	template<typename T>
	T* GetComponent()
	{
		for (auto Component : Components)
		{
			if (dynamic_cast<T*>(Component))
			{
				return dynamic_cast<T*>(Component);
			}
		}
		return nullptr;
	}

	void SetActorLocation(FVector2D Value)
	{
		//Location = Value; //��������� �����Ҽ��� ���Ҽ��� ����
		Location.X = Value.X;
		Location.Y = Value.Y;
	}

	virtual void ActorBeginOverlap();
	virtual void Hit();

	void SetupAttachment(UComponent* InComponent);

	std::vector<class UComponent*> Components;

protected:
	FVector2D Location;
};