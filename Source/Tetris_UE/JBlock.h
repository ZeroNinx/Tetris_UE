// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Block.h"
#include "JBlock.generated.h"

/**
 * J·½¿é
 */
UCLASS()
class TETRIS_UE_API AJBlock : public ABlock
{
	GENERATED_BODY()

public:
	AJBlock();

protected:

	void Spin_L() override;

	void Spin_R() override;

	TArray<FPoint> GetPosList() override;
	TArray<FPoint> GetPosListL() override;
	TArray<FPoint> GetPosListR() override;

};
