// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Block.generated.h"

//ö����ͼ�࣬��ʾ��������
UENUM(BlueprintType)
enum class EBlockType: uint8
{
	NONE,
	TBLOCK,
	IBLOCK,
	OBLOCK,
	LBLOCK,
	JBLOCK,
	SBLOCK,
	ZBLOCK
};

//�ṹ�壬��ʾ����
USTRUCT(BlueprintType)
struct FPoint
{
	GENERATED_BODY()

	//Ĭ�ϳ�ʼ��Ϊ0
	FPoint() :X(0), Y(0) {};

	//X������
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int X;

	//Y������
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int Y;
};

//ש����
UCLASS()
class TETRIS_UE_API ABlock : public AActor
{
	GENERATED_BODY()
	
public:	
	//Ĭ�Ϲ��캯��
	ABlock();

protected:
	
	UPROPERTY(EditAnywhere)
	int BlockSize = 60;

	//��ת�б�
	UPROPERTY(EditAnywhere)
	FRotator RotationList[4] =
	{
		FRotator(0.0f,0.0f,0.0f),
		FRotator(0.0f,90.0f,0.0f),
		FRotator(0.0f,180.0f,0.0f),
		FRotator(0.0f,270.0f,0.0f)
	};
	
	//��ǰ��ת����
	UPROPERTY(BlueprintReadWrite)
	int RotationIndex = 0;
	
	
	//��Ϸ��ʼ
	virtual void BeginPlay() override;

	//����ת
	virtual void Spin_L();
	
	//����ת
	virtual void Spin_R();

public:	
	//ÿִ֡��
	virtual void Tick(float DeltaTime) override;

	//����
	UPROPERTY(BlueprintReadWrite)
	FPoint Pos;

	//����
	UPROPERTY(EditAnywhere)
	EBlockType Type;

};
