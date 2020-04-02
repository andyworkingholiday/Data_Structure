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
	int m_Usage; //물품의 종류
	int m_PurchaseDay; // 물품을 구입한 날짜
	int m_RecentDay; // 물품을 최근 사용한 날짜
	int m_Place; // 물품을 놓을 장소
	string m_Name; //물품명
	int m_KeyNumber; // 물품에 대한 고유 값
	int m_Num; // 구매한 물품의 수

};

#endif	// _ITEMTYPE_H