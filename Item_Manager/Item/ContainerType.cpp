#include "pch.h"
#include "ContainerType.h"

// Check capacity of SimpleItemList is full.
bool ContainerType::IsItemFull() {
	return SimpleItemList.IsFull();
}

// Check capacity of SimpleItemList is empty.
bool ContainerType::IsItemEmpty() {
	return SimpleItemList.IsEmpty();
}

// Check capacity of PhotoList is full.
bool ContainerType::IsPhotoFull() {
	return PhotoList.IsFull();
}

// Check capacity of PhotoList is Empty.
bool ContainerType::IsPhotoEmpty() {
	return PhotoList.IsEmpty();
}

// Set Container Id
void ContainerType::SetContainerId(int inId) {
	this->ContainerId = inId;
}

// Set Container Id from keyboard
void ContainerType::SetContainerIdFromKB() {
	cout << "\tContainer    : ";
	cin >> ContainerId;
}

// Add Item using Add Function of UnsortedList
void ContainerType::AddItem(SimpleItemType& data) {
	if (SimpleItemList.Add(data)){
		NumofItem++;
	}
	
}

// Delete Item using Delete Function of UnsortedList
int ContainerType::DeleteItem(SimpleItemType& data) {
	if (SimpleItemList.Delete(data)) {
		NumofItem--;
		return 1;
	}
	return 0;
}

// Update Item using Update Function of UnsortedList
int ContainerType::UpdateItem(SimpleItemType& data) {
	return(SimpleItemList.Replace(data));
}

// Add Photo(string) using Add Function of UnsortedList
int ContainerType::AddPhoto(string s) {
	if (PhotoList.Add(s)) {
		NumofPhoto++;
		return 1;
	}
	return 0;
}

// Delete Photo(string) using Delete Function of UnsortedList
int ContainerType::DeletePhoto(string& s) {
	if (PhotoList.Delete(s)) {
		NumofPhoto--;
		return 1;
	}
	return 0;
}

// Update Photo(string) using Update Function of UnsortedList
int ContainerType::UpdatePhoto(string s) {
	return (PhotoList.Replace(s));
}

// Display All the item using Print function of UnsortedList
void ContainerType::DisplayAllItem() {
	if (SimpleItemList.IsEmpty()) return;
	cout << "\n\t========= Container " << ContainerId << " Items" << " ========" << endl;
	SimpleItemList.Print();
}

// Display All the Photo using Print function of UnsortedList
void ContainerType::DisplayAllPhoto() {
	if (PhotoList.IsEmpty()) return;

	cout << "\n\t========= Container" << ContainerId<< " Photos" << " ========" << endl;
	PhotoList.Printstring();
}

// 스택리스트의 처음부터 끝까지 탐색하면서 해당 string이 포함돼는지 검색한다.
int ContainerType::FindByName(SimpleItemType data) {
	SimpleItemType CurData;
	SimpleItemList.ResetList();
	int len = SimpleItemList.GetLength();
	bool found = false;
	while (len--) {
		SimpleItemList.GetNextItem(CurData);
		if (CurData.GetName().find(data.GetName()) != -1) { //string member 함수 find 사용 해당 string을 포함하지 않을시 -1을 return 하는 함수
			CurData.DisplayRecordOnScreen();
			found = true;
		}
	}
	if (found) return 1;
	return 0;
}

// 리스트의 처음부터 끝까지 탐색하면서 일치하는 usage 번호가 있는 지 검색한다.
int ContainerType::FindByUsage(SimpleItemType inUsage) {
	SimpleItemType CurData;
	SimpleItemList.ResetList();
	int len = SimpleItemList.GetLength();
	bool found = false;
	while (len--) {
		SimpleItemList.GetNextItem(CurData);
		if (CurData.GetUsage() == inUsage.GetUsage()) {
			CurData.DisplayRecordOnScreen();
			found = true;
		}
	}
	if (found) return 1;
	return 0;
}

// 키보드로 부터 입력받은 name으로 데이터 찾기
void ContainerType::FindNameFromKB() {
	printf("\n\tEnter the Name you want to find\n");
	SimpleItemType data;
	data.SetNameFromKB();
	if (!FindByName(data)) printf("\n\tList has no name you want to search");
}

// 키보드로 부터 입력받은 usage 번호로 데이터 찾기
void ContainerType::FindUsageFromKB() {
	printf("\n\tEnter the Usage you want to find\n");
	SimpleItemType data;
	data.SetUsageFromKB();
	if (!FindByUsage(data)) printf("\n\tList has no usage you want to search");
}

// 마스터리스트를 참조하여 아이템정보를 자세히 출력한다.
void ContainerType::DisplayAllDetailsItem(DoublySortedLinkedList<ItemType>& ref) {
	SimpleItemType CurData;
	
	SimpleItemList.ResetList(); // 처음위치부터 탐색하기 위해 simpleitemlist reset
	int len = SimpleItemList.GetLength();
	while (len--) { //simpleitemlist에 담긴 아이템의 갯수만큼 반복
		SimpleItemList.GetNextItem(CurData); // 아이템 복사
		int prime_number = CurData.GetItemNum();
		ItemType cItem;
		cItem.SetItemNum(prime_number); //아이템과 일치하는 아이디를 마스터리스트에서 참조 
		ref.Get(cItem); // 참조한 아이디의 마스터아이템 복사
		cItem.DisplayRecordOnScreen(); //출력
	}
}