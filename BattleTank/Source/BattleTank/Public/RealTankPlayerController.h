// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "RealTankPlayerController.generated.h" //Make sure this is last

/**
 * 
 */
UCLASS()
class BATTLETANK_API ARealTankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaTime) override;

	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;

	//start moving barreal towards crosshair
	void AimTowardsCrosshair();

private:
	//where the tank is aiming - using & reference to the fvector
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
};
