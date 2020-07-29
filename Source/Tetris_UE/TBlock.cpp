// Fill out your copyright notice in the Description page of Project Settings.


#include "TBlock.h"

//���캯��
ATBlock::ATBlock() :ABlock()
{
	//�趨��������
	Type = EBlockType::TBLOCK;

	//��ʼ�������б�
	PosList.Init(TArray<FPoint>(), 3);

	//��
	PosList[0].Add(FPoint(0, -1));
	PosList[0].Add(FPoint(1, 0));
	PosList[0].Add(FPoint(0, 1));
	PosList[0].Add(FPoint(-1, 0));

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
	UStaticMeshComponent* TB_Center = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TBlock_Center"));
	RootComponent = TB_Center;

	//�Ͽ�
	UStaticMeshComponent* TB_Up = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TBlock_Up"));
	TB_Up->SetRelativeLocation(FVector(0.0f, -BlockSize, 0.0f));
	TB_Up->SetupAttachment(RootComponent);

	//���
	UStaticMeshComponent* TB_Left = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TBlock_Left"));
	TB_Left->SetRelativeLocation(FVector(-BlockSize, 0.0f, 0.0f));
	TB_Left->SetupAttachment(RootComponent);

	//�ҿ�
	UStaticMeshComponent* TB_Right = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TBLock_Right"));
	TB_Right->SetRelativeLocation(FVector(BlockSize, 0.0f, 0.0f));
	TB_Right->SetupAttachment(RootComponent);

	//������״
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Basic_Block(TEXT("StaticMesh'/Game/Shapes/Basic_Block.Basic_Block'"));
	if (Basic_Block.Succeeded())
	{
		TB_Center->SetStaticMesh(Basic_Block.Object);
		TB_Up->SetStaticMesh(Basic_Block.Object);
		TB_Left->SetStaticMesh(Basic_Block.Object);
		TB_Right->SetStaticMesh(Basic_Block.Object);
	}

	//���ز���
	static ConstructorHelpers::FObjectFinder<UMaterial> M_TBlock(TEXT("Material'/Game/Materials/M_TBlock.M_TBlock'"));
	if (M_TBlock.Succeeded())
	{
		TB_Center->SetMaterial(0, M_TBlock.Object);
		TB_Up->SetMaterial(0, M_TBlock.Object);
		TB_Left->SetMaterial(0, M_TBlock.Object);
		TB_Right->SetMaterial(0, M_TBlock.Object);
	}

	//��¼��������
	MeshList.Add(TB_Up);
	MeshList.Add(TB_Center);
	MeshList.Add(TB_Left);
	MeshList.Add(TB_Right);
}

//����
void ATBlock::Spin_L()
{
	Super::Spin_L();
}

//����
void ATBlock::Spin_R()
{
	Super::Spin_R();
}

//���������б�
TArray<FPoint> ATBlock::GetPosList()
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
TArray<FPoint> ATBlock::GetPosListL()
{
	//��������
	TArray<FPoint> Arr;

	//Ԥ����һ�����ĵ����תҳ
	FPoint NextPos = Pos;
	int NewRotationIndex = (RotationIndex + 3) % 4;

	//��������
	Arr.Add(NextPos);

	//��������ͨ�����������ת�Ƕȼ������������
	for (int i = 0; i < PosList.Num(); i++)
		Arr.Add(NextPos + PosList[i][NewRotationIndex]);
	return Arr;
}

//�������������б�
TArray<FPoint> ATBlock::GetPosListR()
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
