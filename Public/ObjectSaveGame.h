#pragma once

#include "CoreMinimal.h"
#include "SaveStructs.h"
#include "GameFramework/SaveGame.h"
#include "ObjectSaveGame.generated.h"

/**
 * Use this to save/load properties of actors/components marked with SaveGame flag.
 */
UCLASS()
class YOUR_API UObjectSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	// Save properties marked with SaveGame flag.
    void SaveActor(AActor* Actor, bool bSaveComponents);

	// Load properties marked with SaveGame flag.
    void LoadActor(AActor* Actor, bool bLoadComponents) const;

    // Provide kismet function libraries in blueprint graph editor.
    virtual UWorld* GetWorld() const final override;

private:
    UPROPERTY()
    TMap<FString, FObjectSaveRecord> SavedObjects;
};
