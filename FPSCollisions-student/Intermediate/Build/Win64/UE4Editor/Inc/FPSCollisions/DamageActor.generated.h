// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UDamageType;
class AController;
#ifdef FPSCOLLISIONS_DamageActor_generated_h
#error "DamageActor.generated.h already included, missing '#pragma once' in DamageActor.h"
#endif
#define FPSCOLLISIONS_DamageActor_generated_h

#define FPSCollisions_student_Source_FPSCollisions_DamageActor_h_12_SPARSE_DATA
#define FPSCollisions_student_Source_FPSCollisions_DamageActor_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execTakeAnyDamage) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_DamagedActor); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Damage); \
		P_GET_OBJECT(UDamageType,Z_Param_DamageType); \
		P_GET_OBJECT(AController,Z_Param_InstigatedBy); \
		P_GET_OBJECT(AActor,Z_Param_DamageCauser); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->TakeAnyDamage(Z_Param_DamagedActor,Z_Param_Damage,Z_Param_DamageType,Z_Param_InstigatedBy,Z_Param_DamageCauser); \
		P_NATIVE_END; \
	}


#define FPSCollisions_student_Source_FPSCollisions_DamageActor_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execTakeAnyDamage) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_DamagedActor); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Damage); \
		P_GET_OBJECT(UDamageType,Z_Param_DamageType); \
		P_GET_OBJECT(AController,Z_Param_InstigatedBy); \
		P_GET_OBJECT(AActor,Z_Param_DamageCauser); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->TakeAnyDamage(Z_Param_DamagedActor,Z_Param_Damage,Z_Param_DamageType,Z_Param_InstigatedBy,Z_Param_DamageCauser); \
		P_NATIVE_END; \
	}


#define FPSCollisions_student_Source_FPSCollisions_DamageActor_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADamageActor(); \
	friend struct Z_Construct_UClass_ADamageActor_Statics; \
public: \
	DECLARE_CLASS(ADamageActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FPSCollisions"), NO_API) \
	DECLARE_SERIALIZER(ADamageActor)


#define FPSCollisions_student_Source_FPSCollisions_DamageActor_h_12_INCLASS \
private: \
	static void StaticRegisterNativesADamageActor(); \
	friend struct Z_Construct_UClass_ADamageActor_Statics; \
public: \
	DECLARE_CLASS(ADamageActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FPSCollisions"), NO_API) \
	DECLARE_SERIALIZER(ADamageActor)


#define FPSCollisions_student_Source_FPSCollisions_DamageActor_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ADamageActor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADamageActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADamageActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADamageActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADamageActor(ADamageActor&&); \
	NO_API ADamageActor(const ADamageActor&); \
public:


#define FPSCollisions_student_Source_FPSCollisions_DamageActor_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADamageActor(ADamageActor&&); \
	NO_API ADamageActor(const ADamageActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADamageActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADamageActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADamageActor)


#define FPSCollisions_student_Source_FPSCollisions_DamageActor_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ActorRoot() { return STRUCT_OFFSET(ADamageActor, ActorRoot); } \
	FORCEINLINE static uint32 __PPO__MeshHead() { return STRUCT_OFFSET(ADamageActor, MeshHead); } \
	FORCEINLINE static uint32 __PPO__MeshBody() { return STRUCT_OFFSET(ADamageActor, MeshBody); }


#define FPSCollisions_student_Source_FPSCollisions_DamageActor_h_9_PROLOG
#define FPSCollisions_student_Source_FPSCollisions_DamageActor_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FPSCollisions_student_Source_FPSCollisions_DamageActor_h_12_PRIVATE_PROPERTY_OFFSET \
	FPSCollisions_student_Source_FPSCollisions_DamageActor_h_12_SPARSE_DATA \
	FPSCollisions_student_Source_FPSCollisions_DamageActor_h_12_RPC_WRAPPERS \
	FPSCollisions_student_Source_FPSCollisions_DamageActor_h_12_INCLASS \
	FPSCollisions_student_Source_FPSCollisions_DamageActor_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FPSCollisions_student_Source_FPSCollisions_DamageActor_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FPSCollisions_student_Source_FPSCollisions_DamageActor_h_12_PRIVATE_PROPERTY_OFFSET \
	FPSCollisions_student_Source_FPSCollisions_DamageActor_h_12_SPARSE_DATA \
	FPSCollisions_student_Source_FPSCollisions_DamageActor_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FPSCollisions_student_Source_FPSCollisions_DamageActor_h_12_INCLASS_NO_PURE_DECLS \
	FPSCollisions_student_Source_FPSCollisions_DamageActor_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FPSCOLLISIONS_API UClass* StaticClass<class ADamageActor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FPSCollisions_student_Source_FPSCollisions_DamageActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
