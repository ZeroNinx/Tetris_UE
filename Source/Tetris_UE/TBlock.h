// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Block.h"
#include "TBlock.generated.h"

/**
 * T·½¿é
 */
UCLASS()
class TETRIS_UE_API ATBlock : public ABlock
{
	GENERATED_BODY()

public:
	ATBlock();

protected:

	void Spin_L() override;

	void Spin_R() override;

	TArray<FPoint> GetPosList() override;
};
