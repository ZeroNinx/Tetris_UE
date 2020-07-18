// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include <Camera/CameraComponent.h>

#include "StaticPlayer.generated.h"


UCLASS()
class TETRIS_UE_API AStaticPlayer : public APawn
{
	GENERATED_BODY()

public:
	//构造函数
	AStaticPlayer();

protected:
	//游戏开始
	virtual void BeginPlay() override;

public:	
	//每帧执行
	virtual void Tick(float DeltaTime) override;

	//绑定角色输入
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
