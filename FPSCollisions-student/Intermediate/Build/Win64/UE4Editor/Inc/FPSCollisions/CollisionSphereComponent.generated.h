// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FCollisonParams;
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef FPSCOLLISIONS_CollisionSphereComponent_generated_h
#error "CollisionSphereComponent.generated.h already included, missing '#pragma once' in CollisionSphereComponent.h"
#endif
#define FPSCOLLISIONS_CollisionSphereComponent_generated_h

#define FPSCollisions_student_Source_FPSCollisions_CollisionSphereComponent_h_30_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FTraceParams_Statics; \
	FPSCOLLISIONS_API static class UScriptStruct* StaticStruct();


template<> FPSCOLLISIONS_API UScriptStruct* StaticStruct<struct FTraceParams>();

#define FPSCollisions_student_Source_FPSCollisions_CollisionSphereComponent_h_12_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCollisonParams_Statics; \
	FPSCOLLISIONS_API static class UScriptStruct* StaticStruct();


template<> FPSCOLLISIONS_API UScriptStruct* StaticStruct<struct FCollisonParams>();

#define FPSCollisions_student_Source_FPSCollisions_CollisionSphereComponent_h_54_SPARSE_DATA
#define FPSCollisions_student_Source_FPSCollisions_CollisionSphereComponent_h_54_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetNewCollisionParams) \
	{ \
		P_GET_STRUCT(FCollisonParams,Z_Param_params); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetNewCollisionParams(Z_Param_params); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHandleOverlap) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->HandleOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define FPSCollisions_student_Source_FPSCollisions_CollisionSphereComponent_h_54_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetNewCollisionParams) \
	{ \
		P_GET_STRUCT(FCollisonParams,Z_Param_params); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetNewCollisionParams(Z_Param_params); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHandleOverlap) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->HandleOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define FPSCollisions_student_Source_FPSCollisions_CollisionSphereComponent_h_54_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCollisionSphereComponent(); \
	friend struct Z_Construct_UClass_UCollisionSphereComponent_Statics; \
public: \
	DECLARE_CLASS(UCollisionSphereComponent, USphereComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FPSCollisions"), NO_API) \
	DECLARE_SERIALIZER(UCollisionSphereComponent)


#define FPSCollisions_student_Source_FPSCollisions_CollisionSphereComponent_h_54_INCLASS \
private: \
	static void StaticRegisterNativesUCollisionSphereComponent(); \
	friend struct Z_Construct_UClass_UCollisionSphereComponent_Statics; \
public: \
	DECLARE_CLASS(UCollisionSphereComponent, USphereComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FPSCollisions"), NO_API) \
	DECLARE_SERIALIZER(UCollisionSphereComponent)


#define FPSCollisions_student_Source_FPSCollisions_CollisionSphereComponent_h_54_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCollisionSphereComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCollisionSphereComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCollisionSphereComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCollisionSphereComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCollisionSphereComponent(UCollisionSphereComponent&&); \
	NO_API UCollisionSphereComponent(const UCollisionSphereComponent&); \
public:


#define FPSCollisions_student_Source_FPSCollisions_CollisionSphereComponent_h_54_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCollisionSphereComponent(UCollisionSphereComponent&&); \
	NO_API UCollisionSphereComponent(const UCollisionSphereComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCollisionSphereComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCollisionSphereComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCollisionSphereComponent)


#define FPSCollisions_student_Source_FPSCollisions_CollisionSphereComponent_h_54_PRIVATE_PROPERTY_OFFSET
#define FPSCollisions_student_Source_FPSCollisions_CollisionSphereComponent_h_51_PROLOG
#define FPSCollisions_student_Source_FPSCollisions_CollisionSphereComponent_h_54_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FPSCollisions_student_Source_FPSCollisions_CollisionSphereComponent_h_54_PRIVATE_PROPERTY_OFFSET \
	FPSCollisions_student_Source_FPSCollisions_CollisionSphereComponent_h_54_SPARSE_DATA \
	FPSCollisions_student_Source_FPSCollisions_CollisionSphereComponent_h_54_RPC_WRAPPERS \
	FPSCollisions_student_Source_FPSCollisions_CollisionSphereComponent_h_54_INCLASS \
	FPSCollisions_student_Source_FPSCollisions_CollisionSphereComponent_h_54_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FPSCollisions_student_Source_FPSCollisions_CollisionSphereComponent_h_54_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FPSCollisions_student_Source_FPSCollisions_CollisionSphereComponent_h_54_PRIVATE_PROPERTY_OFFSET \
	FPSCollisions_student_Source_FPSCollisions_CollisionSphereComponent_h_54_SPARSE_DATA \
	FPSCollisions_student_Source_FPSCollisions_CollisionSphereComponent_h_54_RPC_WRAPPERS_NO_PURE_DECLS \
	FPSCollisions_student_Source_FPSCollisions_CollisionSphereComponent_h_54_INCLASS_NO_PURE_DECLS \
	FPSCollisions_student_Source_FPSCollisions_CollisionSphereComponent_h_54_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FPSCOLLISIONS_API UClass* StaticClass<class UCollisionSphereComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FPSCollisions_student_Source_FPSCollisions_CollisionSphereComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
