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
		case 3:		// make empty list.
			MakeEmpty();
			break;
		case 4: // Retrieve item
			RetrieveItem();
			break;
		case 5: // Retrieve item from the input usage
			RetreiveRecordByMemberUsage();
			break;
		case 6: // Retrieve item with including input name
			RetreiveRecordByMemberName();
			break;
		case 7: // Delete item
			DeleteItem();
			break;
		case 8: // Replace item
			ReplaceItem();
			break;
		case 9: // Add photo
			AddPhoto();
			break;
		case 10: // Display photo
			DisplayPhoto();
			break;
		case 11: // Delete photo
			DeletePhoto();
			break;

		case 12: // Update photo
			UpdatePhoto();
			break;

		case 13: // Read file and Put into Temporary Storage
			ReadDataFromFile();
			break;
		case 14: //Write file from Master List
			WriteDataToFile();
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
	cout << "\t   2 : Display Item on screen" << endl;
	cout << "\t   3 : Make empty list" << endl;
	cout << "\t   4 : Find item " << endl;
	cout << "\t   5 : Find item by usage " << endl;
	cout << "\t   6 : Find item by name " << endl;
	cout << "\t   7 : Delete item " << endl;
	cout << "\t   8 : Replace item " << endl;
	cout << "\t   9 : Add Photo " << endl;
	cout << "\t   10 : Display Photo " << endl;
	cout << "\t   11 : Delete Photo " << endl;
	cout << "\t   12 : Update Photo " << endl;
	cout << "\t   13 : Get from file" << endl;
	cout << "\t   14 : Put to file " << endl;
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
	if (MasterList.IsFull()) {
		printf("\tMaster List is Full\n"); // ������ ����Ʈ ���� á�� �� �ش� ���� ���
		return 0;
	}

	else {
		ItemType data;
		data.SetRecordFromKB(); // data ������ �Է¹޴´�.
		
		int location = data.GetContainerId(); 
		ContainerType cdata;
		cdata.SetContainerId(location); //data�� Container Id�� cdata�� �־��ش�.

		SimpleItemType sdata;
		int sUsage = data.GetUsage();
		string sName = data.GetName();
		int sItemNumber = data.GetItemNum();
		sdata.SetRecord(sUsage, sName, sItemNumber); //sdata�� data�� ��ġ�� �������� �־��ش�.

		int index = ContainerList.RetrieveByBS(cdata); //cdata�� Container Id �� ��ġ�ϴ� Container list�� type�� ã�´�.

		if (index >= 0) { 
			if (cdata.IsItemFull()) {
				cout << cdata.GetLocation() << " stack is Full." << endl; // ã�Ҵµ� �ش� Itemlist�� ��á�� �� ����
				return 0;
			}
			cdata.AddItem(sdata); //Itemlist�� ���� �� ���� �� cdata�� sdata �߰�
			ContainerList.Replace(cdata); //���ŵ� cdata�� Replace �Ѵ�.
		}

		else { 
			cdata.AddItem(sdata);
			ContainerList.Add(cdata); //ã�� ������ �� ���ο� Container Id�� ���� type�� �߰��Ѵ�.
		}

		MasterList.Add(data); // Container List�� �����鼭 MasterList���� �־��ش�. (Container�� ��á�µ� Master�� �־��� �� ���� ����)
		cdata.DisplayAllItem();
		return 1;
	}
}

int Application::AddItemToMasterList(ItemType data) {
	if (MasterList.IsFull()) {
		printf("\tMaster List is Full\n"); // ������ ����Ʈ ���� á�� �� �ش� ���� ���
		return 0;
	}

	else {
		int location = data.GetContainerId(); 
		ContainerType cdata;
		cdata.SetContainerId(location);  //data�� Container Id�� cdata�� �־��ش�.

		SimpleItemType sdata;
		int sUsage = data.GetUsage();
		string sName = data.GetName();
		int sItemNumber = data.GetItemNum();
		sdata.SetRecord(sUsage, sName, sItemNumber); //sdata�� data�� ��ġ�� �������� �־��ش�.

		int index = ContainerList.RetrieveByBS(cdata); //cdata�� Container Id �� ��ġ�ϴ� Container list�� type�� ã�´�.

		if (index >= 0) {
			if (cdata.IsItemFull()) {
				cout << cdata.GetLocation() << " stack is Full." << endl; // ã�Ҵµ� �ش� Itemlist�� ��á�� �� ����
				return 0;
			}
			cdata.AddItem(sdata); //Itemlist�� ���� �� ���� �� cdata�� sdata �߰�
			ContainerList.Replace(cdata); //���ŵ� cdata�� Replace �Ѵ�.
		}

		else {
			cdata.AddItem(sdata);
			ContainerList.Add(cdata); //ã�� ������ �� ���ο� Container Id�� ���� type�� �߰��Ѵ�.
		}

		MasterList.Add(data); // Container List�� �����鼭 MasterList���� �־��ش�. (Container�� ��á�µ� Master�� �־��� �� ���� ����)
		cdata.DisplayAllItem(); 
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
		data.SetBrandFromKB();
		data.SetNameFromKB();
		data.SetNumFromKB();
		data.SetItemNumFromKB(); // data ������ �Է¹޴´�.
		TempList.Add(data);

		cout << "\n\t========= All the Temporary Storage Item ========" << endl;
		TempList.Display();
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
		data.SetContainerIdFromKB(); //Templist �����ۿ� �߰��� ��Ҹ� �־��ش�.
		if (AddItemToMasterList(data)) {
			TempList.Delete(data); //Master�� �����鼭 Templist delete
			cout << "\n\t Move Success!" << endl;
			return 1;
		}
		else { // Master�� �����ų� Container�� ������ ���� �� ���� �� �ű�� ����
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
		data.SetContainerIdFromKB(); //Tdata�� �߰��� ��Ҹ� �־��ش�.
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
	cout << "\n\t 3. Display the Item by Location" << endl;
	cout << "\n\t Enter the Command : ";
	int command;
	cin >> command;
	cout << endl;
	ContainerType Cdata;

	switch(command) {
	case 1: // Master List�� ��� ������ ���
		cout << "\n\t========= All the Item ========" << endl;
		MasterList.Print();
		break;
	case 2: // Temporary List�� ��� ������ ���
		cout << "\n\t========= All the Temporary Storage Item ========" << endl;
		TempList.Display();
		break;
	case 3: // ��ġ �Է¹��� �� �ش� ��ġ�� ��� ������ ���
		Cdata.SetContainerIdFromKB();
		if (ContainerList.RetrieveByBS(Cdata) != -1) {
			Cdata.DisplayAllItem();
		}
		else cout << "\tThere is No Items in the Place" << endl; //�ش� ��ġ�� Container��� �ȵ����� ��
		break;
	default: //�Է� ����
		cout << "\tIllegal selection...Try again\n";
		DisplayAllItem();
		break;
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
		ContainerList.MakeEmpty();
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

// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile() {
	ItemType t;
	char filename[FILENAMESIZE];
	printf("\n\tEnter Input file Name : ");
	cin >> filename;

	if (!OpenInFile(filename)) return 0;

	while (!m_InFile.eof()) {
		t.ReadDataFromFile(m_InFile);
		if (m_InFile.eof()) break;
		TempList.Add(t);
	}

	m_InFile.close();

	return 1;
}

// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile() {
	ItemType t;
	char filename[FILENAMESIZE];
	printf("\n\tEnter Output file Name : ");
	cin >> filename;

	if (!OpenOutFile(filename)) return 0;
	MasterList.ResetList();
	int len = MasterList.GetLength();

	while (len--) {
		if (MasterList.GetNextItem(t) >= 0)
			t.WriteDataToFile(m_OutFile);
	}

	m_OutFile.close();
	return 1;
}

//Retrieve item with binary search
void Application::RetrieveItem() {

	cout << "\n\t 1. Find Item from the Master List " << endl; // MasterList�� ������ ã��
	cout << "\n\t 2. Find Item from the Temporary List " << endl; //Temprorary List�� ������ ã��
	cout << "\n\t Enter the Command : ";
	int command;
	cin >> command;
	cout << endl;

	ItemType t;

	switch(command) {
	case 1:
		printf("\n\tEnter the Item Number you want to find.\n");
		t.SetItemNumFromKB();

		if (MasterList.RetrieveByBS(t) != -1) { // MasterList���� ��� �������� ����Ž������ ã���ϴ�.
			printf("\n\tThe Item's data : \n");
			t.DisplayRecordOnScreen();
		}
		else printf("\n\tThere is no Item you want to find.\n");
		break;
	case 2:
		printf("\n\tEnter the Item Number you want to find.\n");
		t.SetItemNumFromKB();

		if (TempList.Search(t)) { // MasterList���� ��� �������� ����Ž������ ã���ϴ�.
			printf("\n\tThe Item's data : \n");
			t.DisplayRecordOnScreen();
		}
		else printf("\n\tThere is no Item you want to find.\n");
		break;

	default:
		cout << "\tIllegal selection...Try again\n"; //�Է� ����
		DeleteItem();
		break;
	}

}

//Delete item with binary search
void Application::DeleteItem() {

	cout << "\n\t 1. Delete Item from the Master List " << endl; // MasterList�� ������ �����
	cout << "\n\t 2. Delete Item from the Temporary List "<< endl; //Temprorary List�� ������ �����
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
	ContainerType Cdata;
	SimpleItemType Sdata;
	printf("\n\tEnter the Item Number you want to delete.\n");
	data.SetItemNumFromKB();
	if (MasterList.Delete(data)) { // MasterList�� �ش� data ���� �� �����ϸ鼭 ���ÿ� data �о��
		int location = data.GetContainerId();
		int iNum = data.GetItemNum();
		Sdata.SetItemNum(iNum); 

		Cdata.SetContainerId(location);
		ContainerList.RetrieveByBS(Cdata);  // Cdata�� ��Ҹ� Set �ϰ� ��ҿ� ���� �������� ã�´�.
		Cdata.DeleteItem(Sdata); // �ݵ�� data�� ���� �� �ۿ� �����Ƿ� �ش� Sdata ����
		ContainerList.Replace(Cdata); //�����Ϸ� �� Cdata�� Container List ���� ����

		cout << "\n\t========= All the " << Cdata.GetLocation() << " Storage Item ========" << endl; // ���� �Ϸ� �� ����Ʈ �����ش�.
		Cdata.DisplayAllItem();
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
	ItemType data;
	ContainerType Cdata;
	SimpleItemType Sdata;
	printf("\n\tEnter the Item Number you want to Replace.\n");
	data.SetItemNumFromKB();
	if (MasterList.RetrieveByBS(data) != -1 ) { // MasterList�� �ش� data ���� �� 
		data.SetUsageFromKB();
		data.SetBrandFromKB();
		data.SetNameFromKB();
		data.SetNumFromKB(); // ���ο� data�� �Է¹���.

		int location = data.GetContainerId();
		int iNum = data.GetItemNum();
		string iName = data.GetName();
		int iUsage = data.GetUsage();
		Sdata.SetRecord(iUsage, iName, iNum); //���ŵ� Container List�� ���ο� ���ڵ� ����

		Cdata.SetContainerId(location);
		ContainerList.RetrieveByBS(Cdata);
		Cdata.UpdateItem(Sdata); //Sdata�� UnsortedList�ȿ� �ִ� ������ update
		ContainerList.Replace(Cdata); // �ٲ� Cdata�� Update

		MasterList.Replace(data);
		cout << "\n\t========= All the " << Cdata.GetLocation() << " Storage Item ========" << endl; //�ٲ� �� �ش� ��ġ�� Container List ���
		Cdata.DisplayAllItem();
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
	ItemType CurData;
	MasterList.ResetList();
	int len = MasterList.GetLength();
	bool found = false;
	while (len--) {
		MasterList.GetNextItem(CurData);
		if (CurData.GetUsage() == inData.GetUsage()) {
			CurData.DisplayRecordOnScreen();
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
	ItemType CurData;
	MasterList.ResetList();
	int len = MasterList.GetLength();
	bool found = false;
	while (len--) {
		MasterList.GetNextItem(CurData);
		if (CurData.GetName().find(inData.GetName()) != -1) { //string member �Լ� find ��� �ش� string�� �������� ������ -1�� return �ϴ� �Լ�
			CurData.DisplayRecordOnScreen();
			found = true;
		}
	}
	if (found) return 1;
	printf("\n\tList has no name you want to search");
	return 0;
}

// Add photo to Container List
int Application::AddPhoto() {
	ContainerType Cdata;
	cout << "\n\tFind the Place to take Photo!" << endl; 
	Cdata.SetContainerIdFromKB(); // ���� string�� �� �ش� Container List�� ID�� �Է¹޴´�.
	if (ContainerList.RetrieveByBS(Cdata) != -1) {
		string s;
		cout << "\n\tPhoto Name : ";
		cin >> s;
		cout << endl;
		Cdata.AddPhoto(s); // ���� List ��� ������ ��Ʈ�� s �߰�
		ContainerList.Replace(Cdata); //Cdata�� �ش� Container List ��ü
		Cdata.DisplayAllPhoto(); //  �ش� Container List�� ���� ��� ���
		return 1;
	}

	else {
		cout << "\n\t The Place Storage has to be initialized" << endl; // ���� Container List�� ���� �� ���
		return 0;
	}
}

// Display photo from Container List
void Application::DisplayPhoto() {
	ContainerType Cdata;
	cout << "\n\tFind the Place to Display Photo!" << endl; 
	Cdata.SetContainerIdFromKB(); // ���� string�� Display �� �ش� Container List�� ID�� �Է¹޴´�.
	if (ContainerList.RetrieveByBS(Cdata) != -1) {
		Cdata.DisplayAllPhoto(); //�ش� Container List�� ��� ���� ��� ���
	}

	else {
		cout << "\n\t The Place Storage has to be initialized" << endl; // ���� Container List�� ���� �� ���
	}
}

// Delete photo from Container List
int Application::DeletePhoto() {
	ContainerType Cdata;
	cout << "\n\tFind the Place to Delete Photo!" << endl; // ���� string�� Delete �� �ش� Container List�� ID�� �Է¹޴´�.
	Cdata.SetContainerIdFromKB();
	if (ContainerList.RetrieveByBS(Cdata) != -1) { // �����̳� ã�� ��
		Cdata.DisplayAllPhoto(); //�ش� Container List�� ��� ���� ��� ���
		cout << endl;
		string s;
		cout << "\n\tPhoto Name : ";
		cin >> s;
		cout << endl;
		if (Cdata.DeletePhoto(s)) { //��ġ�ϴ� string�� Container List�� ���� ����
			ContainerList.Replace(Cdata); // ���� �� �� Contanier List�� ����
			Cdata.DisplayAllPhoto(); //���� �� ���� ��� ���
			return 1;
		}
		else {
			cout << "\n\t The Photo Name not found!" << endl; // �̸� �߰� ����
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
	ContainerType Cdata;
	cout << "\n\tFind the Place to Update Photo!" << endl; // ���� string�� Update �� �ش� Container List�� ID�� �Է¹޴´�.
	Cdata.SetContainerIdFromKB();
	if (ContainerList.RetrieveByBS(Cdata) != -1) { // �����̳� ã�� ��
		Cdata.DisplayAllPhoto(); //�ش� Container List�� ��� ���� ��� ���
		cout << endl;
		string oldPhoto, newPhoto; // �����̸� , �����̸�
		cout << "\n\tPhoto Name : ";
		cin >> oldPhoto;
		cout << endl;
		if (Cdata.DeletePhoto(oldPhoto)) { //��ġ�ϴ� string�� Container List�� ���� ����
			cout << "\n\tNew Photo Name : ";
			cin >> newPhoto;
			Cdata.AddPhoto(newPhoto);
			ContainerList.Replace(Cdata); // ���� �� �� Contanier List�� ����
			Cdata.DisplayAllPhoto(); //���� �� ���� ��� ���
			return 1;
		}

		else {
			cout << "\n\t The Photo Name not found!" << endl; // �̸� �߰� ����
			return 0;
		}
		
	}

	else {
		cout << "\n\t The Place Storage has to be initialized" << endl; // ���� Container List�� ���� �� ���
		return 0;
	}
}