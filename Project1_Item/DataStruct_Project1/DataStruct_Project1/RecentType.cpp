#include "RecentType.h"

int RecentType::IsFull() {
	if (NumofItems == MaxItems) return 1;
	return 0;
}

void RecentType::Bottomdata(ItemType& data) {
	rItemList.ResetCurrentPointer();
	rItemList.GetNextItem(data);
}

void RecentType::MakeEmpty() {
	rItemList.ResetList();
}

void RecentType::Add(ItemType data) {
	if (IsFull()) {
		DeletefromBottom();
		rItemList.Push(data);
	}

	else {
		rItemList.Push(data);
		NumofItems++;
	}
}

void RecentType::DeletefromBottom() {
	ItemType deletedata;
	Bottomdata(deletedata);
	rItemList.Delete(deletedata);
}

int RecentType::GetNum() {
	return NumofItems;
}

void RecentType::Display() {
	rItemList.Print();
}