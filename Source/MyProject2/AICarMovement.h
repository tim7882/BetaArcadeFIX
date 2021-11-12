// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehicleMovementComponent4W.h"
#include "AICarMovement.generated.h"


USTRUCT()
struct PIDController
{
	GENERATED_BODY()


		UPROPERTY(editAnywhere, Catagory = "PID")
		float Proportinal;

		UPROPERTY(editAnywhere, Catagory = "PID")
		float Integral;

		UPROPERTY(editAnywhere, Catagory = "PID")
		float Derivative;

		UPROPERTY(editAnywhere, Catagory = "PID")
		float ErrorMin;

		UPROPERTY(editAnywhere, Catagory = "PID")
		float ErrorMax;

		float ErrorSum;
		float LastPos;

		PIDController() {}

		PIDController(float P, float I, float D, float ErrorMin, float ErrorMax)
		{
			Proportinal = P;
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
class MYPROJECT2_API UAICarMovement : public UWheeledVehicleMovementComponent4W
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, Category = "PID")
		PIDController ThrottleController = PIDController(0.f, 0.f, 0.f, 0.f, 0.f);

		UPROPERTY(EditAnywhere, Category = "PID")
		PIDController SteeringController = PIDController(0, 0, 0, 0, 0);

		FVector InitialLocation;
		FVector InitialDirection;
		bool turningAround = false;

public:

	virtual void RequestDirectMove(const FVector& MoveVelocity, bool ForceMaxSpeed) override;
	virtual void StopActiveMovement() override;

 	
};
