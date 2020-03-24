#ifndef _ITEMTYPE_H
#define _ITEMTYPE_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum RelationType{LESS, GREATER, EQUAL};

class ItemType {
public:
	ItemType() {
		m_Id = 0;
		m_sName = "";
		m_sAddress = "";
	}

	~ItemType() {}

	bool operator == (ItemType& data) {
		if (this->m_Id == data.m_Id) return true;
		return false;
	}

	int GetId();
	string GetName();
	string GetAddress();
	void SetId(int inId);
	void setName(string inName);
	void SetAddress(string inAddress);
	void SetRecord(int inId, string inName, string inAddress);
	void DisplayIdOnScreen();
	void DisplayNameOnScreen();
	void DisplayAddressOnScreen();
	void DisplayRecordOnScreen();
	void SetIdFromKB();
	void SetNameFromKB();
	void SetAddressFromKB();
	void SetRecordFromKB();
	int ReadDataFromFile(ifstream& fin);
	int WriteDataToFile(ofstream& fout);
	RelationType CompareByID(ItemType data);

private:
	int m_Id;
	string m_sName;
	string m_sAddress;
};

#endif	// _ITEMTYPE_H