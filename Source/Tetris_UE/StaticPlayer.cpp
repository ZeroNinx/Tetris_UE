// Fill out your copyright notice in the Description page of Project Settings.


#include "StaticPlayer.h"

//构造函数
AStaticPlayer::AStaticPlayer()
{
 	PrimaryActorTick.bCanEverTick = false;
	
	UCameraComponent* camera = CreateDefaultSubobject<UCameraComponent>("ViewCamera");
	camera->SetupAttachment(RootComponent);

}

//游戏开始
void AStaticPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStaticPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AStaticPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

