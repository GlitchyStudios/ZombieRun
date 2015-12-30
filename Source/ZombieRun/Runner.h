// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Runner.generated.h"

UCLASS()
class ZOMBIERUN_API ARunner : public ACharacter
{
	GENERATED_BODY()

public:
	// Contruction Script
	ARunner();

	// BeginPlay
	virtual void BeginPlay() override;
	
	// Tick
	virtual void Tick( float DeltaSeconds ) override;

	// Idek
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	
	//rotator for 'q' and 'e'
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "C++")
		FRotator turnRotation;

	//turn prototype
	UFUNCTION(BlueprintCallable, Category = "C++")
		void Turn(float delta);

protected:

}; 