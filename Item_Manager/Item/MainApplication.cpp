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

int MainApplication::AddItemToMasterListFromKB() {
	ItemType data;
	data.SetRecordFromKB();

	return(AddItemToMasterList(data));
}

int MainApplication::AddItemToMasterList(ItemType data) {
	if (MasterList.IsFull()) {
		printf("\tMaster List is Full\n"); // 마스터 리스트 가득 찼을 시 해당 문구 출력
		return 0;
	}

	else {
		int location = data.GetStorageId();
		int container = data.GetContainerId();
		StorageType stype;
		ContainerType ctype;
		stype.SetStorageId(location); // location 위치 받아오기
		ctype.SetContainerId(container); // 컨테이너 번호 받아오기

		SimpleItemType simpledata;
		int sUsage = data.GetUsage();
		string sName = data.GetName();
		int sItemNumber = data.GetItemNum();
		simpledata.SetRecord(sUsage, sName, sItemNumber); //sdata에 data와 겹치는 변수들을 넣어준다.

		if (PlaceList.Get(stype)) { // 검색한 장소가 이미 등록이 되있을 시
			if (stype.SearchContainer(ctype)) { // 컨테이너 번호가 이미 등록되어 있을 시
				ctype.AddItem(simpledata); // 해당 컨테이너에 아이템 추가
				stype.UpdateContainer(ctype); // 아이템 추가한 컨테이너로 업데이트
				PlaceList.Replace(stype); // 장소 업데이트
			}

			else { // 컨테이너 번호가 처음 등록될 시
				ctype.AddItem(simpledata); // 해당 컨테이너에 아이템 추가
				stype.AddContainer(ctype); // 아이템 추가한 컨테이너 새로 추가
				PlaceList.Replace(stype); // 장소 업데이트
			}
		}

		else { // 장소가 처음 등록될 시
			ctype.AddItem(simpledata); //해당 컨테이너에 아이템 추가
			stype.AddContainer(ctype); // 아이템 추가한 컨테이너 새로 추가
			PlaceList.Add(stype); // 장소 추가
		}

		MasterList.Add(data); // Container List에 넣으면서 MasterList에도 넣어준다. (Container가 다찼는데 Master만 넣어줄 순 없기 때문)
		RecentList.Add(data);
		cout << "\n\t========= " << stype.GetLocation()<<" ========" << endl;
		ctype.DisplayAllItem(); // 컨테이너에 속해있는 아이템 모두 출력
		return 1;
	}
}


int MainApplication::AddItemToTempList() {
	if (TempList.IsFull()) {
		printf("\tTemporary List is Full\n"); //TempList 꽉찼을 시 함수 종료
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
		data.SetItemNumFromKB(); // 장소 및 컨테이너를 제외한 data 정보를 입력받는다.
		TempList.Add(data);
		RecentList.Add(data);
		cout << "\n\t========= All the Temporary Storage Item ========" << endl;
		TempList.Display(); //Templist의 모든 아이템 출력
		return 1;
	}

}

int MainApplication::AddItemToContainerFromTemp() {
	TempList.Display(); // TempList의 아이템들을 출력하여 어떤 물건을 옮길 수 있는 지 알게해준다.
	ItemType data;
	cout << "\n\t옮기고 싶은 물품의 Item Number를 입력해주세요!" << endl;
	data.SetItemNumFromKB(); // Primary key를 입력받아 옮기고자 하는 아이템을 선택한다.
	if (TempList.Search(data)) {
		RecentList.Delete(data);
		cout << "\n\t 물품을 놓을 위치" << endl;
		data.SetStorageIdFromKB();//Templist 아이템에 추가로 장소를 넣어준다.
		data.SetContainerIdFromKB(); //Templist 아이템에 추가로 컨테이너를 넣어준다.
		if (AddItemToMasterList(data)) {
			RecentList.Add(data);
			TempList.Delete(data); //Master에 넣으면서 Templist delete
			cout << "\n\t Move Success!" << endl;
			return 1;
		}
		else { // Master가 다차거나 Container, 장소가 다차서 넣을 수 없을 시 옮기기 실패
			cout << "\n\t Move Failed!" << endl;
			return 0;
		}
	}
	else { //일치하는 아이템 번호가 없을 시 출력 후 함수 종료
		cout << "\n\t There is no Item Number you want to delete" << endl;
		return 0;
	}
}

int MainApplication::AddItemToContainerFromTempFront() {
	if (!TempList.IsEmpty()) {
		TempList.DisplayFront(); // TempList의 가장 오래된 아이템을 출력하여 어떤 물건을 옮길 수 있는 지 알게해준다.
		ItemType data;
		TempList.Frontdata(data); //data에 가장 오래된 아이템을 복사.
		RecentList.Delete(data);
		cout << "\n\t 물품을 놓을 위치" << endl;
		data.SetStorageIdFromKB();//Templist 아이템에 추가로 장소를 넣어준다.
		data.SetContainerIdFromKB(); //Templist 아이템에 추가로 컨테이너를 넣어준다.
		if (AddItemToMasterList(data)) {
			RecentList.Add(data);
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
	case 1: // Master List의 모든 아이템 출력
		cout << "\n\t========= All the Item ========" << endl;
		MasterList.Print();
		break;
	case 2: // Temporary List의 모든 아이템 출력
		cout << "\n\t========= All the Temporary Storage Item ========" << endl;
		TempList.Display();
		break;
	case 3:
		cout << "\n\t========= All the Recent Storage Item ========" << endl;
		RecentList.Display();
		break;

	default: //입력 오류
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
	case 1: //MasterList에 있는 모든 아이템 Reset, 동시에 Container List도 Reset
		MasterList.MakeEmpty();
		PlaceList.MakeEmpty();
		RecentList.MakeEmpty();
		cout << "\n\t Reset Success!" << endl;
		break;
	case 2: //Temporary List에 있는 모든 Item Reset
		TempList.MakeEmpty();
		RecentList.MakeEmpty();
		cout << "\n\t Reset Success!" << endl;
		break;

	default: //입력오류
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
	RecentList.MakeEmpty(); // 모든 배열들을 초기화해준다 (불러올거기 때문)

	ItemType t;
	stringstream sItemFileName;
	sItemFileName << "DB\\USERITEMS\\" << User.GetID() << ".txt";
	string Itemfile = sItemFileName.str();

	if (OpenInFile((char*)Itemfile.c_str())){
		// 파일의 모든 내용을 읽어 list에 추가
		while (!m_InFile.eof()) {
			// List에 주소들의 정보가 들어있는 structure 저장
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

	cout << "\n\t 1. Find Item from the Master List " << endl; // MasterList의 아이템 검색
	cout << "\n\t 2. Find Item from the Temporary List " << endl; //Temprorary List의 아이템 검색
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
		cout << "\tIllegal selection...Try again\n"; //입력 오류
		RetrieveItem();
		break;
	}
}

//Retrieve item with binary search from Master
void MainApplication::RetrieveItemFromMaster() {
	ItemType t;
	printf("\n\tEnter the Item Number you want to find.\n");
	t.SetItemNumFromKB();

	if (MasterList.Get(t)) { // MasterList안의 모든 아이템을 이진탐색으로 찾습니다.
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

	if (TempList.Search(t)) { // TempList안의 모든 아이템을 이진탐색으로 찾습니다.
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

	cout << "\n\t 1. Delete Item from the Master List " << endl; // MasterList의 아이템 지우기
	cout << "\n\t 2. Delete Item from the Temporary List " << endl; //Temprorary List의 아이템 지우기
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
int MainApplication::DeleteItemFromMaster() {
	ItemType data;
	StorageType stype;
	ContainerType ctype;
	SimpleItemType Sdata;
	printf("\n\tEnter the Item Number you want to delete.\n");
	data.SetItemNumFromKB();
	if (MasterList.Delete(data)) { // MasterList에 해당 data 있을 시 삭제하면서 동시에 data 읽어옴
		RecentList.Delete(data);
		int location = data.GetStorageId();
		int container = data.GetContainerId();
		int iNum = data.GetItemNum();
		Sdata.SetItemNum(iNum);

		stype.SetStorageId(location); // 위치 set
		ctype.SetContainerId(container); // 컨테이너 set
		PlaceList.Get(stype);
		stype.SearchContainer(ctype); // stype의 장소를 Set 하고 장소에 따른 아이템을 찾는다.
		
		ctype.DeleteItem(Sdata); // 반드시 data가 있을 수 밖에 없으므로 해당 Sdata 삭제
		stype.UpdateContainer(ctype);
		PlaceList.Replace(stype); //삭제완료 후 Cdata로 Container List 새로 갱신

		cout << "\n\t========= All the " << stype.GetLocation() << " Storage Item ========" << endl; // 삭제 완료 후 리스트 보여준다.
		stype.DisplayAllContainer();
		return 1;
	}

	else {
		printf("\n\t There is No Item you want to Delete!\n"); // 해당 Item Number가 없을 때
		return 0;
	}
}

//Delete item from Temporary List
int MainApplication::DeleteItemFromTemp() {
	ItemType data;
	printf("\n\tEnter the Item Number you want to delete.\n");
	data.SetItemNumFromKB();
	if (TempList.Delete(data)) { // Temporary List에 해당 data 있을 시 삭제하면서 동시에 data 읽어옴
		RecentList.Delete(data);
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
void MainApplication::ReplaceItem() {

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
int MainApplication::ReplaceItemFromMaster() {
	ItemType data, origin;
	StorageType stype;
	ContainerType ctype;
	SimpleItemType sdata;
	printf("\n\tEnter the Item Number you want to Replace.\n");
	data.SetItemNumFromKB();
	if (MasterList.Get(data)) { // MasterList에 해당 data 있을 시 
		RecentList.Delete(data);
		data.SetUsageFromKB();
		data.SetStorageIdFromKB();
		data.SetContainerIdFromKB();
		data.SetTimeFromSystem();
		data.SetPdayFromKB();
		data.SetBrandFromKB();
		data.SetNameFromKB();
		data.SetNumFromKB(); 
		data.SetHeartFromKB(); // 아이템 고유번호를 제외한 모든 정보를 새로 입력받는다.
		origin.SetItemNum(data.GetItemNum()); // 원래있던 아이템을 찾기 위해 장소 set
		MasterList.Get(origin);
		MasterList.Replace(data); // 마스터리스트의 아이템 갱신
		RecentList.Add(data);

		//기존 내용 삭제
		stype.SetStorageId(origin.GetContainerId()); 
		ctype.SetContainerId(origin.GetContainerId());
		sdata.SetItemNum(origin.GetItemNum());
		PlaceList.Get(stype);
		stype.SearchContainer(ctype);
		ctype.DeleteItem(sdata);
		stype.UpdateContainer(ctype);
		PlaceList.Replace(stype);

		//새로운 데이터 추가
		int location = data.GetStorageId();
		int container = data.GetContainerId();
		int iNum = data.GetItemNum();
		string iName = data.GetName();
		int iUsage = data.GetUsage();
		sdata.SetRecord(iUsage, iName, iNum); //갱신될 Container List에 새로운 레코드 복사

		stype.SetStorageId(location);
		ctype.SetContainerId(container);

		// 삭제후 추가하는 함수로 Add와 원리가 같다.
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
		printf("\n\t There is No Item you want to Replace!\n"); // 해당 ItemNumber 발견 못했을 시 출력
		return 0;
	}
}

//Replace item from Temporary list
int MainApplication::ReplaceItemFromTemp() {
	ItemType data;
	printf("\n\tEnter the Item Number you want to Replace.\n");
	data.SetItemNumFromKB();
	if (TempList.Search(data)) { // Temporary List에 해당 data 있을 시
		RecentList.Delete(data);
		data.SetUsageFromKB();
		data.SetTimeFromSystem();
		data.SetPdayFromKB();
		data.SetBrandFromKB();
		data.SetNameFromKB();
		data.SetNumFromKB(); 
		data.SetHeartFromKB(); // 새로운 data값 입력받음.
		TempList.Replace(data);  // 입력받은 data로 Replace
		RecentList.Add(data);
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
int MainApplication::RetreiveRecordByMemberUsage() {
	printf("\n\tEnter the Usage you want to find\n");
	ItemType data;
	data.SetUsageFromKB();
	if (SearchListByMemberUsage(data)) return 1;
	return 0;
}

// 리스트의 처음부터 끝까지 탐색하면서 일치하는 usage 번호가 있는 지 검색한다.
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

// 키보드로 부터 입력받은 name으로 데이터 찾기
int MainApplication::RetreiveRecordByMemberName() {
	printf("\n\tEnter the name you want to find\n");
	ItemType data;
	data.SetNameFromKB();
	if (SearchListByMemberName(data)) return 1;
	return 0;
}

// 리스트의 처음부터 끝까지 탐색하면서 해당 string이 포함돼는지 검색한다.
int MainApplication::SearchListByMemberName(ItemType &inData) {

	DoublyIterator<ItemType> itor = MasterList;
	ItemType CurData;
	int len = MasterList.GetLength();

	bool found = false;
	while (len--) {
		CurData = itor.Next();
		if (CurData.GetName().find(inData.GetName()) != -1) { //string member 함수 find 사용 해당 string을 포함하지 않을시 -1을 return 하는 함수
			CurData.DisplayRecordOnScreen();
			found = true;
		}
	}
	if (found) return 1;
	printf("\n\tList has no name you want to search");
	return 0;
}

// 키보드로 부터 입력받은 name으로 데이터 찾기
int MainApplication::RetrieveByPday() {
	printf("\n\tEnter the Purchasing year you want to find\n");
	ItemType data1, data2;
	int year1, year2;
	cout << "\t=============== YYYY =============== ex(2020)" << endl;
	cout << "\t검색 시작 년도 : ";
	cin >> year1;
	cout << endl;
	cout << "\t=============== YYYY =============== ex(2020)" << endl;
	cout << "\t검색 끝 년도 : ";
	cin >> year2;
	cout << endl;
	year1 *= 10000;
	year2 *= 10000;
	data1.SetPday(year1);
	data2.SetPday(year2);


	if (SearchListByMemberPday(data1, data2)) return 1;
	return 0;
}

// 리스트의 처음부터 끝까지 탐색하면서 Data1과 Data2사이에 있는 Purchaing day의 Item을 찾는다.
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

// 좋아요가 눌러진 아이템 모두 출력
void MainApplication::RetrieveByHeart() {
	cout << "\n\t========= All the Liked Item ========" << endl; // 삭제 완료 후 리스트 보여준다.

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
	stype.SetStorageIdFromKB(); // 사진 string이 들어갈 해당 Container List의 ID를 입력받는다.
	if (PlaceList.Get(stype) != -1) {
		cout << "\n\tFind the Container to take Photo!" << endl;
		ctype.SetContainerIdFromKB();
		if (stype.SearchContainer(ctype)) {
			
			cout << "\n\tPhoto Name : ";
			cin >> s;
			cout << endl;
			ctype.AddPhoto(s); // 사진 List 멤버 변수에 스트링 s 추가
			stype.UpdateContainer(ctype);  //Ctype로 해당 StorageType의 container 대체
			PlaceList.Replace(stype);
			ctype.DisplayAllPhoto(); //  해당 Container List의 사진 목록 출력
			return 1;
		}

		else {
			cout << "\n\tPhoto Name : ";
			cin >> s;
			cout << endl;
			ctype.AddPhoto(s); // 사진 List 멤버 변수에 스트링 s 추가
			stype.AddContainer(ctype);
			PlaceList.Replace(stype);
			ctype.DisplayAllPhoto();
			return 1;
		}	
	}

	else { // 장소가 처음 등록될 시
		cout << "\n\tFind the Container to take Photo!" << endl;
		ctype.SetContainerIdFromKB();
		cout << "\n\tPhoto Name : ";
		cin >> s;
		cout << endl;
		ctype.AddPhoto(s); //해당 컨테이너에 사진 추가
		stype.AddContainer(ctype); // 사진 추가한 컨테이너 새로 추가
		PlaceList.Add(stype); // 장소 추가
		return 1;
	}

}

// Display photo from Container List
void MainApplication::DisplayPhoto() {
	StorageType stype;
	ContainerType ctype;
	cout << "\n\tFind the Place to Display Photo!" << endl;
	stype.SetStorageIdFromKB(); // 사진 string을 Display 할 해당 Container List의 ID를 입력받는다.
	if (PlaceList.Get(stype)) {
		cout << "\n\tFind the Container to Display Photo!" << endl;
		ctype.SetContainerIdFromKB();
		stype.SearchContainer(ctype);
		ctype.DisplayAllPhoto(); //해당 Container List의 모든 사진 목록 출력
	}

	else {
		cout << "\n\t The Place Storage has to be initialized" << endl; // 아직 Container List가 없을 시 출력
	}
}

// Delete photo from Container List
int MainApplication::DeletePhoto() {
	StorageType stype;
	ContainerType ctype;
	cout << "\n\tFind the Place to Delete Photo!" << endl;
	stype.SetStorageIdFromKB(); // 사진 string이 들어갈 해당 Container List의 ID를 입력받는다.
	if (PlaceList.Get(stype)) {
		cout << "\n\tFind the Container to Delete Photo!" << endl;
		ctype.SetContainerIdFromKB();
		if (stype.SearchContainer(ctype)) {
			string s;
			cout << "\n\tPhoto Name : ";
			cin >> s;
			cout << endl;
			ctype.DeletePhoto(s); // 사진 List 멤버 변수에 스트링 s 추가
			stype.UpdateContainer(ctype);  //Ctype로 해당 StorageType의 container 대체
			PlaceList.Replace(stype);
			ctype.DisplayAllPhoto(); //  해당 Container List의 사진 목록 출력
			return 1;
		}
		else {
			cout << "\n\t There is no Container you Enter" << endl;
			return 0;
		}
	}

	else {
		cout << "\n\t The Place Storage has to be initialized" << endl; // 아직 Container List가 없을 시 출력
		return 0;
	}
}


// Update photo from Container List
int MainApplication::UpdatePhoto() {
	StorageType stype;
	ContainerType ctype;
	cout << "\n\tFind the Place to Update Photo!" << endl;
	stype.SetStorageIdFromKB(); // 사진 string이 들어갈 해당 Container List의 ID를 입력받는다.
	if (PlaceList.Get(stype)) { // Place 찾을 시
		cout << "\n\tFind the Container to Update Photo!" << endl;
		ctype.SetContainerIdFromKB();
		if (stype.SearchContainer(ctype)) {
			ctype.DisplayAllPhoto(); //해당 Container List의 모든 사진 목록 출력
			cout << endl;
			string oldPhoto, newPhoto; // 지울이름 , 갱신이름
			cout << "\n\tPhoto Name to delete : ";
			cin >> oldPhoto;
			cout << endl;

			if (ctype.DeletePhoto(oldPhoto)) { //일치하는 string의 Container List의 사진 삭제
				cout << "\n\tNew Photo Name : ";
				cin >> newPhoto;
				ctype.AddPhoto(newPhoto);
				stype.UpdateContainer(ctype);
				PlaceList.Replace(stype);
				ctype.DisplayAllPhoto(); //갱신 후 사진 목록 출력
				return 1;
			}

			else {
				cout << "\n\t The Photo Name not found!" << endl; // 이름 발견 못함
				return 0;
			}
		}
		else {
			cout << "\n\t The Container not found!" << endl; // 이름 발견 못함
			return 0;
		}
	}

	else {
		cout << "\n\t The Place Storage has to be initialized" << endl; // 아직 Storage List가 없을 시 출력
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
		cout << "\n\t The Place Storage has to be initialized" << endl; // 아직 Container List가 없을 시 출력
}