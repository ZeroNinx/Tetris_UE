// Fill out your copyright notice in the Description page of Project Settings.


#include "SBlock.h"

//构造函数
ASBlock::ASBlock() :ABlock()
{
	//设定方块类型
	Type = EBlockType::SBLOCK;

	//初始化坐标列表
	PosList.Init(TArray<FPoint>(), 3);

	//右方块
	PosList[0].Add(FPoint(1, 0));
	PosList[0].Add(FPoint(0, 1));
	PosList[0].Add(FPoint(-1, 0));
	PosList[0].Add(FPoint(0, -1));

	//下方块
	PosList[1].Add(FPoint(0, 1));
	PosList[1].Add(FPoint(-1, 0));
	PosList[1].Add(FPoint(0, -1));
	PosList[1].Add(FPoint(1, 0));

	//下左方块
	PosList[2].Add(FPoint(-1, 1));
	PosList[2].Add(FPoint(-1, -1));
	PosList[2].Add(FPoint(1, -1));
	PosList[2].Add(FPoint(1, 1));

	//设定中心块
	UStaticMeshComponent* SB_Center = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SBlock_Center"));
	RootComponent = SB_Center;

	//右块
	UStaticMeshComponent* SB_Right = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SBlock_Right"));
	SB_Right->SetRelativeLocation(FVector(BlockSize, 0.0f, 0.0f));
	SB_Right->SetupAttachment(RootComponent);

	//下块
	UStaticMeshComponent* SB_Down = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SBlock_Down"));
	SB_Down->SetRelativeLocation(FVector(0.0f, BlockSize, 0.0f));
	SB_Down->SetupAttachment(RootComponent);

	//下左块
	UStaticMeshComponent* SB_DownLeft = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SBLock_DownLeft"));
	SB_DownLeft->SetRelativeLocation(FVector(-BlockSize, BlockSize, 0.0f));
	SB_DownLeft->SetupAttachment(RootComponent);

	//加载形状
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Basic_Block(TEXT("StaticMesh'/Game/Shapes/Basic_Block.Basic_Block'"));
	if (Basic_Block.Succeeded())
	{
		SB_Center->SetStaticMesh(Basic_Block.Object);
		SB_Right->SetStaticMesh(Basic_Block.Object);
		SB_Down->SetStaticMesh(Basic_Block.Object);
		SB_DownLeft->SetStaticMesh(Basic_Block.Object);
	}

	//加载材质
	static ConstructorHelpers::FObjectFinder<UMaterial> M_SBlock(TEXT("Material'/Game/Materials/M_SBlock.M_SBlock'"));
	if (M_SBlock.Succeeded())
	{
		SB_Center->SetMaterial(0, M_SBlock.Object);
		SB_Right->SetMaterial(0, M_SBlock.Object);
		SB_Down->SetMaterial(0, M_SBlock.Object);
		SB_DownLeft->SetMaterial(0, M_SBlock.Object);
	}

	//记录方块引用
	MeshList.Add(SB_DownLeft);
	MeshList.Add(SB_Center);
	MeshList.Add(SB_Down);
	MeshList.Add(SB_Right);
}

//左旋
void ASBlock::Spin_L()
{
	Super::Spin_L();

	//位移校准
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

//右旋
void ASBlock::Spin_R()
{
	Super::Spin_R();
	//位移校准
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

//返回坐标列表
TArray<FPoint> ASBlock::GetPosList()
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
TArray<FPoint> ASBlock::GetPosListL()
{
	//创建数组
	TArray<FPoint> Arr;

	//预测下一个中心点和旋转页
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

	//中心坐标
	Arr.Add(NextPos);

	//中心坐标通过相对坐标旋转角度计算出其余坐标
	for (int i = 0; i < PosList.Num(); i++)
		Arr.Add(NextPos + PosList[i][NewRotationIndex]);
	return Arr;
}

//返回右旋坐标列表
TArray<FPoint> ASBlock::GetPosListR()
{
	//创建数组
	TArray<FPoint> Arr;

	//预测下一个中心点和旋转页
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

	//中心坐标
	Arr.Add(NextPos);

	//中心坐标通过相对坐标旋转角度计算出其余坐标
	for (int i = 0; i < PosList.Num(); i++)
		Arr.Add(NextPos + PosList[i][NewRotationIndex]);
	return Arr;
}
