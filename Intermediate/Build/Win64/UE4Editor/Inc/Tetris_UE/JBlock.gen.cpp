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
	DEFINE_FUNCTION(AJBlock::execSpin_R)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Spin_R_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AJBlock::execSpin_L)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Spin_L_Implementation();
		P_NATIVE_END;
	}
	static FName NAME_AJBlock_Spin_L = FName(TEXT("Spin_L"));
	void AJBlock::Spin_L()
	{
		ProcessEvent(FindFunctionChecked(NAME_AJBlock_Spin_L),NULL);
	}
	static FName NAME_AJBlock_Spin_R = FName(TEXT("Spin_R"));
	void AJBlock::Spin_R()
	{
		ProcessEvent(FindFunctionChecked(NAME_AJBlock_Spin_R),NULL);
	}
	void AJBlock::StaticRegisterNativesAJBlock()
	{
		UClass* Class = AJBlock::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Spin_L", &AJBlock::execSpin_L },
			{ "Spin_R", &AJBlock::execSpin_R },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AJBlock_Spin_L_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AJBlock_Spin_L_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//????\n" },
		{ "ModuleRelativePath", "JBlock.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AJBlock_Spin_L_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AJBlock, nullptr, "Spin_L", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C080C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AJBlock_Spin_L_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AJBlock_Spin_L_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AJBlock_Spin_L()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AJBlock_Spin_L_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AJBlock_Spin_R_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AJBlock_Spin_R_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//????\n" },
		{ "ModuleRelativePath", "JBlock.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AJBlock_Spin_R_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AJBlock, nullptr, "Spin_R", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C080C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AJBlock_Spin_R_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AJBlock_Spin_R_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AJBlock_Spin_R()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AJBlock_Spin_R_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AJBlock_NoRegister()
	{
		return AJBlock::StaticClass();
	}
	struct Z_Construct_UClass_AJBlock_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
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
	const FClassFunctionLinkInfo Z_Construct_UClass_AJBlock_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AJBlock_Spin_L, "Spin_L" }, // 3958321924
		{ &Z_Construct_UFunction_AJBlock_Spin_R, "Spin_R" }, // 792527269
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AJBlock_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "JBlock.h" },
		{ "ModuleRelativePath", "JBlock.h" },
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
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
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
	IMPLEMENT_CLASS(AJBlock, 940254458);
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
