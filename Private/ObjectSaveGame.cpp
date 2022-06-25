#include "ObjectSaveGame.h"
#include "SaveGameArchive.h"
#include "GameFramework/Actor.h"

void UObjectSaveGame::SaveActor(AActor* Actor, bool bSaveComponents)
{
	if (bSaveComponents) // save components first
	{
		TInlineComponentArray<UActorComponent*> Components(Actor);
		for (UActorComponent* Component : Components)
		{
			if (Component)
			{
				FObjectSaveRecord Record = FObjectSaveRecord::SerializeFrom(Component);
				SavedObjects.Add(Component->GetPathName(), Record);
			}
		}
	}

	if (Actor)
	{
		FObjectSaveRecord Record = FObjectSaveRecord::SerializeFrom(Actor);
		SavedObjects.Add(Actor->GetPathName(), Record);
	}
}

void UObjectSaveGame::LoadActor(AActor* Actor, bool bLoadComponents) const
{
	if (bLoadComponents) // load components first
	{
		TInlineComponentArray<UActorComponent*> Components(Actor);
		for (UActorComponent* Component : Components)
		{
			if (Component)
			{
				if (const FObjectSaveRecord* Record = SavedObjects.Find(Component->GetPathName()))
				{
					Record->SerializeTo(Component);
				}
			}
		}
	}

	if (Actor)
	{
		if (const FObjectSaveRecord* Record = SavedObjects.Find(Actor->GetPathName()))
		{
			Record->SerializeTo(Actor);
		}
	}
}

UWorld* UObjectSaveGame::GetWorld() const
{
	if (GetOuter() == nullptr)
	{
		return nullptr;
	}

	// Special case to give access to kismet libraries in the editor
	if (Cast<UPackage>(GetOuter()) != nullptr)
	{
		// GetOuter should return a UPackage and its Outer is a UWorld
		return Cast<UWorld>(GetOuter()->GetOuter());
	}

	// In all other cases...
	return GetOuter()->GetWorld();
}
