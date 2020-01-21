// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "FPSCollisionsCharacter.h"
#include "FPSCollisionsProjectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "CollisionSphereComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "MotionControllerComponent.h"
#include "XRMotionControllerBase.h" // for FXRMotionControllerBase::RightHandSourceId


#include "DrawDebugHelpers.h" ////

DEFINE_LOG_CATEGORY_STATIC(LogFPChar, Warning, All);

//////////////////////////////////////////////////////////////////////////
// AFPSCollisionsCharacter

AFPSCollisionsCharacter::AFPSCollisionsCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));

	// Create a gun mesh component
	FP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_Gun"));
	FP_Gun->SetOnlyOwnerSee(true);			// only the owning player will see this mesh
	FP_Gun->bCastDynamicShadow = false;
	FP_Gun->CastShadow = false;
	// FP_Gun->SetupAttachment(Mesh1P, TEXT("GripPoint"));
	FP_Gun->SetupAttachment(RootComponent);

	FP_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	FP_MuzzleLocation->SetupAttachment(FP_Gun);
	FP_MuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));

	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(100.0f, 0.0f, 10.0f);

	// Note: The ProjectileClass and the skeletal mesh/anim blueprints for Mesh1P, FP_Gun, and VR_Gun 
	// are set in the derived blueprint asset named MyCharacter to avoid direct content references in C++.

	//Week 3 ADD:
	CollisionSphere = CreateDefaultSubobject<UCollisionSphereComponent>("Collision Sphere");
	CollisionSphere->SetupAttachment(RootComponent);
}


void AFPSCollisionsCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Attach gun mesh component to Skeleton, doing it here because the skeleton is not yet created in the constructor
	FP_Gun->AttachToComponent(Mesh1P, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));	
	Mesh1P->SetHiddenInGame(false, true);


	//Week 3 ADD:
	CollisionSphere->SetNewCollisionParams(SphereCollisionParams);
}

//////////////////////////////////////////////////////////////////////////
// Input

void AFPSCollisionsCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	check(PlayerInputComponent);

	// Bind jump events
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	// Bind fire event
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AFPSCollisionsCharacter::OnFire);

	// Bind movement events
	PlayerInputComponent->BindAxis("MoveForward", this, &AFPSCollisionsCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFPSCollisionsCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AFPSCollisionsCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AFPSCollisionsCharacter::LookUpAtRate);
}


void AFPSCollisionsCharacter::OnFire()
{
	// try and fire a projectile
	if (ProjectileClass != NULL)
	{
		UWorld* const World = GetWorld();
		if (World != NULL)
		{
				const FRotator SpawnRotation = GetControlRotation();
				// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
				const FVector SpawnLocation = ((FP_MuzzleLocation != nullptr) ? FP_MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);

				//Set Spawn Collision Handling Override
				FActorSpawnParameters ActorSpawnParams;
				ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

				// spawn the projectile at the muzzle
				World->SpawnActor<AFPSCollisionsProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);

		}
	}

	// try and play the sound if specified
	if (FireSound != NULL)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}

	// try and play a firing animation if specified
	if (FireAnimation != NULL)
	{
		// Get the animation object for the arms mesh
		UAnimInstance* AnimInstance = Mesh1P->GetAnimInstance();
		if (AnimInstance != NULL)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}
}

void AFPSCollisionsCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AFPSCollisionsCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void AFPSCollisionsCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AFPSCollisionsCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

bool AFPSCollisionsCharacter::GetPickableActor_LineTraceTestByChannel(ECollisionChannel CollisionChannel)
{
	bool hit = false;
	if (Controller && Controller->IsLocalPlayerController()) // we check the controller becouse we dont want bots to grab the use object and we need a controller for the Getplayerviewpoint function
	{
		FVector StartTrace;
		FVector Direction;
		FVector EndTrace;
		//Call SetupRay() to set the Start end End Trace
		SetupRay(StartTrace, Direction, EndTrace);
		FCollisionQueryParams TraceParams;
		//Ignore this Actor
		TraceParams.AddIgnoredActor(this);
		TraceParams.bTraceComplex = true;
		TraceParams.bReturnPhysicalMaterial = true;

		FHitResult Hit(ForceInit);
		UWorld* World = GetWorld();
		hit = World->LineTraceTestByChannel(StartTrace, EndTrace, CollisionChannel, TraceParams); // simple trace function
		DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor::Green, true, 1, 0, 1.f);
		return hit;
	}

	return hit;
}

bool AFPSCollisionsCharacter::GetPickableActor_LineTraceTestByObjectType(EObjectTypeQuery ObjectType)
{
	bool hit = false;
	if (Controller && Controller->IsLocalPlayerController()) // we check the controller becouse we dont want bots to grab the use object and we need a controller for the Getplayerviewpoint function
	{
		FVector StartTrace;
		FVector Direction;
		FVector EndTrace;

		SetupRay(StartTrace, Direction, EndTrace);
		FCollisionQueryParams TraceParams;
		TraceParams.AddIgnoredActor(this);
		TraceParams.bTraceComplex = true;
		TraceParams.bReturnPhysicalMaterial = true;

		//Convert the EObjectTypeQuery to a byte
		TEnumAsByte<EObjectTypeQuery> ObjectToTrace = ObjectType;
		//Create a TArray of type TEnumAsByte<EObjectTypeQuery>
		TArray<TEnumAsByte<EObjectTypeQuery> > ObjectsToTraceAsByte;
		//Add the ObjectToTrace into the TArray, we can trace (look) for more than 1 ObjectType
		ObjectsToTraceAsByte.Add(ObjectToTrace);

		FHitResult Hit(ForceInit);
		UWorld* World = GetWorld();
		hit = World->LineTraceTestByObjectType(StartTrace, EndTrace, FCollisionObjectQueryParams(ObjectsToTraceAsByte), TraceParams); // simple trace function
		DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor::Green, true, 1, 0, 1.f);
		return hit;
	}
	return hit;
}

bool AFPSCollisionsCharacter::GetPickableActor_LineTraceTestByProfile(FName ProfileName)
{
	bool hit = false;
	if (Controller && Controller->IsLocalPlayerController()) // we check the controller becouse we dont want bots to grab the use object and we need a controller for the Getplayerviewpoint function
	{
		FVector StartTrace;
		FVector Direction;
		FVector EndTrace;

		SetupRay(StartTrace, Direction, EndTrace);
		FCollisionQueryParams TraceParams;
		TraceParams.AddIgnoredActor(this);
		TraceParams.bTraceComplex = true;
		TraceParams.bReturnPhysicalMaterial = true;

		FHitResult Hit(ForceInit);
		UWorld* World = GetWorld();
		hit = World->LineTraceTestByProfile(StartTrace, EndTrace, ProfileName, TraceParams); // simple trace function
		DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor::Green, true, 1, 0, 1.f);
		return hit;
	}

	return hit;
}

AActor * AFPSCollisionsCharacter::GetPickableActor_LineTraceSingleByChannel(ECollisionChannel CollisionChannel)
{
	if (Controller && Controller->IsLocalPlayerController()) // we check the controller because we don't want bots to grab the use object and we need a controller for the GetPlayerViewpoint function
	{

		FVector StartTrace;
		FVector Direction;
		FVector EndTrace;

		SetupRay(StartTrace, Direction, EndTrace);

		FCollisionQueryParams TraceParams;
		TraceParams.AddIgnoredActor(this);
		TraceParams.bTraceComplex = true;
		TraceParams.bReturnPhysicalMaterial = true;

		FHitResult Hit(ForceInit);
		UWorld* World = GetWorld();
		World->LineTraceSingleByChannel(Hit, StartTrace, EndTrace, CollisionChannel, TraceParams); // simple trace function  ECC_PhysicsBody
		DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor::Green, true, 1, 0, 1.f);
		return Hit.GetActor();
	}

	return nullptr;
}

AActor * AFPSCollisionsCharacter::GetPickableActor_LineTraceSingleByObjectType(EObjectTypeQuery ObjectType)
{
	if (Controller && Controller->IsLocalPlayerController()) // we check the controller because we dont want bots to grab the use object and we need a controller for the Getplayerviewpoint function
	{
		FVector StartTrace;
		FVector Direction;
		FVector EndTrace;


		SetupRay(StartTrace, Direction, EndTrace);

		FCollisionQueryParams TraceParams;
		TraceParams.AddIgnoredActor(this);
		TraceParams.bTraceComplex = true;
		TraceParams.bReturnPhysicalMaterial = true;

		FHitResult Hit(ForceInit);
		UWorld* World = GetWorld(); //FCollisionObjectQueryParams(EObjectTypeQuery::ObjectTypeQuery1)
		//need to convert the enum to a Byte
		TEnumAsByte<EObjectTypeQuery> ObjectToTrace = ObjectType;
		TArray<TEnumAsByte<EObjectTypeQuery> > ObjectsToTraceAsByte;
		ObjectsToTraceAsByte.Add(ObjectToTrace);

		World->LineTraceSingleByObjectType(Hit, StartTrace, EndTrace, FCollisionObjectQueryParams(ObjectsToTraceAsByte), TraceParams); // simple trace function  ObjectTypeQuery1
		DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor::Green, false, -1.0f, 0, 1.f);
		return Hit.GetActor();
	}

	return nullptr;
}

AActor * AFPSCollisionsCharacter::GetPickableActor_LineTraceSingleByTraceType(ETraceTypeQuery TraceType)
{
	if (Controller && Controller->IsLocalPlayerController()) // we check the controller because we dont want bots to grab the use object and we need a controller for the Getplayerviewpoint function
	{
		FVector StartTrace;
		FVector Direction;
		FVector EndTrace;


		SetupRay(StartTrace, Direction, EndTrace);

		FCollisionQueryParams TraceParams;
		TraceParams.AddIgnoredActor(this);
		TraceParams.bTraceComplex = true;
		TraceParams.bReturnPhysicalMaterial = true;

		FHitResult Hit(ForceInit);
		UWorld* World = GetWorld();

		//need to convert the enum to a Byte
		TEnumAsByte<ETraceTypeQuery> ObjectToTrace = TraceType;
		TArray<TEnumAsByte<ETraceTypeQuery> > ObjectsToTraceAsByte;
		ObjectsToTraceAsByte.Add(ObjectToTrace);

		World->LineTraceSingleByObjectType(Hit, StartTrace, EndTrace, FCollisionObjectQueryParams(TraceType), TraceParams); // simple trace function  ObjectTypeQuery1
		DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor::Green, false, -1.0f, 0, 1.f);
		return Hit.GetActor();
	}

	return nullptr;
}

AActor * AFPSCollisionsCharacter::GetPickableActor_LineTraceSingleByProfile(FName ProfileName)
{
	if (Controller && Controller->IsLocalPlayerController()) // we check the controller because we dont want bots to grab the use object and we need a controller for the Getplayerviewpoint function
	{
		FVector StartTrace;
		FVector Direction;
		FVector EndTrace;

		SetupRay(StartTrace, Direction, EndTrace);
		FCollisionQueryParams TraceParams;
		TraceParams.AddIgnoredActor(this);
		TraceParams.bTraceComplex = true;
		TraceParams.bReturnPhysicalMaterial = true;

		FHitResult Hit(ForceInit);
		UWorld* World = GetWorld();
		World->LineTraceSingleByProfile(Hit, StartTrace, EndTrace, ProfileName, TraceParams); // simple trace function
		DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor::Green, true, 1, 0, 1.f);
		return Hit.GetActor();
	}

	return nullptr;
}

TArray<FHitResult> AFPSCollisionsCharacter::GetPickableActor_LineTraceMultiByChannel(ECollisionChannel CollisionChannel)
{
	TArray<FHitResult> OutHits;
	if (Controller && Controller->IsLocalPlayerController()) // we check the controller because we dont want bots to grab the use object and we need a controller for the Getplayerviewpoint function
	{
		FVector StartTrace;
		FVector Direction;
		FVector EndTrace;

		SetupRay(StartTrace, Direction, EndTrace);
		FCollisionQueryParams TraceParams;
		TraceParams.AddIgnoredActor(this);
		TraceParams.bTraceComplex = true;
		TraceParams.bReturnPhysicalMaterial = true;

		UWorld* World = GetWorld();
		World->LineTraceMultiByChannel(OutHits, StartTrace, EndTrace, CollisionChannel, TraceParams); // simple trace function 
		DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor::Green, true, 1, 0, 1.f);

	}

	return OutHits;
}

TArray<FHitResult> AFPSCollisionsCharacter::GetPickableActor_LineTraceMultiByObjectType(EObjectTypeQuery ObjectType)
{
	TArray<FHitResult> OutHits;
	if (Controller && Controller->IsLocalPlayerController()) // we check the controller because we dont want bots to grab the use object and we need a controller for the Getplayerviewpoint function
	{
		FVector StartTrace;
		FVector Direction;
		FVector EndTrace;

		SetupRay(StartTrace, Direction, EndTrace);
		FCollisionQueryParams TraceParams;
		TraceParams.AddIgnoredActor(this);
		TraceParams.bTraceComplex = true;
		TraceParams.bReturnPhysicalMaterial = true;

		TEnumAsByte<EObjectTypeQuery> ObjectToTrace = ObjectType;
		TArray<TEnumAsByte<EObjectTypeQuery> > ObjectsToTraceAsByte;
		ObjectsToTraceAsByte.Add(ObjectToTrace);

		UWorld* World = GetWorld();
		World->LineTraceMultiByObjectType(OutHits, StartTrace, EndTrace, FCollisionObjectQueryParams(ObjectsToTraceAsByte), TraceParams); // simple trace function ObjectTypeQuery1
		DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor::Green, true, 1, 0, 1.f);

	}

	return OutHits;
}

TArray<FHitResult> AFPSCollisionsCharacter::GetPickableActor_LineTraceMultiByProfile(FName ProfileName)
{
	TArray<FHitResult> OutHits;
	if (Controller && Controller->IsLocalPlayerController()) // we check the controller because we dont want bots to grab the use object and we need a controller for the Getplayerviewpoint function
	{
		FVector StartTrace;
		FVector Direction;
		FVector EndTrace;

		SetupRay(StartTrace, Direction, EndTrace);
		FCollisionQueryParams TraceParams;
		TraceParams.AddIgnoredActor(this);
		TraceParams.bTraceComplex = true;
		TraceParams.bReturnPhysicalMaterial = true;

		UWorld* World = GetWorld();
		World->LineTraceMultiByProfile(OutHits, StartTrace, EndTrace, ProfileName, TraceParams); // simple trace function "Pawn"
		DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor::Green, true, 1, 0, 1.f);
		// return OutHits;
	}

	return OutHits;
}

void AFPSCollisionsCharacter::SetupRay(FVector & StartTrace, FVector & Direction, FVector & EndTrace)
{
	FVector CamLoc;
	FRotator CamRot;

	Controller->GetPlayerViewPoint(CamLoc, CamRot); // Get the camera position and rotation
	CamLoc = GetActorLocation();

	StartTrace = CamLoc; // trace start is the camera location
	Direction = CamRot.Vector();
	EndTrace = StartTrace + Direction * 300; // and trace end is the camera location + an offset in the direction you are looking, the 300 is the distance at which it checks 
}

void AFPSCollisionsCharacter::EnableCollisionSphere(bool enable)
{
	if (!enable)
	{
		CollisionSphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		CollisionSphere->SetHiddenInGame(true);
	}
	else
	{
		CollisionSphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		CollisionSphere->SetHiddenInGame(false);
	}
}

//Week 3 ADD:


void AFPSCollisionsCharacter::PostEditChangeProperty(FPropertyChangedEvent & e)
{
	FName PropertyName = (e.Property != NULL) ? e.Property->GetFName() : NAME_None;

	if (PropertyName == GET_MEMBER_NAME_CHECKED(FCollisonParams, CollisionEnabled))
	{
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, "Property - SphereCollisionParams.CollisionEnabled ");

	}

	if (PropertyName == GET_MEMBER_NAME_CHECKED(FCollisonParams, CollisionResponseNew))
	{
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, "Property - SphereCollisionParams.CollisionResponseNew ");

	}

	if (PropertyName == GET_MEMBER_NAME_CHECKED(FCollisonParams, CollisionChannel))
	{
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, "Property - SphereCollisionParams.CollisionChannel ");

	}

	if (PropertyName == GET_MEMBER_NAME_CHECKED(FCollisonParams, ProfileName))
	{
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, "Property - SphereCollisionParams.ProfileName ");

	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (PropertyName == GET_MEMBER_NAME_CHECKED(FTraceParams, CollisionChannel))
	{
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, "Property - FTraceParams.CollisionChannel ");
	}

	if (PropertyName == GET_MEMBER_NAME_CHECKED(FTraceParams, ObjectType))
	{
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, "Property - FTraceParams.ObjectType ");

	}

	if (PropertyName == GET_MEMBER_NAME_CHECKED(FTraceParams, TraceType))
	{
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, "Property - FTraceParams.TraceType ");

	}

	if (PropertyName == GET_MEMBER_NAME_CHECKED(FTraceParams, ProfileName))
	{
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, "Property - FTraceParams.ProfileName ");

	}

	CollisionSphere->SetNewCollisionParams(SphereCollisionParams);


}

void AFPSCollisionsCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//Week 3 ADD:
	AActor * HitActor = nullptr;
	switch (ETraceType)
	{
	case ETestTraceType::TTT_CollisionChannel:
	{
		HitActor = GetPickableActor_LineTraceSingleByChannel(TraceCollisionParams.CollisionChannel);
		break;
	}
	case ETestTraceType::TTT_ObjectType:
	{
		HitActor = GetPickableActor_LineTraceSingleByObjectType(TraceCollisionParams.ObjectType);
		break;
	}
	case ETestTraceType::TTT_TraceType:
	{
		HitActor = GetPickableActor_LineTraceSingleByTraceType(TraceCollisionParams.TraceType);
		break;
	}
	case ETestTraceType::TTT_ProfileName:
	{
		HitActor = GetPickableActor_LineTraceSingleByProfile(TraceCollisionParams.ProfileName);
		break;
	}
	}
	if (HitActor)
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, "Hit - " + HitActor->GetActorLabel());
	//ADD Two more switch statements to test the other two flavors of Trace functions

}

//Week 3:
