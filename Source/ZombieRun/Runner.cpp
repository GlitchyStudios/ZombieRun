 // Fill out your copyright notice in the Description page of Project Settings.

#include "ZombieRun.h"
#include "Runner.h"
#include "Kismet/KismetMathLibrary.h"

// Contrictor Script (Sets default values)
ARunner::ARunner()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Event BeginPlay
void ARunner::BeginPlay()
{
	Super::BeginPlay();
	
}

// My Super-Awesome Tick Function
void ARunner::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	AddMovementInput(GetActorForwardVector(), 1.0f); //Auto run the player, yo
	Turn(DeltaTime);//Super fucking broken turn function (see bottom)
}

// Apparently, I need this to bind functionality to input
void ARunner::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

//Hella broken (not anymoar!!!!)
void ARunner::Turn(float delta) {
	if (UKismetMathLibrary::NotEqual_RotatorRotator(turnRotation, GetControlRotation())) {
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetControlRotation(UKismetMathLibrary::RInterpTo(GetControlRotation(), turnRotation, delta, 8.0f));
	}
}