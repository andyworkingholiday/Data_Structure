#pragma once
#include "ItemType.h"
#include "TempType.h"
#include "SortedList.h"
#include "StorageType.h"

class StorageType;
class ItemType;
class SimpleItemType;
class TempType;

template<typename T>
class SortedList;

class Base {
public:
	static SortedList<ItemType> MasterList;
	static SortedList<StorageType> StorageList;
	static TempType TempList;
};