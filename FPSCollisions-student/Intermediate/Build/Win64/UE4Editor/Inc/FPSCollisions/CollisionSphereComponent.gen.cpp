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
	FPSCOLLISIONS_API UClass* Z_Construct_UClass_UCollisionSphereComponent_NoRegister();
	FPSCOLLISIONS_API UClass* Z_Construct_UClass_UCollisionSphereComponent();
	ENGINE_API UClass* Z_Construct_UClass_USphereComponent();
	UPackage* Z_Construct_UPackage__Script_FPSCollisions();
// End Cross Module References
	void UCollisionSphereComponent::StaticRegisterNativesUCollisionSphereComponent()
	{
	}
	UClass* Z_Construct_UClass_UCollisionSphereComponent_NoRegister()
	{
		return UCollisionSphereComponent::StaticClass();
	}
	struct Z_Construct_UClass_UCollisionSphereComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
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
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
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
	IMPLEMENT_CLASS(UCollisionSphereComponent, 3731632121);
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
