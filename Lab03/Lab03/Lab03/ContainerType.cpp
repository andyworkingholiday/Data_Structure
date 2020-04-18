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
	if (inId == 1) Location = "LivingRoom";
	else if (inId == 2) Location = "Kitchen";
	else if (inId == 3) Location = "BathRoom";
	else if (inId == 4) Location = "BedRoom";
	else if (inId == 5)Location = "Library";
	else Location = "Etc";
}

// Set Container Id from keyboard
void ContainerType::SetContainerIdFromKB() {
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
void ContainerType::AddItem(SimpleItemType& data) {
	SimpleItemList.Add(data);
	NumofItem++;
}

// Delete Item using Delete Function of UnsortedList
int ContainerType::DeleteItem(SimpleItemType& data) {
	return(SimpleItemList.Delete(data));
	NumofItem--;
}

// Update Item using Update Function of UnsortedList
int ContainerType::UpdateItem(SimpleItemType& data) {
	return(SimpleItemList.Replace(data));
}

// Add Photo(string) using Add Function of UnsortedList
int ContainerType::AddPhoto(string s) {
	return (PhotoList.Add(s));
	NumofPhoto++;
}

// Delete Photo(string) using Delete Function of UnsortedList
int ContainerType::DeletePhoto(string& s) {
	return (PhotoList.Delete(s));
	NumofPhoto--;
}

// Update Photo(string) using Update Function of UnsortedList
int ContainerType::UpdatePhoto(string s) {
	return (PhotoList.Replace(s));
}

// Display All the item using Print function of UnsortedList
void ContainerType::DisplayAllItem() {
	if (SimpleItemList.IsEmpty()) return;
	cout << "\n\t========= " << Location << " List" << " ========" << endl;
	SimpleItemList.Print();
}

// Display All the Photo using Print function of UnsortedList
void ContainerType::DisplayAllPhoto() {
	if (PhotoList.IsEmpty()) return;

	cout << "\n\t========= " << Location << " Photo List" << " ========" << endl;
	PhotoList.Print();
}

// ���ø���Ʈ�� ó������ ������ Ž���ϸ鼭 �ش� string�� ���ԵŴ��� �˻��Ѵ�.
int ContainerType::FindByName(SimpleItemType data) {
	SimpleItemType CurData;
	SimpleItemList.ResetList();
	int len = SimpleItemList.GetLength();
	bool found = false;
	while (len--) {
		SimpleItemList.GetNextItem(CurData);
		if (CurData.GetName().find(data.GetName()) != -1) { //string member �Լ� find ��� �ش� string�� �������� ������ -1�� return �ϴ� �Լ�
			CurData.DisplayRecordOnScreen();
			found = true;
		}
	}
	if (found) return 1;
	return 0;
}

// ����Ʈ�� ó������ ������ Ž���ϸ鼭 ��ġ�ϴ� usage ��ȣ�� �ִ� �� �˻��Ѵ�.
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

// Ű����� ���� �Է¹��� name���� ������ ã��
void ContainerType::FindNameFromKB() {
	printf("\n\tEnter the Name you want to find\n");
	SimpleItemType data;
	data.SetNameFromKB();
	if (!FindByName(data)) printf("\n\tList has no name you want to search");
}

// Ű����� ���� �Է¹��� usage ��ȣ�� ������ ã��
void ContainerType::FindUsageFromKB() {
	printf("\n\tEnter the Usage you want to find\n");
	SimpleItemType data;
	data.SetUsageFromKB();
	if (!FindByUsage(data)) printf("\n\tList has no usage you want to search");
}