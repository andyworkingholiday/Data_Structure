#include "PlaceType.h"

// Check capacity of SimpleItemList is full.
bool PlaceType::IsItemFull() {
	return SimpleItemList.IsFull();
}

// Check capacity of SimpleItemList is empty.
bool PlaceType::IsItemEmpty() {
	return SimpleItemList.IsEmpty();
}

// Check capacity of PhotoList is full.
bool PlaceType::IsPhotoFull() {
	return PhotoList.IsFull();
}

// Check capacity of PhotoList is Empty.
bool PlaceType::IsPhotoEmpty() {
	return PhotoList.IsEmpty();
}

// Set Container Id
void PlaceType::SetContainerId(int inId) {
	this->ContainerId = inId;
	if (inId == 1) Location = "LivingRoom";
	else if (inId == 2) Location = "Kitchen";
	else if (inId == 3) Location = "BathRoom";
	else if (inId == 4) Location = "BedRoom";
	else if (inId == 5)Location = "Library";
	else Location = "Etc";
}

// Set Container Id from keyboard
void PlaceType::SetContainerIdFromKB() {
	cout << "\tEnter the number with Suitable Place" << endl;
	cout << "\t=============== Place ===============" << endl;
	cout << "\t1 : LivingRoom         " << "4 : BedRoom" << endl;
	cout << "\t2 : Kitchen            " << "5 : Library" << endl;
	cout << "\t3 : BathRoom           " << "0 : Etc" << endl;
	int number;
	printf("\tPlace    : ");
	cin >> number;

	if (number <= 5) SetContainerId(number);
	else {
		cout << "\tIllegal selection...try again\n";
		SetContainerIdFromKB();
	}
}

// Add Item using Add Function of UnsortedList
void PlaceType::AddItem(SimpleItemType& data) {
	if (SimpleItemList.Add(data)) 
		NumofItem++;
}

// Delete Item using Delete Function of UnsortedList
int PlaceType::DeleteItem(SimpleItemType& data) {
	if (SimpleItemList.Delete(data)) {
		NumofItem--;
		return 1;
	}
	return 0;
}

// Update Item using Update Function of UnsortedList
int PlaceType::UpdateItem(SimpleItemType& data) {
	return(SimpleItemList.Replace(data));
}

// Add Photo(string) using Add Function of UnsortedList
int PlaceType::AddPhoto(string s) {
	return (PhotoList.Add(s));
	NumofPhoto++;
}

// Delete Photo(string) using Delete Function of UnsortedList
int PlaceType::DeletePhoto(string& s) {
	return (PhotoList.Delete(s));
	NumofPhoto--;
}

// Update Photo(string) using Update Function of UnsortedList
int PlaceType::UpdatePhoto(string s) {
	return (PhotoList.Replace(s));
}

// Display All the item using Print function of UnsortedList
void PlaceType::DisplayAllItem() {
	if (SimpleItemList.IsEmpty()) return;
	cout << "\n\t========= " << Location << " List" << " ========" << endl;
	SimpleItemList.Print();
}

// Display All the Photo using Print function of UnsortedList
void PlaceType::DisplayAllPhoto() {
	if (PhotoList.IsEmpty()) return;

	cout << "\n\t========= " << Location << " Photo List" << " ========" << endl;
	PhotoList.Print();
}

// 스택리스트의 처음부터 끝까지 탐색하면서 해당 string이 포함돼는지 검색한다.
int PlaceType::FindByName(SimpleItemType data) {
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
int PlaceType::FindByUsage(SimpleItemType inUsage) {
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
void PlaceType::FindNameFromKB() {
	printf("\n\tEnter the Name you want to find\n");
	SimpleItemType data;
	data.SetNameFromKB();
	if (!FindByName(data)) printf("\n\tList has no name you want to search");
}

// 키보드로 부터 입력받은 usage 번호로 데이터 찾기
void PlaceType::FindUsageFromKB() {
	printf("\n\tEnter the Usage you want to find\n");
	SimpleItemType data;
	data.SetUsageFromKB();
	if (!FindByUsage(data)) printf("\n\tList has no usage you want to search");
}