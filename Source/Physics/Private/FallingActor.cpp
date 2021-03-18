// Fill out your copyright notice in the Description page of Project Settings.


#include "FallingActor.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/Engine.h"

// Sets default values
AFallingActor::AFallingActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    //Initialize a StaticMeshComponent
    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));

    //Enable physics so the cube will fall
    StaticMesh->SetSimulatePhysics(true);
    
   

}

// Called when the game starts or when spawned
void AFallingActor::BeginPlay()
{
	Super::BeginPlay();
    //You only need to register the OnHit function
    StaticMesh->OnComponentHit.AddDynamic(this, &AFallingActor::OnHit);
   
}

void AFallingActor::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
    FVector NormalImpulse, const FHitResult& Hit)
{
    /*GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Green, "Hit");*/
    GLog->Log(*OtherActor->GetName());
}
/*quando l'attore è colpito da qualcosa*/
void AFallingActor::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
    Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
    /*GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Green, "ReceiveHit"); */
    GLog->Log(*Other->GetName());
}

// Called every frame
void AFallingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
   

}

