// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

//~=============================================================================
// ReimportTextureFactory
//~=============================================================================

#pragma once
#include "ReimportVectorFieldStaticFactory.generated.h"

UCLASS()
class UReimportVectorFieldStaticFactory : public UVectorFieldStaticFactory, public FReimportHandler
{
	GENERATED_UCLASS_BODY()

	//~ Begin FReimportHandler Interface
	virtual bool CanReimport( UObject* Obj, TArray<FString>& OutFilenames ) override;
	virtual void SetReimportPaths( UObject* Obj, const TArray<FString>& NewReimportPaths ) override;
	virtual EReimportResult::Type Reimport( UObject* Obj ) override;
	virtual int32 GetPriority() const override;
	//~ End FReimportHandler Interface
};



