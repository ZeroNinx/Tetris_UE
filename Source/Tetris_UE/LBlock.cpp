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
	static ConstructorHelpers::FObjectFinder<UMaterial> M_LBlock(TEXT("Material'/Game/Materials/M_LBlock.M_LBlock'"));
	if (M_LBlock.Succeeded())
	{
		LB_Center->SetMaterial(0, M_LBlock.Object);
		LB_UpRight->SetMaterial(0, M_LBlock.Object);
		LB_Left->SetMaterial(0, M_LBlock.Object);
		LB_Right->SetMaterial(0, M_LBlock.Object);
	}

	//��¼��������
	MeshList.Add(LB_Left);
	MeshList.Add(LB_Center);
	MeshList.Add(LB_Right);
	MeshList.Add(LB_UpRight);
}

//����
void ALBlock::Spin_L()
{
	Super::Spin_L();

	//λ��У׼
	switch (RotationIndex)
	{
	case 0:
		SetActorRelativeLocation(GetActorLocation() + FVector(0.0f, BlockSize, 0.0f));
		Pos.Y++;
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		SetActorRelativeLocation(GetActorLocation() + FVector(0.0f, -BlockSize, 0.0f));
		Pos.Y--;
		break;
	default:
		break;
	}
}

//����
void ALBlock::Spin_R()
{
	Super::Spin_R();

	//λ��У׼
	switch (RotationIndex)
	{
	case 1:
		SetActorRelativeLocation(GetActorLocation() + FVector(0.0f, -BlockSize, 0.0f));
		Pos.Y--;
		break;
	case 2:
		break;
	case 3:
		break;
	case 0:
		SetActorRelativeLocation(GetActorLocation() + FVector(0.0f, BlockSize, 0.0f));
		Pos.Y++;
		break;
	default:
		break;
	}
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

	//λ��У׼
	switch (NewRotationIndex)
	{
	case 0:
		NextPos.Y++;
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		NextPos.Y--;
		break;
	default:
		break;
	}

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

	//λ��У׼
	switch (NewRotationIndex)
	{
	case 1:
		NextPos.Y--;
		break;
	case 2:
		break;
	case 3:
		break;
	case 0:
		NextPos.Y++;
		break;
	default:
		break;
	}

	//��������ͨ�����������ת�Ƕȼ������������
	for (int i = 0; i < PosList.Num(); i++)
		Arr.Add(NextPos + PosList[i][NewRotationIndex]);
	return Arr;
}
