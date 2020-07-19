// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Block.h"
#include "IBlock.generated.h"

/**
 * I����
 */
UCLASS()
class TETRIS_UE_API AIBlock : public ABlock
{
	GENERATED_BODY()

public:
	AIBlock();

protected:

	void Spin_L() override;

	void Spin_R() override;

	TArray<FPoint> GetPosList() override;
	TArray<FPoint> GetPosListL() override;
	TArray<FPoint> GetPosListR() override;
};
