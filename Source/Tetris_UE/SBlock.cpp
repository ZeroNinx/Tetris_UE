// Fill out your copyright notice in the Description page of Project Settings.


#include "SBlock.h"

//���캯��
ASBlock::ASBlock() :ABlock()
{
	//�趨��������
	Type = EBlockType::ZBLOCK;

	//��ʼ�������б�
	PosList.Init(TArray<FPoint>(), 3);

	//�ҷ���
	PosList[0].Add(FPoint(1, 0));
	PosList[0].Add(FPoint(0, 1));
	PosList[0].Add(FPoint(-1, 0));
	PosList[0].Add(FPoint(0, -1));

	//�·���
	PosList[1].Add(FPoint(0, 1));
	PosList[1].Add(FPoint(-1, 0));
	PosList[1].Add(FPoint(0, -1));
	PosList[1].Add(FPoint(1, 0));

	//���󷽿�
	PosList[2].Add(FPoint(-1, 1));
	PosList[2].Add(FPoint(-1, -1));
	PosList[2].Add(FPoint(1, -1));
	PosList[2].Add(FPoint(1, 1));

	//�趨���Ŀ�
	UStaticMeshComponent* SB_Center = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SBlock_Center"));
	RootComponent = SB_Center;

	//�ҿ�
	UStaticMeshComponent* SB_Right = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SBlock_Right"));
	SB_Right->SetRelativeLocation(FVector(BlockSize, 0.0f, 0.0f));
	SB_Right->SetupAttachment(RootComponent);

	//�¿�
	UStaticMeshComponent* SB_Down = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SBlock_Down"));
	SB_Down->SetRelativeLocation(FVector(0.0f, BlockSize, 0.0f));
	SB_Down->SetupAttachment(RootComponent);

	//�����
	UStaticMeshComponent* SB_DownLeft = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SBLock_DownLeft"));
	SB_DownLeft->SetRelativeLocation(FVector(-BlockSize, BlockSize, 0.0f));
	SB_DownLeft->SetupAttachment(RootComponent);

	//������״
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Basic_Block(TEXT("StaticMesh'/Game/Shapes/Basic_Block.Basic_Block'"));
	if (Basic_Block.Succeeded())
	{
		SB_Center->SetStaticMesh(Basic_Block.Object);
		SB_Right->SetStaticMesh(Basic_Block.Object);
		SB_Down->SetStaticMesh(Basic_Block.Object);
		SB_DownLeft->SetStaticMesh(Basic_Block.Object);
	}

	//���ز���
	static ConstructorHelpers::FObjectFinder<UMaterial> SBlock_Material(TEXT("Material'/Game/Materials/SBlock_Material.SBlock_Material'"));
	if (SBlock_Material.Succeeded())
	{
		SB_Center->SetMaterial(0, SBlock_Material.Object);
		SB_Right->SetMaterial(0, SBlock_Material.Object);
		SB_Down->SetMaterial(0, SBlock_Material.Object);
		SB_DownLeft->SetMaterial(0, SBlock_Material.Object);
	}
}

//����
void ASBlock::Spin_L()
{
	Super::Spin_L();

	//λ��У׼
	switch (RotationIndex)
	{
	case 3:
		SetActorRelativeLocation(GetActorLocation() + FVector(-BlockSize, BlockSize, 0.0f));
		Pos.X--;
		Pos.Y++;
		break;
	case 2:
		SetActorRelativeLocation(GetActorLocation() + FVector(BlockSize, BlockSize, 0.0f));
		Pos.X++;
		Pos.Y++;
		break;
	case 1:
		SetActorRelativeLocation(GetActorLocation() + FVector(BlockSize, -BlockSize, 0.0f));
		Pos.X++;
		Pos.Y--;
		break;
	case 0:
		SetActorRelativeLocation(GetActorLocation() + FVector(-BlockSize, -BlockSize, 0.0f));
		Pos.X--;
		Pos.Y--;
		break;
	default:
		break;
	}
}

//����
void ASBlock::Spin_R()
{
	Super::Spin_R();
	//λ��У׼
	switch (RotationIndex)
	{
	case 1:
		SetActorRelativeLocation(GetActorLocation() + FVector(BlockSize, BlockSize, 0.0f));
		Pos.X++;
		Pos.Y++;
		break;
	case 2:
		SetActorRelativeLocation(GetActorLocation() + FVector(-BlockSize, BlockSize, 0.0f));
		Pos.X--;
		Pos.Y++;
		break;
	case 3:
		SetActorRelativeLocation(GetActorLocation() + FVector(-BlockSize, -BlockSize, 0.0f));
		Pos.X--;
		Pos.Y--;
		break;
	case 0:
		SetActorRelativeLocation(GetActorLocation() + FVector(BlockSize, -BlockSize, 0.0f));
		Pos.X++;
		Pos.Y--;
		break;
	default:
		break;
	}
}

//���������б�
TArray<FPoint> ASBlock::GetPosList()
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