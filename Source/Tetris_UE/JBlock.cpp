// Fill out your copyright notice in the Description page of Project Settings.


#include "JBlock.h"

//���캯��
AJBlock::AJBlock() :ABlock()
{
	//�趨��������
	Type = EBlockType::JBLOCK;

	//��ʼ�������б�
	PosList.Init(TArray<FPoint>(), 3);

	//���󷽿�
	PosList[0].Add(FPoint(-1, -1));
	PosList[0].Add(FPoint(1, -1));
	PosList[0].Add(FPoint(1, 1));
	PosList[0].Add(FPoint(-1, 1));

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
	UStaticMeshComponent* JB_Center = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("JBlock_Center"));
	RootComponent = JB_Center;

	//�����
	UStaticMeshComponent* JB_UpLeft = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("JBlock_UpLeft"));
	JB_UpLeft->SetRelativeLocation(FVector(-BlockSize, -BlockSize, 0.0f));
	JB_UpLeft->SetupAttachment(RootComponent);

	//���
	UStaticMeshComponent* JB_Left = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("JBlock_Left"));
	JB_Left->SetRelativeLocation(FVector(-BlockSize, 0.0f, 0.0f));
	JB_Left->SetupAttachment(RootComponent);

	//�ҿ�
	UStaticMeshComponent* JB_Right = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("JBLock_Right"));
	JB_Right->SetRelativeLocation(FVector(BlockSize, 0.0f, 0.0f));
	JB_Right->SetupAttachment(RootComponent);

	//������״
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Basic_Block(TEXT("StaticMesh'/Game/Shapes/Basic_Block.Basic_Block'"));
	if (Basic_Block.Succeeded())
	{
		JB_Center->SetStaticMesh(Basic_Block.Object);
		JB_UpLeft->SetStaticMesh(Basic_Block.Object);
		JB_Left->SetStaticMesh(Basic_Block.Object);
		JB_Right->SetStaticMesh(Basic_Block.Object);
	}

	//���ز���
	static ConstructorHelpers::FObjectFinder<UMaterial> M_JBlock(TEXT("Material'/Game/Materials/M_JBlock.M_JBlock'"));
	if (M_JBlock.Succeeded())
	{
		JB_Center->SetMaterial(0, M_JBlock.Object);
		JB_UpLeft->SetMaterial(0, M_JBlock.Object);
		JB_Left->SetMaterial(0, M_JBlock.Object);
		JB_Right->SetMaterial(0, M_JBlock.Object);
	}

	//��¼��������
	MeshList.Add(JB_Center);
	MeshList.Add(JB_Left);
	MeshList.Add(JB_UpLeft);
	MeshList.Add(JB_Right);
}

//����
void AJBlock::Spin_L()
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
void AJBlock::Spin_R()
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
TArray<FPoint> AJBlock::GetPosList()
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
TArray<FPoint> AJBlock::GetPosListL()
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
TArray<FPoint> AJBlock::GetPosListR()
{
	//��������
	TArray<FPoint> Arr;

	//Ԥ����һ�����ĵ����תҳ
	FPoint NextPos = Pos;
	int NewRotationIndex = (RotationIndex + 1) % 4;

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


	//��������
	Arr.Add(NextPos);

	//��������ͨ�����������ת�Ƕȼ������������
	for (int i = 0; i < PosList.Num(); i++)
		Arr.Add(NextPos + PosList[i][NewRotationIndex]);
	return Arr;
}