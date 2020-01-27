// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FPSCollisions/CollisionSphereComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCollisionSphereComponent() {}
// Cross Module References
	FPSCOLLISIONS_API UScriptStruct* Z_Construct_UScriptStruct_FTraceParams();
	UPackage* Z_Construct_UPackage__Script_FPSCollisions();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_ETraceTypeQuery();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_EObjectTypeQuery();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionChannel();
	FPSCOLLISIONS_API UScriptStruct* Z_Construct_UScriptStruct_FCollisonParams();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionResponse();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionEnabled();
	FPSCOLLISIONS_API UClass* Z_Construct_UClass_UCollisionSphereComponent_NoRegister();
	FPSCOLLISIONS_API UClass* Z_Construct_UClass_UCollisionSphereComponent();
	ENGINE_API UClass* Z_Construct_UClass_USphereComponent();
	FPSCOLLISIONS_API UFunction* Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	FPSCOLLISIONS_API UFunction* Z_Construct_UFunction_UCollisionSphereComponent_SetNewCollisionParams();
// End Cross Module References
class UScriptStruct* FTraceParams::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern FPSCOLLISIONS_API uint32 Get_Z_Construct_UScriptStruct_FTraceParams_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FTraceParams, Z_Construct_UPackage__Script_FPSCollisions(), TEXT("TraceParams"), sizeof(FTraceParams), Get_Z_Construct_UScriptStruct_FTraceParams_Hash());
	}
	return Singleton;
}
template<> FPSCOLLISIONS_API UScriptStruct* StaticStruct<FTraceParams>()
{
	return FTraceParams::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FTraceParams(FTraceParams::StaticStruct, TEXT("/Script/FPSCollisions"), TEXT("TraceParams"), false, nullptr, nullptr);
static struct FScriptStruct_FPSCollisions_StaticRegisterNativesFTraceParams
{
	FScriptStruct_FPSCollisions_StaticRegisterNativesFTraceParams()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("TraceParams")),new UScriptStruct::TCppStructOps<FTraceParams>);
	}
} ScriptStruct_FPSCollisions_StaticRegisterNativesFTraceParams;
	struct Z_Construct_UScriptStruct_FTraceParams_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProfileName_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_ProfileName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TraceType_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_TraceType;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ObjectType_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ObjectType;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CollisionChannel_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_CollisionChannel;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTraceParams_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "CollisionSphereComponent.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FTraceParams_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FTraceParams>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTraceParams_Statics::NewProp_ProfileName_MetaData[] = {
		{ "Category", "Collision" },
		{ "ModuleRelativePath", "CollisionSphereComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FTraceParams_Statics::NewProp_ProfileName = { "ProfileName", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FTraceParams, ProfileName), METADATA_PARAMS(Z_Construct_UScriptStruct_FTraceParams_Statics::NewProp_ProfileName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTraceParams_Statics::NewProp_ProfileName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTraceParams_Statics::NewProp_TraceType_MetaData[] = {
		{ "Category", "Collision" },
		{ "ModuleRelativePath", "CollisionSphereComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FTraceParams_Statics::NewProp_TraceType = { "TraceType", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FTraceParams, TraceType), Z_Construct_UEnum_Engine_ETraceTypeQuery, METADATA_PARAMS(Z_Construct_UScriptStruct_FTraceParams_Statics::NewProp_TraceType_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTraceParams_Statics::NewProp_TraceType_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTraceParams_Statics::NewProp_ObjectType_MetaData[] = {
		{ "Category", "Collision" },
		{ "ModuleRelativePath", "CollisionSphereComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FTraceParams_Statics::NewProp_ObjectType = { "ObjectType", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FTraceParams, ObjectType), Z_Construct_UEnum_Engine_EObjectTypeQuery, METADATA_PARAMS(Z_Construct_UScriptStruct_FTraceParams_Statics::NewProp_ObjectType_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTraceParams_Statics::NewProp_ObjectType_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTraceParams_Statics::NewProp_CollisionChannel_MetaData[] = {
		{ "Category", "Collision" },
		{ "ModuleRelativePath", "CollisionSphereComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FTraceParams_Statics::NewProp_CollisionChannel = { "CollisionChannel", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FTraceParams, CollisionChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(Z_Construct_UScriptStruct_FTraceParams_Statics::NewProp_CollisionChannel_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTraceParams_Statics::NewProp_CollisionChannel_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FTraceParams_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTraceParams_Statics::NewProp_ProfileName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTraceParams_Statics::NewProp_TraceType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTraceParams_Statics::NewProp_ObjectType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTraceParams_Statics::NewProp_CollisionChannel,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FTraceParams_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_FPSCollisions,
		nullptr,
		&NewStructOps,
		"TraceParams",
		sizeof(FTraceParams),
		alignof(FTraceParams),
		Z_Construct_UScriptStruct_FTraceParams_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTraceParams_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FTraceParams_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTraceParams_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FTraceParams()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FTraceParams_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_FPSCollisions();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("TraceParams"), sizeof(FTraceParams), Get_Z_Construct_UScriptStruct_FTraceParams_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FTraceParams_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FTraceParams_Hash() { return 870855537U; }
class UScriptStruct* FCollisonParams::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern FPSCOLLISIONS_API uint32 Get_Z_Construct_UScriptStruct_FCollisonParams_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FCollisonParams, Z_Construct_UPackage__Script_FPSCollisions(), TEXT("CollisonParams"), sizeof(FCollisonParams), Get_Z_Construct_UScriptStruct_FCollisonParams_Hash());
	}
	return Singleton;
}
template<> FPSCOLLISIONS_API UScriptStruct* StaticStruct<FCollisonParams>()
{
	return FCollisonParams::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FCollisonParams(FCollisonParams::StaticStruct, TEXT("/Script/FPSCollisions"), TEXT("CollisonParams"), false, nullptr, nullptr);
static struct FScriptStruct_FPSCollisions_StaticRegisterNativesFCollisonParams
{
	FScriptStruct_FPSCollisions_StaticRegisterNativesFCollisonParams()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("CollisonParams")),new UScriptStruct::TCppStructOps<FCollisonParams>);
	}
} ScriptStruct_FPSCollisions_StaticRegisterNativesFCollisonParams;
	struct Z_Construct_UScriptStruct_FCollisonParams_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProfileName_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_ProfileName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CollisionChannel_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_CollisionChannel;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CollisionResponseNew_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_CollisionResponseNew;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CollisionEnabled_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_CollisionEnabled;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCollisonParams_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "CollisionSphereComponent.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FCollisonParams_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCollisonParams>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCollisonParams_Statics::NewProp_ProfileName_MetaData[] = {
		{ "Category", "Collision" },
		{ "Comment", "//Collision Channel Flag\n" },
		{ "ModuleRelativePath", "CollisionSphereComponent.h" },
		{ "ToolTip", "Collision Channel Flag" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FCollisonParams_Statics::NewProp_ProfileName = { "ProfileName", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCollisonParams, ProfileName), METADATA_PARAMS(Z_Construct_UScriptStruct_FCollisonParams_Statics::NewProp_ProfileName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCollisonParams_Statics::NewProp_ProfileName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCollisonParams_Statics::NewProp_CollisionChannel_MetaData[] = {
		{ "Category", "Collision" },
		{ "Comment", "//Collision Response Flag\n" },
		{ "ModuleRelativePath", "CollisionSphereComponent.h" },
		{ "ToolTip", "Collision Response Flag" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FCollisonParams_Statics::NewProp_CollisionChannel = { "CollisionChannel", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCollisonParams, CollisionChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(Z_Construct_UScriptStruct_FCollisonParams_Statics::NewProp_CollisionChannel_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCollisonParams_Statics::NewProp_CollisionChannel_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCollisonParams_Statics::NewProp_CollisionResponseNew_MetaData[] = {
		{ "Category", "Collision" },
		{ "Comment", "//Collision Enabled Flag\n" },
		{ "ModuleRelativePath", "CollisionSphereComponent.h" },
		{ "ToolTip", "Collision Enabled Flag" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FCollisonParams_Statics::NewProp_CollisionResponseNew = { "CollisionResponseNew", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCollisonParams, CollisionResponseNew), Z_Construct_UEnum_Engine_ECollisionResponse, METADATA_PARAMS(Z_Construct_UScriptStruct_FCollisonParams_Statics::NewProp_CollisionResponseNew_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCollisonParams_Statics::NewProp_CollisionResponseNew_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCollisonParams_Statics::NewProp_CollisionEnabled_MetaData[] = {
		{ "Category", "Collision" },
		{ "ModuleRelativePath", "CollisionSphereComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FCollisonParams_Statics::NewProp_CollisionEnabled = { "CollisionEnabled", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCollisonParams, CollisionEnabled), Z_Construct_UEnum_Engine_ECollisionEnabled, METADATA_PARAMS(Z_Construct_UScriptStruct_FCollisonParams_Statics::NewProp_CollisionEnabled_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCollisonParams_Statics::NewProp_CollisionEnabled_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCollisonParams_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCollisonParams_Statics::NewProp_ProfileName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCollisonParams_Statics::NewProp_CollisionChannel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCollisonParams_Statics::NewProp_CollisionResponseNew,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCollisonParams_Statics::NewProp_CollisionEnabled,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCollisonParams_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_FPSCollisions,
		nullptr,
		&NewStructOps,
		"CollisonParams",
		sizeof(FCollisonParams),
		alignof(FCollisonParams),
		Z_Construct_UScriptStruct_FCollisonParams_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCollisonParams_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FCollisonParams_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCollisonParams_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FCollisonParams()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FCollisonParams_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_FPSCollisions();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("CollisonParams"), sizeof(FCollisonParams), Get_Z_Construct_UScriptStruct_FCollisonParams_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FCollisonParams_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FCollisonParams_Hash() { return 1128723052U; }
	void UCollisionSphereComponent::StaticRegisterNativesUCollisionSphereComponent()
	{
		UClass* Class = UCollisionSphereComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "HandleOverlap", &UCollisionSphereComponent::execHandleOverlap },
			{ "SetNewCollisionParams", &UCollisionSphereComponent::execSetNewCollisionParams },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap_Statics
	{
		struct CollisionSphereComponent_eventHandleOverlap_Parms
		{
			UPrimitiveComponent* OverlappedComponent;
			AActor* OtherActor;
			UPrimitiveComponent* OtherComp;
			int32 OtherBodyIndex;
			bool bFromSweep;
			FHitResult SweepResult;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SweepResult;
		static void NewProp_bFromSweep_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OverlappedComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OverlappedComponent;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap_Statics::NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CollisionSphereComponent_eventHandleOverlap_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap_Statics::NewProp_SweepResult_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap_Statics::NewProp_SweepResult_MetaData)) };
	void Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap_Statics::NewProp_bFromSweep_SetBit(void* Obj)
	{
		((CollisionSphereComponent_eventHandleOverlap_Parms*)Obj)->bFromSweep = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CollisionSphereComponent_eventHandleOverlap_Parms), &Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CollisionSphereComponent_eventHandleOverlap_Parms, OtherBodyIndex), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap_Statics::NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CollisionSphereComponent_eventHandleOverlap_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap_Statics::NewProp_OtherComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap_Statics::NewProp_OtherComp_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CollisionSphereComponent_eventHandleOverlap_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap_Statics::NewProp_OverlappedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap_Statics::NewProp_OverlappedComponent = { "OverlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CollisionSphereComponent_eventHandleOverlap_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap_Statics::NewProp_OverlappedComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap_Statics::NewProp_OverlappedComponent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap_Statics::NewProp_SweepResult,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap_Statics::NewProp_bFromSweep,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap_Statics::NewProp_OtherBodyIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap_Statics::NewProp_OtherComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap_Statics::NewProp_OtherActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap_Statics::NewProp_OverlappedComponent,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//The Components Handle Overlap\n" },
		{ "ModuleRelativePath", "CollisionSphereComponent.h" },
		{ "ToolTip", "The Components Handle Overlap" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCollisionSphereComponent, nullptr, "HandleOverlap", nullptr, nullptr, sizeof(CollisionSphereComponent_eventHandleOverlap_Parms), Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCollisionSphereComponent_SetNewCollisionParams_Statics
	{
		struct CollisionSphereComponent_eventSetNewCollisionParams_Parms
		{
			FCollisonParams params;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_params;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCollisionSphereComponent_SetNewCollisionParams_Statics::NewProp_params = { "params", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CollisionSphereComponent_eventSetNewCollisionParams_Parms, params), Z_Construct_UScriptStruct_FCollisonParams, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCollisionSphereComponent_SetNewCollisionParams_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCollisionSphereComponent_SetNewCollisionParams_Statics::NewProp_params,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCollisionSphereComponent_SetNewCollisionParams_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "CollisionSphereComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UCollisionSphereComponent_SetNewCollisionParams_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCollisionSphereComponent, nullptr, "SetNewCollisionParams", nullptr, nullptr, sizeof(CollisionSphereComponent_eventSetNewCollisionParams_Parms), Z_Construct_UFunction_UCollisionSphereComponent_SetNewCollisionParams_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCollisionSphereComponent_SetNewCollisionParams_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCollisionSphereComponent_SetNewCollisionParams_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCollisionSphereComponent_SetNewCollisionParams_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCollisionSphereComponent_SetNewCollisionParams()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UCollisionSphereComponent_SetNewCollisionParams_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UCollisionSphereComponent_NoRegister()
	{
		return UCollisionSphereComponent::StaticClass();
	}
	struct Z_Construct_UClass_UCollisionSphereComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCollisionSphereComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USphereComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_FPSCollisions,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UCollisionSphereComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCollisionSphereComponent_HandleOverlap, "HandleOverlap" }, // 4060540218
		{ &Z_Construct_UFunction_UCollisionSphereComponent_SetNewCollisionParams, "SetNewCollisionParams" }, // 716501143
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCollisionSphereComponent_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Object LOD Lighting TextureStreaming Object LOD Lighting TextureStreaming Activation Components|Activation Trigger" },
		{ "IncludePath", "CollisionSphereComponent.h" },
		{ "ModuleRelativePath", "CollisionSphereComponent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCollisionSphereComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCollisionSphereComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCollisionSphereComponent_Statics::ClassParams = {
		&UCollisionSphereComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x00B010A4u,
		METADATA_PARAMS(Z_Construct_UClass_UCollisionSphereComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCollisionSphereComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCollisionSphereComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCollisionSphereComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCollisionSphereComponent, 894437106);
	template<> FPSCOLLISIONS_API UClass* StaticClass<UCollisionSphereComponent>()
	{
		return UCollisionSphereComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCollisionSphereComponent(Z_Construct_UClass_UCollisionSphereComponent, &UCollisionSphereComponent::StaticClass, TEXT("/Script/FPSCollisions"), TEXT("UCollisionSphereComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCollisionSphereComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
