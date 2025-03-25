// Fill out your copyright notice in the Description page of Project Settings.

#include "GameAnimationSample/Public/Actors/LimitedBoxPawn.h"

#include "Components/BoxComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

ALimitedBoxPawn::ALimitedBoxPawn()
{
	PrimaryActorTick.bCanEverTick = true;
	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>("FloatingMovement");
}

void ALimitedBoxPawn::BeginPlay()
{
	Super::BeginPlay();
	
	const UBoxComponent* ConfinedBox = ConfinedVolume->FindComponentByClass<UBoxComponent>();

	//Because our box is static we can write his transforms
	BorderTransform = ConfinedBox->GetComponentTransform();
	BoxExtent = ConfinedBox->GetScaledBoxExtent();
}

void ALimitedBoxPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ClampVelocity();
}

void ALimitedBoxPawn::ClampVelocity()
{
	const FVector WorldLocation = GetActorLocation();
	
	//Getting current pawn position in box-local coordinates
	FVector LocalLocation = BorderTransform.InverseTransformPosition(WorldLocation);
	
	bool bOutOfBounds = false;
	
	// Check do we need correct the position to not move from border
	if (LocalLocation.X < -BoxExtent.X) { LocalLocation.X = -BoxExtent.X; bOutOfBounds = true; }
	if (LocalLocation.X > BoxExtent.X) { LocalLocation.X = BoxExtent.X; bOutOfBounds = true; }
	if (LocalLocation.Y < -BoxExtent.Y) { LocalLocation.Y = -BoxExtent.Y; bOutOfBounds = true; }
	if (LocalLocation.Y > BoxExtent.Y) { LocalLocation.Y = BoxExtent.Y; bOutOfBounds = true; }
	if (LocalLocation.Z < -BoxExtent.Z) { LocalLocation.Z = -BoxExtent.Z; bOutOfBounds = true; }
	if (LocalLocation.Z > BoxExtent.Z) { LocalLocation.Z = BoxExtent.Z; bOutOfBounds = true; }
	
	if (bOutOfBounds)
	{
		// Transform from box-local to world
		FVector CorrectedWorldLocation = BorderTransform.TransformPosition(LocalLocation);
		SetActorLocation(CorrectedWorldLocation);
	}
}

