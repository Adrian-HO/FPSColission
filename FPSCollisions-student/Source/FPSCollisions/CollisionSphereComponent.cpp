// Fill out your copyright notice in the Description page of Project Settings.


#include "CollisionSphereComponent.h"
#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"

UCollisionSphereComponent::UCollisionSphereComponent()
{
	bWantsInitializeComponent = true;
}

void UCollisionSphereComponent::OnRegister()
{
	Super::OnRegister();
}

void UCollisionSphereComponent::InitializeComponent()
{
	Super::InitializeComponent();
	//SET the OverlapComponent radius.
	SetSphereRadius(200);
	//SET the OverlapComponent to be visible in Game
	SetHiddenInGame(false);
	//Subscribe to the OnComponentBeginOverlap event  of the OverlapComponent and pass a reference to the function HandleOverlap() to handle the event
	OnComponentBeginOverlap.AddDynamic(this,
		&UCollisionSphereComponent::HandleOverlap);
}

void UCollisionSphereComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	DrawDebugSphere(GetWorld(), GetOwner()->GetActorLocation(), this->GetScaledSphereRadius(), 12, FColor::Red, false, 10.0f);
}

void UCollisionSphereComponent::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool                                                      bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, "Collision Sphere - " + OtherActor->GetActorLabel());
}

void UCollisionSphereComponent::SetNewCollisionParams(FCollisonParams params)
{
	SetCollisionEnabled(params.CollisionEnabled);
	//SET the OverlapComponent's Collision to ignore all channels
	SetCollisionResponseToAllChannels(ECR_Ignore);
	//SET the OverlapComponents to respond to the Pawn channel and only Overlap events
	SetCollisionResponseToChannel(params.CollisionChannel, params.CollisionResponseNew);
	//SET the OverlapComponent radius.    
}