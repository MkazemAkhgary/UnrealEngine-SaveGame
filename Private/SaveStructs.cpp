
#include "SaveStructs.h"
#include "SaveGameArchive.h"
#include "Serialization/MemoryReader.h"
#include "Serialization/MemoryWriter.h"

void FObjectSaveRecord::SerializeTo(UObject* Object) const
{
	if (!Object) return;

	FMemoryReader MemoryStream(Data);
	FSaveGameArchive LoadStream(MemoryStream);
	Object->Serialize(LoadStream);
}

FObjectSaveRecord FObjectSaveRecord::SerializeFrom(UObject* Object)
{
	FObjectSaveRecord Record;
	if (!Object) return Record;

	FMemoryWriter MemoryStream(Record.Data);
	FSaveGameArchive SaveStream(MemoryStream);
	Object->Serialize(SaveStream);
	return Record;
}
