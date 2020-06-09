// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Block.generated.h"

//枚举蓝图类，表示方块类型
UENUM(BlueprintType)
enum class EBlockType: uint8
{
	NONE,
	TBLOCK,
	IBLOCK,
	OBLOCK,
	LBLOCK,
	JBLOCK,
	SBLOCK,
	ZBLOCK
};

//结构体，表示坐标
USTRUCT(BlueprintType)
struct FPoint
{
	GENERATED_BODY()

	//默认初始化为0
	FPoint() :X(0), Y(0) {};

	//X轴坐标
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int X;

	//Y轴坐标
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int Y;
};

//砖块类
UCLASS()
class TETRIS_UE_API ABlock : public AActor
{
	GENERATED_BODY()
	
public:	
	//默认构造函数
	ABlock();

protected:
	
	UPROPERTY(EditAnywhere)
	int BlockSize = 60;

	//旋转列表
	UPROPERTY(EditAnywhere)
	FRotator RotationList[4] =
	{
		FRotator(0.0f,0.0f,0.0f),
		FRotator(0.0f,90.0f,0.0f),
		FRotator(0.0f,180.0f,0.0f),
		FRotator(0.0f,270.0f,0.0f)
	};
	
	//当前旋转方向
	UPROPERTY(BlueprintReadWrite)
	int RotationIndex = 0;
	
	
	//游戏开始
	virtual void BeginPlay() override;

	//左旋转
	virtual void Spin_L();
	
	//右旋转
	virtual void Spin_R();

public:	
	//每帧执行
	virtual void Tick(float DeltaTime) override;

	//坐标
	UPROPERTY(BlueprintReadWrite)
	FPoint Pos;

	//种类
	UPROPERTY(EditAnywhere)
	EBlockType Type;

};
