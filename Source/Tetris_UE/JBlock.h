// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Block.h"
#include "JBlock.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_UE_API AJBlock : public ABlock
{
	GENERATED_BODY()

protected:
	//×óÐý
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Spin_L() override;
	
	//ÓÒÐý
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Spin_R() override;

};
