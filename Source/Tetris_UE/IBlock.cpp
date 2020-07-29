// Fill out your copyright notice in the Description page of Project Settings.


#include "IBlock.h"

//默认构造函数
AIBlock::AIBlock():ABlock()
{
	//设定方块类型
	Type = EBlockType::IBLOCK;

	//初始化坐标列表
	PosList.Init(TArray<FPoint>(), 3);

	//左方块
	PosList[0].Add(FPoint(-1, 0));
	PosList[0].Add(FPoint(0, -1));
	PosList[0].Add(FPoint(1, 0));
	PosList[0].Add(FPoint(0, 1));
	

	//右方块
	PosList[1].Add(FPoint(1, 0));
	PosList[1].Add(FPoint(0, 1));
	PosList[1].Add(FPoint(-1, 0));
	PosList[1].Add(FPoint(0, -1));


	//下下方块
	PosList[2].Add(FPoint(2, 0));
	PosList[2].Add(FPoint(0, 2));
	PosList[2].Add(FPoint(-2, 0));
	PosList[2].Add(FPoint(0, -2));
	

	//设定中心块
	UStaticMeshComponent* IB_Center = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("IBlock_Center"));
	RootComponent = IB_Center;

	//左块
	UStaticMeshComponent* IB_Left = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("IBlock_Left"));
	IB_Left->SetRelativeLocation(FVector(-BlockSize,0.0f,  0.0f));
	IB_Left->SetupAttachment(RootComponent);

	//右块
	UStaticMeshComponent* IB_Right = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("IBlock_Right"));
	IB_Right->SetRelativeLocation(FVector(BlockSize,0.0f,  0.0f));
	IB_Right->SetupAttachment(RootComponent);

	//右右块
	UStaticMeshComponent* IB_RightRight = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("IBlock_RightRight"));
	IB_RightRight->SetRelativeLocation(FVector(BlockSize*2,0.0f,  0.0f));
	IB_RightRight->SetupAttachment(RootComponent);

	//加载形状
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Basic_Block(TEXT("StaticMesh'/Game/Shapes/Basic_Block.Basic_Block'"));
	if (Basic_Block.Succeeded())
	{
		IB_Left->SetStaticMesh(Basic_Block.Object);
		IB_Center->SetStaticMesh(Basic_Block.Object);
		IB_Right->SetStaticMesh(Basic_Block.Object);
		IB_RightRight->SetStaticMesh(Basic_Block.Object);
	}

	//加载材质
	static ConstructorHelpers::FObjectFinder<UMaterial> IBlock_Material(TEXT("Material'/Game/Materials/M_IBlock.M_IBlock'"));
	if (IBlock_Material.Succeeded())
	{
		IB_Left->SetMaterial(0,IBlock_Material.Object);
		IB_Center->SetMaterial(0,IBlock_Material.Object);
		IB_Right->SetMaterial(0, IBlock_Material.Object);
		IB_RightRight->SetMaterial(0, IBlock_Material.Object);
	}

	//记录方块引用
	MeshList.Add(IB_Left);
	MeshList.Add(IB_Center);
	MeshList.Add(IB_Right);
	MeshList.Add(IB_RightRight);
}

//左旋
void AIBlock::Spin_L()
{
	Super::Spin_L();

	//位移校准
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

//右旋
void AIBlock::Spin_R()
{
	Super::Spin_R();
	
	//位移校准
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

//返回坐标列表
TArray<FPoint> AIBlock::GetPosList()
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
TArray<FPoint> AIBlock::GetPosListL()
{
	//创建数组
	TArray<FPoint> Arr;

	//预测下一个中心点和旋转页
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

	//中心坐标
	Arr.Add(NextPos);

	//中心坐标通过相对坐标旋转角度计算出其余坐标
	for (int i = 0; i < PosList.Num(); i++)
		Arr.Add(NextPos + PosList[i][NewRotationIndex]);
	return Arr;
}

//返回右旋坐标列表
TArray<FPoint> AIBlock::GetPosListR()
{
	//创建数组
	TArray<FPoint> Arr;

	//预测下一个中心点和旋转页
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

	//中心坐标
	Arr.Add(NextPos);

	//中心坐标通过相对坐标旋转角度计算出其余坐标
	for (int i = 0; i < PosList.Num(); i++)
		Arr.Add(NextPos + PosList[i][NewRotationIndex]);
	return Arr;
}