// Fill out your copyright notice in the Description page of Project Settings.


#include "StaticPlayer.h"

//���캯��
AStaticPlayer::AStaticPlayer()
{
 	PrimaryActorTick.bCanEverTick = false;
	
	UCameraComponent* camera = CreateDefaultSubobject<UCameraComponent>("ViewCamera");
	camera->SetupAttachment(RootComponent);

}

//��Ϸ��ʼ
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

