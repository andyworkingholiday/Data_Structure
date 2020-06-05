#include "pch.h"
#include "SimpleItemType.h"
using namespace std;

// Usage�� int���̹Ƿ� �ش� �ϴ� Usage ��ȣ�� ���� �� screen�� �뵵�� ����Ѵ�.
void SimpleItemType::DisplayUsageOnScreen() {
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


void SimpleItemType::DisplayNameOnScreen() {
	cout << "\tName    : " << m_Name << endl;
}

void SimpleItemType::DisplayItemNumOnScreen() {
	cout << "\tPrimary Number    : " << m_ItemNumber << endl;
}

void SimpleItemType::DisplayRecordOnScreen() {
	printf("\n");
	DisplayUsageOnScreen();
	DisplayNameOnScreen();
	DisplayItemNumOnScreen();
}

// int��ȣ�� �ش��ϴ� usage�� ȭ�鿡 ����ְ� �ش��ϴ� ��ȣ�� �Է��� �� �ְ� �� �Ͽ����ϴ�. 
// 0~9�� �ش��ϴ� ��ȣ�� �ƴ� �� �ٽ� �Է��� �޽��ϴ�.
void SimpleItemType::SetUsageFromKB() {
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

void SimpleItemType::SetNameFromKB() {
	cout << "\tName    : ";
	cin >> m_Name;
}

void SimpleItemType::SetItemNumFromKB() {
	cout << "\tPrimary Number    : ";
	cin >> m_ItemNumber;
}


void SimpleItemType::SetRecordFromKB() {
	SetUsageFromKB();
	SetNameFromKB();
	SetItemNumFromKB();
}

int SimpleItemType::ReadDataFromFile(ifstream& fin) {
	string sUsage, sItemNum, dummy;

	getline(fin, sUsage, '\n');
	getline(fin, m_Name, '\n');
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

	int iinum = stoi(sItemNum);
	SetItemNum(iinum);
	return 1;
}


int SimpleItemType::WriteDataToFile(ofstream& fout) {

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

	fout << m_Name << '\n';
	fout << m_ItemNumber << '\n';
	fout << endl;
	return 1;
}