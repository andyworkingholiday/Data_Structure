#include "pch.h"
#include "TempType.h"

// Check capacity of tItemList is full.
int TempType::IsFull() {
	return (tItemList.IsFull());
}

// Check capacity of tItemList is Empty
int TempType::IsEmpty() {
	return (tItemList.IsEmpty());
}

// Copdy the front data to prameter data
void TempType::Frontdata(ItemType& data) {
	tItemList.ResetCurrentPointer();
	tItemList.GetNextItem(data);
}

void TempType::ResetPointer() {
	tItemList.ResetCurrentPointer();
}

// Make tItemList Empty
void TempType::MakeEmpty() {
	tItemList.MakeEmpty();
	NumofItems = 0;
}

// Add Item use Enque
void TempType::Add(ItemType data) {
	tItemList.EnQueue(data);
	NumofItems = tItemList.GetLength();
}

int TempType::GetNextItem(ItemType& data) {
	return(tItemList.GetNextItem(data));
}

// Delete Item use Deque and copy the item to parameter data
void TempType::DeltefromFront(ItemType& data) {
	tItemList.DeQueue(data);
	NumofItems = tItemList.GetLength();
}

// Get numbers of data
int TempType::GetNum() {
	return NumofItems;
}

// Display All the data except ContainerID
void TempType::Display() {
	ItemType t;
	tItemList.ResetCurrentPointer();
	int index = tItemList.GetNextItem(t);
	while (index >= 0) {
		t.DisplayUsageOnScreen();
		t.DisplayRtimeOnScreen();
		t.DisplayPdayOnScreen();
		t.DisplayBrandOnScreen();
		t.DisplayNameOnScreen();
		t.DisplayNumOnScreen();
		t.DisplayHeartOnScreen();
		t.DisplayItemNumOnScreen();
		cout << endl;
		if (index == 0) break;
		index = tItemList.GetNextItem(t);
	}
}

// Display only the front data
void TempType::DisplayFront() {
	ItemType t;
	tItemList.ResetCurrentPointer();
	tItemList.GetNextItem(t);
	t.DisplayUsageOnScreen();
	t.DisplayRtimeOnScreen();
	t.DisplayPdayOnScreen();
	t.DisplayBrandOnScreen();
	t.DisplayNameOnScreen();
	t.DisplayNumOnScreen();
	t.DisplayHeartOnScreen();
	t.DisplayItemNumOnScreen();
	cout << endl;
}

// Delete Using Delete function of QLIST
int TempType::Delete(ItemType& data) {
	if (tItemList.Delete(data)) {
		NumofItems = tItemList.GetLength();
		return 1;
	}
	return 0;
}

// Search Using Search function of QLIST
int TempType::Search(ItemType& data) {
	return (tItemList.Search(data));
}

// Replace Using Replace function of QLIST
int TempType::Replace(ItemType& data) {
	return (tItemList.Replace(data));
}