#pragma once

#include "CoreMinimal.h"
#include "Serialization/ObjectAndNameAsStringProxyArchive.h"

/**
 * Proxy archive that also checks in SaveGame properties.
 */
class YOUR_API FSaveGameArchive : public FObjectAndNameAsStringProxyArchive
{
public:
	FSaveGameArchive(FArchive& InInnerArchive) : FObjectAndNameAsStringProxyArchive(InInnerArchive, false)
	{
		ArIsSaveGame = true;
		ArNoDelta = true;
		ArNoIntraPropertyDelta = true;
	}
};
