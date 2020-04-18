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
	case 1: //Masterlist에 넣으면서 Container에 넣기
		AddItemToMasterListFromKB();
		return 1;
	case 2: //Temporary list에만 넣기
		AddItemToTempList();
		return 1;
	case 3: //Temporary list에서 원하는 아이템 찾은 후 Masterlist에 넣기
		AddItemToContainerFromTemp();
		return 1;
	case 4: //Temporary list의 가장 오래된 아이템 Master list에 넣기
		AddItemToContainerFromTempFront();
		return 1;
	default: //잘못입력
		cout << "\tIllegal selection...Try again\n";
		AddItem();
		return 0;
	}
}

int Application::AddItemToMasterListFromKB() {
	if (MasterList.IsFull()) {
		printf("\tMaster List is Full\n"); // 마스터 리스트 가득 찼을 시 해당 문구 출력
		return 0;
	}

	else {
		ItemType data;
		data.SetRecordFromKB(); // data 정보를 입력받는다.
		
		int location = data.GetContainerId(); 
		ContainerType cdata;
		cdata.SetContainerId(location); //data의 Container Id를 cdata에 넣어준다.

		SimpleItemType sdata;
		int sUsage = data.GetUsage();
		string sName = data.GetName();
		int sItemNumber = data.GetItemNum();
		sdata.SetRecord(sUsage, sName, sItemNumber); //sdata에 data와 겹치는 변수들을 넣어준다.

		int index = ContainerList.RetrieveByBS(cdata); //cdata의 Container Id 와 일치하는 Container list의 type을 찾는다.

		if (index >= 0) { 
			if (cdata.IsItemFull()) {
				cout << cdata.GetLocation() << " stack is Full." << endl; // 찾았는데 해당 Itemlist가 꽉찼을 시 종료
				return 0;
			}
			cdata.AddItem(sdata); //Itemlist에 넣을 수 있을 때 cdata에 sdata 추가
			ContainerList.Replace(cdata); //갱신된 cdata로 Replace 한다.
		}

		else { 
			cdata.AddItem(sdata);
			ContainerList.Add(cdata); //찾지 못했을 때 새로운 Container Id를 가진 type을 추가한다.
		}

		MasterList.Add(data); // Container List에 넣으면서 MasterList에도 넣어준다. (Container가 다찼는데 Master만 넣어줄 순 없기 때문)
		cdata.DisplayAllItem();
		return 1;
	}
}

int Application::AddItemToMasterList(ItemType data) {
	if (MasterList.IsFull()) {
		printf("\tMaster List is Full\n"); // 마스터 리스트 가득 찼을 시 해당 문구 출력
		return 0;
	}

	else {
		int location = data.GetContainerId(); 
		ContainerType cdata;
		cdata.SetContainerId(location);  //data의 Container Id를 cdata에 넣어준다.

		SimpleItemType sdata;
		int sUsage = data.GetUsage();
		string sName = data.GetName();
		int sItemNumber = data.GetItemNum();
		sdata.SetRecord(sUsage, sName, sItemNumber); //sdata에 data와 겹치는 변수들을 넣어준다.

		int index = ContainerList.RetrieveByBS(cdata); //cdata의 Container Id 와 일치하는 Container list의 type을 찾는다.

		if (index >= 0) {
			if (cdata.IsItemFull()) {
				cout << cdata.GetLocation() << " stack is Full." << endl; // 찾았는데 해당 Itemlist가 꽉찼을 시 종료
				return 0;
			}
			cdata.AddItem(sdata); //Itemlist에 넣을 수 있을 때 cdata에 sdata 추가
			ContainerList.Replace(cdata); //갱신된 cdata로 Replace 한다.
		}

		else {
			cdata.AddItem(sdata);
			ContainerList.Add(cdata); //찾지 못했을 때 새로운 Container Id를 가진 type을 추가한다.
		}

		MasterList.Add(data); // Container List에 넣으면서 MasterList에도 넣어준다. (Container가 다찼는데 Master만 넣어줄 순 없기 때문)
		cdata.DisplayAllItem(); 
		return 1;
	}
}


int Application::AddItemToTempList() {
	if (TempList.IsFull()) {
		printf("\tTemporary List is Full\n"); //TempList 꽉찼을 시 함수 종료
		return 0;
	}

	else {
		ItemType data;
		data.SetUsageFromKB();
		data.SetTimeFromSystem();
		data.SetBrandFromKB();
		data.SetNameFromKB();
		data.SetNumFromKB();
		data.SetItemNumFromKB(); // data 정보를 입력받는다.
		TempList.Add(data);

		cout << "\n\t========= All the Temporary Storage Item ========" << endl;
		TempList.Display();
		return 1;
	}

}

int Application::AddItemToContainerFromTemp() {
	TempList.Display(); // TempList의 아이템들을 출력하여 어떤 물건을 옮길 수 있는 지 알게해준다.
	ItemType data;
	cout << "\n\t옮기고 싶은 물품의 Item Number를 입력해주세요!" << endl;
	data.SetItemNumFromKB(); // Primary key를 입력받아 옮기고자 하는 아이템을 선택한다.
	if (TempList.Search(data)) {
		cout << "\n\t 물품을 놓을 위치" << endl;
		data.SetContainerIdFromKB(); //Templist 아이템에 추가로 장소를 넣어준다.
		if (AddItemToMasterList(data)) {
			TempList.Delete(data); //Master에 넣으면서 Templist delete
			cout << "\n\t Move Success!" << endl;
			return 1;
		}
		else { // Master가 다차거나 Container가 다차서 넣을 수 없을 시 옮기기 실패
			cout << "\n\t Move Failed!" << endl;
			return 0;
		}
	}
	else { //일치하는 아이템 번호가 없을 시 출력 후 함수 종료
		cout << "\n\t There is no Item Number you want to delete" << endl;
		return 0;
	}
}

int Application::AddItemToContainerFromTempFront() {
	if (!TempList.IsEmpty()) {
		TempList.DisplayFront(); // TempList의 가장 오래된 아이템을 출력하여 어떤 물건을 옮길 수 있는 지 알게해준다.
		ItemType data;
		TempList.Frontdata(data); //data에 가장 오래된 아이템을 복사.
		cout << "\n\t 물품을 놓을 위치" << endl;
		data.SetContainerIdFromKB(); //Tdata에 추가로 장소를 넣어준다.
		if (AddItemToMasterList(data)) {
			TempList.DeltefromFront(data);  //Master에 넣으면서 Templist delete
			cout << "\n\t Move Success!" << endl;
			return 1;
		}
		else { // Master가 다차거나 Container가 다차서 넣을 수 없을 시 옮기기 실패
			cout << "\n\t Move Failed!" << endl;
			return 0;
		}
	}

	else { //Templist 비었을 시 함수 종료
		cout << "Temporary List is Empty" << endl;
		return 0;
	}
}

// 리스트에 담긴 모든 데이터 출력
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
	case 1: // Master List의 모든 아이템 출력
		cout << "\n\t========= All the Item ========" << endl;
		MasterList.Print();
		break;
	case 2: // Temporary List의 모든 아이템 출력
		cout << "\n\t========= All the Temporary Storage Item ========" << endl;
		TempList.Display();
		break;
	case 3: // 위치 입력받은 후 해당 위치의 모든 아이템 출력
		Cdata.SetContainerIdFromKB();
		if (ContainerList.RetrieveByBS(Cdata) != -1) {
			Cdata.DisplayAllItem();
		}
		else cout << "\tThere is No Items in the Place" << endl; //해당 위치의 Container등록 안돼있을 시
		break;
	default: //입력 오류
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
	case 1: //MasterList에 있는 모든 아이템 Reset, 동시에 Container List도 Reset
		MasterList.MakeEmpty();
		ContainerList.MakeEmpty();
		cout << "\n\t Reset Success!" << endl;
		break;
	case 2: //Temporary List에 있는 모든 Item Reset
		TempList.MakeEmpty();
		cout << "\n\t Reset Success!" << endl;
		break;

	default: //입력오류
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

	cout << "\n\t 1. Find Item from the Master List " << endl; // MasterList의 아이템 찾기
	cout << "\n\t 2. Find Item from the Temporary List " << endl; //Temprorary List의 아이템 찾기
	cout << "\n\t Enter the Command : ";
	int command;
	cin >> command;
	cout << endl;

	ItemType t;

	switch(command) {
	case 1:
		printf("\n\tEnter the Item Number you want to find.\n");
		t.SetItemNumFromKB();

		if (MasterList.RetrieveByBS(t) != -1) { // MasterList안의 모든 아이템을 이진탐색으로 찾습니다.
			printf("\n\tThe Item's data : \n");
			t.DisplayRecordOnScreen();
		}
		else printf("\n\tThere is no Item you want to find.\n");
		break;
	case 2:
		printf("\n\tEnter the Item Number you want to find.\n");
		t.SetItemNumFromKB();

		if (TempList.Search(t)) { // MasterList안의 모든 아이템을 이진탐색으로 찾습니다.
			printf("\n\tThe Item's data : \n");
			t.DisplayRecordOnScreen();
		}
		else printf("\n\tThere is no Item you want to find.\n");
		break;

	default:
		cout << "\tIllegal selection...Try again\n"; //입력 오류
		DeleteItem();
		break;
	}

}

//Delete item with binary search
void Application::DeleteItem() {

	cout << "\n\t 1. Delete Item from the Master List " << endl; // MasterList의 아이템 지우기
	cout << "\n\t 2. Delete Item from the Temporary List "<< endl; //Temprorary List의 아이템 지우기
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
		cout << "\tIllegal selection...Try again\n"; //입력 오류
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
	if (MasterList.Delete(data)) { // MasterList에 해당 data 있을 시 삭제하면서 동시에 data 읽어옴
		int location = data.GetContainerId();
		int iNum = data.GetItemNum();
		Sdata.SetItemNum(iNum); 

		Cdata.SetContainerId(location);
		ContainerList.RetrieveByBS(Cdata);  // Cdata의 장소를 Set 하고 장소에 따른 아이템을 찾는다.
		Cdata.DeleteItem(Sdata); // 반드시 data가 있을 수 밖에 없으므로 해당 Sdata 삭제
		ContainerList.Replace(Cdata); //삭제완료 후 Cdata로 Container List 새로 갱신

		cout << "\n\t========= All the " << Cdata.GetLocation() << " Storage Item ========" << endl; // 삭제 완료 후 리스트 보여준다.
		Cdata.DisplayAllItem();
		return 1;
	}

	else {
		printf("\n\t There is No Item you want to Delete!\n"); // 해당 Item Number가 없을 때
		return 0;
	}
}

//Delete item from Temporary List
int Application::DeleteItemFromTemp() {
	ItemType data;
	printf("\n\tEnter the Item Number you want to delete.\n");
	data.SetItemNumFromKB();
	if (TempList.Delete(data)) { // Temporary List에 해당 data 있을 시 삭제하면서 동시에 data 읽어옴
		cout << "\n\t========= All the Temporary Storage Item ========" << endl;
		TempList.Display(); // 삭제 완료 후 리스트 보여준다.
		return 1;
	}

	else {
		printf("\n\t There is No Item you want to Delete!\n");  // 해당 Item Number가 없을 때
		return 0;
	}
}

//Replace item with binary search
void Application::ReplaceItem() {

	cout << "\n\t 1. Replace Item from the Master List " << endl; // MasterList의 아이템 갱신
	cout << "\n\t 2. Replace Item from the Temporary List " << endl; // Temporary List의 아이템 갱신
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
		cout << "\tIllegal selection...Try again\n"; //입력 오류
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
	if (MasterList.RetrieveByBS(data) != -1 ) { // MasterList에 해당 data 있을 시 
		data.SetUsageFromKB();
		data.SetBrandFromKB();
		data.SetNameFromKB();
		data.SetNumFromKB(); // 새로운 data값 입력받음.

		int location = data.GetContainerId();
		int iNum = data.GetItemNum();
		string iName = data.GetName();
		int iUsage = data.GetUsage();
		Sdata.SetRecord(iUsage, iName, iNum); //갱신될 Container List에 새로운 레코드 복사

		Cdata.SetContainerId(location);
		ContainerList.RetrieveByBS(Cdata);
		Cdata.UpdateItem(Sdata); //Sdata로 UnsortedList안에 있는 아이템 update
		ContainerList.Replace(Cdata); // 바뀐 Cdata로 Update

		MasterList.Replace(data);
		cout << "\n\t========= All the " << Cdata.GetLocation() << " Storage Item ========" << endl; //바뀐 후 해당 위치의 Container List 출력
		Cdata.DisplayAllItem();
		return 1;
	}

	else {
		printf("\n\t There is No Item you want to Replace!\n"); // 해당 ItemNumber 발견 못했을 시 출력
		return 0;
	}
}

//Replace item from Temporary list
int Application::ReplaceItemFromTemp() {
	ItemType data;
	printf("\n\tEnter the Item Number you want to Replace.\n");
	data.SetItemNumFromKB();
	if (TempList.Search(data)) { // Temporary List에 해당 data 있을 시 
		data.SetUsageFromKB();
		data.SetBrandFromKB();
		data.SetNameFromKB();
		data.SetNumFromKB(); // 새로운 data값 입력받음.
		TempList.Replace(data);  // 입력받은 data로 Replace
		cout << "\n\t========= All the Temporary Storage Item ========" << endl; // Temporay List의 모든 아이템 출력
		TempList.Display();
		return 1;
	}

	else {
		printf("\n\t There is No Item you want to Replace!\n"); // 해당 ItemNumber 발견 못했을 시 출력
		return 0;
	}
}

// 키보드로 부터 입력받은 usage 번호로 데이터 찾기
int Application::RetreiveRecordByMemberUsage() {
	printf("\n\tEnter the Usage you want to find\n");
	ItemType data;
	data.SetUsageFromKB();
	if (SearchListByMemberUsage(data)) return 1;
	return 0;
}

// 리스트의 처음부터 끝까지 탐색하면서 일치하는 usage 번호가 있는 지 검색한다.
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

// 키보드로 부터 입력받은 name으로 데이터 찾기
int Application::RetreiveRecordByMemberName() {
	printf("\n\tEnter the name you want to find\n");
	ItemType data;
	data.SetNameFromKB();
	if (SearchListByMemberName(data)) return 1;
	return 0;
}

// 리스트의 처음부터 끝까지 탐색하면서 해당 string이 포함돼는지 검색한다.
int Application::SearchListByMemberName(ItemType &inData) {
	ItemType CurData;
	MasterList.ResetList();
	int len = MasterList.GetLength();
	bool found = false;
	while (len--) {
		MasterList.GetNextItem(CurData);
		if (CurData.GetName().find(inData.GetName()) != -1) { //string member 함수 find 사용 해당 string을 포함하지 않을시 -1을 return 하는 함수
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
	Cdata.SetContainerIdFromKB(); // 사진 string이 들어갈 해당 Container List의 ID를 입력받는다.
	if (ContainerList.RetrieveByBS(Cdata) != -1) {
		string s;
		cout << "\n\tPhoto Name : ";
		cin >> s;
		cout << endl;
		Cdata.AddPhoto(s); // 사진 List 멤버 변수에 스트링 s 추가
		ContainerList.Replace(Cdata); //Cdata로 해당 Container List 대체
		Cdata.DisplayAllPhoto(); //  해당 Container List의 사진 목록 출력
		return 1;
	}

	else {
		cout << "\n\t The Place Storage has to be initialized" << endl; // 아직 Container List가 없을 시 출력
		return 0;
	}
}

// Display photo from Container List
void Application::DisplayPhoto() {
	ContainerType Cdata;
	cout << "\n\tFind the Place to Display Photo!" << endl; 
	Cdata.SetContainerIdFromKB(); // 사진 string을 Display 할 해당 Container List의 ID를 입력받는다.
	if (ContainerList.RetrieveByBS(Cdata) != -1) {
		Cdata.DisplayAllPhoto(); //해당 Container List의 모든 사진 목록 출력
	}

	else {
		cout << "\n\t The Place Storage has to be initialized" << endl; // 아직 Container List가 없을 시 출력
	}
}

// Delete photo from Container List
int Application::DeletePhoto() {
	ContainerType Cdata;
	cout << "\n\tFind the Place to Delete Photo!" << endl; // 사진 string을 Delete 할 해당 Container List의 ID를 입력받는다.
	Cdata.SetContainerIdFromKB();
	if (ContainerList.RetrieveByBS(Cdata) != -1) { // 컨테이너 찾을 시
		Cdata.DisplayAllPhoto(); //해당 Container List의 모든 사진 목록 출력
		cout << endl;
		string s;
		cout << "\n\tPhoto Name : ";
		cin >> s;
		cout << endl;
		if (Cdata.DeletePhoto(s)) { //일치하는 string의 Container List의 사진 삭제
			ContainerList.Replace(Cdata); // 삭제 한 후 Contanier List로 갱신
			Cdata.DisplayAllPhoto(); //갱신 후 사진 목록 출력
			return 1;
		}
		else {
			cout << "\n\t The Photo Name not found!" << endl; // 이름 발견 못함
			return 0;
		}
		
	}

	else {
		cout << "\n\t The Place Storage has to be initialized" << endl; // 아직 Container List가 없을 시 출력
		return 0;
	}
}


// Update photo from Container List
int Application::UpdatePhoto() {
	ContainerType Cdata;
	cout << "\n\tFind the Place to Update Photo!" << endl; // 사진 string을 Update 할 해당 Container List의 ID를 입력받는다.
	Cdata.SetContainerIdFromKB();
	if (ContainerList.RetrieveByBS(Cdata) != -1) { // 컨테이너 찾을 시
		Cdata.DisplayAllPhoto(); //해당 Container List의 모든 사진 목록 출력
		cout << endl;
		string oldPhoto, newPhoto; // 지울이름 , 갱신이름
		cout << "\n\tPhoto Name : ";
		cin >> oldPhoto;
		cout << endl;
		if (Cdata.DeletePhoto(oldPhoto)) { //일치하는 string의 Container List의 사진 삭제
			cout << "\n\tNew Photo Name : ";
			cin >> newPhoto;
			Cdata.AddPhoto(newPhoto);
			ContainerList.Replace(Cdata); // 삭제 한 후 Contanier List로 갱신
			Cdata.DisplayAllPhoto(); //갱신 후 사진 목록 출력
			return 1;
		}

		else {
			cout << "\n\t The Photo Name not found!" << endl; // 이름 발견 못함
			return 0;
		}
		
	}

	else {
		cout << "\n\t The Place Storage has to be initialized" << endl; // 아직 Container List가 없을 시 출력
		return 0;
	}
}