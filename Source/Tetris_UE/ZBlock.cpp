// Fill out your copyright notice in the Description page of Project Settings.


#include "ZBlock.h"

void AZBlock::Spin_L_Implementation()
{
	Super::Spin_L();

	//位移校准
	switch (RotationIndex)
	{
	case 3:
		SetActorRelativeLocation(GetActorLocation() + FVector(-BlockSize, BlockSize, 0.0f));
		break;
	case 2:
		SetActorRelativeLocation(GetActorLocation() + FVector(BlockSize, BlockSize, 0.0f));
		break;
	case 1:
		SetActorRelativeLocation(GetActorLocation() + FVector(BlockSize, -BlockSize, 0.0f));
		break;
	case 0:
		SetActorRelativeLocation(GetActorLocation() + FVector(-BlockSize, -BlockSize, 0.0f));
		break;
	default:
		break;
	}
}

void AZBlock::Spin_R_Implementation()
{
	Super::Spin_R();
	//位移校准
	switch (RotationIndex)
	{
	case 1:
		SetActorRelativeLocation(GetActorLocation() + FVector(BlockSize, BlockSize, 0.0f));
		break;
	case 2:
		SetActorRelativeLocation(GetActorLocation() + FVector(-BlockSize, BlockSize, 0.0f));
		break;
	case 3:
		SetActorRelativeLocation(GetActorLocation() + FVector(-BlockSize, -BlockSize, 0.0f));
		break;
	case 0:
		SetActorRelativeLocation(GetActorLocation() + FVector(BlockSize, -BlockSize, 0.0f));
		break;
	default:
		break;
	}
}