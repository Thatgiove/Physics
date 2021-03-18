// Fill out your copyright notice in the Description page of Project Settings.

#include "ForceApplicator.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AForceApplicator::AForceApplicator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AForceApplicator::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AForceApplicator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AForceApplicator::ApplyForce()
{
    //Get the static mesh of the chosen Actor
    UStaticMeshComponent* SM = Cast<UStaticMeshComponent>(ActorToMove->GetRootComponent());

    //If the static mesh is valid apply the given force
    if (SM)
    {
        /*When you want to apply a force you always need to multiply it's value by the
        mass of the object that the object is applied to. The "enable Physics" on SM should be set to ON*/
        SM->AddForce(ForceToAdd * SM->GetMass());
    }
    else GLog->Log("Root component is not a static mesh!");
}

void AForceApplicator::ApplyInpulse()
{
    //Get the static mesh of the chosen Actor
    UStaticMeshComponent* SM = Cast<UStaticMeshComponent>(ActorToMove->GetRootComponent());

    //If the static mesh is valid apply the given force
    if (SM)
    {
        /*When you want to apply an impulse you always need to multiply it's value by the
		mass of the object that the object is applied to.*/
        SM->AddImpulse(ForceToAdd * SM->GetMass());
    }
    else GLog->Log("Root component is not a static mesh!");
}

