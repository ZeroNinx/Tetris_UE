// Fill out your copyright notice in the Description page of Project Settings.


#include "Block.h"

//默认构造函数
ABlock::ABlock()
{
 	//设置可以被Tick
	PrimaryActorTick.bCanEverTick = true;

}

//游戏开始
void ABlock::BeginPlay()
{
	Super::BeginPlay();
	
}

//每帧执行
void ABlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//左旋
void ABlock::Spin_L()
{
	RotationIndex += 3;
	RotationIndex %= 4;
	SetActorRelativeRotation(RotationList[RotationIndex]);
}

//右旋
void ABlock::Spin_R()
{
	RotationIndex++;
	RotationIndex %= 4;
	SetActorRelativeRotation(RotationList[RotationIndex]);
}

//设定坐标
void ABlock::SetPos(FPoint NewPos)
{
	Pos = NewPos;
	SetActorLocation(FVector(Pos.X * 60, Pos.Y * 60, 0.0f));
}

//返回坐标列表
TArray<FPoint> ABlock::GetPosList()
{
	TArray<FPoint> Arr;
	Arr.Add(Pos);
	return Arr;
}
