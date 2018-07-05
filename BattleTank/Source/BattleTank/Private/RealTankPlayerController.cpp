// Fill out your copyright notice in the Description page of Project Settings.
#include "RealTankPlayerController.h"
#include "BattleTank.h"

ATank* ARealTankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


