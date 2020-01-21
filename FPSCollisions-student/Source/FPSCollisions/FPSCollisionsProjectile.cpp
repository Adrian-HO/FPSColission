// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "FPSCollisionsProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "GameFramework/DamageType.h"


#define SURFACE_HEAD		SurfaceType1
#define SURFACE_BODY		SurfaceType2

AFPSCollisionsProjectile::AFPSCollisionsProjectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &AFPSCollisionsProjectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
}

void AFPSCollisionsProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) )// && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());

        EPhysicalSurface SurfaceType = SurfaceType_Default;
        FBodyInstance* BodyInstance = OtherComp->GetBodyInstance();
        UPhysicalMaterial* PhyMat = BodyInstance->GetSimplePhysicalMaterial();

        SurfaceType = UPhysicalMaterial::DetermineSurfaceType(PhyMat);// Hit.PhysMaterial.Get());
        //float ActualDamage = BaseDamage;
        float DamageAmount = 0.0f;
        TSubclassOf<UDamageType> const ValidDamageTypeClass = TSubclassOf<UDamageType>(UDamageType::StaticClass());
        FDamageEvent DamageEvent(ValidDamageTypeClass);

        if (SurfaceType == SURFACE_HEAD)
        {
            GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, "HEAD - " + OtherActor->GetActorLabel());                     
            DamageAmount = 60;
            //UGameplayStatics:(OtherActor, ActualDamage, ShotDirection, Hit, MyOwner->GetInstigatorController(), this, DamageType);
           // ActualDamage *= 4.0f;
        }
        if (SurfaceType == SURFACE_BODY)
        {
            GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, "BODY - " + OtherActor->GetActorLabel());
            DamageAmount = 40;
            //UGameplayStatics::ApplyPointDamage(HitActor, ActualDamage, ShotDirection, Hit, MyOwner->GetInstigatorController(), this, DamageType);
        }
        OtherActor->TakeDamage(DamageAmount, DamageEvent, nullptr, this);
        //UGameplayStatics::ApplyPointDamage(HitActor, ActualDamage, ShotDirection, Hit, MyOwner->GetInstigatorController(), this, DamageType);


		Destroy();
	}
}