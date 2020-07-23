// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Tetris_UE/JBlock.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeJBlock() {}
// Cross Module References
	TETRIS_UE_API UClass* Z_Construct_UClass_AJBlock_NoRegister();
	TETRIS_UE_API UClass* Z_Construct_UClass_AJBlock();
	TETRIS_UE_API UClass* Z_Construct_UClass_ABlock();
	UPackage* Z_Construct_UPackage__Script_Tetris_UE();
// End Cross Module References
	void AJBlock::StaticRegisterNativesAJBlock()
	{
	}
	UClass* Z_Construct_UClass_AJBlock_NoRegister()
	{
		return AJBlock::StaticClass();
	}
	struct Z_Construct_UClass_AJBlock_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AJBlock_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ABlock,
		(UObject* (*)())Z_Construct_UPackage__Script_Tetris_UE,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AJBlock_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * J????\n */" },
		{ "IncludePath", "JBlock.h" },
		{ "ModuleRelativePath", "JBlock.h" },
		{ "ToolTip", "J????" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AJBlock_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AJBlock>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AJBlock_Statics::ClassParams = {
		&AJBlock::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AJBlock_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AJBlock_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AJBlock()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AJBlock_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AJBlock, 702221484);
	template<> TETRIS_UE_API UClass* StaticClass<AJBlock>()
	{
		return AJBlock::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AJBlock(Z_Construct_UClass_AJBlock, &AJBlock::StaticClass, TEXT("/Script/Tetris_UE"), TEXT("AJBlock"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AJBlock);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
