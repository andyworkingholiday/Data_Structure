#include "pch.h"
#include "ItemType.h"

using namespace std;

// Usage�� int���̹Ƿ� �ش� �ϴ� Usage ��ȣ�� ���� �� screen�� �뵵�� ����Ѵ�.
void  ItemType::DisplayUsageOnScreen() {
	switch (this->m_Usage) {
	case 0:
		cout << "\tUsage	: Etc" << endl;
		break;
	case 1:
		cout << "\tUsage	: Furniture" << endl;
		break;
	case 2:
		cout << "\tUsage	: Electric" << endl;
		break;
	case 3:
		cout << "\tUsage	: Clothes" << endl;
		break;
	case 4:
		cout << "\tUsage	: Books" << endl;
		break;
	case 5:
		cout << "\tUsage	: Bath" << endl;
		break;
	case 6:
		cout << "\tUsage	: Cosmetics" << endl;
		break;
	case 7:
		cout << "\tUsage	: Stationery" << endl;
		break;
	case 8:
		cout << "\tUsage	: Food" << endl;
		break;
	case 9:
		cout << "\tUsage	: Excercise" << endl;
		break;
	default:
		cout << "\tUsage	: Unknown" << endl;
		break;
	}
}

// ������ ������ ��Ҹ� ����մϴ�.
void  ItemType::DisplayStorageIdOnScreen() {
	switch (this->m_StorageId) {
	case 0:
		cout << "\tPlace	: Etc" << endl;
		break;
	case 1:
		cout << "\tPlace	: LivingRoom" << endl;
		break;
	case 2:
		cout << "\tPlace	: Kitchen" << endl;
		break;
	case 3:
		cout << "\tPlace	: Bathroom" << endl;
		break;
	case 4:
		cout << "\tPlace	: Bedroom" << endl;
		break;
	case 5:
		cout << "\tPlace	: Library" << endl;
		break;
	default:
		cout << "\tPlace	: Unknown" << endl;
		break;
	}
}

void ItemType::DisplayContainerIdOnScreen() {
	cout << "\tContainer	: " << m_ContainerId << "�� ° Container" << endl;
}

void  ItemType::DisplayRtimeOnScreen() {
	if (this->m_RegisterTime == "")
		cout << "\tRegister Time	: Unknown" << endl;
	else {

		string year = m_RegisterTime.substr(0, 4);
		string month = m_RegisterTime.substr(4, 2);
		string day = m_RegisterTime.substr(6, 2);
		string hour = m_RegisterTime.substr(8, 2);
		string minute = m_RegisterTime.substr(10, 2);
		string second = m_RegisterTime.substr(12);

		cout << "\tRegister Time    : " << year << "�� " << month << "�� " << day << "�� " << hour << "�� " << minute << "�� " << second << "�� " << endl;
	}
}

void ItemType::DisplayPdayOnScreen() {
	cout << "\tPurchase Day: " << m_Pday << endl;
}

void  ItemType::DisplayBrandOnScreen() {
	cout << "\tBrand    : " << m_Brand << endl;
}

void ItemType::DisplayNameOnScreen() {
	cout << "\tName    : " << m_Name << endl;
}

void ItemType::DisplayNumOnScreen() {
	cout << "\tNumber of Item    : " << m_Num << endl;
}

void ItemType::DisplayHeartOnScreen() {
	Heart heart;
	cout << "\tLike	: ";
	if (GetHeart()) heart.Like();
	else heart.UnLike();
}

void ItemType::DisplayItemNumOnScreen() {
	cout << "\tPrimary Number    : " << m_ItemNumber << endl;
}

void ItemType::DisplayRecordOnScreen() {
	printf("\n");
	DisplayUsageOnScreen();
	DisplayStorageIdOnScreen();
	DisplayContainerIdOnScreen();
	DisplayRtimeOnScreen();
	DisplayPdayOnScreen();
	DisplayBrandOnScreen();
	DisplayNameOnScreen();
	DisplayNumOnScreen();
	DisplayHeartOnScreen();
	DisplayItemNumOnScreen();
}

// int��ȣ�� �ش��ϴ� usage�� ȭ�鿡 ����ְ� �ش��ϴ� ��ȣ�� �Է��� �� �ְ� �� �Ͽ����ϴ�. 
// 0~9�� �ش��ϴ� ��ȣ�� �ƴ� �� �ٽ� �Է��� �޽��ϴ�.
void ItemType::SetUsageFromKB() {
	cout << "\tEnter the number suitable for your usage." << endl;
	cout << "\t=============== Usage ===============" << endl;
	cout << "\t1 : Furniture          " << "6 : Cosmetics" << endl;
	cout << "\t2 : Electric           " << "7 : Stationery" << endl;
	cout << "\t3 : Clothes            " << "8 : Food" << endl;
	cout << "\t4 : Books              " << "9 : Excercise" << endl;
	cout << "\t5 : Bath               " << "0 : Etc" << endl << endl;
	int number;
	printf("\tUsage    : ");
	cin >> number;
	if (number <= 9) SetUsage(number);
	else {
		cout << "\tIllegal selection...try again\n";
		SetUsageFromKB();
	}
}

// int��ȣ�� �ش��ϴ� usage�� ȭ�鿡 ����ְ� �ش��ϴ� ��ȣ�� �Է��� �� �ְ� �� �Ͽ����ϴ�. 
// 0~5�� �ش��ϴ� ��ȣ�� �ƴ� �� �ٽ� �Է��� �޽��ϴ�.
void ItemType::SetStorageIdFromKB() {
	cout << endl;
	cout << "\tEnter the number suitable for place you put." << endl;
	cout << "\t=============== Place ===============" << endl;
	cout << "\t1 : LivingRoom         " << "4 : BedRoom" << endl;
	cout << "\t2 : Kitchen            " << "5 : Library" << endl;
	cout << "\t3 : BathRoom           " << "0 : Etc" << endl << endl;
	int number;
	printf("\tPlace    : ");
	cin >> number;

	if (number <= 5) SetStorageId(number);
	else {
		cout << "\tIllegal selection...try again\n";
		SetStorageIdFromKB();
	}
	cout << endl;
}

void ItemType::SetContainerIdFromKB() {
	cout << "\tContainer    : ";
	cin >> m_ContainerId;
}


//����Ͻð����ʷ� �Է¹޽��ϴ�.
void ItemType::SetRtimeFromKB() {
	cout << "\t=============== YYYYMMDDHHMMSS =============== ex(20191215071022)" << endl;
	cout << "\tRegister Time    : ";
	cin >> m_RegisterTime;
}

void ItemType::SetPdayFromKB() {
	cout << "\t=============== YYYYMMDD =============== ex(20191215)" << endl;
	cout << "\tPurchase Day    : ";
	cin >> m_Pday;
}


void ItemType::SetBrandFromKB() {
	cout << "\tBrand    : ";
	cin >> m_Brand;
}


void ItemType::SetNameFromKB() {
	cout << "\tName    : ";
	cin >> m_Name;
}

void ItemType::SetNumFromKB() {
	cout << "\tNumber of Item    : ";
	cin >> m_Num;
}

void ItemType::SetHeartFromKB() {
	cout << "\tType (y / n)" << endl;
	cout << "\tLike	: ";
	char c;
	cin >> c;
	if (c == 'y' || c == 'Y') m_Heart = true;
	else if (c == 'n' || c == 'N') m_Heart = false;
	else SetHeartFromKB();
}

void ItemType::SetItemNumFromKB() {
	cout << "\tPrimary Number    : ";
	cin >> m_ItemNumber;
}


void ItemType::SetRecordFromKB() {
	SetUsageFromKB();
	SetStorageIdFromKB();
	SetContainerIdFromKB();
	SetTimeFromSystem();
	SetPdayFromKB();
	SetBrandFromKB();
	SetNameFromKB();
	SetNumFromKB();
	SetHeartFromKB();
	SetItemNumFromKB();
}

int ItemType::ReadDataFromFile(ifstream& fin) {
	string sUsage, sSID, sCID, sPday, sNum, sItemNum, dummy, sheart;

	getline(fin, sUsage, '\n');
	getline(fin, sSID, '\n');
	getline(fin, sCID, '\n');
	getline(fin, m_RegisterTime, '\n');
	getline(fin, sPday, '\n');
	getline(fin, m_Brand, '\n');
	getline(fin, m_Name, '\n');
	getline(fin, sNum, '\n');
	getline(fin, sheart, '\n');
	getline(fin, sItemNum, '\n');
	getline(fin, dummy, '\n');

	if (sUsage == "Exercise") m_Usage = 9;
	else if (sUsage == "Furniture") m_Usage = 1;
	else if (sUsage == "Electric") m_Usage = 2;
	else if (sUsage == "Clothes") m_Usage = 3;
	else if (sUsage == "Books") m_Usage = 4;
	else if (sUsage == "Bath") m_Usage = 5;
	else if (sUsage == "Cosmetics") m_Usage = 6;
	else if (sUsage == "Stationery") m_Usage = 7;
	else if (sUsage == "Food") m_Usage = 8;
	else m_Usage = 0;

	if (sSID == "LivingRoom") m_StorageId = 1;
	else if (sSID == "Kitchen") m_StorageId = 2;
	else if (sSID == "BathRoom") m_StorageId = 3;
	else if (sSID == "BedRoom") m_StorageId = 4;
	else if (sSID == "Library") m_StorageId = 5;
	else m_StorageId = 0;

	if (sheart == "1") m_Heart = true;
	else m_Heart = false;

	int icontainer = stoi(sCID);
	int ipday = stoi(sPday);
	int inum = stoi(sNum);
	int iinum = stoi(sItemNum);
	SetContainerId(icontainer);
	SetPday(ipday);
	SetNum(inum);
	SetItemNum(iinum);
	return 1;
}


int ItemType::WriteDataToFile(ofstream& fout) {

	if (m_Usage == 9) fout << "Exercise" << '\n';
	else if (m_Usage == 1) fout << "Furniture" << '\n';
	else if (m_Usage == 2) fout << "Electric" << '\n';
	else if (m_Usage == 3) fout << "Clothes" << '\n';
	else if (m_Usage == 4) fout << "Books" << '\n';
	else if (m_Usage == 5) fout << "Bath" << '\n';
	else if (m_Usage == 6) fout << "Cosmetics" << '\n';
	else if (m_Usage == 7) fout << "Stationery" << '\n';
	else if (m_Usage == 8) fout << "Food" << '\n';
	else fout << "Etc" << '\n';

	if (m_StorageId == 1) fout << "LivingRoom" << endl;
	else if (m_StorageId == 2) fout << "Kitchen" << endl;
	else if (m_StorageId == 3) fout << "BathRoom" << endl;
	else if (m_StorageId == 4) fout << "BedRoom" << endl;
	else if (m_StorageId == 5) fout << "Library" << endl;
	else fout << "Etc" << endl;

	fout << m_ContainerId << '\n';
	fout << m_RegisterTime << '\n';
	fout << m_Pday << '\n';
	fout << m_Brand << '\n';
	fout << m_Name << '\n';
	fout << m_Num << '\n';
	if (m_Heart) fout << "1" << endl;
	else fout << "0" << endl;
	fout << m_ItemNumber << '\n';
	fout << endl;
	return 1;
}

int ItemType::WriteDataToFileLast(ofstream& fout) {

	if (m_Usage == 9) fout << "Exercise" << '\n';
	else if (m_Usage == 1) fout << "Furniture" << '\n';
	else if (m_Usage == 2) fout << "Electric" << '\n';
	else if (m_Usage == 3) fout << "Clothes" << '\n';
	else if (m_Usage == 4) fout << "Books" << '\n';
	else if (m_Usage == 5) fout << "Bath" << '\n';
	else if (m_Usage == 6) fout << "Cosmetics" << '\n';
	else if (m_Usage == 7) fout << "Stationery" << '\n';
	else if (m_Usage == 8) fout << "Food" << '\n';
	else fout << "Etc" << '\n';

	if (m_StorageId == 1) fout << "LivingRoom" << endl;
	else if (m_StorageId == 2) fout << "Kitchen" << endl;
	else if (m_StorageId == 3) fout << "BathRoom" << endl;
	else if (m_StorageId == 4) fout << "BedRoom" << endl;
	else if (m_StorageId == 5) fout << "Library" << endl;
	else fout << "Etc" << endl;

	fout << m_ContainerId << '\n';
	fout << m_RegisterTime << '\n';
	fout << m_Pday << '\n';
	fout << m_Brand << '\n';
	fout << m_Name << '\n';
	fout << m_Num << '\n';
	if (m_Heart) fout << "1" << endl;
	else fout << "0" << endl;
	fout << m_ItemNumber;
	return 1;
}