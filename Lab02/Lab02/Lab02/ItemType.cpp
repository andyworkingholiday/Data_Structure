#include "ItemType.h"
using namespace std;

int ItemType::GetUsage() {
	return this->m_Usage;
}

int ItemType::GetPday() {
	return this->m_PurchaseDay;
}

int ItemType::GetRday() {
	return this->m_RecentDay;
}

int ItemType::GetPlace() {
	return this->m_Place;
}

string ItemType::GetName() {
	return this->m_Name;
}

int ItemType::GetKeyNumber() {
	return this->m_KeyNumber;
}

int ItemType::GetNum() {
	return this->m_Num;
}

void ItemType::SetUsage(int inUsage) {
	this->m_Usage = inUsage;
}

void ItemType::SetPday(int inPday) {
	this->m_PurchaseDay = inPday;
}

void ItemType::SetRday(int inRday) {
	this->m_RecentDay = inRday;
}

void ItemType::SetPlace(int inPlace) {
	this->m_Place = inPlace;
}

void ItemType::SetName(string inName) {
	this->m_Name = inName;
}
void ItemType::SetKeyNumber(int inKeyNumber) {
	this->m_KeyNumber = inKeyNumber;
}

void ItemType::SetNum(int inNum) {
	this->m_Num = inNum;
}

void ItemType::SetRecord(int inUsage, int inPday, int inRday, int inPlace, string inName, int inKeyNumber, int inNum) {
	SetUsage(inUsage);
	SetPday(inPday);
	SetRday(inRday);
	SetPlace(inPlace);
	SetName(inName);
	SetKeyNumber(inKeyNumber);
	SetNum(inNum);
}

void ItemType::CopyRecord(ItemType inData) {
	this->m_Usage = inData.GetUsage();
	this->m_PurchaseDay = inData.GetPday();
	this->m_RecentDay = inData.GetRday();
	this->m_Place = inData.GetPlace();
	this->m_Name = inData.GetName();
	this->m_KeyNumber = inData.GetKeyNumber();
	this->m_Num = inData.GetNum();
}
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
	}

}

void  ItemType::DisplayPdayOnScreen() {
	cout << "\tPurchase Day    : " << m_PurchaseDay << endl;
}

void  ItemType::DisplayRdayOnScreen() {
	cout << "\tRecent Use Day    : " << m_RecentDay << endl;
}

void ItemType::DisplayPlaceOnScreen() {
	switch (this->m_Place) {
	case 0:
		cout << "\tUsage	: Garage" << endl;
		break;
	case 1:
		cout << "\tUsage	: LivingRoom" << endl;
		break;
	case 2:
		cout << "\tUsage	: Kitchen" << endl;
		break;
	case 3:
		cout << "\tUsage	: Bathroom" << endl;
		break;
	case 4:
		cout << "\tUsage	: Bedroom" << endl;
		break;
	case 5:
		cout << "\tUsage	: Library" << endl;
		break;
	}
}

void ItemType::DisplayNameOnScreen() {
	cout << "\tName    : " << m_Name << endl;
}

void ItemType::DisplayKeyNumberOnScreen() {
	cout << "\tKeyNumber	: " << m_KeyNumber << endl;
}

void ItemType::DisplayNumOnScreen() {
	cout << "\tNumber of Item    : " << m_Num << endl;
}

void ItemType::DisplayRecordOnScreen() {
	printf("\n");
	DisplayUsageOnScreen();
	DisplayPdayOnScreen();
	DisplayRdayOnScreen();
	DisplayPlaceOnScreen();
	DisplayNameOnScreen();
	DisplayKeyNumberOnScreen();
	DisplayNumOnScreen();
}
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

void ItemType::SetPdayFromKB() {
	cout << "\t=============== YYYYMMDD =============== ex(20191215)" << endl;
	cout << "\tPurchase Day    : ";
	cin >> m_PurchaseDay;
}

void ItemType::SetRdayFromKB() {
	cout << "\t=============== YYYYMMDD =============== ex(20191215)" << endl;
	cout << "\tRecent Use Day    : ";
	cin >> m_RecentDay;
}

void ItemType::SetPlaceFromKB() {
	cout << "\tEnter the number suitable for place you put." << endl;
	cout << "\t=============== Usage ===============" << endl;
	cout << "\t1 : LivingRoom         " << "4 : BedRoom" << endl;
	cout << "\t2 : Kitchen            " << "5 : Library" << endl;
	cout << "\t3 : BathRoom           " << "0 : Garage" << endl;
	int number;
	printf("\tPlace    : ");
	cin >> number;

	if (number <= 5) SetPlace(number);
	else {
		cout << "\tIllegal selection...try again\n";
		SetPlaceFromKB();
	}
	
}

void ItemType::SetNameFromKB() {
	cout << "\tName    : ";
	cin >> m_Name;
}


void ItemType::SetKeyNumberFromKB() {
	cout << "\tKeyNumber	: ";
	cin >> m_KeyNumber;
}

void ItemType::SetNumFromKB() {
	cout << "\tNumber of Item    : ";
	cin >> m_Num;
}

void ItemType::SetRecordFromKB() {
	SetUsageFromKB();
	SetPdayFromKB();
	SetRdayFromKB();
	SetPlaceFromKB();
	SetNameFromKB();
	SetKeyNumberFromKB();
	SetNumFromKB();
}

int ItemType::ReadDataFromFile(ifstream& fin) {
	fin >> m_Usage;
	fin >> m_PurchaseDay;
	fin >> m_RecentDay;
	fin >> m_Place;
	fin >> m_Name;
	fin >> m_KeyNumber;
	fin >> m_Num;
	return 1;
}

int ItemType::WriteDataToFile(ofstream& fout) {
	fout << m_Usage << " ";
	fout << m_PurchaseDay << " ";
	fout << m_RecentDay << " ";
	fout << m_Place << " ";
	fout << m_Name << " ";
	fout << m_KeyNumber << " ";
	fout << m_Num << endl;
	return 1;
}

RelationType ItemType::CompareByID(ItemType data) {
	if (this->m_KeyNumber < data.m_KeyNumber) return LESS;
	else if (this->m_KeyNumber > data.m_KeyNumber) return GREATER;
	else return EQUAL;
}