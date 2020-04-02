#ifndef _ITEMTYPE_H
#define _ITEMTYPE_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum RelationType { LESS, GREATER, EQUAL };

class ItemType {
public:
	ItemType() {
		m_Usage = 0;
		m_PurchaseDay = 0;
		m_RecentDay = 0;
		m_Place = 0;
		m_Name = "";
		m_KeyNumber = -1;
		m_Num = 0;
	}

	~ItemType() {}

	bool operator == (ItemType& data) {
		if (this->m_KeyNumber == data.m_KeyNumber) return true;
		return false;
	}

	bool operator > (ItemType& data) {
		if (this->m_KeyNumber > data.m_KeyNumber) return true;
		return false;
	}

	bool operator < (ItemType& data) {
		if (this->m_KeyNumber < data.m_KeyNumber) return true;
		return false;
	}

	int GetUsage();
	int GetPday();
	int GetRday();
	int GetPlace();
	string GetName();
	int GetKeyNumber();
	int GetNum();
	void SetUsage(int inUsage);
	void SetPday(int inPday);
	void SetRday(int inRday);
	void SetPlace(int inPlace);
	void SetName(string inName);
	void SetKeyNumber(int inKeyNumber);
	void SetNum(int inNum);
	void SetRecord(int inUsage, int inPday, int inRday, int inPlace, string inName, int inKeyNumber, int inNum);
	void CopyRecord(ItemType inData);
	void DisplayUsageOnScreen();
	void DisplayPdayOnScreen();
	void DisplayRdayOnScreen();
	void DisplayPlaceOnScreen();
	void DisplayNameOnScreen();
	void DisplayKeyNumberOnScreen();
	void DisplayNumOnScreen();
	void DisplayRecordOnScreen();
	void SetUsageFromKB();
	void SetPdayFromKB();
	void SetRdayFromKB();
	void SetPlaceFromKB();
	void SetNameFromKB();
	void SetKeyNumberFromKB();
	void SetNumFromKB();
	void SetRecordFromKB();
	int ReadDataFromFile(ifstream& fin);
	int WriteDataToFile(ofstream& fout);
	RelationType CompareByID(ItemType data);

private:
	int m_Usage; //��ǰ�� ����
	int m_PurchaseDay; // ��ǰ�� ������ ��¥
	int m_RecentDay; // ��ǰ�� �ֱ� ����� ��¥
	int m_Place; // ��ǰ�� ���� ���
	string m_Name; //��ǰ��
	int m_KeyNumber; // ��ǰ�� ���� ���� ��
	int m_Num; // ������ ��ǰ�� ��

};

#endif	// _ITEMTYPE_H