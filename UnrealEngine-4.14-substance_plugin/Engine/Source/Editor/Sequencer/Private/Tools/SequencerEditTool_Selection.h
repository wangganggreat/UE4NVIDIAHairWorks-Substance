// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "SequencerEditTool.h"
#include "UniquePtr.h"
#include "DelayedDrag.h"


struct FMarqueeSelectData;


class FSequencerEditTool_Selection
	: public FSequencerEditTool
{
public:

	/** Static identifier for this edit tool */
	static const FName Identifier;

	/** Create and initialize a new instance. */
	FSequencerEditTool_Selection(FSequencer& InSequencer);

public:

	// ISequencerEditTool interface	
	virtual int32 OnPaint(const FGeometry& AllottedGeometry, const FSlateRect& MyClippingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId) const override;
	virtual FReply OnMouseButtonDown(SWidget& OwnerWidget, const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseButtonUp(SWidget& OwnerWidget, const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseMove(SWidget& OwnerWidget, const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual void OnMouseLeave(SWidget& OwnerWidget, const FPointerEvent& MouseEvent) override;
	virtual void OnMouseCaptureLost() override;
	virtual FCursorReply OnCursorQuery(const FGeometry& MyGeometry, const FPointerEvent& CursorEvent) const override;
	virtual FName GetIdentifier() const override;
	virtual bool CanDeactivate() const override;
	virtual const ISequencerHotspot* GetDragHotspot() const override;
	
private:

	/** Update the software cursor */
	void UpdateCursor(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent);

private:

	/** Sequencer widget */
	TWeakPtr<SSequencer> SequencerWidget;

	struct FDelayedDrag_Hotspot : FDelayedDrag
	{
		FDelayedDrag_Hotspot(FVector2D InInitialPosition, FKey InApplicableKey, TSharedPtr<ISequencerHotspot> InHotspot)
			: FDelayedDrag(InInitialPosition, InApplicableKey)
			, Hotspot(MoveTemp(InHotspot))
		{}

		TSharedPtr<ISequencerHotspot> Hotspot;
	};

	/** Helper class responsible for handling delayed dragging */
	TOptional<FDelayedDrag_Hotspot> DelayedDrag;
	
	/** Current drag operation if any */
	TSharedPtr<ISequencerEditToolDragOperation> DragOperation;

	/** Cached mouse position for software cursor rendering */
	FVector2D MousePosition;

	/** Software cursor decorator brush */
	const FSlateBrush* CursorDecorator;
};