// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Tetris_UE/OBlock.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOBlock() {}
// Cross Module References
	TETRIS_UE_API UClass* Z_Construct_UClass_AOBlock_NoRegister();
	TETRIS_UE_API UClass* Z_Construct_UClass_AOBlock();
	TETRIS_UE_API UClass* Z_Construct_UClass_ABlock();
	UPackage* Z_Construct_UPackage__Script_Tetris_UE();
// End Cross Module References
	void AOBlock::StaticRegisterNativesAOBlock()
	{
	}
	UClass* Z_Construct_UClass_AOBlock_NoRegister()
	{
		return AOBlock::StaticClass();
	}
	struct Z_Construct_UClass_AOBlock_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AOBlock_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ABlock,
		(UObject* (*)())Z_Construct_UPackage__Script_Tetris_UE,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOBlock_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * O????\n */" },
		{ "IncludePath", "OBlock.h" },
		{ "ModuleRelativePath", "OBlock.h" },
		{ "ToolTip", "O????" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AOBlock_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOBlock>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AOBlock_Statics::ClassParams = {
		&AOBlock::StaticClass,
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
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AOBlock_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AOBlock_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AOBlock()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AOBlock_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AOBlock, 2150852248);
	template<> TETRIS_UE_API UClass* StaticClass<AOBlock>()
	{
		return AOBlock::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AOBlock(Z_Construct_UClass_AOBlock, &AOBlock::StaticClass, TEXT("/Script/Tetris_UE"), TEXT("AOBlock"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AOBlock);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
