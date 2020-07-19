// Fill out your copyright notice in the Description page of Project Settings.


#include "LBlock.h"

//���캯��
ALBlock::ALBlock() :ABlock()
{
	//�趨��������
	Type = EBlockType::LBLOCK;

	//��ʼ�������б�
	PosList.Init(TArray<FPoint>(), 3);

	//���ҷ���
	PosList[0].Add(FPoint(1, -1));
	PosList[0].Add(FPoint(1, 1));
	PosList[0].Add(FPoint(-1, 1));
	PosList[0].Add(FPoint(-1, -1));

	//�󷽿�
	PosList[1].Add(FPoint(-1, 0));
	PosList[1].Add(FPoint(0, -1));
	PosList[1].Add(FPoint(1, 0));
	PosList[1].Add(FPoint(0, 1));

	//�ҷ���
	PosList[2].Add(FPoint(1, 0));
	PosList[2].Add(FPoint(0, 1));
	PosList[2].Add(FPoint(-1, 0));
	PosList[2].Add(FPoint(0, -1));

	//�趨���Ŀ�
	UStaticMeshComponent* LB_Center = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LBlock_Center"));
	RootComponent = LB_Center;

	//���ҿ�
	UStaticMeshComponent* LB_UpRight = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LBlock_UpRight"));
	LB_UpRight->SetRelativeLocation(FVector(BlockSize, -BlockSize, 0.0f));
	LB_UpRight->SetupAttachment(RootComponent);

	//���
	UStaticMeshComponent* LB_Left = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LBlock_Left"));
	LB_Left->SetRelativeLocation(FVector(-BlockSize, 0.0f, 0.0f));
	LB_Left->SetupAttachment(RootComponent);

	//�ҿ�
	UStaticMeshComponent* LB_Right = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LBLock_Right"));
	LB_Right->SetRelativeLocation(FVector(BlockSize, 0.0f, 0.0f));
	LB_Right->SetupAttachment(RootComponent);

	//������״
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Basic_Block(TEXT("StaticMesh'/Game/Shapes/Basic_Block.Basic_Block'"));
	if (Basic_Block.Succeeded())
	{
		LB_Center->SetStaticMesh(Basic_Block.Object);
		LB_UpRight->SetStaticMesh(Basic_Block.Object);
		LB_Left->SetStaticMesh(Basic_Block.Object);
		LB_Right->SetStaticMesh(Basic_Block.Object);
	}

	//���ز���
	static ConstructorHelpers::FObjectFinder<UMaterial> LBlock_Material(TEXT("Material'/Game/Materials/LBlock_Material.LBlock_Material'"));
	if (LBlock_Material.Succeeded())
	{
		LB_Center->SetMaterial(0, LBlock_Material.Object);
		LB_UpRight->SetMaterial(0, LBlock_Material.Object);
		LB_Left->SetMaterial(0, LBlock_Material.Object);
		LB_Right->SetMaterial(0, LBlock_Material.Object);
	}
}

//����
void ALBlock::Spin_L()
{
	Super::Spin_L();

}

//����
void ALBlock::Spin_R()
{
	Super::Spin_R();

}

//���������б�
TArray<FPoint> ALBlock::GetPosList()
{
	//��������
	TArray<FPoint> Arr;

	//��������
	Arr.Add(Pos);

	//��������ͨ�����������ת�Ƕȼ������������
	for (int i = 0; i < PosList.Num(); i++)
		Arr.Add(Pos + PosList[i][RotationIndex]);
	return Arr;
}

//�������������б�
TArray<FPoint> ALBlock::GetPosListL()
{
	//��������
	TArray<FPoint> Arr;

	//Ԥ����һ�����ĵ����תҳ
	FPoint NextPos = Pos;
	int NewRotationIndex = (RotationIndex + 3) % 4;

	//��������ͨ�����������ת�Ƕȼ������������
	for (int i = 0; i < PosList.Num(); i++)
		Arr.Add(NextPos + PosList[i][NewRotationIndex]);
	return Arr;
}

//�������������б�
TArray<FPoint> ALBlock::GetPosListR()
{
	//��������
	TArray<FPoint> Arr;

	//Ԥ����һ�����ĵ����תҳ
	FPoint NextPos = Pos;
	int NewRotationIndex = (RotationIndex + 1) % 4;

	//��������
	Arr.Add(NextPos);

	//��������ͨ�����������ת�Ƕȼ������������
	for (int i = 0; i < PosList.Num(); i++)
		Arr.Add(NextPos + PosList[i][NewRotationIndex]);
	return Arr;
}
