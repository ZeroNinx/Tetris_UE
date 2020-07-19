// Fill out your copyright notice in the Description page of Project Settings.


#include "ZBlock.h"

//构造函数
AZBlock::AZBlock() :ABlock()
{
	//设定方块类型
	Type = EBlockType::ZBLOCK;

	//初始化坐标列表
	PosList.Init(TArray<FPoint>(), 3);

	//左方块
	PosList[0].Add(FPoint(-1, 0));
	PosList[0].Add(FPoint(0, -1));
	PosList[0].Add(FPoint(1, 0));
	PosList[0].Add(FPoint(0, 1));

	//下方块
	PosList[1].Add(FPoint(0, 1));
	PosList[1].Add(FPoint(-1, 0));
	PosList[1].Add(FPoint(0, -1));
	PosList[1].Add(FPoint(1, 0));

	//下右方块
	PosList[2].Add(FPoint(1, 1));
	PosList[2].Add(FPoint(-1, 1));
	PosList[2].Add(FPoint(-1, -1));
	PosList[2].Add(FPoint(1, -1));

	//设定中心块
	UStaticMeshComponent* ZB_Center = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ZBlock_Center"));
	RootComponent = ZB_Center;

	//左块
	UStaticMeshComponent* ZB_Left = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ZBlock_Left"));
	ZB_Left->SetRelativeLocation(FVector(-BlockSize, 0.0f, 0.0f));
	ZB_Left->SetupAttachment(RootComponent);

	//下块
	UStaticMeshComponent* ZB_Down = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ZBlock_Down"));
	ZB_Down->SetRelativeLocation(FVector(0.0f, BlockSize, 0.0f));
	ZB_Down->SetupAttachment(RootComponent);

	//下右块
	UStaticMeshComponent* ZB_DownRight = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ZBLock_DownRight"));
	ZB_DownRight->SetRelativeLocation(FVector(BlockSize, BlockSize, 0.0f));
	ZB_DownRight->SetupAttachment(RootComponent);

	//加载形状
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Basic_Block(TEXT("StaticMesh'/Game/Shapes/Basic_Block.Basic_Block'"));
	if (Basic_Block.Succeeded())
	{
		ZB_Center->SetStaticMesh(Basic_Block.Object);
		ZB_Left->SetStaticMesh(Basic_Block.Object);
		ZB_Down->SetStaticMesh(Basic_Block.Object);
		ZB_DownRight->SetStaticMesh(Basic_Block.Object);
	}

	//加载材质
	static ConstructorHelpers::FObjectFinder<UMaterial> ZBlock_Material(TEXT("Material'/Game/Materials/ZBlock_Material.ZBlock_Material'"));
	if (ZBlock_Material.Succeeded())
	{
		ZB_Center->SetMaterial(0, ZBlock_Material.Object);
		ZB_Left->SetMaterial(0, ZBlock_Material.Object);
		ZB_Down->SetMaterial(0, ZBlock_Material.Object);
		ZB_DownRight->SetMaterial(0, ZBlock_Material.Object);
	}
}

//左旋
void AZBlock::Spin_L()
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
void AZBlock::Spin_R()
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
TArray<FPoint> AZBlock::GetPosList()
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
TArray<FPoint> AZBlock::GetPosListL()
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
TArray<FPoint> AZBlock::GetPosListR()
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
