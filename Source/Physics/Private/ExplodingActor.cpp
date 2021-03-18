// Fill out your copyright notice in the Description page of Project Settings.


#include "ExplodingActor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AExplodingActor::AExplodingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AExplodingActor::BeginPlay()
{
	Super::BeginPlay();
    //Get all the nearby actors
    for (auto It = NearbyActors.CreateIterator(); It; It++)
    {
        //Get the static mesh component for each actor
        UStaticMeshComponent* SM = Cast<UStaticMeshComponent>((*It)->GetRootComponent());

        /*If the component is valid, apply a radial impulse from the location of the "Bomb" Actor
        having as Radius and Strength the values from the Editor.
        The RIF_Linear impulse fall off parameter means that we want the impulse to fall off to zero when
        the max distance is reached.
        The last parameter means that we want to ignore the mass of each Static Mesh*/

        if (SM)
        {
            SM->AddRadialImpulse(GetActorLocation(), Radius, Strength, ERadialImpulseFalloff::RIF_Constant, true);
        }
    }
}

// Called every frame
void AExplodingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

