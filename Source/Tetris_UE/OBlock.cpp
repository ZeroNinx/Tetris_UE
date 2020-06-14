// Fill out your copyright notice in the Description page of Project Settings.


#include "OBlock.h"

AOBlock::AOBlock() :ABlock()
{
	//设定方块类型
	Type = EBlockType::OBLOCK;

	//上块（中心）
	UStaticMeshComponent* OB_Up = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OBlock_Up"));
	RootComponent = OB_Up;

	//右块
	UStaticMeshComponent* OB_Right = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OBlock_Right"));
	OB_Right->SetRelativeLocation(FVector(60.0f, 0.0f, 0.0f));
	OB_Right->SetupAttachment(RootComponent);

	//下块
	UStaticMeshComponent* OB_Down = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OBlock_Down"));
	OB_Down->SetRelativeLocation(FVector(60.0f, 60.0f, 0.0f));
	OB_Down->SetupAttachment(RootComponent);

	//左块
	UStaticMeshComponent* OB_Left = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OBlock_Left"));
	OB_Left->SetRelativeLocation(FVector(0.0f, 60.0f, 0.0f));
	OB_Left->SetupAttachment(RootComponent);

	//加载形状
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Basic_Block(TEXT("StaticMesh'/Game/Shapes/Basic_Block.Basic_Block'"));
	if (Basic_Block.Succeeded())
	{
		OB_Up->SetStaticMesh(Basic_Block.Object);
		OB_Right->SetStaticMesh(Basic_Block.Object);
		OB_Down->SetStaticMesh(Basic_Block.Object);
		OB_Left->SetStaticMesh(Basic_Block.Object);
	}

	//加载材质
	static ConstructorHelpers::FObjectFinder<UMaterial> OBlock_Material(TEXT("Material'/Game/Materials/OBlock_Material.OBlock_Material'"));
	if (OBlock_Material.Succeeded())
	{
		OB_Up->SetMaterial(0, OBlock_Material.Object);
		OB_Right->SetMaterial(0, OBlock_Material.Object);
		OB_Down->SetMaterial(0, OBlock_Material.Object);
		OB_Left->SetMaterial(0, OBlock_Material.Object);
	}
}

void AOBlock::Spin_L()
{
	
}

void AOBlock::Spin_R()
{
	
}

//返回坐标列表
TArray<FPoint> AOBlock::GetPosList()
{
	//创建数组
	TArray<FPoint> Arr;

	//添加坐标
	Arr.Add(Pos);
	Arr.Add(Pos+FPoint(0,1));
	Arr.Add(Pos + FPoint(1, 0));
	Arr.Add(Pos + FPoint(1, 1));

	return Arr;
}