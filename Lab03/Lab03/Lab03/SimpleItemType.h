#ifndef _SIMPLEITEMTYPE_H
#define _SIMPLEITEMTYPE_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**
*	item information class.
*/
class SimpleItemType {
public:
	/**
	*	default constructor.
	*/
	SimpleItemType() {
		m_Usage = -1;
		m_Name = "";
		m_ItemNumber = -1;
	}

	/**
	*	parameterized constructor.
	*/
	SimpleItemType(int inUsage, string inName, int inItemNum) {
		this->m_Usage = inUsage;
		this->m_Name = inName;
		this->m_ItemNumber = inItemNum;
	}

	/**
	*	destructor.
	*/

	~SimpleItemType() {}

	/**
	*	@brief	Get Item usage
	*	@pre	Item usage is set.
	*	@post	none.
	*	@return	Item usage
	*/
	int GetUsage() const {
		return m_Usage;
	}

	/**
	*	@brief	Get Item Name
	*	@pre	Item Name is set.
	*	@post	none.
	*	@return	Item Name
	*/
	string GetName() const {
		return m_Name;
	}

	/**
	*	@brief	Get Primary KeyNumber of item
	*	@pre	Primary KeyNumber of item is set.
	*	@post	none.
	*	@return	Primary KeyNumber of item
	*/
	int GetItemNum() const {
		return m_ItemNumber;
	}


	/**
	*	@brief	Set Item usage
	*	@pre	none.
	*	@post	Item usage is set.
	*	@param	inUsage	Item usage
	*/
	void SetUsage(int inUsage) {
		this->m_Usage = inUsage;
	}

	/**
	*	@brief	Set Item name
	*	@pre	none.
	*	@post	Item name is set.
	*	@param	inName	Item name
	*/
	void SetName(string inName) {
		this->m_Name = inName;
	}

	/**
	*	@brief	Set Primary KeyNumber of Item
	*	@pre	none.
	*	@post	Primary KeyNumber of Item is set.
	*	@param	inItemNum	 Primary KeyNumber
	*/
	void SetItemNum(int inItemNum) {
		this->m_ItemNumber = inItemNum;
	}

	/**
	*	@brief	Set Item record.
	*	@pre	none.
	*	@post	Item record is set.
	*	@param	inUsage	Item usage
	*	@param	inName	Item name
	*	@param	inItemNum	 Primary KeyNumber
	*/
	void SetRecord(int inUsage, string inName,int inItemNum) {
		SetUsage(inUsage);
		SetName(inName);
		SetItemNum(inItemNum);
	}

	/**
	*	@brief	Display Item usage on screen.
	*	@pre	Item usage is set.
	*	@post	Item usage is on screen.
	*/
	void DisplayUsageOnScreen();

	/**
	*	@brief	Display Name on screen.
	*	@pre	Nameis set.
	*	@post	Name is on screen.
	*/
	void DisplayNameOnScreen();

	/**
	*	@brief	Display Primary KeyNumber of item on screen.
	*	@pre	Primary KeyNumber of item is set.
	*	@post	Primary KeyNumber of item is on screen.
	*/
	void DisplayItemNumOnScreen();

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
	*	@brief	Set Item Name from keyboard.
	*	@pre	none.
	*	@post	Item Name is set.
	*/
	void SetNameFromKB();

	/**
	*	@brief	Set Primary KeyNumber of Item from keyboard.
	*	@pre	none.
	*	@post	Primary KeyNumber of Item is set.
	*/
	void SetItemNumFromKB();

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

	// 연산자 오버로딩
	bool operator==(const SimpleItemType &data) {
		return (this->m_ItemNumber == data.m_ItemNumber);
	}
	bool operator!=(const SimpleItemType &data) {
		return !(*this == data);
	}
	bool operator<(const SimpleItemType &data) {
		return (this->m_ItemNumber < data.m_ItemNumber);
	}

	bool operator<=(const SimpleItemType &data) {
		return (*this == data || *this < data);
	}

	bool operator>(const SimpleItemType &data) {
		return (this->m_ItemNumber > data.m_ItemNumber);
	}
	bool operator>=(const SimpleItemType &data) {
		return !(*this < data);
	}

	void operator=(const SimpleItemType &data) {
		m_Usage = data.GetUsage();
		m_Name = data.GetName();
		m_ItemNumber = data.GetItemNum();
	}

	friend ostream& operator<<(ostream& os, const SimpleItemType &data) {
		os << endl;
		switch (data.GetUsage()) {
		case 0:
			os << "\tUsage	: Etc" << endl;
			break;
		case 1:
			os << "\tUsage	: Furniture" << endl;
			break;
		case 2:
			os << "\tUsage	: Electric" << endl;
			break;
		case 3:
			os << "\tUsage	: Clothes" << endl;
			break;
		case 4:
			os << "\tUsage	: Books" << endl;
			break;
		case 5:
			os << "\tUsage	: Bath" << endl;
			break;
		case 6:
			os << "\tUsage	: Cosmetics" << endl;
			break;
		case 7:
			os << "\tUsage	: Stationery" << endl;
			break;
		case 8:
			os << "\tUsage	: Food" << endl;
			break;
		case 9:
			os << "\tUsage	: Excercise" << endl;
			break;
		default:
			os << "\tUsage	: Unknown" << endl;
			break;
		}

		os << "\tName   : " << data.m_Name << endl;
		os << "\tPrimary Number   : " << data.m_ItemNumber << endl;
		return os;
	}

private:
	int m_Usage; //물품의 종류
	string m_Name; //물품명
	int m_ItemNumber; // 물품번호 primary key
};

#endif	// _SIMPLEITEMTYPE_H