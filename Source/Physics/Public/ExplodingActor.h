// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExplodingActor.generated.h"

UCLASS()
class PHYSICS_API AExplodingActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AExplodingActor();

	/*Strength of the impulse*/
	UPROPERTY(EditAnywhere)
		float Strength;

	/*Radius of the impulse*/
	UPROPERTY(EditAnywhere)
		float Radius;

	/*A dynamic array of nearby actors
	 *In this case, I will manually place some Actors near my “Bomb” Actor – this technique is just for demonstration purposes.
	 *If you wanted to simulate a bomb you should perform a sphere sweep and then store all the hits into the TArray seen above
	 */
	UPROPERTY(EditAnywhere)
		TArray<AActor*> NearbyActors;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
