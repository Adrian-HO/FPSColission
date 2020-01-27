// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CollisionSphereComponent.h"
#include "FPSCollisionsCharacter.generated.h"


class UInputComponent;

//Enum used for what type of trace we will perform

UENUM(BlueprintType)
enum class ETestTraceType : uint8
{
	TTT_CollisionChannel 	UMETA(DisplayName = "Collision Channel"),
	TTT_ObjectType 	UMETA(DisplayName = "Object Type"),
	TTT_TraceType	UMETA(DisplayName = "Trace Type"),
	TTT_ProfileName UMETA(DisplayName = "Profile Name")
};

UCLASS(config=Game)
class AFPSCollisionsCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category=Mesh)
	class USkeletalMeshComponent* Mesh1P;

	/** Gun mesh: 1st person view (seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USkeletalMeshComponent* FP_Gun;

	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USceneComponent* FP_MuzzleLocation;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FirstPersonCameraComponent;

public:
	AFPSCollisionsCharacter();

protected:
	virtual void BeginPlay();

public:
	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	FVector GunOffset;

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category=Projectile)
	TSubclassOf<class AFPSCollisionsProjectile> ProjectileClass;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	class USoundBase* FireSound;

	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class UAnimMontage* FireAnimation;


	//WEEK 3: ADD
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CollisionTests)
		ETestTraceType ETraceType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CollisionTests)
		FTraceParams TraceCollisionParams;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CollisionTests)
		FCollisonParams SphereCollisionParams;

	//Called when a property is edited in the blueprint editor or in the Instance editor
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& e) override;

    virtual void Tick(float DeltaTime) override;



protected:
	
	/** Fires a projectile. */
	void OnFire();

	/** Handles moving forward/backward */
	void MoveForward(float Val);

	/** Handles stafing movement, left and right */
	void MoveRight(float Val);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);
	
	//WEEK 3: ADD
	class UCollisionSphereComponent* CollisionSphere;

	//Test Function to see if the Ray hits a Actor using the Collision Channel filter
	bool GetPickableActor_LineTraceTestByChannel(ECollisionChannel CollisionChannel);
	//Test Function to see if the Ray hits a Actor using the Object Type filter
	bool GetPickableActor_LineTraceTestByObjectType(EObjectTypeQuery ObjectType);
	//Test Function to see if the Ray hits a Actor using the Profile Name filter
	bool GetPickableActor_LineTraceTestByProfile(FName ProfileName);

	//Returns A Actor* if the Ray hits it using the Collision Channel filter
	AActor* GetPickableActor_LineTraceSingleByChannel(ECollisionChannel CollisionChannel);
	//Returns A Actor* if the Ray hits it using the Object Type filter
	AActor* GetPickableActor_LineTraceSingleByObjectType(EObjectTypeQuery ObjectType);
	//Returns A Actor* if the Ray hits it using the Trace Type filter
	AActor* GetPickableActor_LineTraceSingleByTraceType(ETraceTypeQuery TraceType);
	//Returns A Actor* if the Ray hits it using the Profile Name filter
	AActor* GetPickableActor_LineTraceSingleByProfile(FName ProfileName);

	//Returns a Array of FHitResult if the Ray hits a bunch of Actors using the  Collision Channel Filter
	TArray<FHitResult> GetPickableActor_LineTraceMultiByChannel(ECollisionChannel CollisionChannel);
	//Returns a Array of FHitResult if the Ray hits a bunch of Actors using the  Object Type Filter
	TArray<FHitResult> GetPickableActor_LineTraceMultiByObjectType(EObjectTypeQuery ObjectType);
	//Returns a Array of FHitResult if the Ray hits a bunch of Actors using the  Profile Name Filter
	TArray<FHitResult> GetPickableActor_LineTraceMultiByProfile(FName ProfileName);

	//Sets up the Ray for Ray Casting
	void SetupRay(FVector& StartTrace, FVector& Direction, FVector& EndTrace);

	UFUNCTION()
		void EnableCollisionSphere(bool enable);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	// End of APawn interface

public:
	/** Returns Mesh1P subobject **/
	FORCEINLINE class USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	/** Returns FirstPersonCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

};

/*
@@object_type_query_1: EObjectTypeQuery!int(0) // world static
  @@object_type_query_2: EObjectTypeQuery!int(1) // world dynamic
  @@object_type_query_3: EObjectTypeQuery!int(2) // pawn
  @@object_type_query_4: EObjectTypeQuery!int(3) // physics body
  @@object_type_query_5: EObjectTypeQuery!int(4) // vehicle
  @@object_type_query_6: EObjectTypeQuery!int(5) // destructible
  @@object_type_query_7: EObjectTypeQuery!int(6) // custom 1
  @@object_type_query_8: EObjectTypeQuery!int(7)
  @@object_type_query_9: EObjectTypeQuery!int(8)
  @@object_type_query_10: EObjectTypeQuery!int(9)
  @@object_type_query_11: EObjectTypeQuery!int(10)
  @@object_type_query_12: EObjectTypeQuery!int(11)
  @@object_type_query_13: EObjectTypeQuery!int(12)
  @@object_type_query_14: EObjectTypeQuery!int(13)
  @@object_type_query_15: EObjectTypeQuery!int(14)
  @@object_type_query_16: EObjectTypeQuery!int(15)
  @@object_type_query_17: EObjectTypeQuery!int(16)
  @@object_type_query_18: EObjectTypeQuery!int(17)
  @@object_type_query_19: EObjectTypeQuery!int(18)
  @@object_type_query_20: EObjectTypeQuery!int(19)
  @@object_type_query_21: EObjectTypeQuery!int(20)
  @@object_type_query_22: EObjectTypeQuery!int(21)
  @@object_type_query_23: EObjectTypeQuery!int(22)
  @@object_type_query_24: EObjectTypeQuery!int(23)
  @@object_type_query_25: EObjectTypeQuery!int(24)
  @@object_type_query_26: EObjectTypeQuery!int(25)
  @@object_type_query_27: EObjectTypeQuery!int(26)
  @@object_type_query_28: EObjectTypeQuery!int(27)
  @@object_type_query_29: EObjectTypeQuery!int(28)
  @@object_type_query_30: EObjectTypeQuery!int(29)
  @@object_type_query_31: EObjectTypeQuery!int(30)
  @@object_type_query_32: EObjectTypeQuery!int(31)
  @@object_type_query_max: EObjectTypeQuery!int(32)
*/