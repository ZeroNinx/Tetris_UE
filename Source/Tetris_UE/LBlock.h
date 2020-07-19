// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Block.h"
#include "LBlock.generated.h"

/**
 * L����
 */
UCLASS()
class TETRIS_UE_API ALBlock : public ABlock
{
	GENERATED_BODY()

public:
	ALBlock();

protected:

	void Spin_L() override;

	void Spin_R() override;

	TArray<FPoint> GetPosList() override;
	TArray<FPoint> GetPosListL() override;
	TArray<FPoint> GetPosListR() override;
};
