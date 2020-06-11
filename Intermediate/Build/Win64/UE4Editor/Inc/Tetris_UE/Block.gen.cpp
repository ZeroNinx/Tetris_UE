// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Tetris_UE/Block.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBlock() {}
// Cross Module References
	TETRIS_UE_API UEnum* Z_Construct_UEnum_Tetris_UE_EBlockType();
	UPackage* Z_Construct_UPackage__Script_Tetris_UE();
	TETRIS_UE_API UScriptStruct* Z_Construct_UScriptStruct_FPoint();
	TETRIS_UE_API UClass* Z_Construct_UClass_ABlock_NoRegister();
	TETRIS_UE_API UClass* Z_Construct_UClass_ABlock();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
// End Cross Module References
	static UEnum* EBlockType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Tetris_UE_EBlockType, Z_Construct_UPackage__Script_Tetris_UE(), TEXT("EBlockType"));
		}
		return Singleton;
	}
	template<> TETRIS_UE_API UEnum* StaticEnum<EBlockType>()
	{
		return EBlockType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EBlockType(EBlockType_StaticEnum, TEXT("/Script/Tetris_UE"), TEXT("EBlockType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Tetris_UE_EBlockType_Hash() { return 1317411380U; }
	UEnum* Z_Construct_UEnum_Tetris_UE_EBlockType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Tetris_UE();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EBlockType"), 0, Get_Z_Construct_UEnum_Tetris_UE_EBlockType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EBlockType::NONE", (int64)EBlockType::NONE },
				{ "EBlockType::TBLOCK", (int64)EBlockType::TBLOCK },
				{ "EBlockType::IBLOCK", (int64)EBlockType::IBLOCK },
				{ "EBlockType::OBLOCK", (int64)EBlockType::OBLOCK },
				{ "EBlockType::LBLOCK", (int64)EBlockType::LBLOCK },
				{ "EBlockType::JBLOCK", (int64)EBlockType::JBLOCK },
				{ "EBlockType::SBLOCK", (int64)EBlockType::SBLOCK },
				{ "EBlockType::ZBLOCK", (int64)EBlockType::ZBLOCK },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Comment", "//\xc3\xb6????\xcd\xbc?\xe0\xa3\xac??\xca\xbe????????\n" },
				{ "IBLOCK.Name", "EBlockType::IBLOCK" },
				{ "JBLOCK.Name", "EBlockType::JBLOCK" },
				{ "LBLOCK.Name", "EBlockType::LBLOCK" },
				{ "ModuleRelativePath", "Block.h" },
				{ "NONE.Name", "EBlockType::NONE" },
				{ "OBLOCK.Name", "EBlockType::OBLOCK" },
				{ "SBLOCK.Name", "EBlockType::SBLOCK" },
				{ "TBLOCK.Name", "EBlockType::TBLOCK" },
				{ "ToolTip", "\xc3\xb6????\xcd\xbc?\xe0\xa3\xac??\xca\xbe????????" },
				{ "ZBLOCK.Name", "EBlockType::ZBLOCK" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Tetris_UE,
				nullptr,
				"EBlockType",
				"EBlockType",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
class UScriptStruct* FPoint::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern TETRIS_UE_API uint32 Get_Z_Construct_UScriptStruct_FPoint_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FPoint, Z_Construct_UPackage__Script_Tetris_UE(), TEXT("Point"), sizeof(FPoint), Get_Z_Construct_UScriptStruct_FPoint_Hash());
	}
	return Singleton;
}
template<> TETRIS_UE_API UScriptStruct* StaticStruct<FPoint>()
{
	return FPoint::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FPoint(FPoint::StaticStruct, TEXT("/Script/Tetris_UE"), TEXT("Point"), false, nullptr, nullptr);
static struct FScriptStruct_Tetris_UE_StaticRegisterNativesFPoint
{
	FScriptStruct_Tetris_UE_StaticRegisterNativesFPoint()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("Point")),new UScriptStruct::TCppStructOps<FPoint>);
	}
} ScriptStruct_Tetris_UE_StaticRegisterNativesFPoint;
	struct Z_Construct_UScriptStruct_FPoint_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Y_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Y;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_X_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_X;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPoint_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "//?\xe1\xb9\xb9?\xe5\xa3\xac??\xca\xbe????\n" },
		{ "ModuleRelativePath", "Block.h" },
		{ "ToolTip", "?\xe1\xb9\xb9?\xe5\xa3\xac??\xca\xbe????" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPoint_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPoint>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPoint_Statics::NewProp_Y_MetaData[] = {
		{ "Category", "Point" },
		{ "Comment", "//Y??????\n" },
		{ "ModuleRelativePath", "Block.h" },
		{ "ToolTip", "Y??????" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FPoint_Statics::NewProp_Y = { "Y", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPoint, Y), METADATA_PARAMS(Z_Construct_UScriptStruct_FPoint_Statics::NewProp_Y_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPoint_Statics::NewProp_Y_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPoint_Statics::NewProp_X_MetaData[] = {
		{ "Category", "Point" },
		{ "Comment", "//X??????\n" },
		{ "ModuleRelativePath", "Block.h" },
		{ "ToolTip", "X??????" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FPoint_Statics::NewProp_X = { "X", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPoint, X), METADATA_PARAMS(Z_Construct_UScriptStruct_FPoint_Statics::NewProp_X_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPoint_Statics::NewProp_X_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPoint_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPoint_Statics::NewProp_Y,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPoint_Statics::NewProp_X,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPoint_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Tetris_UE,
		nullptr,
		&NewStructOps,
		"Point",
		sizeof(FPoint),
		alignof(FPoint),
		Z_Construct_UScriptStruct_FPoint_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPoint_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FPoint_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPoint_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FPoint()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FPoint_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_Tetris_UE();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("Point"), sizeof(FPoint), Get_Z_Construct_UScriptStruct_FPoint_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FPoint_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FPoint_Hash() { return 779017914U; }
	DEFINE_FUNCTION(ABlock::execGetPosList)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FPoint>*)Z_Param__Result=P_THIS->GetPosList();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABlock::execSetPos)
	{
		P_GET_STRUCT(FPoint,Z_Param_p);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetPos(Z_Param_p);
		P_NATIVE_END;
	}
	void ABlock::StaticRegisterNativesABlock()
	{
		UClass* Class = ABlock::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetPosList", &ABlock::execGetPosList },
			{ "SetPos", &ABlock::execSetPos },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ABlock_GetPosList_Statics
	{
		struct Block_eventGetPosList_Parms
		{
			TArray<FPoint> ReturnValue;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ABlock_GetPosList_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Block_eventGetPosList_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ABlock_GetPosList_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FPoint, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABlock_GetPosList_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABlock_GetPosList_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABlock_GetPosList_Statics::NewProp_ReturnValue_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABlock_GetPosList_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//??\xc8\xa1?????\xd0\xb1?\n" },
		{ "ModuleRelativePath", "Block.h" },
		{ "ToolTip", "??\xc8\xa1?????\xd0\xb1?" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABlock_GetPosList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABlock, nullptr, "GetPosList", nullptr, nullptr, sizeof(Block_eventGetPosList_Parms), Z_Construct_UFunction_ABlock_GetPosList_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABlock_GetPosList_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABlock_GetPosList_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABlock_GetPosList_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABlock_GetPosList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABlock_GetPosList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABlock_SetPos_Statics
	{
		struct Block_eventSetPos_Parms
		{
			FPoint p;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_p;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ABlock_SetPos_Statics::NewProp_p = { "p", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Block_eventSetPos_Parms, p), Z_Construct_UScriptStruct_FPoint, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABlock_SetPos_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABlock_SetPos_Statics::NewProp_p,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABlock_SetPos_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//?\xe8\xb6\xa8????\n" },
		{ "ModuleRelativePath", "Block.h" },
		{ "ToolTip", "?\xe8\xb6\xa8????" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABlock_SetPos_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABlock, nullptr, "SetPos", nullptr, nullptr, sizeof(Block_eventSetPos_Parms), Z_Construct_UFunction_ABlock_SetPos_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABlock_SetPos_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABlock_SetPos_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABlock_SetPos_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABlock_SetPos()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABlock_SetPos_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ABlock_NoRegister()
	{
		return ABlock::StaticClass();
	}
	struct Z_Construct_UClass_ABlock_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Type_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Type;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Type_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Pos_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Pos;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BlockSize_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_BlockSize;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABlock_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Tetris_UE,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ABlock_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ABlock_GetPosList, "GetPosList" }, // 1539894603
		{ &Z_Construct_UFunction_ABlock_SetPos, "SetPos" }, // 4022394586
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABlock_Statics::Class_MetaDataParams[] = {
		{ "Comment", "//\xd7\xa9????\n" },
		{ "IncludePath", "Block.h" },
		{ "ModuleRelativePath", "Block.h" },
		{ "ToolTip", "\xd7\xa9????" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABlock_Statics::NewProp_Type_MetaData[] = {
		{ "Category", "Block" },
		{ "Comment", "//????????\n" },
		{ "ModuleRelativePath", "Block.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ABlock_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0020080000020015, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABlock, Type), Z_Construct_UEnum_Tetris_UE_EBlockType, METADATA_PARAMS(Z_Construct_UClass_ABlock_Statics::NewProp_Type_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABlock_Statics::NewProp_Type_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_ABlock_Statics::NewProp_Type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABlock_Statics::NewProp_Pos_MetaData[] = {
		{ "Category", "Block" },
		{ "Comment", "//????\n" },
		{ "ModuleRelativePath", "Block.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ABlock_Statics::NewProp_Pos = { "Pos", nullptr, (EPropertyFlags)0x0020080000000014, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABlock, Pos), Z_Construct_UScriptStruct_FPoint, METADATA_PARAMS(Z_Construct_UClass_ABlock_Statics::NewProp_Pos_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABlock_Statics::NewProp_Pos_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABlock_Statics::NewProp_BlockSize_MetaData[] = {
		{ "Category", "Block" },
		{ "Comment", "//??????\xd0\xa1\n" },
		{ "ModuleRelativePath", "Block.h" },
		{ "ToolTip", "??????\xd0\xa1" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ABlock_Statics::NewProp_BlockSize = { "BlockSize", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABlock, BlockSize), METADATA_PARAMS(Z_Construct_UClass_ABlock_Statics::NewProp_BlockSize_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABlock_Statics::NewProp_BlockSize_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABlock_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABlock_Statics::NewProp_Type,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABlock_Statics::NewProp_Type_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABlock_Statics::NewProp_Pos,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABlock_Statics::NewProp_BlockSize,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABlock_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABlock>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABlock_Statics::ClassParams = {
		&ABlock::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ABlock_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ABlock_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ABlock_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABlock_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABlock()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABlock_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABlock, 1397395026);
	template<> TETRIS_UE_API UClass* StaticClass<ABlock>()
	{
		return ABlock::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABlock(Z_Construct_UClass_ABlock, &ABlock::StaticClass, TEXT("/Script/Tetris_UE"), TEXT("ABlock"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABlock);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
