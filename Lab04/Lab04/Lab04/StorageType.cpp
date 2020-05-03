#include "StorageType.h"

// Set Storage Id
void StorageType::SetStorageId(int inId) {
	this->StorageId = inId;
	if (inId == 1) Location = "LivingRoom";
	else if (inId == 2) Location = "Kitchen";
	else if (inId == 3) Location = "BathRoom";
	else if (inId == 4) Location = "BedRoom";
	else if (inId == 5)Location = "Library";
	else Location = "Etc";
}

// Set Storage Id from keyboard
void StorageType::SetStorageIdFromKB() {
	cout << "\tEnter the number with Suitable Place" << endl;
	cout << "\t=============== Place ===============" << endl;
	cout << "\t1 : LivingRoom         " << "4 : BedRoom" << endl;
	cout << "\t2 : Kitchen            " << "5 : Library" << endl;
	cout << "\t3 : BathRoom           " << "0 : Etc" << endl;
	int number;
	printf("\tPlace    : ");
	cin >> number;

	if (number <= 5) SetStorageId(number);
	else {
		cout << "\tIllegal selection...try again\n";
		SetStorageIdFromKB();
	}
}

// Search Container using Get Function of SingleLinkedList
int StorageType::SearchContainer(ContainerType& data) {
	return(ContainerList.Get(data));
}

// Add Container using Add Function of SingleLinkedList
int StorageType::AddContainer(ContainerType& data) {
	if (CurrentNum < MaxNum) {
		ContainerList.Add(data);
		CurrentNum++;
		return 1;
	}
	return 0;
}

// Delete Container using Delete Function of SingleLinkedList
int StorageType::DeleteContainer(ContainerType& data) {
	if (ContainerList.Delete(data)) {
		CurrentNum--;
		return 1;
	}
	return 0;
}

// Update Container using Update Function of SingleLinkedList
int StorageType::UpdateContainer(ContainerType& data) {
	return(ContainerList.Replace(data));
}

// Display All the Container using Print function of SingleLinkedList
void StorageType::DisplayAllContainer() {
	cout << "\n\t========= " << Location << " ========" << endl;
	ContainerType c;
	int len = ContainerList.GetLength();
	ContainerList.ResetList();
	while (len--) { // �����̳��� ������ŭ ���鼭 �ش� ������ ����Ѵ�
		ContainerList.GetNextItem(c);
		cout << "\n\t========= Container" << c.GetContainerId() << " ========" << endl << endl;
		c.DisplayAllItem(); //������ ���� ���
		c.DisplayAllPhoto(); // ���� ���� ���
	}
}

// Display All the Photo using Print function of UnsortedList
void StorageType::DisplayAllDetailContainer(SortedList<ItemType>& ref) {
	cout << "\n\t========= " << Location << " ========" << endl;
	ContainerType c;
	int len = ContainerList.GetLength();
	ContainerList.ResetList();
	while (len--) { // �����̳��� ������ŭ ���鼭 �ش� ������ ����Ѵ�
		ContainerList.GetNextItem(c);
		cout << "\n\t========= Container" << c.GetContainerId() << " ========" << endl << endl;
		c.DisplayAllDetailsItem(ref); //�����͸���Ʈ ���� �� ������ ���� �ڼ��� ���
		c.DisplayAllPhoto(); // ���� ���� ���
	}
}

void StorageType::DisplayAllItem() {
	cout << "\n\t========= " << Location << " ========" << endl << endl;
	int len = ContainerList.GetLength();
	ContainerType c;
	ContainerList.ResetList();
	while (len--) { // �����̳��� ������ŭ ���鼭 ������ ������ ����Ѵ�
		ContainerList.GetNextItem(c);
		c.DisplayAllItem(); //������ ���� ���
	}
}
