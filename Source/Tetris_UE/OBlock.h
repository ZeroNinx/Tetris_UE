// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Block.h"
#include "OBlock.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_UE_API AOBlock : public ABlock
{
	GENERATED_BODY()
	
protected:
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Spin_L() override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Spin_R() override;

};
