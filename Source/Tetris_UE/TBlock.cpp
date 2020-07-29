// Fill out your copyright notice in the Description page of Project Settings.


#include "TBlock.h"

//构造函数
ATBlock::ATBlock() :ABlock()
{
	//设定方块类型
	Type = EBlockType::TBLOCK;

	//初始化坐标列表
	PosList.Init(TArray<FPoint>(), 3);

	//上
	PosList[0].Add(FPoint(0, -1));
	PosList[0].Add(FPoint(1, 0));
	PosList[0].Add(FPoint(0, 1));
	PosList[0].Add(FPoint(-1, 0));

	//左方块
	PosList[1].Add(FPoint(-1, 0));
	PosList[1].Add(FPoint(0, -1));
	PosList[1].Add(FPoint(1, 0));
	PosList[1].Add(FPoint(0, 1));

	//右方块
	PosList[2].Add(FPoint(1, 0));
	PosList[2].Add(FPoint(0, 1));
	PosList[2].Add(FPoint(-1, 0));
	PosList[2].Add(FPoint(0, -1));

	//设定中心块
	UStaticMeshComponent* TB_Center = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TBlock_Center"));
	RootComponent = TB_Center;

	//上块
	UStaticMeshComponent* TB_Up = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TBlock_Up"));
	TB_Up->SetRelativeLocation(FVector(0.0f, -BlockSize, 0.0f));
	TB_Up->SetupAttachment(RootComponent);

	//左块
	UStaticMeshComponent* TB_Left = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TBlock_Left"));
	TB_Left->SetRelativeLocation(FVector(-BlockSize, 0.0f, 0.0f));
	TB_Left->SetupAttachment(RootComponent);

	//右块
	UStaticMeshComponent* TB_Right = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TBLock_Right"));
	TB_Right->SetRelativeLocation(FVector(BlockSize, 0.0f, 0.0f));
	TB_Right->SetupAttachment(RootComponent);

	//加载形状
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Basic_Block(TEXT("StaticMesh'/Game/Shapes/Basic_Block.Basic_Block'"));
	if (Basic_Block.Succeeded())
	{
		TB_Center->SetStaticMesh(Basic_Block.Object);
		TB_Up->SetStaticMesh(Basic_Block.Object);
		TB_Left->SetStaticMesh(Basic_Block.Object);
		TB_Right->SetStaticMesh(Basic_Block.Object);
	}

	//加载材质
	static ConstructorHelpers::FObjectFinder<UMaterial> M_TBlock(TEXT("Material'/Game/Materials/M_TBlock.M_TBlock'"));
	if (M_TBlock.Succeeded())
	{
		TB_Center->SetMaterial(0, M_TBlock.Object);
		TB_Up->SetMaterial(0, M_TBlock.Object);
		TB_Left->SetMaterial(0, M_TBlock.Object);
		TB_Right->SetMaterial(0, M_TBlock.Object);
	}

	//记录方块引用
	MeshList.Add(TB_Up);
	MeshList.Add(TB_Center);
	MeshList.Add(TB_Left);
	MeshList.Add(TB_Right);
}

//左旋
void ATBlock::Spin_L()
{
	Super::Spin_L();
}

//右旋
void ATBlock::Spin_R()
{
	Super::Spin_R();
}

//返回坐标列表
TArray<FPoint> ATBlock::GetPosList()
{
	//创建数组
	TArray<FPoint> Arr;

	//中心坐标
	Arr.Add(Pos);

	//中心坐标通过相对坐标旋转角度计算出其余坐标
	for (int i = 0; i < PosList.Num(); i++)
		Arr.Add(Pos + PosList[i][RotationIndex]);
	return Arr;
}

//返回左旋坐标列表
TArray<FPoint> ATBlock::GetPosListL()
{
	//创建数组
	TArray<FPoint> Arr;

	//预测下一个中心点和旋转页
	FPoint NextPos = Pos;
	int NewRotationIndex = (RotationIndex + 3) % 4;

	//中心坐标
	Arr.Add(NextPos);

	//中心坐标通过相对坐标旋转角度计算出其余坐标
	for (int i = 0; i < PosList.Num(); i++)
		Arr.Add(NextPos + PosList[i][NewRotationIndex]);
	return Arr;
}

//返回右旋坐标列表
TArray<FPoint> ATBlock::GetPosListR()
{
	//创建数组
	TArray<FPoint> Arr;

	//预测下一个中心点和旋转页
	FPoint NextPos = Pos;
	int NewRotationIndex = (RotationIndex + 1) % 4;

	//中心坐标
	Arr.Add(NextPos);

	//中心坐标通过相对坐标旋转角度计算出其余坐标
	for (int i = 0; i < PosList.Num(); i++)
		Arr.Add(NextPos + PosList[i][NewRotationIndex]);
	return Arr;
}
