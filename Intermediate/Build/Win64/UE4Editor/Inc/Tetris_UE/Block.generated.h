// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TETRIS_UE_Block_generated_h
#error "Block.generated.h already included, missing '#pragma once' in Block.h"
#endif
#define TETRIS_UE_Block_generated_h

#define Tetris_UE_Source_Tetris_UE_Block_h_27_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPoint_Statics; \
	TETRIS_UE_API static class UScriptStruct* StaticStruct();


template<> TETRIS_UE_API UScriptStruct* StaticStruct<struct FPoint>();

#define Tetris_UE_Source_Tetris_UE_Block_h_45_SPARSE_DATA
#define Tetris_UE_Source_Tetris_UE_Block_h_45_RPC_WRAPPERS
#define Tetris_UE_Source_Tetris_UE_Block_h_45_RPC_WRAPPERS_NO_PURE_DECLS
#define Tetris_UE_Source_Tetris_UE_Block_h_45_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABlock(); \
	friend struct Z_Construct_UClass_ABlock_Statics; \
public: \
	DECLARE_CLASS(ABlock, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Tetris_UE"), NO_API) \
	DECLARE_SERIALIZER(ABlock)


#define Tetris_UE_Source_Tetris_UE_Block_h_45_INCLASS \
private: \
	static void StaticRegisterNativesABlock(); \
	friend struct Z_Construct_UClass_ABlock_Statics; \
public: \
	DECLARE_CLASS(ABlock, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Tetris_UE"), NO_API) \
	DECLARE_SERIALIZER(ABlock)


#define Tetris_UE_Source_Tetris_UE_Block_h_45_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABlock(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABlock) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABlock); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABlock); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABlock(ABlock&&); \
	NO_API ABlock(const ABlock&); \
public:


#define Tetris_UE_Source_Tetris_UE_Block_h_45_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABlock(ABlock&&); \
	NO_API ABlock(const ABlock&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABlock); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABlock); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABlock)


#define Tetris_UE_Source_Tetris_UE_Block_h_45_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__BlockSize() { return STRUCT_OFFSET(ABlock, BlockSize); } \
	FORCEINLINE static uint32 __PPO__RotationList() { return STRUCT_OFFSET(ABlock, RotationList); } \
	FORCEINLINE static uint32 __PPO__RotationIndex() { return STRUCT_OFFSET(ABlock, RotationIndex); }


#define Tetris_UE_Source_Tetris_UE_Block_h_42_PROLOG
#define Tetris_UE_Source_Tetris_UE_Block_h_45_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Tetris_UE_Source_Tetris_UE_Block_h_45_PRIVATE_PROPERTY_OFFSET \
	Tetris_UE_Source_Tetris_UE_Block_h_45_SPARSE_DATA \
	Tetris_UE_Source_Tetris_UE_Block_h_45_RPC_WRAPPERS \
	Tetris_UE_Source_Tetris_UE_Block_h_45_INCLASS \
	Tetris_UE_Source_Tetris_UE_Block_h_45_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Tetris_UE_Source_Tetris_UE_Block_h_45_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Tetris_UE_Source_Tetris_UE_Block_h_45_PRIVATE_PROPERTY_OFFSET \
	Tetris_UE_Source_Tetris_UE_Block_h_45_SPARSE_DATA \
	Tetris_UE_Source_Tetris_UE_Block_h_45_RPC_WRAPPERS_NO_PURE_DECLS \
	Tetris_UE_Source_Tetris_UE_Block_h_45_INCLASS_NO_PURE_DECLS \
	Tetris_UE_Source_Tetris_UE_Block_h_45_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TETRIS_UE_API UClass* StaticClass<class ABlock>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Tetris_UE_Source_Tetris_UE_Block_h


#define FOREACH_ENUM_EBLOCKTYPE(op) \
	op(EBlockType::NONE) \
	op(EBlockType::TBLOCK) \
	op(EBlockType::IBLOCK) \
	op(EBlockType::OBLOCK) \
	op(EBlockType::LBLOCK) \
	op(EBlockType::JBLOCK) \
	op(EBlockType::SBLOCK) \
	op(EBlockType::ZBLOCK) 

enum class EBlockType : uint8;
template<> TETRIS_UE_API UEnum* StaticEnum<EBlockType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
