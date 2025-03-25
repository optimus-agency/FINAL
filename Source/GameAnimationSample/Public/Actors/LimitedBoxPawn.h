// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "LimitedBoxPawn.generated.h"

class UBoxComponent;
class UFloatingPawnMovement;

UCLASS()
class GAMEANIMATIONSAMPLE_API ALimitedBoxPawn : public APawn
{
	GENERATED_BODY()

public:
	ALimitedBoxPawn();
	
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	UFloatingPawnMovement* FloatingMovement;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	AActor* ConfinedVolume;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FVector MoveVector;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	float ZoomSpeed = 500.f;
	
private:
	void ClampVelocity();
	
	FTransform BorderTransform;;
	FVector BoxExtent;
};
