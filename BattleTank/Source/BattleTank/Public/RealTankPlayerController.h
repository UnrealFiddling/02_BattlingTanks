// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
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

	virtual void BeginPlay() override;

private:
	ATank* GetControlledTank() const;
	//start moving barreal towards crosshair
	void AimTowardsCrosshair();
	//where the tank is aiming - using & reference to the fvector
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.3333;
};
