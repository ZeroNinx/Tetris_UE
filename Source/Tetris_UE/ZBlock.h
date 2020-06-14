// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Block.h"
#include "ZBlock.generated.h"

/**
 * Z·½¿é
 */
UCLASS()
class TETRIS_UE_API AZBlock : public ABlock
{
	GENERATED_BODY()
	
public:
	AZBlock();

protected:

	void Spin_L() override;

	void Spin_R() override;

	TArray<FPoint> GetPosList() override;
};
