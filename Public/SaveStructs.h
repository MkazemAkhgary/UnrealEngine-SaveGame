#pragma once

#include "CoreMinimal.h"
#include "SaveStructs.generated.h"

/**
 * Structure for saving or loading object. Only properties with SaveGame flag are serialized.
 */
USTRUCT()
struct YOUR_API FObjectSaveRecord
{
	GENERATED_BODY()
	
public:
	void SerializeTo(UObject* Object) const;
	static FObjectSaveRecord SerializeFrom(UObject* Object);

private:
	UPROPERTY()
	TArray<uint8> Data;
};
