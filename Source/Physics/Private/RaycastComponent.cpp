// Fill out your copyright notice in the Description page of Project Settings.


#include "RaycastComponent.h"
#include "CollisionQueryParams.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"

// Sets default values for this component's properties
URaycastComponent::URaycastComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URaycastComponent::BeginPlay()
{
	Super::BeginPlay();
	// ...
}


// Called every frame
void URaycastComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Hit contains information about what the raycast hit.
	FHitResult Hit;

	//The length of the ray in units.
	//For more flexibility you can expose a public variable in the editor
	float RayLength = 500;
	AActor* Owner = GetOwner();
	
	if(Owner != nullptr)
	{
		//The Origin of the raycast
		//FVector StartLocation = FirstPersonCameraComponent->GetComponentLocation();
		FVector StartLocation = Owner->GetActorLocation();
		
		//The EndLocation of the raycast
		//FVector EndLocation = StartLocation + (FirstPersonCameraComponent->GetForwardVector() * RayLength);
		FVector EndLocation = StartLocation + (Owner->GetActorForwardVector() * RayLength);

		//Collision parameters. The following syntax means that we don't want the trace to be complex
		FCollisionQueryParams CollisionParameters;
		//Perform the line trace

		//The ECollisionChannel parameter is used in order to determine what we are looking for when performing the raycast
		//ActorLineTraceSingle(Hit, StartLocation, EndLocation, ECollisionChannel::ECC_WorldDynamic, CollisionParameters);
		//call GetWorld() from within an actor extending class
		GetWorld()->LineTraceSingleByChannel(
			Hit,        //result
			StartLocation,    //start
			EndLocation, //end
			ECC_Pawn, //collision channel
			CollisionParameters
		);
		//DrawDebugLine is used in order to see the raycast we performed
		//The boolean parameter used here means that we want the lines to be persistent so we can see the actual raycast
		//The last parameter is the width of the lines.
		DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Green, true, -1, 0, 1.f);
	}
	

	


}

