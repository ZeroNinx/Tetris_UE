// Fill out your copyright notice in the Description page of Project Settings.


#include "JBlock.h"

//构造函数
AJBlock::AJBlock() :ABlock()
{
	//设定方块类型
	Type = EBlockType::JBLOCK;

	//初始化坐标列表
	PosList.Init(TArray<FPoint>(), 3);

	//上左方块
	PosList[0].Add(FPoint(-1, -1));
	PosList[0].Add(FPoint(1, -1));
	PosList[0].Add(FPoint(1, 1));
	PosList[0].Add(FPoint(-1, 1));

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
	UStaticMeshComponent* JB_Center = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("JBlock_Center"));
	RootComponent = JB_Center;

	//上左块
	UStaticMeshComponent* JB_UpLeft = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("JBlock_UpLeft"));
	JB_UpLeft->SetRelativeLocation(FVector(-BlockSize, -BlockSize, 0.0f));
	JB_UpLeft->SetupAttachment(RootComponent);

	//左块
	UStaticMeshComponent* JB_Left = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("JBlock_Left"));
	JB_Left->SetRelativeLocation(FVector(-BlockSize, 0.0f, 0.0f));
	JB_Left->SetupAttachment(RootComponent);

	//右块
	UStaticMeshComponent* JB_Right = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("JBLock_Right"));
	JB_Right->SetRelativeLocation(FVector(BlockSize, 0.0f, 0.0f));
	JB_Right->SetupAttachment(RootComponent);

	//加载形状
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Basic_Block(TEXT("StaticMesh'/Game/Shapes/Basic_Block.Basic_Block'"));
	if (Basic_Block.Succeeded())
	{
		JB_Center->SetStaticMesh(Basic_Block.Object);
		JB_UpLeft->SetStaticMesh(Basic_Block.Object);
		JB_Left->SetStaticMesh(Basic_Block.Object);
		JB_Right->SetStaticMesh(Basic_Block.Object);
	}

	//加载材质
	static ConstructorHelpers::FObjectFinder<UMaterial> M_JBlock(TEXT("Material'/Game/Materials/M_JBlock.M_JBlock'"));
	if (M_JBlock.Succeeded())
	{
		JB_Center->SetMaterial(0, M_JBlock.Object);
		JB_UpLeft->SetMaterial(0, M_JBlock.Object);
		JB_Left->SetMaterial(0, M_JBlock.Object);
		JB_Right->SetMaterial(0, M_JBlock.Object);
	}

	//记录方块引用
	MeshList.Add(JB_Center);
	MeshList.Add(JB_Left);
	MeshList.Add(JB_UpLeft);
	MeshList.Add(JB_Right);
}

//左旋
void AJBlock::Spin_L()
{
	Super::Spin_L();

	//位移校准
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

//右旋
void AJBlock::Spin_R()
{
	Super::Spin_R();

	//位移校准
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

//返回坐标列表
TArray<FPoint> AJBlock::GetPosList()
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
TArray<FPoint> AJBlock::GetPosListL()
{
	//创建数组
	TArray<FPoint> Arr;

	//预测下一个中心点和旋转页
	FPoint NextPos = Pos;
	int NewRotationIndex = (RotationIndex + 3) % 4;

	//位移校准
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


	//中心坐标通过相对坐标旋转角度计算出其余坐标
	for (int i = 0; i < PosList.Num(); i++)
		Arr.Add(NextPos + PosList[i][NewRotationIndex]);
	return Arr;
}

//返回右旋坐标列表
TArray<FPoint> AJBlock::GetPosListR()
{
	//创建数组
	TArray<FPoint> Arr;

	//预测下一个中心点和旋转页
	FPoint NextPos = Pos;
	int NewRotationIndex = (RotationIndex + 1) % 4;

	//位移校准
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


	//中心坐标
	Arr.Add(NextPos);

	//中心坐标通过相对坐标旋转角度计算出其余坐标
	for (int i = 0; i < PosList.Num(); i++)
		Arr.Add(NextPos + PosList[i][NewRotationIndex]);
	return Arr;
}