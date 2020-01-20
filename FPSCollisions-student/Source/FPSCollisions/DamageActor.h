// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DamageActor.generated.h"

UCLASS()
class FPSCOLLISIONS_API ADamageActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADamageActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UFUNCTION()
        void TakeAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "DamageMesh")
        class USceneComponent* ActorRoot;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "DamageMesh")
        class UStaticMeshComponent* MeshHead;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "DamageMesh")
        class UStaticMeshComponent* MeshBody;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
