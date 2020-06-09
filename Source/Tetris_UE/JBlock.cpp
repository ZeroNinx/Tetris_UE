// Fill out your copyright notice in the Description page of Project Settings.


#include "JBlock.h"

void AJBlock::Spin_L_Implementation()
{
	Super::Spin_L();

	//旋转时校正位置
	switch (RotationIndex)
	{
	case 0:
		SetActorLocation(GetActorLocation() + FVector(BlockSize, 0.0f, 0.0f));
		break;
	case 1:
		SetActorLocation(GetActorLocation() + FVector(0.0f, BlockSize * 2, 0.0f));
		break;
	case 2:
		SetActorLocation(GetActorLocation() + FVector(-BlockSize * 2, 0.0f, 0.0f));
		break;
	case 3:
		SetActorLocation(GetActorLocation() + FVector(BlockSize, -BlockSize * 2, 0.0f));
		break;
	default:
		break;
	}

}

void AJBlock::Spin_R_Implementation()
{
	Super::Spin_R();

	//旋转时校正位置
	switch (RotationIndex)
	{
	case 1:
		SetActorLocation(GetActorLocation() + FVector(-BlockSize, 0.0f, 0.0f));
		break;
	case 2:
		SetActorLocation(GetActorLocation() + FVector(0.0f, -BlockSize * 2, 0.0f));
		break;
	case 3:
		SetActorLocation(GetActorLocation() + FVector(BlockSize * 2, 0.0f, 0.0f));
		break;
	case 0:
		SetActorLocation(GetActorLocation() + FVector(-BlockSize, BlockSize * 2, 0.0f));
		break;
	default:
		break;
	}
	
}
