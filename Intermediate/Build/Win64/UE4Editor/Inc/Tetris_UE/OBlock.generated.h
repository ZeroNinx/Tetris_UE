// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TETRIS_UE_OBlock_generated_h
#error "OBlock.generated.h already included, missing '#pragma once' in OBlock.h"
#endif
#define TETRIS_UE_OBlock_generated_h

#define Tetris_UE_Source_Tetris_UE_OBlock_h_15_SPARSE_DATA
#define Tetris_UE_Source_Tetris_UE_OBlock_h_15_RPC_WRAPPERS \
	virtual void Spin_R_Implementation(); \
	virtual void Spin_L_Implementation(); \
 \
	DECLARE_FUNCTION(execSpin_R); \
	DECLARE_FUNCTION(execSpin_L);


#define Tetris_UE_Source_Tetris_UE_OBlock_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void Spin_R_Implementation(); \
	virtual void Spin_L_Implementation(); \
 \
	DECLARE_FUNCTION(execSpin_R); \
	DECLARE_FUNCTION(execSpin_L);


#define Tetris_UE_Source_Tetris_UE_OBlock_h_15_EVENT_PARMS
#define Tetris_UE_Source_Tetris_UE_OBlock_h_15_CALLBACK_WRAPPERS
#define Tetris_UE_Source_Tetris_UE_OBlock_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAOBlock(); \
	friend struct Z_Construct_UClass_AOBlock_Statics; \
public: \
	DECLARE_CLASS(AOBlock, ABlock, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Tetris_UE"), NO_API) \
	DECLARE_SERIALIZER(AOBlock)


#define Tetris_UE_Source_Tetris_UE_OBlock_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAOBlock(); \
	friend struct Z_Construct_UClass_AOBlock_Statics; \
public: \
	DECLARE_CLASS(AOBlock, ABlock, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Tetris_UE"), NO_API) \
	DECLARE_SERIALIZER(AOBlock)


#define Tetris_UE_Source_Tetris_UE_OBlock_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AOBlock(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AOBlock) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AOBlock); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AOBlock); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AOBlock(AOBlock&&); \
	NO_API AOBlock(const AOBlock&); \
public:


#define Tetris_UE_Source_Tetris_UE_OBlock_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AOBlock() { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AOBlock(AOBlock&&); \
	NO_API AOBlock(const AOBlock&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AOBlock); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AOBlock); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AOBlock)


#define Tetris_UE_Source_Tetris_UE_OBlock_h_15_PRIVATE_PROPERTY_OFFSET
#define Tetris_UE_Source_Tetris_UE_OBlock_h_12_PROLOG \
	Tetris_UE_Source_Tetris_UE_OBlock_h_15_EVENT_PARMS


#define Tetris_UE_Source_Tetris_UE_OBlock_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Tetris_UE_Source_Tetris_UE_OBlock_h_15_PRIVATE_PROPERTY_OFFSET \
	Tetris_UE_Source_Tetris_UE_OBlock_h_15_SPARSE_DATA \
	Tetris_UE_Source_Tetris_UE_OBlock_h_15_RPC_WRAPPERS \
	Tetris_UE_Source_Tetris_UE_OBlock_h_15_CALLBACK_WRAPPERS \
	Tetris_UE_Source_Tetris_UE_OBlock_h_15_INCLASS \
	Tetris_UE_Source_Tetris_UE_OBlock_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Tetris_UE_Source_Tetris_UE_OBlock_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Tetris_UE_Source_Tetris_UE_OBlock_h_15_PRIVATE_PROPERTY_OFFSET \
	Tetris_UE_Source_Tetris_UE_OBlock_h_15_SPARSE_DATA \
	Tetris_UE_Source_Tetris_UE_OBlock_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	Tetris_UE_Source_Tetris_UE_OBlock_h_15_CALLBACK_WRAPPERS \
	Tetris_UE_Source_Tetris_UE_OBlock_h_15_INCLASS_NO_PURE_DECLS \
	Tetris_UE_Source_Tetris_UE_OBlock_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TETRIS_UE_API UClass* StaticClass<class AOBlock>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Tetris_UE_Source_Tetris_UE_OBlock_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
