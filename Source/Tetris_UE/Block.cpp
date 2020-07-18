// Fill out your copyright notice in the Description page of Project Settings.


#include "Block.h"

//Ĭ�Ϲ��캯��
ABlock::ABlock()
{
 	//���ÿ��Ա�Tick
	PrimaryActorTick.bCanEverTick = true;

}

//��Ϸ��ʼ
void ABlock::BeginPlay()
{
	Super::BeginPlay();
	
}

//ÿִ֡��
void ABlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//����
void ABlock::Spin_L()
{
	RotationIndex += 3;
	RotationIndex %= 4;
	SetActorRelativeRotation(RotationList[RotationIndex]);
}

//����
void ABlock::Spin_R()
{
	RotationIndex++;
	RotationIndex %= 4;
	SetActorRelativeRotation(RotationList[RotationIndex]);
}

//�趨����
void ABlock::SetPos(FPoint NewPos)
{
	Pos = NewPos;
	SetActorLocation(FVector(Pos.X * 60, Pos.Y * 60, 0.0f));
}

//���������б�
TArray<FPoint> ABlock::GetPosList()
{
	TArray<FPoint> Arr;
	Arr.Add(Pos);
	return Arr;
}
