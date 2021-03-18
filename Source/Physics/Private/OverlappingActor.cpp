// Fill out your copyright notice in the Description page of Project Settings.


#include "OverlappingActor.h"
#include "Components/BoxComponent.h"
#include "Components/ShapeComponent.h"
namespace
{
	static const FColor TriggerBaseColor(255, 0, 0, 255);
	static const FName TriggerCollisionProfileName(TEXT("Trigger"));
}
AOverlappingActor::AOverlappingActor()
{
	UBoxComponent* BoxCollisionComponent = Cast<UBoxComponent>(GetCollisionComponent());
	if(BoxCollisionComponent != nullptr)
	{
		BoxCollisionComponent->ShapeColor = TriggerBaseColor;
		BoxCollisionComponent->InitBoxExtent(FVector(80.0f, 80.0f, 80.0f));
	}
	//GetCollisionComponent()->ShapeColor = TriggerBaseColor;
	
}

void AOverlappingActor::BeginPlay()
{
	Super::BeginPlay();
	
	//Register the enter and exit overlaps to fire
	OnActorBeginOverlap.AddDynamic(this, &AOverlappingActor::OnTriggerEnter);
	OnActorEndOverlap.AddDynamic(this, &AOverlappingActor::OnTriggerExit);
}

void AOverlappingActor::OnTriggerEnter(AActor* OverlapedActor, AActor* OtherActor)
{
	GLog->Log("Begin overlap has fired");
}


void AOverlappingActor::OnTriggerExit(AActor* OverlapedActor, AActor* OtherActor)
{
	GLog->Log("End overlap has fired");
}