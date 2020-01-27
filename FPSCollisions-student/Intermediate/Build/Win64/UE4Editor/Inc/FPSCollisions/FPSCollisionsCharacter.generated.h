// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FPSCOLLISIONS_FPSCollisionsCharacter_generated_h
#error "FPSCollisionsCharacter.generated.h already included, missing '#pragma once' in FPSCollisionsCharacter.h"
#endif
#define FPSCOLLISIONS_FPSCollisionsCharacter_generated_h

#define FPSCollisions_student_Source_FPSCollisions_FPSCollisionsCharacter_h_27_SPARSE_DATA
#define FPSCollisions_student_Source_FPSCollisions_FPSCollisionsCharacter_h_27_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execEnableCollisionSphere) \
	{ \
		P_GET_UBOOL(Z_Param_enable); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EnableCollisionSphere(Z_Param_enable); \
		P_NATIVE_END; \
	}


#define FPSCollisions_student_Source_FPSCollisions_FPSCollisionsCharacter_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execEnableCollisionSphere) \
	{ \
		P_GET_UBOOL(Z_Param_enable); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EnableCollisionSphere(Z_Param_enable); \
		P_NATIVE_END; \
	}


#define FPSCollisions_student_Source_FPSCollisions_FPSCollisionsCharacter_h_27_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFPSCollisionsCharacter(); \
	friend struct Z_Construct_UClass_AFPSCollisionsCharacter_Statics; \
public: \
	DECLARE_CLASS(AFPSCollisionsCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FPSCollisions"), NO_API) \
	DECLARE_SERIALIZER(AFPSCollisionsCharacter)


#define FPSCollisions_student_Source_FPSCollisions_FPSCollisionsCharacter_h_27_INCLASS \
private: \
	static void StaticRegisterNativesAFPSCollisionsCharacter(); \
	friend struct Z_Construct_UClass_AFPSCollisionsCharacter_Statics; \
public: \
	DECLARE_CLASS(AFPSCollisionsCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FPSCollisions"), NO_API) \
	DECLARE_SERIALIZER(AFPSCollisionsCharacter)


#define FPSCollisions_student_Source_FPSCollisions_FPSCollisionsCharacter_h_27_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFPSCollisionsCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFPSCollisionsCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSCollisionsCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSCollisionsCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSCollisionsCharacter(AFPSCollisionsCharacter&&); \
	NO_API AFPSCollisionsCharacter(const AFPSCollisionsCharacter&); \
public:


#define FPSCollisions_student_Source_FPSCollisions_FPSCollisionsCharacter_h_27_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSCollisionsCharacter(AFPSCollisionsCharacter&&); \
	NO_API AFPSCollisionsCharacter(const AFPSCollisionsCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSCollisionsCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSCollisionsCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFPSCollisionsCharacter)


#define FPSCollisions_student_Source_FPSCollisions_FPSCollisionsCharacter_h_27_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Mesh1P() { return STRUCT_OFFSET(AFPSCollisionsCharacter, Mesh1P); } \
	FORCEINLINE static uint32 __PPO__FP_Gun() { return STRUCT_OFFSET(AFPSCollisionsCharacter, FP_Gun); } \
	FORCEINLINE static uint32 __PPO__FP_MuzzleLocation() { return STRUCT_OFFSET(AFPSCollisionsCharacter, FP_MuzzleLocation); } \
	FORCEINLINE static uint32 __PPO__FirstPersonCameraComponent() { return STRUCT_OFFSET(AFPSCollisionsCharacter, FirstPersonCameraComponent); }


#define FPSCollisions_student_Source_FPSCollisions_FPSCollisionsCharacter_h_24_PROLOG
#define FPSCollisions_student_Source_FPSCollisions_FPSCollisionsCharacter_h_27_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FPSCollisions_student_Source_FPSCollisions_FPSCollisionsCharacter_h_27_PRIVATE_PROPERTY_OFFSET \
	FPSCollisions_student_Source_FPSCollisions_FPSCollisionsCharacter_h_27_SPARSE_DATA \
	FPSCollisions_student_Source_FPSCollisions_FPSCollisionsCharacter_h_27_RPC_WRAPPERS \
	FPSCollisions_student_Source_FPSCollisions_FPSCollisionsCharacter_h_27_INCLASS \
	FPSCollisions_student_Source_FPSCollisions_FPSCollisionsCharacter_h_27_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FPSCollisions_student_Source_FPSCollisions_FPSCollisionsCharacter_h_27_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FPSCollisions_student_Source_FPSCollisions_FPSCollisionsCharacter_h_27_PRIVATE_PROPERTY_OFFSET \
	FPSCollisions_student_Source_FPSCollisions_FPSCollisionsCharacter_h_27_SPARSE_DATA \
	FPSCollisions_student_Source_FPSCollisions_FPSCollisionsCharacter_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	FPSCollisions_student_Source_FPSCollisions_FPSCollisionsCharacter_h_27_INCLASS_NO_PURE_DECLS \
	FPSCollisions_student_Source_FPSCollisions_FPSCollisionsCharacter_h_27_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FPSCOLLISIONS_API UClass* StaticClass<class AFPSCollisionsCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FPSCollisions_student_Source_FPSCollisions_FPSCollisionsCharacter_h


#define FOREACH_ENUM_ETESTTRACETYPE(op) \
	op(ETestTraceType::TTT_CollisionChannel) \
	op(ETestTraceType::TTT_ObjectType) \
	op(ETestTraceType::TTT_TraceType) \
	op(ETestTraceType::TTT_ProfileName) 

enum class ETestTraceType : uint8;
template<> FPSCOLLISIONS_API UEnum* StaticEnum<ETestTraceType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
