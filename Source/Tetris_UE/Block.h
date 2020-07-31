// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/StaticMeshComponent.h>
#include "Block.generated.h"

//ö����ͼ�࣬��ʾ��������
UENUM(BlueprintType)
enum class EBlockType : uint8
{
	NONE = 0,
	TBLOCK = 1,
	IBLOCK = 2,
	OBLOCK = 3,
	LBLOCK = 4,
	JBLOCK = 5,
	SBLOCK = 6,
	ZBLOCK = 7
};

//�ṹ�壬��ʾ����
USTRUCT(BlueprintType)
struct FPoint
{
	GENERATED_BODY()

	//Ĭ�ϳ�ʼ��Ϊ0
	FPoint() :X(0), Y(0) {};

	//���캯��
	FPoint(int x,int y) :X(x), Y(y) {};

	FPoint operator+(const FPoint& b)
	{
		FPoint fp;
		fp.X = this->X + b.X;
		fp.Y = this->Y + b.Y;
		return fp;
	}

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

	//�����С
	UPROPERTY(EditAnywhere)
	int BlockSize = 60;

	//����
	UPROPERTY(BlueprintReadOnly)
	FPoint Pos;

	//��������
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	EBlockType Type=EBlockType::NONE;

	//��ǰ��ת����
	int RotationIndex = 0;

	//��ת�б�
	FRotator RotationList[4] =
	{
		FRotator(0.0f,0.0f,0.0f),
		FRotator(0.0f,90.0f,0.0f),
		FRotator(0.0f,180.0f,0.0f),
		FRotator(0.0f,270.0f,0.0f)
	};

	//�����б�
	TArray<TArray<FPoint>> PosList;

	//��������б�
	TArray<UStaticMeshComponent*> MeshList;

	//��Ϸ��ʼ
	virtual void BeginPlay() override;

	//����ת
	UFUNCTION(BlueprintCallable)
	virtual void Spin_L();
	
	//����ת
	UFUNCTION(BlueprintCallable)
	virtual void Spin_R();

public:	

	//ÿִ֡��
	virtual void Tick(float DeltaTime) override;

	//��ȡ��ת����
	UFUNCTION(BlueprintCallable)
	int GetRotationIndex();

	//�趨����
	UFUNCTION(BlueprintCallable)
	void SetPos(FPoint NewPos);

	//��ȡ�����б�
	UFUNCTION(BlueprintCallable)
	virtual TArray<FPoint> GetPosList();

	//��ȡ���������б�
	UFUNCTION(BlueprintCallable)
	virtual TArray<FPoint> GetPosListL();

	//��ȡ���������б�
	UFUNCTION(BlueprintCallable)
	virtual TArray<FPoint> GetPosListR();

	//�趨�������
	UFUNCTION(BlueprintCallable)
	void SetBlockMaterial(UMaterialInterface* material);
};
