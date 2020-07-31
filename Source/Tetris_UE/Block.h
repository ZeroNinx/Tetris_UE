// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/StaticMeshComponent.h>
#include "Block.generated.h"

//枚举蓝图类，表示方块类型
UENUM(BlueprintType)
enum class EBlockType : uint8
{
	NONE = 0,
	TBLOCK = 1,
	IBLOCK = 2,
	OBLOCK = 3,
	LBLOCK = 4,
	JBLOCK = 5,
	SBLOCK = 6,
	ZBLOCK = 7
};

//结构体，表示坐标
USTRUCT(BlueprintType)
struct FPoint
{
	GENERATED_BODY()

	//默认初始化为0
	FPoint() :X(0), Y(0) {};

	//构造函数
	FPoint(int x,int y) :X(x), Y(y) {};

	FPoint operator+(const FPoint& b)
	{
		FPoint fp;
		fp.X = this->X + b.X;
		fp.Y = this->Y + b.Y;
		return fp;
	}

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

	//方块大小
	UPROPERTY(EditAnywhere)
	int BlockSize = 60;

	//坐标
	UPROPERTY(BlueprintReadOnly)
	FPoint Pos;

	//方块类型
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	EBlockType Type=EBlockType::NONE;

	//当前旋转方向
	int RotationIndex = 0;

	//旋转列表
	FRotator RotationList[4] =
	{
		FRotator(0.0f,0.0f,0.0f),
		FRotator(0.0f,90.0f,0.0f),
		FRotator(0.0f,180.0f,0.0f),
		FRotator(0.0f,270.0f,0.0f)
	};

	//坐标列表
	TArray<TArray<FPoint>> PosList;

	//方块材质列表
	TArray<UStaticMeshComponent*> MeshList;

	//游戏开始
	virtual void BeginPlay() override;

	//左旋转
	UFUNCTION(BlueprintCallable)
	virtual void Spin_L();
	
	//右旋转
	UFUNCTION(BlueprintCallable)
	virtual void Spin_R();

public:	

	//每帧执行
	virtual void Tick(float DeltaTime) override;

	//获取旋转方向
	UFUNCTION(BlueprintCallable)
	int GetRotationIndex();

	//设定坐标
	UFUNCTION(BlueprintCallable)
	void SetPos(FPoint NewPos);

	//获取坐标列表
	UFUNCTION(BlueprintCallable)
	virtual TArray<FPoint> GetPosList();

	//获取左旋坐标列表
	UFUNCTION(BlueprintCallable)
	virtual TArray<FPoint> GetPosListL();

	//获取右旋坐标列表
	UFUNCTION(BlueprintCallable)
	virtual TArray<FPoint> GetPosListR();

	//设定方块材质
	UFUNCTION(BlueprintCallable)
	void SetBlockMaterial(UMaterialInterface* material);
};
