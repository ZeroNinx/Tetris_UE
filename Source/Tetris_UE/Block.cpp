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

//����
void ABlock::Spin_L()
{
	RotationIndex += 3;
	RotationIndex %= 4;
	SetActorRotation(RotationList[RotationIndex]);
}

//����
void ABlock::Spin_R()
{
	RotationIndex++;
	RotationIndex %= 4;
	SetActorRotation(RotationList[RotationIndex]);
}

//ÿִ֡��
void ABlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

