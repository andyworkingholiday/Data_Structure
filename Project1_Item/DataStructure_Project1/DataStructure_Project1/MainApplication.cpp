#include "pch.h"
#include "MainApplication.h"

void MainApplication::Run() {
	LoadDB();
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
		case 10:
			RetrieveByHeart();
			break;
		case 11: // Delete item
			DeleteItem();
			break;
		case 12: // Replace item
			ReplaceItem();
			break;
		case 13: // Add photo
			AddPhoto();
			break;
		case 14: // Display photo
			DisplayPhoto();
			break;
		case 15: // Delete photo
			DeletePhoto();
			break;
		case 16: // Update photo
			UpdatePhoto();
			break;
		case 17: // Display Containers
			DisplayAllDetailsContainer();
			break;
		case 0: //end the program
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}

	SaveDB();
}

int MainApplication::GetCommand() {
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
	cout << "\t   10 : Find item by Heart " << endl;
	cout << "\t   11 : Delete item " << endl;
	cout << "\t   12 : Replace item " << endl;
	cout << "\t   13 : Add Photo " << endl;
	cout << "\t   14 : Display Photo " << endl;
	cout << "\t   15 : Delete Photo " << endl;
	cout << "\t   16 : Update Photo " << endl;
	cout << "\t   17 : Display All detail Containers " << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// Add new record into list.
int MainApplication::AddItem() {
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

int MainApplication::AddItemToMasterListFromKB() {
	ItemType data;
	data.SetRecordFromKB();

	return(AddItemToMasterList(data));
}

int MainApplication::AddItemToMasterList(ItemType data) {
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

		if (PlaceList.Get(stype)) { // �˻��� ��Ұ� �̹� ����� ������ ��
			if (stype.SearchContainer(ctype)) { // �����̳� ��ȣ�� �̹� ��ϵǾ� ���� ��
				ctype.AddItem(simpledata); // �ش� �����̳ʿ� ������ �߰�
				stype.UpdateContainer(ctype); // ������ �߰��� �����̳ʷ� ������Ʈ
				PlaceList.Replace(stype); // ��� ������Ʈ
			}

			else { // �����̳� ��ȣ�� ó�� ��ϵ� ��
				ctype.AddItem(simpledata); // �ش� �����̳ʿ� ������ �߰�
				stype.AddContainer(ctype); // ������ �߰��� �����̳� ���� �߰�
				PlaceList.Replace(stype); // ��� ������Ʈ
			}
		}

		else { // ��Ұ� ó�� ��ϵ� ��
			ctype.AddItem(simpledata); //�ش� �����̳ʿ� ������ �߰�
			stype.AddContainer(ctype); // ������ �߰��� �����̳� ���� �߰�
			PlaceList.Add(stype); // ��� �߰�
		}

		MasterList.Add(data); // Container List�� �����鼭 MasterList���� �־��ش�. (Container�� ��á�µ� Master�� �־��� �� ���� ����)
		RecentList.Add(data);
		cout << "\n\t========= " << stype.GetLocation()<<" ========" << endl;
		ctype.DisplayAllItem(); // �����̳ʿ� �����ִ� ������ ��� ���
		return 1;
	}
}


int MainApplication::AddItemToTempList() {
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
		data.SetHeartFromKB();
		data.SetItemNumFromKB(); // ��� �� �����̳ʸ� ������ data ������ �Է¹޴´�.
		TempList.Add(data);
		RecentList.Add(data);
		cout << "\n\t========= All the Temporary Storage Item ========" << endl;
		TempList.Display(); //Templist�� ��� ������ ���
		return 1;
	}

}

int MainApplication::AddItemToContainerFromTemp() {
	TempList.Display(); // TempList�� �����۵��� ����Ͽ� � ������ �ű� �� �ִ� �� �˰����ش�.
	ItemType data;
	cout << "\n\t�ű�� ���� ��ǰ�� Item Number�� �Է����ּ���!" << endl;
	data.SetItemNumFromKB(); // Primary key�� �Է¹޾� �ű���� �ϴ� �������� �����Ѵ�.
	if (TempList.Search(data)) {
		RecentList.Delete(data);
		cout << "\n\t ��ǰ�� ���� ��ġ" << endl;
		data.SetStorageIdFromKB();//Templist �����ۿ� �߰��� ��Ҹ� �־��ش�.
		data.SetContainerIdFromKB(); //Templist �����ۿ� �߰��� �����̳ʸ� �־��ش�.
		if (AddItemToMasterList(data)) {
			RecentList.Add(data);
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

int MainApplication::AddItemToContainerFromTempFront() {
	if (!TempList.IsEmpty()) {
		TempList.DisplayFront(); // TempList�� ���� ������ �������� ����Ͽ� � ������ �ű� �� �ִ� �� �˰����ش�.
		ItemType data;
		TempList.Frontdata(data); //data�� ���� ������ �������� ����.
		RecentList.Delete(data);
		cout << "\n\t ��ǰ�� ���� ��ġ" << endl;
		data.SetStorageIdFromKB();//Templist �����ۿ� �߰��� ��Ҹ� �־��ش�.
		data.SetContainerIdFromKB(); //Templist �����ۿ� �߰��� �����̳ʸ� �־��ش�.
		if (AddItemToMasterList(data)) {
			RecentList.Add(data);
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
void MainApplication::DisplayAllItem() {
	cout << "\n\t 1. Display All the Item in the Master List" << endl;
	cout << "\n\t 2. Display the Item in the Temporary Storage" << endl;
	cout << "\n\t 3. Display the Item in the Recent Storage" << endl;
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
	case 3:
		cout << "\n\t========= All the Recent Storage Item ========" << endl;
		RecentList.Display();
		break;

	default: //�Է� ����
		cout << "\tIllegal selection...Try again\n";
		DisplayAllItem();
		break;
	}
}

void MainApplication::DisplayItembyLocation() {
	StorageType stype;
	stype.SetStorageIdFromKB();
	if (PlaceList.Get(stype)) {
		stype.DisplayAllItem();
	}
}

void MainApplication::DisplayPhotobyLocation() {
	StorageType stype;
	stype.SetStorageIdFromKB();
	if (PlaceList.Get(stype)) {
		stype.DisplayAllPhoto();
	}
}

void MainApplication::MakeEmpty() {
	cout << "\n\t 1. Reset All the Item" << endl;
	cout << "\n\t 2. Reset All the Item in the Temporary Storage" << endl;
	cout << "\n\t Enter the Command : ";
	int command;
	cin >> command;
	cout << endl;

	switch (command) {
	case 1: //MasterList�� �ִ� ��� ������ Reset, ���ÿ� Container List�� Reset
		MasterList.MakeEmpty();
		PlaceList.MakeEmpty();
		RecentList.MakeEmpty();
		cout << "\n\t Reset Success!" << endl;
		break;
	case 2: //Temporary List�� �ִ� ��� Item Reset
		TempList.MakeEmpty();
		RecentList.MakeEmpty();
		cout << "\n\t Reset Success!" << endl;
		break;

	default: //�Է¿���
		cout << "\tIllegal selection...Try again\n";
		DisplayAllItem();
		break;
	}
}

int MainApplication::OpenInFile(char* fileName) {
	m_InFile.open(fileName);
	if (m_InFile) return 1;
	else return 0;
}

// Open a file by file descriptor as an output file.
int MainApplication::OpenOutFile(char* fileName) {
	m_OutFile.open(fileName);
	if (m_OutFile) return 1;
	else return 0;
}

// Open a file as a read mode, read all data on the file, and set list by the data.
int MainApplication::LoadDB() {

	MasterList.MakeEmpty();
	PlaceList.MakeEmpty();
	TempList.MakeEmpty();
	RecentList.MakeEmpty(); // ��� �迭���� �ʱ�ȭ���ش� (�ҷ��ðű� ����)

	ItemType t;
	stringstream sItemFileName;
	sItemFileName << "DB\\USERITEMS\\" << User.GetID() << ".txt";
	string Itemfile = sItemFileName.str();

	if (OpenInFile((char*)Itemfile.c_str())){
		// ������ ��� ������ �о� list�� �߰�
		while (!m_InFile.eof()) {
			// List�� �ּҵ��� ������ ����ִ� structure ����
			if (m_InFile.eof()) break;
			t.ReadDataFromFile(m_InFile);

			if (t.GetContainerId() == -1) TempList.Add(t);
			else AddItemToMasterList(t);
		}
	}
	// file close
	m_InFile.close();

	return 1;
}

// Open a file as a write mode, and write all data into the file,
int MainApplication::SaveDB() {

	ItemType t;
	stringstream sItemFileName;
	sItemFileName << "DB\\USERITEMS\\" << User.GetID() << ".txt";
	string Itemfile = sItemFileName.str();

	if (!OpenOutFile((char*)Itemfile.c_str())) return 0;

	
	DoublySortedLinkedList<ItemType> All;

	DoublyIterator<ItemType> itor = MasterList;
	int len_master = MasterList.GetLength();
	int len_temp = TempList.GetNum();
	int len_all = len_master + len_temp;

	while (len_master--) {
		t = itor.Next();
		All.Add(t);
	}

	TempList.ResetPointer();
	while (len_temp--) {
		TempList.GetNextItem(t);
		All.Add(t);
	}

	ItemType CurData;
	DoublyIterator<ItemType> itor_all = All;
	while(len_all--) {
		CurData = itor_all.Next();
		if (len_all != 0) CurData.WriteDataToFile(m_OutFile);
		else if (len_all == 0) CurData.WriteDataToFileLast(m_OutFile);
	}
	
	m_OutFile.close();

	return 1;
}


//Replace item with binary search
void MainApplication::RetrieveItem() {

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
void MainApplication::RetrieveItemFromMaster() {
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
void MainApplication::RetrieveItemFromTemp() {
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
		t.DisplayHeartOnScreen();
		t.DisplayItemNumOnScreen();
		cout << endl;
	}
	else printf("\n\tThere is no Item you want to find.\n");
}


//Delete item with binary search
void MainApplication::DeleteItem() {

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
int MainApplication::DeleteItemFromMaster() {
	ItemType data;
	StorageType stype;
	ContainerType ctype;
	SimpleItemType Sdata;
	printf("\n\tEnter the Item Number you want to delete.\n");
	data.SetItemNumFromKB();
	if (MasterList.Delete(data)) { // MasterList�� �ش� data ���� �� �����ϸ鼭 ���ÿ� data �о��
		RecentList.Delete(data);
		int location = data.GetStorageId();
		int container = data.GetContainerId();
		int iNum = data.GetItemNum();
		Sdata.SetItemNum(iNum);

		stype.SetStorageId(location); // ��ġ set
		ctype.SetContainerId(container); // �����̳� set
		PlaceList.Get(stype);
		stype.SearchContainer(ctype); // stype�� ��Ҹ� Set �ϰ� ��ҿ� ���� �������� ã�´�.
		
		ctype.DeleteItem(Sdata); // �ݵ�� data�� ���� �� �ۿ� �����Ƿ� �ش� Sdata ����
		stype.UpdateContainer(ctype);
		PlaceList.Replace(stype); //�����Ϸ� �� Cdata�� Container List ���� ����

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
int MainApplication::DeleteItemFromTemp() {
	ItemType data;
	printf("\n\tEnter the Item Number you want to delete.\n");
	data.SetItemNumFromKB();
	if (TempList.Delete(data)) { // Temporary List�� �ش� data ���� �� �����ϸ鼭 ���ÿ� data �о��
		RecentList.Delete(data);
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
void MainApplication::ReplaceItem() {

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
int MainApplication::ReplaceItemFromMaster() {
	ItemType data, origin;
	StorageType stype;
	ContainerType ctype;
	SimpleItemType sdata;
	printf("\n\tEnter the Item Number you want to Replace.\n");
	data.SetItemNumFromKB();
	if (MasterList.Get(data)) { // MasterList�� �ش� data ���� �� 
		RecentList.Delete(data);
		data.SetUsageFromKB();
		data.SetStorageIdFromKB();
		data.SetContainerIdFromKB();
		data.SetTimeFromSystem();
		data.SetPdayFromKB();
		data.SetBrandFromKB();
		data.SetNameFromKB();
		data.SetNumFromKB(); 
		data.SetHeartFromKB(); // ������ ������ȣ�� ������ ��� ������ ���� �Է¹޴´�.
		origin.SetItemNum(data.GetItemNum()); // �����ִ� �������� ã�� ���� ��� set
		MasterList.Get(origin);
		MasterList.Replace(data); // �����͸���Ʈ�� ������ ����
		RecentList.Add(data);

		//���� ���� ����
		stype.SetStorageId(origin.GetContainerId()); 
		ctype.SetContainerId(origin.GetContainerId());
		sdata.SetItemNum(origin.GetItemNum());
		PlaceList.Get(stype);
		stype.SearchContainer(ctype);
		ctype.DeleteItem(sdata);
		stype.UpdateContainer(ctype);
		PlaceList.Replace(stype);

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
		if (PlaceList.Get(stype)) {
			if (stype.SearchContainer(ctype)) {
				ctype.AddItem(sdata);
				stype.UpdateContainer(ctype);
				PlaceList.Replace(stype);
			}

			else {
				ctype.AddItem(sdata);
				stype.AddContainer(ctype);
				PlaceList.Replace(stype);
			}
		}

		else {
			ctype.AddItem(sdata);
			stype.AddContainer(ctype);
			PlaceList.Add(stype);
		}
		return 1;
	}

	else {
		printf("\n\t There is No Item you want to Replace!\n"); // �ش� ItemNumber �߰� ������ �� ���
		return 0;
	}
}

//Replace item from Temporary list
int MainApplication::ReplaceItemFromTemp() {
	ItemType data;
	printf("\n\tEnter the Item Number you want to Replace.\n");
	data.SetItemNumFromKB();
	if (TempList.Search(data)) { // Temporary List�� �ش� data ���� ��
		RecentList.Delete(data);
		data.SetUsageFromKB();
		data.SetTimeFromSystem();
		data.SetPdayFromKB();
		data.SetBrandFromKB();
		data.SetNameFromKB();
		data.SetNumFromKB(); 
		data.SetHeartFromKB(); // ���ο� data�� �Է¹���.
		TempList.Replace(data);  // �Է¹��� data�� Replace
		RecentList.Add(data);
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
int MainApplication::RetreiveRecordByMemberUsage() {
	printf("\n\tEnter the Usage you want to find\n");
	ItemType data;
	data.SetUsageFromKB();
	if (SearchListByMemberUsage(data)) return 1;
	return 0;
}

// ����Ʈ�� ó������ ������ Ž���ϸ鼭 ��ġ�ϴ� usage ��ȣ�� �ִ� �� �˻��Ѵ�.
int MainApplication::SearchListByMemberUsage(ItemType &inData) {

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
			PlaceList.Get(Stype);
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
int MainApplication::RetreiveRecordByMemberName() {
	printf("\n\tEnter the name you want to find\n");
	ItemType data;
	data.SetNameFromKB();
	if (SearchListByMemberName(data)) return 1;
	return 0;
}

// ����Ʈ�� ó������ ������ Ž���ϸ鼭 �ش� string�� ���ԵŴ��� �˻��Ѵ�.
int MainApplication::SearchListByMemberName(ItemType &inData) {

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
int MainApplication::RetrieveByPday() {
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
int MainApplication::SearchListByMemberPday(ItemType &inData1, ItemType &inData2) {

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

// ���ƿ䰡 ������ ������ ��� ���
void MainApplication::RetrieveByHeart() {
	cout << "\n\t========= All the Liked Item ========" << endl; // ���� �Ϸ� �� ����Ʈ �����ش�.

	DoublyIterator<ItemType> itor = MasterList;
	ItemType CurData;
	int len = MasterList.GetLength();

	bool found = false;
	while (len--) {
		CurData = itor.Next();
		if (CurData.GetHeart()) {
			CurData.DisplayRecordOnScreen();
			found = true;
		}
	}
	if (!found) printf("\n\tNo Liked Item.");
}

// Add photo to Container List
int MainApplication::AddPhoto() {
	StorageType stype;
	ContainerType ctype;
	string s;
	cout << "\n\tFind the Place to take Photo!" << endl;
	stype.SetStorageIdFromKB(); // ���� string�� �� �ش� Container List�� ID�� �Է¹޴´�.
	if (PlaceList.Get(stype) != -1) {
		cout << "\n\tFind the Container to take Photo!" << endl;
		ctype.SetContainerIdFromKB();
		if (stype.SearchContainer(ctype)) {
			
			cout << "\n\tPhoto Name : ";
			cin >> s;
			cout << endl;
			ctype.AddPhoto(s); // ���� List ��� ������ ��Ʈ�� s �߰�
			stype.UpdateContainer(ctype);  //Ctype�� �ش� StorageType�� container ��ü
			PlaceList.Replace(stype);
			ctype.DisplayAllPhoto(); //  �ش� Container List�� ���� ��� ���
			return 1;
		}

		else {
			cout << "\n\tPhoto Name : ";
			cin >> s;
			cout << endl;
			ctype.AddPhoto(s); // ���� List ��� ������ ��Ʈ�� s �߰�
			stype.AddContainer(ctype);
			PlaceList.Replace(stype);
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
		PlaceList.Add(stype); // ��� �߰�
		return 1;
	}

}

// Display photo from Container List
void MainApplication::DisplayPhoto() {
	StorageType stype;
	ContainerType ctype;
	cout << "\n\tFind the Place to Display Photo!" << endl;
	stype.SetStorageIdFromKB(); // ���� string�� Display �� �ش� Container List�� ID�� �Է¹޴´�.
	if (PlaceList.Get(stype)) {
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
int MainApplication::DeletePhoto() {
	StorageType stype;
	ContainerType ctype;
	cout << "\n\tFind the Place to Delete Photo!" << endl;
	stype.SetStorageIdFromKB(); // ���� string�� �� �ش� Container List�� ID�� �Է¹޴´�.
	if (PlaceList.Get(stype)) {
		cout << "\n\tFind the Container to Delete Photo!" << endl;
		ctype.SetContainerIdFromKB();
		if (stype.SearchContainer(ctype)) {
			string s;
			cout << "\n\tPhoto Name : ";
			cin >> s;
			cout << endl;
			ctype.DeletePhoto(s); // ���� List ��� ������ ��Ʈ�� s �߰�
			stype.UpdateContainer(ctype);  //Ctype�� �ش� StorageType�� container ��ü
			PlaceList.Replace(stype);
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
int MainApplication::UpdatePhoto() {
	StorageType stype;
	ContainerType ctype;
	cout << "\n\tFind the Place to Update Photo!" << endl;
	stype.SetStorageIdFromKB(); // ���� string�� �� �ش� Container List�� ID�� �Է¹޴´�.
	if (PlaceList.Get(stype)) { // Place ã�� ��
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
				PlaceList.Replace(stype);
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

void MainApplication::DisplayAllDetailsContainer() {
	StorageType stype;
	stype.SetStorageIdFromKB();
	
	if (PlaceList.Get(stype)) {
		stype.DisplayAllDetailContainer(MasterList);
	}

	else
		cout << "\n\t The Place Storage has to be initialized" << endl; // ���� Container List�� ���� �� ���
}