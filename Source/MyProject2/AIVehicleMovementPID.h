// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehicleMovementComponent4W.h"
#include "AIVehicleMovementPID.generated.h"


USTRUCT()
struct FPIDControl
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "PID")
		float Proportinal;

	UPROPERTY(EditAnywhere, Category = "PID")
		float Integral;

	UPROPERTY(EditAnywhere, Category = "PID")
		float Derivative;

	UPROPERTY(EditAnywhere, Category = "PID")
		float ErrorMin;

	UPROPERTY(EditAnywhere, Category = "PID")
		float ErrorMax;

	float ErrorSum;
	float LastPos;

	FPIDControl() {}

	FPIDControl(float P, float I, float D, float ErrorMin, float ErrorMax)
	{
		Proportinal = P;
		Integral = I;
		Derivative = D;
		this->ErrorMin = ErrorMin;
		this->ErrorMax = ErrorMax;
	}

	float CalcNewInput(float Error, float Pos);

	/**
	 *
	 */


};

