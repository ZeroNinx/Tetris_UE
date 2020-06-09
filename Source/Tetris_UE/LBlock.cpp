// Fill out your copyright notice in the Description page of Project Settings.


#include "LBlock.h"

void ALBlock::Spin_L_Implementation()
{
	Super::Spin_L();

	//旋转时校正位置
	switch (RotationIndex)
	{
	case 0:
		SetActorLocation(GetActorLocation() + FVector(BlockSize, BlockSize, 0.0f));
		break;
	case 1:
		SetActorLocation(GetActorLocation() + FVector(-BlockSize, BlockSize , 0.0f));
		break;
	case 2:
		SetActorLocation(GetActorLocation() + FVector(-BlockSize, -BlockSize, 0.0f));
		break;
	case 3:
		SetActorLocation(GetActorLocation() + FVector(BlockSize, -BlockSize, 0.0f));
		break;
	default:
		break;
	}

}

void ALBlock::Spin_R_Implementation()
{
	Super::Spin_R();

	//旋转时校正位置
	switch (RotationIndex)
	{
	case 1:
		SetActorLocation(GetActorLocation() + FVector(-BlockSize, -BlockSize, 0.0f));
		break;
	case 2:
		SetActorLocation(GetActorLocation() + FVector(BlockSize, -BlockSize , 0.0f));
		break;
	case 3:
		SetActorLocation(GetActorLocation() + FVector(BlockSize , BlockSize, 0.0f));
		break;
	case 0:
		SetActorLocation(GetActorLocation() + FVector(-BlockSize, BlockSize, 0.0f));
		break;
	default:
		break;
	}

}

