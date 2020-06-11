// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Block.h"
#include "IBlock.generated.h"

/**
 * I·½¿é
 */
UCLASS()
class TETRIS_UE_API AIBlock : public ABlock
{
	GENERATED_BODY()

public:
	AIBlock();

protected:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Spin_L() override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Spin_R() override;

	UFUNCTION(BlueprintCallable)
	TArray<FPoint> GetPosList() override;
};
