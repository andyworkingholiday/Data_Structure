#ifndef _ITEMTYPE_H
#define _ITEMTYPE_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum RelationType { LESS, GREATER, EQUAL };

/**
*	item information class.
*/
class ItemType {
public:
	/**
	*	default constructor.
	*/
	ItemType() {
		m_Usage = 0;
		m_PurchaseDay = 0;
		m_RecentDay = 0;
		m_Place = 0;
		m_Name = "";
		m_KeyNumber = -1;
		m_Num = 0;
	}

	/**
	*	destructor.
	*/

	~ItemType() {}

	/**
	*	Relation between two items. Equal
	*/
	bool operator == (ItemType& data) {
		if (this->m_KeyNumber == data.m_KeyNumber) return true;
		return false;
	}

	/**
	*	Relation between two items. Greater
	*/
	bool operator > (ItemType& data) {
		if (this->m_KeyNumber > data.m_KeyNumber) return true;
		return false;
	}

	/**
	*	Relation between two items. Less
	*/
	bool operator < (ItemType& data) {
		if (this->m_KeyNumber < data.m_KeyNumber) return true;
		return false;
	}

	/**
	*	@brief	Get Item usage
	*	@pre	Item usage is set.
	*	@post	none.
	*	@return	Item usage
	*/
	int GetUsage();

	/**
	*	@brief	Get Item purchase day
	*	@pre	Item purchase day is set.
	*	@post	none.
	*	@return	Item purchase day
	*/
	int GetPday();

	/**
	*	@brief	Get recent item using day
	*	@pre	recent item using day is set.
	*	@post	none.
	*	@return	recent item using day
	*/
	int GetRday();

	/**
	*	@brief	Get place where to put
	*	@pre	place where to put is set.
	*	@post	none.
	*	@return	place where to put
	*/
	int GetPlace();

	/**
	*	@brief	Get Item Name
	*	@pre	Item Name is set.
	*	@post	none.
	*	@return	Item Name 
	*/
	string GetName();

	/**
	*	@brief	Get Primary keynumber
	*	@pre	Primary keynumber is set.
	*	@post	none.
	*	@return	Primary keynumber
	*/
	int GetKeyNumber();

	/**
	*	@brief	Get Number of item
	*	@pre	Number of item is set.
	*	@post	none.
	*	@return	Number of item
	*/
	int GetNum();

	/**
	*	@brief	Set Item usage
	*	@pre	none.
	*	@post	Item usage is set.
	*	@param	inUsage	Item usage
	*/
	void SetUsage(int inUsage);

	/**
	*	@brief	Set Item purchase day
	*	@pre	none.
	*	@post	Item purchase day is set.
	*	@param	inPday	Item purchase day
	*/
	void SetPday(int inPday);

	/**
	*	@brief	Set recent item using day
	*	@pre	none.
	*	@post	recent item using day is set.
	*	@param	inRday	recent item using day
	*/
	void SetRday(int inRday);

	/**
	*	@brief	Set Place where to put
	*	@pre	none.
	*	@post	Place where to put is set.
	*	@param	inPlace	Place where to put
	*/
	void SetPlace(int inPlace);

	/**
	*	@brief	Set Item name
	*	@pre	none.
	*	@post	Item name is set.
	*	@param	inName	Item name
	*/
	void SetName(string inName);

	/**
	*	@brief	Set Primary Keynumber
	*	@pre	none.
	*	@post	Primary Keynumber is set.
	*	@param	inKeyNumber	Primary Keynumber
	*/
	void SetKeyNumber(int inKeyNumber);

	/**
	*	@brief	Set Number of Item
	*	@pre	none.
	*	@post	Number of Item is set.
	*	@param	inNum	 Number of Item
	*/
	void SetNum(int inNum);

	/**
	*	@brief	Set Item record.
	*	@pre	none.
	*	@post	Item record is set.
	*	@param	inUsage	Item usage
	*	@param	inPday	Item purchasing day
	*	@param	inRday	Recnt using day
	*	@param	inPlace	Place where to put
	*	@param	inName	Item name
	*	@param	inkeynumber	Primary keynumber
	*	@param	inNum	Number of Item
	*/
	void SetRecord(int inUsage, int inPday, int inRday, int inPlace, string inName, int inKeyNumber, int inNum);

	/**
	*	@brief	Copy Item record
	*	@pre	none.
	*	@post	Record is set
	*	@param	inData	 Item data
	*/
	void CopyRecord(ItemType inData);

	/**
	*	@brief	Display Item usage on screen.
	*	@pre	Item usage is set.
	*	@post	Item usage is on screen.
	*/
	void DisplayUsageOnScreen();

	/**
	*	@brief	Display Purchasing day on screen.
	*	@pre	Purchasing day is set.
	*	@post	Purchasing day is on screen.
	*/
	void DisplayPdayOnScreen();

	/**
	*	@brief	Display Recent using day on screen.
	*	@pre	Recent using day is set.
	*	@post	Recent using day is on screen.
	*/
	void DisplayRdayOnScreen();

	/**
	*	@brief	Display Place on screen.
	*	@pre	Place is set.
	*	@post	Place is on screen.
	*/
	void DisplayPlaceOnScreen();

	/**
	*	@brief	Display Name on screen.
	*	@pre	Nameis set.
	*	@post	Name is on screen.
	*/
	void DisplayNameOnScreen();

	/**
	*	@brief	Display Keynumber on screen.
	*	@pre	Keynumber is set.
	*	@post	Keynumber is on screen.
	*/
	void DisplayKeyNumberOnScreen();

	/**
	*	@brief	Display Number of item on screen.
	*	@pre	Number of item is set.
	*	@post	Number of item is on screen.
	*/
	void DisplayNumOnScreen();

	/**
	*	@brief	Display item record on screen.
	*	@pre	item record is set.
	*	@post	item record is on screen.
	*/
	void DisplayRecordOnScreen();

	/**
	*	@brief	Set Item usage from keyboard.
	*	@pre	none.
	*	@post	Item usage is set.
	*/
	void SetUsageFromKB();

	/**
	*	@brief	Set Purchasing day from keyboard.
	*	@pre	none.
	*	@post	 Purchasing day is set.
	*/
	void SetPdayFromKB();

	/**
	*	@brief	Set Recent using day from keyboard.
	*	@pre	none.
	*	@post	Recent using day is set.
	*/
	void SetRdayFromKB();

	/**
	*	@brief	Set Place where to put from keyboard.
	*	@pre	none.
	*	@post	Place where to put is set.
	*/
	void SetPlaceFromKB();

	/**
	*	@brief	Set Item Name from keyboard.
	*	@pre	none.
	*	@post	Item Name is set.
	*/
	void SetNameFromKB();

	/**
	*	@brief	Set Primary Keynumber from keyboard.
	*	@pre	none.
	*	@post	Primary Keynumber is set.
	*/
	void SetKeyNumberFromKB();

	/**
	*	@brief	Set Number of Item from keyboard.
	*	@pre	none.
	*	@post	Number of Item is set.
	*/
	void SetNumFromKB();

	/**
	*	@brief	Set Item data from keyboard.
	*	@pre	none.
	*	@post	Item data is set.
	*/
	void SetRecordFromKB();

	/**
	*	@brief	Read a record from file.
	*	@pre	the target file is opened.
	*	@post	Item record is set.
	*	@param	fin	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	Write a record into file.
	*	@pre	the target file is opened. And the list should be initialized.
	*	@post	the target file is included the new Item record.
	*	@param	fout	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile(ofstream& fout);

	/**
	*	Compare two itemtypes.
	*	@brief	Compare two item types by item id.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	return LESS if this.id < data.id,
	*			return GREATER if this.id > data.id then,
	*			otherwise return EQUAL.
	*/
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