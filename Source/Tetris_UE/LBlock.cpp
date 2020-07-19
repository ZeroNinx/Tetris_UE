// Fill out your copyright notice in the Description page of Project Settings.


#include "LBlock.h"

//构造函数
ALBlock::ALBlock() :ABlock()
{
	//设定方块类型
	Type = EBlockType::LBLOCK;

	//初始化坐标列表
	PosList.Init(TArray<FPoint>(), 3);

	//上右方块
	PosList[0].Add(FPoint(1, -1));
	PosList[0].Add(FPoint(1, 1));
	PosList[0].Add(FPoint(-1, 1));
	PosList[0].Add(FPoint(-1, -1));

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
	UStaticMeshComponent* LB_Center = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LBlock_Center"));
	RootComponent = LB_Center;

	//上右块
	UStaticMeshComponent* LB_UpRight = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LBlock_UpRight"));
	LB_UpRight->SetRelativeLocation(FVector(BlockSize, -BlockSize, 0.0f));
	LB_UpRight->SetupAttachment(RootComponent);

	//左块
	UStaticMeshComponent* LB_Left = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LBlock_Left"));
	LB_Left->SetRelativeLocation(FVector(-BlockSize, 0.0f, 0.0f));
	LB_Left->SetupAttachment(RootComponent);

	//右块
	UStaticMeshComponent* LB_Right = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LBLock_Right"));
	LB_Right->SetRelativeLocation(FVector(BlockSize, 0.0f, 0.0f));
	LB_Right->SetupAttachment(RootComponent);

	//加载形状
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Basic_Block(TEXT("StaticMesh'/Game/Shapes/Basic_Block.Basic_Block'"));
	if (Basic_Block.Succeeded())
	{
		LB_Center->SetStaticMesh(Basic_Block.Object);
		LB_UpRight->SetStaticMesh(Basic_Block.Object);
		LB_Left->SetStaticMesh(Basic_Block.Object);
		LB_Right->SetStaticMesh(Basic_Block.Object);
	}

	//加载材质
	static ConstructorHelpers::FObjectFinder<UMaterial> LBlock_Material(TEXT("Material'/Game/Materials/LBlock_Material.LBlock_Material'"));
	if (LBlock_Material.Succeeded())
	{
		LB_Center->SetMaterial(0, LBlock_Material.Object);
		LB_UpRight->SetMaterial(0, LBlock_Material.Object);
		LB_Left->SetMaterial(0, LBlock_Material.Object);
		LB_Right->SetMaterial(0, LBlock_Material.Object);
	}
}

//左旋
void ALBlock::Spin_L()
{
	Super::Spin_L();

}

//右旋
void ALBlock::Spin_R()
{
	Super::Spin_R();

}

//返回坐标列表
TArray<FPoint> ALBlock::GetPosList()
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
TArray<FPoint> ALBlock::GetPosListL()
{
	//创建数组
	TArray<FPoint> Arr;

	//预测下一个中心点和旋转页
	FPoint NextPos = Pos;
	int NewRotationIndex = (RotationIndex + 3) % 4;

	//中心坐标通过相对坐标旋转角度计算出其余坐标
	for (int i = 0; i < PosList.Num(); i++)
		Arr.Add(NextPos + PosList[i][NewRotationIndex]);
	return Arr;
}

//返回右旋坐标列表
TArray<FPoint> ALBlock::GetPosListR()
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
