// Fill out your copyright notice in the Description page of Project Settings.


#include "ZBlock.h"

//���캯��
AZBlock::AZBlock() :ABlock()
{
	//�趨��������
	Type = EBlockType::ZBLOCK;

	//��ʼ�������б�
	PosList.Init(TArray<FPoint>(), 3);

	//�󷽿�
	PosList[0].Add(FPoint(-1, 0));
	PosList[0].Add(FPoint(0, -1));
	PosList[0].Add(FPoint(1, 0));
	PosList[0].Add(FPoint(0, 1));

	//�·���
	PosList[1].Add(FPoint(0, 1));
	PosList[1].Add(FPoint(-1, 0));
	PosList[1].Add(FPoint(0, -1));
	PosList[1].Add(FPoint(1, 0));

	//���ҷ���
	PosList[2].Add(FPoint(1, 1));
	PosList[2].Add(FPoint(-1, 1));
	PosList[2].Add(FPoint(-1, -1));
	PosList[2].Add(FPoint(1, -1));

	//�趨���Ŀ�
	UStaticMeshComponent* ZB_Center = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ZBlock_Center"));
	RootComponent = ZB_Center;

	//���
	UStaticMeshComponent* ZB_Left = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ZBlock_Left"));
	ZB_Left->SetRelativeLocation(FVector(-BlockSize, 0.0f, 0.0f));
	ZB_Left->SetupAttachment(RootComponent);

	//�¿�
	UStaticMeshComponent* ZB_Down = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ZBlock_Down"));
	ZB_Down->SetRelativeLocation(FVector(0.0f, BlockSize, 0.0f));
	ZB_Down->SetupAttachment(RootComponent);

	//���ҿ�
	UStaticMeshComponent* ZB_DownRight = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ZBLock_DownRight"));
	ZB_DownRight->SetRelativeLocation(FVector(BlockSize, BlockSize, 0.0f));
	ZB_DownRight->SetupAttachment(RootComponent);

	//������״
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Basic_Block(TEXT("StaticMesh'/Game/Shapes/Basic_Block.Basic_Block'"));
	if (Basic_Block.Succeeded())
	{
		ZB_Center->SetStaticMesh(Basic_Block.Object);
		ZB_Left->SetStaticMesh(Basic_Block.Object);
		ZB_Down->SetStaticMesh(Basic_Block.Object);
		ZB_DownRight->SetStaticMesh(Basic_Block.Object);
	}

	//���ز���
	static ConstructorHelpers::FObjectFinder<UMaterial> ZBlock_Material(TEXT("Material'/Game/Materials/ZBlock_Material.ZBlock_Material'"));
	if (ZBlock_Material.Succeeded())
	{
		ZB_Center->SetMaterial(0, ZBlock_Material.Object);
		ZB_Left->SetMaterial(0, ZBlock_Material.Object);
		ZB_Down->SetMaterial(0, ZBlock_Material.Object);
		ZB_DownRight->SetMaterial(0, ZBlock_Material.Object);
	}
}

//����
void AZBlock::Spin_L()
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
void AZBlock::Spin_R()
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
TArray<FPoint> AZBlock::GetPosList()
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
TArray<FPoint> AZBlock::GetPosListL()
{
	//��������
	TArray<FPoint> Arr;

	//Ԥ����һ�����ĵ����תҳ
	FPoint NextPos = Pos;
	int NewRotationIndex = (RotationIndex + 3) % 4;

	switch (NewRotationIndex)
	{
	case 3:
		NextPos.X--;
		NextPos.Y++;
		break;
	case 2:
		NextPos.X++;
		NextPos.Y++;
		break;
	case 1:
		NextPos.X++;
		NextPos.Y--;
		break;
	case 0:
		NextPos.X--;
		NextPos.Y--;
		break;
	default:
		break;
	}

	//��������
	Arr.Add(NextPos);

	//��������ͨ�����������ת�Ƕȼ������������
	for (int i = 0; i < PosList.Num(); i++)
		Arr.Add(NextPos + PosList[i][NewRotationIndex]);
	return Arr;
}

//�������������б�
TArray<FPoint> AZBlock::GetPosListR()
{
	//��������
	TArray<FPoint> Arr;

	//Ԥ����һ�����ĵ����תҳ
	FPoint NextPos = Pos;
	int NewRotationIndex = (RotationIndex + 1) % 4;

	switch (NewRotationIndex)
	{
	case 1:
		NextPos.X++;
		NextPos.Y++;
		break;
	case 2:
		NextPos.X--;
		NextPos.Y++;
		break;
	case 3:
		NextPos.X--;
		NextPos.Y--;
		break;
	case 0:
		NextPos.X++;
		NextPos.Y--;
		break;
	default:
		break;
	}

	//��������
	Arr.Add(NextPos);

	//��������ͨ�����������ת�Ƕȼ������������
	for (int i = 0; i < PosList.Num(); i++)
		Arr.Add(NextPos + PosList[i][NewRotationIndex]);
	return Arr;
}
