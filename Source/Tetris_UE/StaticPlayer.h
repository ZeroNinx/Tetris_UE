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
	//���캯��
	AStaticPlayer();

protected:
	//��Ϸ��ʼ
	virtual void BeginPlay() override;

public:	
	//ÿִ֡��
	virtual void Tick(float DeltaTime) override;

	//�󶨽�ɫ����
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
