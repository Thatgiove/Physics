// Fill out your copyright notice in the Description page of Project Settings.
/*Performing the Raycast
In order to perform the raycast seen in the first image, we need the following variables:

A collection to store all the possible hit results
The start location of the trace, which is going to be the actor’s location)
The end location of the trace, which is going to be calculated based on the actor’s location)
An FQuat which is a way to represent a rotation in a 3D space)
The collision channel, which contains information about what we want to trace (ie pawns only, static objects, etc…)
The shape we want to trace (in this post: a sphere)
The logic which involes the trace is actually straight forward:
 *
 */

#include "SweepActor.h"
#include "CollisionShape.h"
#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"
#include "Engine/World.h"

// Sets default values
ASweepActor::ASweepActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASweepActor::BeginPlay()
{
	Super::BeginPlay();
	/*TArray is the collection that contains all the HitResults*/
	TArray<FHitResult> HitResults;

	/*The Start location of the sphere*/
	FVector StartLocation = GetActorLocation();

	/*The End location of the sphere is equal to the default location of the actor
	 *plus the height we will enter from the editor
	 *To extend this functionality, you can replace the height variable with a FVector*/
	FVector EndLocation = GetActorLocation();
	EndLocation.Z += SphereHeight;

	/*Search for static objects only*/
	ECollisionChannel ECC = ECollisionChannel::ECC_WorldStatic;
	
	/*Declare the Collision Shape, assign a Sphere shape and set it's radius*/
	FCollisionShape CollisionShape;
	CollisionShape.ShapeType = ECollisionShape::Sphere;
	CollisionShape.SetSphere(SphereRadius);
	/*Perform the actual raycast. This method returns true if there is at least 1 hit.*/
	bool bHitSomething = GetWorld()->SweepMultiByChannel(HitResults, StartLocation, EndLocation, FQuat::FQuat(), ECC, CollisionShape);

	/*If the raycast hit a number of objects, iterate through them and print their name in the console*/
	if (bHitSomething)
	{
		for (auto It = HitResults.CreateIterator(); It; It++)
		{
			/*GLog->Log((*It).Actor->GetName());*/
			GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Red, (*It).Actor->GetName());
		}
	}
	/*In order to draw the sphere of the first image, I will use the DrawDebugSphere function which resides in the DrawDebugHelpers.h
   This function needs the center of the sphere which in this case is provided by the following equation*/
	FVector CenterOfSphere = ((EndLocation - StartLocation) / 2) + StartLocation;

	/*Draw the sphere in the viewport*/
	DrawDebugSphere(GetWorld(), CenterOfSphere, CollisionShape.GetSphereRadius(), Segments, FColor::Green, true);
}

// Called every frame
void ASweepActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

