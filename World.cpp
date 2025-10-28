#include "World.h"
#include "SceneComponent.h"
#include "PaperFlipBookComponent.h"
#include <algorithm>

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
//���丮 ����(������ �� �Լ��� ��)
AActor* UWorld::SpawnActor(AActor* NewActor)
{
	Actors.push_back(NewActor);

	return NewActor;
}
void UWorld::SortActor()
{
	//������ , �����Լ�(�͸��Լ�)
	std::sort(Actors.begin(), Actors.end(), [&](const AActor* A, const AActor* B) {
		UPaperFlipBookComponent* Scene1 = nullptr;
		for (auto Component : A->Components)
		{
			Scene1 = dynamic_cast<UPaperFlipBookComponent*>(Component);
			if (Scene1)
			{
				break;
			}
		}

		UPaperFlipBookComponent* Scene2 = nullptr;
		for (auto Component : B->Components)
		{
			Scene2 = dynamic_cast<UPaperFlipBookComponent*>(Component);
			if (Scene2)
			{
				break;
			}
		}

		if (!Scene1 || !Scene2)
		{
			return false;
		}

		return (Scene1->GetZOrder() < Scene2->GetZOrder());
		});

	return;
	//��������
	for (int j = 0; j < Actors.size(); ++j)
	{
		//���� ����
		UPaperFlipBookComponent* Scene1 = nullptr;
		for (auto Component : Actors[j]->Components)
		{
			Scene1 = dynamic_cast<UPaperFlipBookComponent*>(Component);
			if (Scene1)
			{
				break;
			}
		}
		if (!Scene1)
		{
			continue;
		}
		for (int i = 0; i < Actors.size(); ++i)
		{
			//������ ���Ϳ� PaperFlipBookComponent �ִ��� Ȯ��
			UPaperFlipBookComponent* Scene2 = nullptr;
			for (auto Component : Actors[i]->Components)
			{
				Scene2 = dynamic_cast<UPaperFlipBookComponent*>(Component);
				if (Scene2)
				{
					break;
				}
			}

			if (!Scene2)
			{
				continue;
			}
			if (Scene1->GetZOrder() < Scene2->GetZOrder())
			{
				AActor* Temp = Actors[j];
				Actors[j] = Actors[i];
				Actors[i] = Temp;
			}
		}
	}
}
void UWorld::Tick()
{
	for (auto Actor : Actors)
	{
		//������ - runtime�ÿ� ������. ���� ���� �Ұ�
		Actor->Tick();
	}
}
void UWorld::Render()
{
	for (auto Actor : Actors)
	{
		for (auto Component : Actor->Components)
		{
			USceneComponent* Scene = dynamic_cast<USceneComponent*>(Component);
			if (Scene)
			{
				Scene->Render();
			}
		}
		//Actor->Render();
	}
}