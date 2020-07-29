// Fill out your copyright notice in the Description page of Project Settings.


#include "IBlock.h"

//Ĭ�Ϲ��캯��
AIBlock::AIBlock():ABlock()
{
	//�趨��������
	Type = EBlockType::IBLOCK;

	//��ʼ�������б�
	PosList.Init(TArray<FPoint>(), 3);

	//�󷽿�
	PosList[0].Add(FPoint(-1, 0));
	PosList[0].Add(FPoint(0, -1));
	PosList[0].Add(FPoint(1, 0));
	PosList[0].Add(FPoint(0, 1));
	

	//�ҷ���
	PosList[1].Add(FPoint(1, 0));
	PosList[1].Add(FPoint(0, 1));
	PosList[1].Add(FPoint(-1, 0));
	PosList[1].Add(FPoint(0, -1));


	//���·���
	PosList[2].Add(FPoint(2, 0));
	PosList[2].Add(FPoint(0, 2));
	PosList[2].Add(FPoint(-2, 0));
	PosList[2].Add(FPoint(0, -2));
	

	//�趨���Ŀ�
	UStaticMeshComponent* IB_Center = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("IBlock_Center"));
	RootComponent = IB_Center;

	//���
	UStaticMeshComponent* IB_Left = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("IBlock_Left"));
	IB_Left->SetRelativeLocation(FVector(-BlockSize,0.0f,  0.0f));
	IB_Left->SetupAttachment(RootComponent);

	//�ҿ�
	UStaticMeshComponent* IB_Right = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("IBlock_Right"));
	IB_Right->SetRelativeLocation(FVector(BlockSize,0.0f,  0.0f));
	IB_Right->SetupAttachment(RootComponent);

	//���ҿ�
	UStaticMeshComponent* IB_RightRight = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("IBlock_RightRight"));
	IB_RightRight->SetRelativeLocation(FVector(BlockSize*2,0.0f,  0.0f));
	IB_RightRight->SetupAttachment(RootComponent);

	//������״
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Basic_Block(TEXT("StaticMesh'/Game/Shapes/Basic_Block.Basic_Block'"));
	if (Basic_Block.Succeeded())
	{
		IB_Left->SetStaticMesh(Basic_Block.Object);
		IB_Center->SetStaticMesh(Basic_Block.Object);
		IB_Right->SetStaticMesh(Basic_Block.Object);
		IB_RightRight->SetStaticMesh(Basic_Block.Object);
	}

	//���ز���
	static ConstructorHelpers::FObjectFinder<UMaterial> IBlock_Material(TEXT("Material'/Game/Materials/M_IBlock.M_IBlock'"));
	if (IBlock_Material.Succeeded())
	{
		IB_Left->SetMaterial(0,IBlock_Material.Object);
		IB_Center->SetMaterial(0,IBlock_Material.Object);
		IB_Right->SetMaterial(0, IBlock_Material.Object);
		IB_RightRight->SetMaterial(0, IBlock_Material.Object);
	}

	//��¼��������
	MeshList.Add(IB_Left);
	MeshList.Add(IB_Center);
	MeshList.Add(IB_Right);
	MeshList.Add(IB_RightRight);
}

//����
void AIBlock::Spin_L()
{
	Super::Spin_L();

	//λ��У׼
	switch (RotationIndex)
	{
	case 0:
		SetActorRelativeLocation(GetActorLocation() + FVector(0.0f, BlockSize, 0.0f));
		Pos.Y++;
		break;
	case 3:
		SetActorRelativeLocation(GetActorLocation() + FVector(BlockSize, 0.0f, 0.0f));
		Pos.X++;
		break;
	case 2:
		SetActorRelativeLocation(GetActorLocation() + FVector(0.0f, -BlockSize, 0.0f));
		Pos.Y--;
		break;
	case 1:
		SetActorRelativeLocation(GetActorLocation() + FVector(-BlockSize, 0.0f, 0.0f));
		Pos.X--;
		break;
	default:
		break;
	}
}

//����
void AIBlock::Spin_R()
{
	Super::Spin_R();
	
	//λ��У׼
	switch (RotationIndex)
	{
	case 3:
		SetActorRelativeLocation(GetActorLocation() + FVector(0.0f, BlockSize, 0.0f));
		Pos.Y++;
		break;
	case 0:
		SetActorRelativeLocation(GetActorLocation() + FVector(-BlockSize, 0.0f, 0.0f));
		Pos.X--;
		break;
	case 1:
		SetActorRelativeLocation(GetActorLocation() + FVector(0.0f, -BlockSize, 0.0f));
		Pos.Y--;
		break;
	case 2:
		SetActorRelativeLocation(GetActorLocation() + FVector(BlockSize, 0.0f, 0.0f));
		Pos.X++;
		break;
	default:
		break;
	}
}

//���������б�
TArray<FPoint> AIBlock::GetPosList()
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
TArray<FPoint> AIBlock::GetPosListL()
{
	//��������
	TArray<FPoint> Arr;

	//Ԥ����һ�����ĵ����תҳ
	FPoint NextPos = Pos;
	int NewRotationIndex = (RotationIndex + 3) % 4;

	switch (NewRotationIndex)
	{
	case 0:
		NextPos.Y++;
		break;
	case 3:
		NextPos.X++;
		break;
	case 2:
		NextPos.Y--;
		break;
	case 1:
		NextPos.X--;
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
TArray<FPoint> AIBlock::GetPosListR()
{
	//��������
	TArray<FPoint> Arr;

	//Ԥ����һ�����ĵ����תҳ
	FPoint NextPos = Pos;
	int NewRotationIndex = (RotationIndex + 1) % 4;

	switch (NewRotationIndex)
	{
	case 3:
		NextPos.Y++;
		break;
	case 0:
		NextPos.X--;
		break;
	case 1:
		NextPos.Y--;
		break;
	case 2:
		NextPos.X++;
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