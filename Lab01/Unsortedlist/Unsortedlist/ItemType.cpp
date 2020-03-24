#include "ItemType.h"
#include <string>
using namespace std;

int ItemType::GetId() {
	return this->m_Id;
}

string ItemType::GetName() {
	return this->m_sName;
}

string ItemType::GetAddress() {
	return this->m_sAddress;
}

void ItemType::SetId(int inId) {
	this->m_Id = inId;
}
void ItemType::setName(string inName) {
	this->m_sName = inName;
}
void ItemType::SetAddress(string inAddress) {
	this->m_sAddress = inAddress;
}
void ItemType::SetRecord(int inId, string inName, string inAddress) {
	this->m_Id = inId;
	this->m_sName = inName;
	this->m_sAddress = inAddress;
}
void  ItemType::DisplayIdOnScreen() {
	printf("\tID	: %d\n", m_Id);
}
void ItemType::DisplayNameOnScreen() {
	cout << "\tName	: " << m_sName << endl;
}
void ItemType::DisplayAddressOnScreen() {
	cout << "\tName	: " << m_sAddress << endl;
}
void ItemType::DisplayRecordOnScreen() {
	printf("\n");
	DisplayIdOnScreen();
	DisplayNameOnScreen();
	DisplayAddressOnScreen();
}
void ItemType::SetIdFromKB() {
	printf("\tID	: ");
	cin >> m_Id;
}

void ItemType::SetNameFromKB() {
	printf("\tName	: ");
	cin >> m_sName;
}

void ItemType::SetAddressFromKB() {
	printf("\tAddress	: ");
	cin >> m_sAddress;
}

void ItemType::SetRecordFromKB() {
	SetIdFromKB();
	SetNameFromKB();
	SetAddressFromKB();
}

int ItemType::ReadDataFromFile(ifstream& fin) {
	fin >> m_Id;
	fin >> m_sAddress;
	fin >> m_sAddress;
	return 1;
}

int ItemType::WriteDataToFile(ofstream& fout) {
	fout << m_Id;
	fout << m_sName;
	fout << m_sAddress;
	return 1;
}

RelationType ItemType::CompareByID(ItemType data) {
	if (this->m_Id < data.m_Id) return LESS;
	else if (this->m_Id > data.m_Id) return GREATER;
	else return EQUAL;
}
