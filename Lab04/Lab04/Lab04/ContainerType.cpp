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
	cout << "\tStorage    : ";
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

// �����͸���Ʈ�� �����Ͽ� ������������ �ڼ��� ����Ѵ�.
void ContainerType::DisplayAllDetailsItem(SortedList<ItemType>& ref) {
	SimpleItemType CurData;
	
	SimpleItemList.ResetList(); // ó����ġ���� Ž���ϱ� ���� simpleitemlist reset
	int len = SimpleItemList.GetLength();
	while (len--) { //simpleitemlist�� ��� �������� ������ŭ �ݺ�
		SimpleItemList.GetNextItem(CurData); // ������ ����
		int prime_number = CurData.GetItemNum();
		ItemType cItem;
		cItem.SetItemNum(prime_number); //�����۰� ��ġ�ϴ� ���̵� �����͸���Ʈ���� ���� 
		ref.RetrieveByBS(cItem); // ������ ���̵��� �����;����� ����
		cItem.DisplayRecordOnScreen(); //���
	}
}