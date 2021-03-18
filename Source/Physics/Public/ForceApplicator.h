// Fill out your copyright notice in the Description page of Project Settings.

/*Sometimes, we need to apply a force to an Actor. The force we apply is like a “thruster”.
 *It’s good for adding a burst over some (non zero) time and it should be called every frame
 *for the duration of the force. In order to apply a force you need a Primitive Component.

In this tutorial however, I won’t apply the force over some time but instead I’m going to apply
it once for demonstration purposes. I’m going to choose an Actor from my Viewport and by pressing
a button, I will apply a force so I can make it go a little higher.

In this tutorial, I’m going to use a FirstPerson C++ Template. To avoid creating a keybind in C++
I will create a function that is going to apply the force and call it from Blueprint, just for prototyping
purposes. In order to apply a force to an Actor, we need the direction of the force and of course the corresponding
Actor.Open up the header file of your C++ Character and add in the following variables and function:

  */
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ForceApplicator.generated.h"

UCLASS()
class PHYSICS_API AForceApplicator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AForceApplicator();

	/*The Actor which will be selected from the Viewport*/
	UPROPERTY(EditAnywhere, Category = "Physics")
		AActor* ActorToMove;
	
	/*The Force that we're going to apply to the chosen Actor with a default value*/
	UPROPERTY(EditAnywhere, Category = "Physics")
		FVector ForceToAdd = FVector(5000, 0, 0);
	
	/*The function that applies the above force to the chosen Actor*/
	UFUNCTION(BlueprintCallable, Category = "Physics")
		void ApplyForce();

	/*The function that applies the above impulse to the chosen Actor*/
	UFUNCTION(BlueprintCallable, Category = "Physics")
		void ApplyInpulse();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
