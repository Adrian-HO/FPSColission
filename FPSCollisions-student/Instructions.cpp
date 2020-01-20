
Instructions:

1) Use the provided C++ projectand ADD the following.

2) Add the following Component CollisionSphereComponent that Inherits from USphereComponent :

In CollisionSphereComponent.h :
	//This struct will be used for setting collisions during runtime in the UCollisionSphereComponent
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

//This struct will be used for Setting Ray Trace filtering during runtime
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

// Collision Sphere to detect Objects within its proximity
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

In CollisionSphereComponent.cpp:

UCollisionSphereComponent::UCollisionSphereComponent()
{
	bWantsInitializeComponent = true;
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

3) In FPSCollisionsCharacter.h:
//Enum used for what type of trace we will perform
UENUM(BlueprintType)
enum class ETestTraceType : uint8
{
	TTT_CollisionChannel 	UMETA(DisplayName = "Collision Channel"),
	TTT_ObjectType 	UMETA(DisplayName = "Object Type"),
	TTT_TraceType	UMETA(DisplayName = "Trace Type"),
	TTT_ProfileName UMETA(DisplayName = "Profile Name")
};

In AFPSCollisionsCharacter class :
	public:
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CollisionTests)
			ETestTraceType ETraceType;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CollisionTests)
			FTraceParams TraceCollisionParams;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CollisionTests)
			FCollisonParams SphereCollisionParams;

		//Called when a property is edited in the blueprint editor or in the Instance editor
		virtual void PostEditChangeProperty(struct FPropertyChangedEvent& e) override;

	protected:

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

		In FPSCollisionsCharacter.cpp:

		Inside the Constructor :
		CollisionSphere = CreateDefaultSubobject<UCollisionSphereComponent>("Collision Sphere");
		CollisionSphere->SetupAttachment(RootComponent);

		In BeginPlay() :
			CollisionSphere->SetNewCollisionParams(SphereCollisionParams);

		In SetupRay(FVector& StartTrace, FVector& Direction, FVector& EndTrace) :
			FVector CamLoc;
		FRotator CamRot;

		Controller->GetPlayerViewPoint(CamLoc, CamRot); // Get the camera position and rotation
		CamLoc = GetActorLocation();

		StartTrace = CamLoc; // trace start is the camera location
		Direction = CamRot.Vector();
		EndTrace = StartTrace + Direction * 300; // and trace end is the camera location + an offset in the direction you are looking, the 300 is the distance at which it checks 

		In EnableCollisionSphere(bool enable) :
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

		bool GetPickableActor_LineTraceTestByChannel(ECollisionChannel CollisionChannel) :
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

		bool GetPickableActor_LineTraceTestByObjectType(EObjectTypeQuery ObjectType) :
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

		bool GetPickableActor_LineTraceTestByProfile(FName ProfileName) :
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

		AActor* GetPickableActor_LineTraceSingleByChannel(ECollisionChannel CollisionChannel) :
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

		AActor* GetPickableActor_LineTraceSingleByObjectType(EObjectTypeQuery ObjectType) :
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

		AActor* GetPickableActor_LineTraceSingleByTraceType(ETraceTypeQuery TraceType) :
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

		AActor* GetPickableActor_LineTraceSingleByProfile(FName ProfileName)
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

		TArray<FHitResult> GetPickableActor_LineTraceMultiByChannel(ECollisionChannel CollisionChannel) :
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

		TArray<FHitResult> GetPickableActor_LineTraceMultiByObjectType(EObjectTypeQuery ObjectType) :
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

		TArray<FHitResult> GetPickableActor_LineTraceMultiByProfile(FName ProfileName) :
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

		In Tick() :
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

		In PostEditChangeProperty(struct FPropertyChangedEvent& e) :

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

