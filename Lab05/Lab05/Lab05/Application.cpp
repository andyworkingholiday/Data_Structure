#include "pch.h"
#include "Application.h"

void Application::Run() {
	while (1) {
		m_Command = GetCommand();
		switch (m_Command) {
		case 1:		// read a record and add to list.
			AddItem();
			break;
		case 2:		// display all the records in list on screen.
			DisplayAllItem();
			break;
		case 3:
			DisplayItembyLocation(); // display all the items in list by input Storage.
			break;
		case 4:
			DisplayPhotobyLocation(); // display all the photos in list by input Storage.
			break;
		case 5:		// make empty list.
			MakeEmpty();
			break;
		case 6: // Retrieve item
			RetrieveItem();
			break;
		case 7: // Retrieve item from the input usage
			RetreiveRecordByMemberUsage();
			break;
		case 8: // Retrieve item with including input name
			RetreiveRecordByMemberName();
			break;
		case 9: // Retrieve item with including input name
			RetrieveByPday();
			break;
		case 10: // Delete item
			DeleteItem();
			break;
		case 11: // Replace item
			ReplaceItem();
			break;
		case 12: // Add photo
			AddPhoto();
			break;
		case 13: // Display photo
			DisplayPhoto();
			break;
		case 14: // Delete photo
			DeletePhoto();
			break;
		case 15: // Update photo
			UpdatePhoto();
			break;
		case 16: // Display Containers
			DisplayAllContainer();
			break;
		case 17: // Display All details Containers
			DisplayAllDetailsContainer();
			break;
		case 0: //end the program
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

int Application::GetCommand() {
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add Item" << endl;
	cout << "\t   2 : Display All the Items on screen" << endl;
	cout << "\t   3 : Display Items by Place" << endl;
	cout << "\t   4 : Display Photos by Place" << endl;
	cout << "\t   5 : Make empty list" << endl;
	cout << "\t   6 : Find item " << endl;
	cout << "\t   7 : Find item by usage " << endl;
	cout << "\t   8 : Find item by name " << endl;
	cout << "\t   9 : Find item by Purchasing day " << endl;
	cout << "\t   10 : Delete item " << endl;
	cout << "\t   11 : Replace item " << endl;
	cout << "\t   12 : Add Photo " << endl;
	cout << "\t   13 : Display Photo " << endl;
	cout << "\t   14 : Delete Photo " << endl;
	cout << "\t   15 : Update Photo " << endl;
	cout << "\t   16 : Display All Containers " << endl;
	cout << "\t   17 : Display All detail Containers " << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// Add new record into list.
int Application::AddItem() {
	cout << "\n\t 1. Put Item to the Master List (You know where to put)." << endl;
	cout << "\n\t 2. Put Item to the Temporary Storage (You don't know where to put)" << endl;
	cout << "\n\t 3. Find the Item from Temporary Storage and decide where to put." << endl;
	cout << "\n\t 4. Move First element from the Temporary List" << endl;
	cout << "\n\t Enter the Command : ";
	int command;
	cin >> command;
	cout << endl;

	switch (command) {
	case 1: //Masterlist�� �����鼭 Container�� �ֱ�
		AddItemToMasterListFromKB();
		return 1;
	case 2: //Temporary list���� �ֱ�
		AddItemToTempList();
		return 1;
	case 3: //Temporary list���� ���ϴ� ������ ã�� �� Masterlist�� �ֱ�
		AddItemToContainerFromTemp();
		return 1;
	case 4: //Temporary list�� ���� ������ ������ Master list�� �ֱ�
		AddItemToContainerFromTempFront();
		return 1;
	default: //�߸��Է�
		cout << "\tIllegal selection...Try again\n";
		AddItem();
		return 0;
	}
}

int Application::AddItemToMasterListFromKB() {
	ItemType data;
	data.SetRecordFromKB();

	return(AddItemToMasterList(data));
}

int Application::AddItemToMasterList(ItemType data) {
	if (MasterList.IsFull()) {
		printf("\tMaster List is Full\n"); // ������ ����Ʈ ���� á�� �� �ش� ���� ���
		return 0;
	}

	else {
		int location = data.GetStorageId();
		int container = data.GetContainerId();
		StorageType stype;
		ContainerType ctype;
		stype.SetStorageId(location); // location ��ġ �޾ƿ���
		ctype.SetContainerId(container); // �����̳� ��ȣ �޾ƿ���

		SimpleItemType simpledata;
		int sUsage = data.GetUsage();
		string sName = data.GetName();
		int sItemNumber = data.GetItemNum();
		simpledata.SetRecord(sUsage, sName, sItemNumber); //sdata�� data�� ��ġ�� �������� �־��ش�.

		int index = StorageList.RetrieveByBS(stype);
		if (index >= 0) { // �˻��� ��Ұ� �̹� ����� ������ ��
			if (stype.SearchContainer(ctype)) { // �����̳� ��ȣ�� �̹� ��ϵǾ� ���� ��
				ctype.AddItem(simpledata); // �ش� �����̳ʿ� ������ �߰�
				stype.UpdateContainer(ctype); // ������ �߰��� �����̳ʷ� ������Ʈ
				StorageList.Replace(stype); // ��� ������Ʈ
			}

			else { // �����̳� ��ȣ�� ó�� ��ϵ� ��
				ctype.AddItem(simpledata); // �ش� �����̳ʿ� ������ �߰�
				stype.AddContainer(ctype); // ������ �߰��� �����̳� ���� �߰�
				StorageList.Replace(stype); // ��� ������Ʈ
			}
		}

		else { // ��Ұ� ó�� ��ϵ� ��
			ctype.AddItem(simpledata); //�ش� �����̳ʿ� ������ �߰�
			stype.AddContainer(ctype); // ������ �߰��� �����̳� ���� �߰�
			StorageList.Add(stype); // ��� �߰�
		}

		MasterList.Add(data); // Container List�� �����鼭 MasterList���� �־��ش�. (Container�� ��á�µ� Master�� �־��� �� ���� ����)
		cout << "\n\t========= " << stype.GetLocation()<<" ========" << endl;
		ctype.DisplayAllItem(); // �����̳ʿ� �����ִ� ������ ��� ���
		return 1;
	}
}


int Application::AddItemToTempList() {
	if (TempList.IsFull()) {
		printf("\tTemporary List is Full\n"); //TempList ��á�� �� �Լ� ����
		return 0;
	}

	else {
		ItemType data;
		data.SetUsageFromKB();
		data.SetTimeFromSystem();
		data.SetPdayFromKB();
		data.SetBrandFromKB();
		data.SetNameFromKB();
		data.SetNumFromKB();
		data.SetItemNumFromKB(); // ��� �� �����̳ʸ� ������ data ������ �Է¹޴´�.
		TempList.Add(data);

		cout << "\n\t========= All the Temporary Storage Item ========" << endl;
		TempList.Display(); //Templist�� ��� ������ ���
		return 1;
	}

}

int Application::AddItemToContainerFromTemp() {
	TempList.Display(); // TempList�� �����۵��� ����Ͽ� � ������ �ű� �� �ִ� �� �˰����ش�.
	ItemType data;
	cout << "\n\t�ű�� ���� ��ǰ�� Item Number�� �Է����ּ���!" << endl;
	data.SetItemNumFromKB(); // Primary key�� �Է¹޾� �ű���� �ϴ� �������� �����Ѵ�.
	if (TempList.Search(data)) {
		cout << "\n\t ��ǰ�� ���� ��ġ" << endl;
		data.SetStorageIdFromKB();//Templist �����ۿ� �߰��� ��Ҹ� �־��ش�.
		data.SetContainerIdFromKB(); //Templist �����ۿ� �߰��� �����̳ʸ� �־��ش�.
		if (AddItemToMasterList(data)) {
			TempList.Delete(data); //Master�� �����鼭 Templist delete
			cout << "\n\t Move Success!" << endl;
			return 1;
		}
		else { // Master�� �����ų� Container, ��Ұ� ������ ���� �� ���� �� �ű�� ����
			cout << "\n\t Move Failed!" << endl;
			return 0;
		}
	}
	else { //��ġ�ϴ� ������ ��ȣ�� ���� �� ��� �� �Լ� ����
		cout << "\n\t There is no Item Number you want to delete" << endl;
		return 0;
	}
}

int Application::AddItemToContainerFromTempFront() {
	if (!TempList.IsEmpty()) {
		TempList.DisplayFront(); // TempList�� ���� ������ �������� ����Ͽ� � ������ �ű� �� �ִ� �� �˰����ش�.
		ItemType data;
		TempList.Frontdata(data); //data�� ���� ������ �������� ����.
		cout << "\n\t ��ǰ�� ���� ��ġ" << endl;
		data.SetStorageIdFromKB();//Templist �����ۿ� �߰��� ��Ҹ� �־��ش�.
		data.SetContainerIdFromKB(); //Templist �����ۿ� �߰��� �����̳ʸ� �־��ش�.
		if (AddItemToMasterList(data)) {
			TempList.DeltefromFront(data);  //Master�� �����鼭 Templist delete
			cout << "\n\t Move Success!" << endl;
			return 1;
		}
		else { // Master�� �����ų� Container�� ������ ���� �� ���� �� �ű�� ����
			cout << "\n\t Move Failed!" << endl;
			return 0;
		}
	}

	else { //Templist ����� �� �Լ� ����
		cout << "Temporary List is Empty" << endl;
		return 0;
	}
}

// ����Ʈ�� ��� ��� ������ ���
void Application::DisplayAllItem() {
	cout << "\n\t 1. Display All the Item in the Master List" << endl;
	cout << "\n\t 2. Display the Item in the Temporary Storage" << endl;
	cout << "\n\t Enter the Command : ";
	int command;
	cin >> command;
	cout << endl;
	StorageType stype;

	switch (command) {
	case 1: // Master List�� ��� ������ ���
		cout << "\n\t========= All the Item ========" << endl;
		MasterList.Print();
		break;
	case 2: // Temporary List�� ��� ������ ���
		cout << "\n\t========= All the Temporary Storage Item ========" << endl;
		TempList.Display();
		break;

	default: //�Է� ����
		cout << "\tIllegal selection...Try again\n";
		DisplayAllItem();
		break;
	}
}

void Application::DisplayItembyLocation() {
	StorageType stype;
	stype.SetStorageIdFromKB();
	if (StorageList.RetrieveByBS(stype) != -1) {
		stype.DisplayAllItem();
	}
}

void Application::DisplayPhotobyLocation() {
	StorageType stype;
	stype.SetStorageIdFromKB();
	if (StorageList.RetrieveByBS(stype) != -1) {
		stype.DisplayAllPhoto();
	}
}

void Application::MakeEmpty() {
	cout << "\n\t 1. Reset All the Item" << endl;
	cout << "\n\t 2. Reset All the Item in the Temporary Storage" << endl;
	cout << "\n\t Enter the Command : ";
	int command;
	cin >> command;
	cout << endl;

	switch (command) {
	case 1: //MasterList�� �ִ� ��� ������ Reset, ���ÿ� Container List�� Reset
		MasterList.MakeEmpty();
		StorageList.MakeEmpty();
		cout << "\n\t Reset Success!" << endl;
		break;
	case 2: //Temporary List�� �ִ� ��� Item Reset
		TempList.MakeEmpty();
		cout << "\n\t Reset Success!" << endl;
		break;

	default: //�Է¿���
		cout << "\tIllegal selection...Try again\n";
		DisplayAllItem();
		break;
	}
}

// Open a file by file descriptor as an input file.
int Application::OpenInFile(char *fileName) {
	m_InFile.open(fileName);
	if (m_InFile) return 1;
	else return 0;
}

// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName) {
	m_OutFile.open(fileName);
	if (m_OutFile) return 1;
	else return 0;
}

//Replace item with binary search
void Application::RetrieveItem() {

	cout << "\n\t 1. Find Item from the Master List " << endl; // MasterList�� ������ �˻�
	cout << "\n\t 2. Find Item from the Temporary List " << endl; //Temprorary List�� ������ �˻�
	cout << "\n\t Enter the Command : ";
	int command;
	cin >> command;
	cout << endl;

	switch (command) {
	case 1:
		RetrieveItemFromMaster();
		break;
	case 2:
		RetrieveItemFromTemp();
		break;

	default:
		cout << "\tIllegal selection...Try again\n"; //�Է� ����
		RetrieveItem();
		break;
	}
}

//Retrieve item with binary search from Master
void Application::RetrieveItemFromMaster() {
	ItemType t;
	printf("\n\tEnter the Item Number you want to find.\n");
	t.SetItemNumFromKB();

	if (MasterList.Get(t)) { // MasterList���� ��� �������� ����Ž������ ã���ϴ�.
		printf("\n\tThe Item's data : \n");
		t.DisplayRecordOnScreen();
	}
	else printf("\n\tThere is no Item you want to find.\n");

}

//Retrieve item with binary search from Master
void Application::RetrieveItemFromTemp() {
	ItemType t;
	printf("\n\tEnter the Item Number you want to find.\n");
	t.SetItemNumFromKB();

	if (TempList.Search(t)) { // TempList���� ��� �������� ����Ž������ ã���ϴ�.
		printf("\n\tThe Item's data : \n");
		t.DisplayUsageOnScreen();
		t.DisplayRtimeOnScreen();
		t.DisplayPdayOnScreen();
		t.DisplayBrandOnScreen();
		t.DisplayNameOnScreen();
		t.DisplayNumOnScreen();
		t.DisplayItemNumOnScreen();
		cout << endl;
	}
	else printf("\n\tThere is no Item you want to find.\n");
}


//Delete item with binary search
void Application::DeleteItem() {

	cout << "\n\t 1. Delete Item from the Master List " << endl; // MasterList�� ������ �����
	cout << "\n\t 2. Delete Item from the Temporary List " << endl; //Temprorary List�� ������ �����
	cout << "\n\t Enter the Command : ";
	int command;
	cin >> command;
	cout << endl;

	switch (command) {
	case 1:
		DeleteItemFromMaster();
		break;
	case 2:
		DeleteItemFromTemp();
		break;

	default:
		cout << "\tIllegal selection...Try again\n"; //�Է� ����
		DeleteItem();
		break;
	}
}

//Delete item from MasterList
int Application::DeleteItemFromMaster() {
	ItemType data;
	StorageType stype;
	ContainerType ctype;
	SimpleItemType Sdata;
	printf("\n\tEnter the Item Number you want to delete.\n");
	data.SetItemNumFromKB();
	if (MasterList.Delete(data)) { // MasterList�� �ش� data ���� �� �����ϸ鼭 ���ÿ� data �о��
		int location = data.GetStorageId();
		int container = data.GetContainerId();
		int iNum = data.GetItemNum();
		Sdata.SetItemNum(iNum);

		stype.SetStorageId(location); // ��ġ set
		ctype.SetContainerId(container); // �����̳� set
		StorageList.RetrieveByBS(stype);
		stype.SearchContainer(ctype); // stype�� ��Ҹ� Set �ϰ� ��ҿ� ���� �������� ã�´�.
		
		ctype.DeleteItem(Sdata); // �ݵ�� data�� ���� �� �ۿ� �����Ƿ� �ش� Sdata ����
		stype.UpdateContainer(ctype);
		StorageList.Replace(stype); //�����Ϸ� �� Cdata�� Container List ���� ����

		cout << "\n\t========= All the " << stype.GetLocation() << " Storage Item ========" << endl; // ���� �Ϸ� �� ����Ʈ �����ش�.
		stype.DisplayAllContainer();
		return 1;
	}

	else {
		printf("\n\t There is No Item you want to Delete!\n"); // �ش� Item Number�� ���� ��
		return 0;
	}
}

//Delete item from Temporary List
int Application::DeleteItemFromTemp() {
	ItemType data;
	printf("\n\tEnter the Item Number you want to delete.\n");
	data.SetItemNumFromKB();
	if (TempList.Delete(data)) { // Temporary List�� �ش� data ���� �� �����ϸ鼭 ���ÿ� data �о��
		cout << "\n\t========= All the Temporary Storage Item ========" << endl;
		TempList.Display(); // ���� �Ϸ� �� ����Ʈ �����ش�.
		return 1;
	}

	else {
		printf("\n\t There is No Item you want to Delete!\n");  // �ش� Item Number�� ���� ��
		return 0;
	}
}

//Replace item with binary search
void Application::ReplaceItem() {

	cout << "\n\t 1. Replace Item from the Master List " << endl; // MasterList�� ������ ����
	cout << "\n\t 2. Replace Item from the Temporary List " << endl; // Temporary List�� ������ ����
	cout << "\n\t Enter the Command : ";
	int command;
	cin >> command;
	cout << endl;

	switch (command) {
	case 1:
		ReplaceItemFromMaster();
		break;
	case 2:
		ReplaceItemFromTemp();
		break;

	default:
		cout << "\tIllegal selection...Try again\n"; //�Է� ����
		ReplaceItem();
		break;
	}
}

//Replace item from MasterList
int Application::ReplaceItemFromMaster() {
	ItemType data, origin;
	StorageType stype;
	ContainerType ctype;
	SimpleItemType sdata;
	printf("\n\tEnter the Item Number you want to Replace.\n");
	data.SetItemNumFromKB();
	if (MasterList.Get(data)) { // MasterList�� �ش� data ���� �� 
		data.SetUsageFromKB();
		data.SetStorageIdFromKB();
		data.SetContainerIdFromKB();
		data.SetTimeFromSystem();
		data.SetPdayFromKB();
		data.SetBrandFromKB();
		data.SetNameFromKB();
		data.SetNumFromKB(); // ������ ������ȣ�� ������ ��� ������ ���� �Է¹޴´�.
		origin.SetItemNum(data.GetItemNum()); // �����ִ� �������� ã�� ���� ��� set
		MasterList.Get(origin);
		MasterList.Replace(data); // �����͸���Ʈ�� ������ ����

		//���� ���� ����
		stype.SetStorageId(origin.GetContainerId()); 
		ctype.SetContainerId(origin.GetContainerId());
		sdata.SetItemNum(origin.GetItemNum());
		StorageList.RetrieveByBS(stype);
		stype.SearchContainer(ctype);
		ctype.DeleteItem(sdata);
		stype.UpdateContainer(ctype);
		StorageList.Replace(stype);

		//���ο� ������ �߰�
		int location = data.GetStorageId();
		int container = data.GetContainerId();
		int iNum = data.GetItemNum();
		string iName = data.GetName();
		int iUsage = data.GetUsage();
		sdata.SetRecord(iUsage, iName, iNum); //���ŵ� Container List�� ���ο� ���ڵ� ����

		stype.SetStorageId(location);
		ctype.SetContainerId(container);

		// ������ �߰��ϴ� �Լ��� Add�� ������ ����.
		int index = StorageList.RetrieveByBS(stype);
		if (index >= 0) {
			if (stype.SearchContainer(ctype)) {
				ctype.AddItem(sdata);
				stype.UpdateContainer(ctype);
				StorageList.Replace(stype);
			}

			else {
				ctype.AddItem(sdata);
				stype.AddContainer(ctype);
				StorageList.Replace(stype);
			}
		}

		else {
			ctype.AddItem(sdata);
			stype.AddContainer(ctype);
			StorageList.Add(stype);
		}
		return 1;
	}

	else {
		printf("\n\t There is No Item you want to Replace!\n"); // �ش� ItemNumber �߰� ������ �� ���
		return 0;
	}
}

//Replace item from Temporary list
int Application::ReplaceItemFromTemp() {
	ItemType data;
	printf("\n\tEnter the Item Number you want to Replace.\n");
	data.SetItemNumFromKB();
	if (TempList.Search(data)) { // Temporary List�� �ش� data ���� �� 
		data.SetUsageFromKB();
		data.SetTimeFromSystem();
		data.SetPdayFromKB();
		data.SetBrandFromKB();
		data.SetNameFromKB();
		data.SetNumFromKB(); // ���ο� data�� �Է¹���.
		TempList.Replace(data);  // �Է¹��� data�� Replace
		cout << "\n\t========= All the Temporary Storage Item ========" << endl; // Temporay List�� ��� ������ ���
		TempList.Display();
		return 1;
	}

	else {
		printf("\n\t There is No Item you want to Replace!\n"); // �ش� ItemNumber �߰� ������ �� ���
		return 0;
	}
}

// Ű����� ���� �Է¹��� usage ��ȣ�� ������ ã��
int Application::RetreiveRecordByMemberUsage() {
	printf("\n\tEnter the Usage you want to find\n");
	ItemType data;
	data.SetUsageFromKB();
	if (SearchListByMemberUsage(data)) return 1;
	return 0;
}

// ����Ʈ�� ó������ ������ Ž���ϸ鼭 ��ġ�ϴ� usage ��ȣ�� �ִ� �� �˻��Ѵ�.
int Application::SearchListByMemberUsage(ItemType &inData) {

	DoublyIterator<ItemType> itor = MasterList;
	ItemType CurData;
	int len = MasterList.GetLength();

	bool found = false;
	while (len--) {
		CurData = itor.Next();
		if (CurData.GetUsage() == inData.GetUsage()) {
			CurData.DisplayRecordOnScreen();
			ContainerType Ctype;
			StorageType Stype;
			Ctype.SetContainerId(CurData.GetContainerId());
			Stype.SetStorageId(CurData.GetStorageId());
			StorageList.RetrieveByBS(Stype);
			Stype.SearchContainer(Ctype);
			Ctype.DisplayAllPhoto();
			found = true;
		}
	}
	if (found) return 1;
	printf("\n\tList has no usage you want to search");
	return 0;
}

// Ű����� ���� �Է¹��� name���� ������ ã��
int Application::RetreiveRecordByMemberName() {
	printf("\n\tEnter the name you want to find\n");
	ItemType data;
	data.SetNameFromKB();
	if (SearchListByMemberName(data)) return 1;
	return 0;
}

// ����Ʈ�� ó������ ������ Ž���ϸ鼭 �ش� string�� ���ԵŴ��� �˻��Ѵ�.
int Application::SearchListByMemberName(ItemType &inData) {

	DoublyIterator<ItemType> itor = MasterList;
	ItemType CurData;
	int len = MasterList.GetLength();

	bool found = false;
	while (len--) {
		CurData = itor.Next();
		if (CurData.GetName().find(inData.GetName()) != -1) { //string member �Լ� find ��� �ش� string�� �������� ������ -1�� return �ϴ� �Լ�
			CurData.DisplayRecordOnScreen();
			found = true;
		}
	}
	if (found) return 1;
	printf("\n\tList has no name you want to search");
	return 0;
}

// Ű����� ���� �Է¹��� name���� ������ ã��
int Application::RetrieveByPday() {
	printf("\n\tEnter the Purchasing year you want to find\n");
	ItemType data1, data2;
	int year1, year2;
	cout << "\t=============== YYYY =============== ex(2020)" << endl;
	cout << "\t�˻� ���� �⵵ : ";
	cin >> year1;
	cout << endl;
	cout << "\t=============== YYYY =============== ex(2020)" << endl;
	cout << "\t�˻� �� �⵵ : ";
	cin >> year2;
	cout << endl;
	year1 *= 10000;
	year2 *= 10000;
	data1.SetPday(year1);
	data2.SetPday(year2);


	if (SearchListByMemberPday(data1, data2)) return 1;
	return 0;
}

// ����Ʈ�� ó������ ������ Ž���ϸ鼭 Data1�� Data2���̿� �ִ� Purchaing day�� Item�� ã�´�.
int Application::SearchListByMemberPday(ItemType &inData1, ItemType &inData2) {

	DoublyIterator<ItemType> itor = MasterList;
	ItemType CurData;
	int len = MasterList.GetLength();

	bool found = false;
	while (len--) {
		CurData = itor.Next();
		if (CurData.GetPday() >= inData1.GetPday() && CurData.GetPday() <= inData2.GetPday()) {
			CurData.DisplayRecordOnScreen();
			found = true;
		}
	}
	if (found) return 1;
	printf("\n\tList has no Purchasing day you want to search");
	return 0;
}

// Add photo to Container List
int Application::AddPhoto() {
	StorageType stype;
	ContainerType ctype;
	string s;
	cout << "\n\tFind the Place to take Photo!" << endl;
	stype.SetStorageIdFromKB(); // ���� string�� �� �ش� Container List�� ID�� �Է¹޴´�.
	if (StorageList.RetrieveByBS(stype) != -1) {
		cout << "\n\tFind the Container to take Photo!" << endl;
		ctype.SetContainerIdFromKB();
		if (stype.SearchContainer(ctype)) {
			
			cout << "\n\tPhoto Name : ";
			cin >> s;
			cout << endl;
			ctype.AddPhoto(s); // ���� List ��� ������ ��Ʈ�� s �߰�
			stype.UpdateContainer(ctype);  //Ctype�� �ش� StorageType�� container ��ü
			StorageList.Replace(stype);
			ctype.DisplayAllPhoto(); //  �ش� Container List�� ���� ��� ���
			return 1;
		}

		else {
			cout << "\n\tPhoto Name : ";
			cin >> s;
			cout << endl;
			ctype.AddPhoto(s); // ���� List ��� ������ ��Ʈ�� s �߰�
			stype.AddContainer(ctype);
			StorageList.Replace(stype);
			ctype.DisplayAllPhoto();
			return 1;
		}	
	}

	else { // ��Ұ� ó�� ��ϵ� ��
		cout << "\n\tFind the Container to take Photo!" << endl;
		ctype.SetContainerIdFromKB();
		cout << "\n\tPhoto Name : ";
		cin >> s;
		cout << endl;
		ctype.AddPhoto(s); //�ش� �����̳ʿ� ���� �߰�
		stype.AddContainer(ctype); // ���� �߰��� �����̳� ���� �߰�
		StorageList.Add(stype); // ��� �߰�
		return 1;
	}

}

// Display photo from Container List
void Application::DisplayPhoto() {
	StorageType stype;
	ContainerType ctype;
	cout << "\n\tFind the Place to Display Photo!" << endl;
	stype.SetStorageIdFromKB(); // ���� string�� Display �� �ش� Container List�� ID�� �Է¹޴´�.
	if (StorageList.RetrieveByBS(stype) != -1) {
		cout << "\n\tFind the Container to Display Photo!" << endl;
		ctype.SetContainerIdFromKB();
		stype.SearchContainer(ctype);
		ctype.DisplayAllPhoto(); //�ش� Container List�� ��� ���� ��� ���
	}

	else {
		cout << "\n\t The Place Storage has to be initialized" << endl; // ���� Container List�� ���� �� ���
	}
}

// Delete photo from Container List
int Application::DeletePhoto() {
	StorageType stype;
	ContainerType ctype;
	cout << "\n\tFind the Place to Delete Photo!" << endl;
	stype.SetStorageIdFromKB(); // ���� string�� �� �ش� Container List�� ID�� �Է¹޴´�.
	if (StorageList.RetrieveByBS(stype) != -1) {
		cout << "\n\tFind the Container to Delete Photo!" << endl;
		ctype.SetContainerIdFromKB();
		if (stype.SearchContainer(ctype)) {
			string s;
			cout << "\n\tPhoto Name : ";
			cin >> s;
			cout << endl;
			ctype.DeletePhoto(s); // ���� List ��� ������ ��Ʈ�� s �߰�
			stype.UpdateContainer(ctype);  //Ctype�� �ش� StorageType�� container ��ü
			StorageList.Replace(stype);
			ctype.DisplayAllPhoto(); //  �ش� Container List�� ���� ��� ���
			return 1;
		}
		else {
			cout << "\n\t There is no Container you Enter" << endl;
			return 0;
		}
	}

	else {
		cout << "\n\t The Place Storage has to be initialized" << endl; // ���� Container List�� ���� �� ���
		return 0;
	}
}


// Update photo from Container List
int Application::UpdatePhoto() {
	StorageType stype;
	ContainerType ctype;
	cout << "\n\tFind the Place to Update Photo!" << endl;
	stype.SetStorageIdFromKB(); // ���� string�� �� �ش� Container List�� ID�� �Է¹޴´�.
	if (StorageList.RetrieveByBS(stype) != -1) { // Place ã�� ��
		cout << "\n\tFind the Container to Update Photo!" << endl;
		ctype.SetContainerIdFromKB();
		if (stype.SearchContainer(ctype)) {
			ctype.DisplayAllPhoto(); //�ش� Container List�� ��� ���� ��� ���
			cout << endl;
			string oldPhoto, newPhoto; // �����̸� , �����̸�
			cout << "\n\tPhoto Name to delete : ";
			cin >> oldPhoto;
			cout << endl;

			if (ctype.DeletePhoto(oldPhoto)) { //��ġ�ϴ� string�� Container List�� ���� ����
				cout << "\n\tNew Photo Name : ";
				cin >> newPhoto;
				ctype.AddPhoto(newPhoto);
				stype.UpdateContainer(ctype);
				StorageList.Replace(stype);
				ctype.DisplayAllPhoto(); //���� �� ���� ��� ���
				return 1;
			}

			else {
				cout << "\n\t The Photo Name not found!" << endl; // �̸� �߰� ����
				return 0;
			}
		}
		else {
			cout << "\n\t The Container not found!" << endl; // �̸� �߰� ����
			return 0;
		}
	}

	else {
		cout << "\n\t The Place Storage has to be initialized" << endl; // ���� Storage List�� ���� �� ���
		return 0;
	}
}

// Display All the Container
void Application::DisplayAllContainer() {
	StorageType stype;
	stype.SetStorageIdFromKB();
	int index = StorageList.RetrieveByBS(stype);
	if (index >= 0) {
		stype.DisplayAllContainer();
	}

	else 
		cout << "\n\t The Place Storage has to be initialized" << endl; // ���� Storage List�� ���� �� ���		
}

void Application::DisplayAllDetailsContainer() {
	StorageType stype;
	stype.SetStorageIdFromKB();
	int index = StorageList.RetrieveByBS(stype);
	if (index >= 0) {
		stype.DisplayAllDetailContainer(MasterList);
	}

	else
		cout << "\n\t The Place Storage has to be initialized" << endl; // ���� Container List�� ���� �� ���
}