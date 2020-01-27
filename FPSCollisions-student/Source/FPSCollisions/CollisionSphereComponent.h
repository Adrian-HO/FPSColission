// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "CollisionSphereComponent.generated.h"

USTRUCT(BlueprintType)
struct FCollisonParams
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
		TEnumAsByte<ECollisionEnabled::Type> CollisionEnabled; //Collision Enabled Flag

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
		TEnumAsByte <ECollisionResponse> CollisionResponseNew; //Collision Response Flag

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
		TEnumAsByte <ECollisionChannel> CollisionChannel; //Collision Channel Flag

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
		FName ProfileName; //Collision profile Name
};

USTRUCT(BlueprintType)
struct FTraceParams
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
		TEnumAsByte <ECollisionChannel> CollisionChannel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
		TEnumAsByte <EObjectTypeQuery> ObjectType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
		TEnumAsByte < ETraceTypeQuery> TraceType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
		FName ProfileName;


};


/**
 * 
 */
UCLASS()
class FPSCOLLISIONS_API UCollisionSphereComponent : public USphereComponent
{
	GENERATED_BODY()
	
public:
	UCollisionSphereComponent();

	virtual void OnRegister() override; //Called when the component gets registered with a Actor

	virtual void InitializeComponent() override; //Called when a comp[onent Initializes, similar to BeginPlay() in a Actor

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override; //The Components Tick Function

	//The Components Handle Overlap
	UFUNCTION()
		void HandleOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);

	UFUNCTION()
		void SetNewCollisionParams(struct FCollisonParams params);
};
