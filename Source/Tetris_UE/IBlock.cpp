// Fill out your copyright notice in the Description page of Project Settings.


#include "IBlock.h"

//默认构造函数
AIBlock::AIBlock():ABlock()
{
	//设定方块类型
	Type = EBlockType::IBLOCK;

	//初始化坐标列表
	PosList.Init(TArray<FPoint>(), 3);

	//上方块
	PosList[0].Add(FPoint(0, -1));
	PosList[0].Add(FPoint(1, 0));
	PosList[0].Add(FPoint(0, 1));
	PosList[0].Add(FPoint(-1, 0));

	//下方块
	PosList[1].Add(FPoint(0, 1));
	PosList[1].Add(FPoint(-1, 0));
	PosList[1].Add(FPoint(0, -1));
	PosList[1].Add(FPoint(1, 0));

	//下下方块
	PosList[2].Add(FPoint(0, 2));
	PosList[2].Add(FPoint(-2, 0));
	PosList[2].Add(FPoint(0, -2));
	PosList[2].Add(FPoint(2, 0));

	//设定中心块
	UStaticMeshComponent* IB_Center = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("IBlock_Center"));
	RootComponent = IB_Center;

	//上块
	UStaticMeshComponent* IB_Up = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("IBlock_Up"));
	IB_Up->SetRelativeLocation(FVector(0.0f, -BlockSize, 0.0f));
	IB_Up->SetupAttachment(RootComponent);

	//下块
	UStaticMeshComponent* IB_Down = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("IBlock_Down"));
	IB_Down->SetRelativeLocation(FVector(0.0f, BlockSize, 0.0f));
	IB_Down->SetupAttachment(RootComponent);

	//下下块
	UStaticMeshComponent* IB_DownDown = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("IBlock_DownDown"));
	IB_DownDown->SetRelativeLocation(FVector(0.0f, BlockSize*2, 0.0f));
	IB_DownDown->SetupAttachment(RootComponent);

	//加载形状
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Basic_Block(TEXT("StaticMesh'/Game/Shapes/Basic_Block.Basic_Block'"));
	if (Basic_Block.Succeeded())
	{
		IB_Up->SetStaticMesh(Basic_Block.Object);
		IB_Center->SetStaticMesh(Basic_Block.Object);
		IB_Down->SetStaticMesh(Basic_Block.Object);
		IB_DownDown->SetStaticMesh(Basic_Block.Object);
	}

	//加载材质
	static ConstructorHelpers::FObjectFinder<UMaterial> IBlock_Material(TEXT("Material'/Game/Materials/IBlock_Material.IBlock_Material'"));
	if (IBlock_Material.Succeeded())
	{
		IB_Up->SetMaterial(0,IBlock_Material.Object);
		IB_Center->SetMaterial(0,IBlock_Material.Object);
		IB_Down->SetMaterial(0, IBlock_Material.Object);
		IB_DownDown->SetMaterial(0, IBlock_Material.Object);
	}

	//记录方块引用
	MeshList.Add(IB_Up);
	MeshList.Add(IB_Center);
	MeshList.Add(IB_Down);
	MeshList.Add(IB_DownDown);
}

//左旋
void AIBlock::Spin_L()
{
	Super::Spin_L();

	//位移校准
	switch (RotationIndex)
	{
	case 3:
		SetActorRelativeLocation(GetActorLocation() + FVector(0.0f, BlockSize, 0.0f));
		Pos.Y++;
		break;
	case 2:
		SetActorRelativeLocation(GetActorLocation() + FVector(BlockSize, 0.0f, 0.0f));
		Pos.X++;
		break;
	case 1:
		SetActorRelativeLocation(GetActorLocation() + FVector(0.0f, -BlockSize, 0.0f));
		Pos.Y--;
		break;
	case 0:
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
	case 1:
		SetActorRelativeLocation(GetActorLocation() + FVector(0.0f, BlockSize, 0.0f));
		Pos.Y++;
		break;
	case 2:
		SetActorRelativeLocation(GetActorLocation() + FVector(-BlockSize, 0.0f, 0.0f));
		Pos.X--;
		break;
	case 3:
		SetActorRelativeLocation(GetActorLocation() + FVector(0.0f, -BlockSize, 0.0f));
		Pos.Y--;
		break;
	case 0:
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
	case 3:
		NextPos.Y++;
		break;
	case 2:
		NextPos.X++;
		break;
	case 1:
		NextPos.Y--;
		break;
	case 0:
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
	case 1:
		NextPos.Y++;
		break;
	case 2:
		NextPos.X--;
		break;
	case 3:
		NextPos.Y--;
		break;
	case 0:
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