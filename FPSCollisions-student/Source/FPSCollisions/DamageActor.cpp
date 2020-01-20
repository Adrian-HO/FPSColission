// Fill out your copyright notice in the Description page of Project Settings.

#include "DamageActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"

// Sets default values
ADamageActor::ADamageActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    ActorRoot = CreateDefaultSubobject<USceneComponent>("Actor Root");
    RootComponent = ActorRoot;

    MeshHead = CreateDefaultSubobject<UStaticMeshComponent>("Head Mesh");
    MeshHead->SetCollisionProfileName("BlockAllDynamic");
    MeshHead->SetNotifyRigidBodyCollision(true);
    MeshHead->SetupAttachment(RootComponent);

    MeshBody = CreateDefaultSubobject<UStaticMeshComponent>("Head Body");
    MeshBody->SetCollisionProfileName("BlockAllDynamic");
    MeshBody->SetNotifyRigidBodyCollision(true);
    MeshBody->SetupAttachment(RootComponent);

	SetCanBeDamaged(true);
    // Subscribe to the delegate in the attached actor.
    OnTakeAnyDamage.AddDynamic(this, &ADamageActor::TakeAnyDamage);
}

// Called when the game starts or when spawned
void ADamageActor::BeginPlay()
{
	Super::BeginPlay();	
}

void ADamageActor::TakeAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
    GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, "Damage Received - " + FString::FromInt(Damage));
}

// Called every frame
void ADamageActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

