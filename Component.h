#pragma once

class AActor;

//�߻� Ŭ����
class IInterface
{
public:
	//���� ���� �Լ�
	//��ӹ޴� Ŭ������ ������ �Ʒ� �Լ��� ������ �ؾ� ��
	virtual void Tick() = 0;
};

class UComponent
{
public:
	UComponent();
	virtual ~UComponent();

	virtual void Tick() = 0;

	AActor* GetOwner() const;
	void SetOwner(AActor* InOwner);

protected:
	AActor* Owner;
};

