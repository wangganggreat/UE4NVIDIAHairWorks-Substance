/**
 *
 * This thumbnail renderer displays a given HairWorks Asset
 */

#pragma once
#include "HairWorksAssetThumbnailRenderer.generated.h"

UCLASS(config = Editor, MinimalAPI)
class UHairWorksAssetThumbnailRenderer: public UDefaultSizedThumbnailRenderer
{
	GENERATED_UCLASS_BODY()

	// Begin UThumbnailRenderer Object
	UNREALED_API virtual void Draw(UObject* Object, int32 X, int32 Y, uint32 Width, uint32 Height, FRenderTarget* RenderTarget, FCanvas* Canvas) override;
	// End UThumbnailRenderer Object

	// UObject implementation
	UNREALED_API virtual void BeginDestroy() override;

private:
	FHairWorksAssetThumbnailScene* ThumbnailScene;
};

