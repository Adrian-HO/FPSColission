// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef FPSCOLLISIONS_FPSCollisionsProjectile_generated_h
#error "FPSCollisionsProjectile.generated.h already included, missing '#pragma once' in FPSCollisionsProjectile.h"
#endif
#define FPSCOLLISIONS_FPSCollisionsProjectile_generated_h

#define FPSCollisions_student_Source_FPSCollisions_FPSCollisionsProjectile_h_12_SPARSE_DATA
#define FPSCollisions_student_Source_FPSCollisions_FPSCollisionsProjectile_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define FPSCollisions_student_Source_FPSCollisions_FPSCollisionsProjectile_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define FPSCollisions_student_Source_FPSCollisions_FPSCollisionsProjectile_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFPSCollisionsProjectile(); \
	friend struct Z_Construct_UClass_AFPSCollisionsProjectile_Statics; \
public: \
	DECLARE_CLASS(AFPSCollisionsProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FPSCollisions"), NO_API) \
	DECLARE_SERIALIZER(AFPSCollisionsProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FPSCollisions_student_Source_FPSCollisions_FPSCollisionsProjectile_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAFPSCollisionsProjectile(); \
	friend struct Z_Construct_UClass_AFPSCollisionsProjectile_Statics; \
public: \
	DECLARE_CLASS(AFPSCollisionsProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FPSCollisions"), NO_API) \
	DECLARE_SERIALIZER(AFPSCollisionsProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FPSCollisions_student_Source_FPSCollisions_FPSCollisionsProjectile_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFPSCollisionsProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFPSCollisionsProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSCollisionsProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSCollisionsProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSCollisionsProjectile(AFPSCollisionsProjectile&&); \
	NO_API AFPSCollisionsProjectile(const AFPSCollisionsProjectile&); \
public:


#define FPSCollisions_student_Source_FPSCollisions_FPSCollisionsProjectile_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSCollisionsProjectile(AFPSCollisionsProjectile&&); \
	NO_API AFPSCollisionsProjectile(const AFPSCollisionsProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSCollisionsProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSCollisionsProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFPSCollisionsProjectile)


#define FPSCollisions_student_Source_FPSCollisions_FPSCollisionsProjectile_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CollisionComp() { return STRUCT_OFFSET(AFPSCollisionsProjectile, CollisionComp); } \
	FORCEINLINE static uint32 __PPO__ProjectileMovement() { return STRUCT_OFFSET(AFPSCollisionsProjectile, ProjectileMovement); }


#define FPSCollisions_student_Source_FPSCollisions_FPSCollisionsProjectile_h_9_PROLOG
#define FPSCollisions_student_Source_FPSCollisions_FPSCollisionsProjectile_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FPSCollisions_student_Source_FPSCollisions_FPSCollisionsProjectile_h_12_PRIVATE_PROPERTY_OFFSET \
	FPSCollisions_student_Source_FPSCollisions_FPSCollisionsProjectile_h_12_SPARSE_DATA \
	FPSCollisions_student_Source_FPSCollisions_FPSCollisionsProjectile_h_12_RPC_WRAPPERS \
	FPSCollisions_student_Source_FPSCollisions_FPSCollisionsProjectile_h_12_INCLASS \
	FPSCollisions_student_Source_FPSCollisions_FPSCollisionsProjectile_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FPSCollisions_student_Source_FPSCollisions_FPSCollisionsProjectile_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FPSCollisions_student_Source_FPSCollisions_FPSCollisionsProjectile_h_12_PRIVATE_PROPERTY_OFFSET \
	FPSCollisions_student_Source_FPSCollisions_FPSCollisionsProjectile_h_12_SPARSE_DATA \
	FPSCollisions_student_Source_FPSCollisions_FPSCollisionsProjectile_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FPSCollisions_student_Source_FPSCollisions_FPSCollisionsProjectile_h_12_INCLASS_NO_PURE_DECLS \
	FPSCollisions_student_Source_FPSCollisions_FPSCollisionsProjectile_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FPSCOLLISIONS_API UClass* StaticClass<class AFPSCollisionsProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FPSCollisions_student_Source_FPSCollisions_FPSCollisionsProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
