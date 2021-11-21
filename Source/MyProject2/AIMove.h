// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehicleMovementComponent.h"
#include "AIMove.generated.h"


USTRUCT()
struct FPIDController
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, Category = "PID")
		float Proportional;

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

	FPIDController() {}

	FPIDController(float P, float I, float D, float ErrorMin, float ErrorMax)
	{
		Proportional = P;
		Integral = I;
		Derivative = D;
		this->ErrorMin = ErrorMin;
		this->ErrorMax = ErrorMax;
	}

	float CalcNewInput(float Error, float Pos);

};

/**
 * 
 */
UCLASS()
class MYPROJECT2_API UAIMove : public UWheeledVehicleMovementComponent
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, Category = "PID")
		FPIDController ThrottleController = FPIDController(0.f, 0.f, 0.f, 0.f, 0.f);

		UPROPERTY(EditAnywhere, Category = "PID")
		FPIDController SteeringController = FPIDController(0, 0, 0, 0, 0);

		FVector InitialLocation;
		FVector InitialDirection;
		bool turningAround = false;

public:

	virtual void RequestDirectMove(const FVector& MoveVelocity, bool ForceMaxSpeed) override;
	virtual void StopActiveMovement() override;

	
};
