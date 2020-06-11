// Fill out your copyright notice in the Description page of Project Settings.


#include "IBlock.h"

//默认构造函数
AIBlock::AIBlock():ABlock()
{

	Type = EBlockType::IBLOCK;

	//设定中心块
	UStaticMeshComponent* IB_Center = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("IBlock_Center"));
	RootComponent = IB_Center;

	//上块
	UStaticMeshComponent* IB_Up = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("IBlock_Up"));
	IB_Up->SetRelativeLocation(FVector(0.0f, -60.0f, 0.0f));
	IB_Up->SetupAttachment(RootComponent);

	//下块
	UStaticMeshComponent* IB_Down = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("IBlock_Down"));
	IB_Down->SetRelativeLocation(FVector(0.0f, 60.0f, 0.0f));
	IB_Down->SetupAttachment(RootComponent);

	//下下块
	UStaticMeshComponent* IB_DownDown = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("IBlock_DownDown"));
	IB_DownDown->SetRelativeLocation(FVector(0.0f, 120.0f, 0.0f));
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
}

//左旋
void AIBlock::Spin_L_Implementation()
{
	Super::Spin_L();

	//位移校准
	switch (RotationIndex)
	{
	case 3:
		SetActorRelativeLocation(GetActorLocation() + FVector(0.0f, BlockSize, 0.0f));
		break;
	case 2:
		SetActorRelativeLocation(GetActorLocation() + FVector(BlockSize, 0.0f, 0.0f));
		break;
	case 1:
		SetActorRelativeLocation(GetActorLocation() + FVector(0.0f, -BlockSize, 0.0f));
		break;
	case 0:
		SetActorRelativeLocation(GetActorLocation() + FVector(-BlockSize, 0.0f, 0.0f));
		break;
	default:
		break;
	}
}

//右旋
void AIBlock::Spin_R_Implementation()
{
	Super::Spin_R();
	
	//位移校准
	switch (RotationIndex)
	{
	case 1:
		SetActorRelativeLocation(GetActorLocation() + FVector(0.0f, BlockSize, 0.0f));
		break;
	case 2:
		SetActorRelativeLocation(GetActorLocation() + FVector(-BlockSize, 0.0f, 0.0f));
		break;
	case 3:
		SetActorRelativeLocation(GetActorLocation() + FVector(0.0f, -BlockSize, 0.0f));
		break;
	case 0:
		SetActorRelativeLocation(GetActorLocation() + FVector(BlockSize, 0.0f, 0.0f));
		break;
	default:
		break;
	}
}


