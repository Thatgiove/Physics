// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "OverlappingActor.generated.h"

/**
 * 
 */
UCLASS()
class PHYSICS_API AOverlappingActor : public ATriggerBox
{
public:
	GENERATED_BODY()
		AOverlappingActor();
	
	UFUNCTION()
		void OnTriggerEnter(AActor* OverlappedActor, AActor* OtherActor);

	
	UFUNCTION()
		void OnTriggerExit(AActor* OverlappedActor, AActor* OtherActor);
	

protected:
	virtual void BeginPlay() override;
};
