// Fill out your copyright notice in the Description page of Project Settings.
#include "RealTankPlayerController.h"
#include "BattleTank.h"

void ARealTankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName()));
	}

}

//called every frame
void ARealTankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();

	//UE_LOG(LogTemp, Warning, TEXT(" Player Controller Ticking"));
}

ATank* ARealTankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ARealTankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector OutHitLocation;
	if (GetSightRayHitLocation(OutHitLocation))//does raytracing
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *OutHitLocation.ToString());
		
		//if hits the landscape		//TODO tell controlled tank to aim here
	}
	
}

//get world location if line trace through crosshair
bool ARealTankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	//finding crosshair location
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	
	//"de-profect" the screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *LookDirection.ToString());
	}

	//line trace along look direction

	return true;
}

bool ARealTankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	
	FVector CameraWorldLocation; //To be discarded

	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection);
	
}