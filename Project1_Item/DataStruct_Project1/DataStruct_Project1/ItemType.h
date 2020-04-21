#ifndef _ITEMTYPE_H
#define _ITEMTYPE_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <Windows.h>
using namespace std;

/**
*	item information class.
*/
class ItemType {
public:
	/**
	*	default constructor.
	*/
	ItemType() {
		m_Usage = -1;
		m_ContainerId = -1;
		SetTimeFromSystem();
		m_Brand = "";
		m_Name = "";
		m_Num = -1;
		m_ItemNumber = -1;
	}

	/**
	*	parameterized constructor.
	*/
	ItemType(int inUsage, int inCID, string inRtime, string inBrand, string inName, int inNum, int inItemNum) {
		this->m_Usage = inUsage;
		this->m_ContainerId = inCID;
		this->m_RegisterTime = inRtime;
		this->m_Brand = inBrand;
		this->m_Name = inName;
		this->m_Num = inNum;
		this->m_ItemNumber = inItemNum;
	}

	/**
	*	destructor.
	*/

	~ItemType() {}

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
	*	@brief	Get Container ID
	*	@pre	Container ID is set.
	*	@post	none.
	*	@return	Container ID
	*/
	int GetContainerId() const {
		return m_ContainerId;
	}

	/**
	*	@brief	Get Item Register time
	*	@pre	Item Register time is set.
	*	@post	none.
	*	@return	Item Register time
	*/
	string GetRtime() const {
		return m_RegisterTime;
	}

	/**
	*	@brief	Get Brand Name
	*	@pre	Brand Name is set.
	*	@post	none.
	*	@return	Brand Name
	*/
	string GetBrand() const {
		return m_Brand;
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
	*	@brief	Get Number of item
	*	@pre	Number of item is set.
	*	@post	none.
	*	@return	Number of item
	*/
	int GetNum() const {
		return m_Num;
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
	*	@brief	Set Container ID
	*	@pre	none.
	*	@post	Container ID is set.
	*	@param	inContainerid Container ID
	*/
	void SetContainerId(int inCID) {
		this->m_ContainerId = inCID;
	}

	/**
	*	@brief	Set Item Register time
	*	@pre	none.
	*	@post	Item Register time is set.
	*	@param	inRtime	Item Register time
	*/
	void SetRtime(string inRtime) {
		this->m_RegisterTime = inRtime;
	}

	/**
	*	@brief	Set Brand name
	*	@pre	none.
	*	@post	Brand name is set.
	*	@param	inBrand	Brand name
	*/
	void SetBrand(string inBrand) {
		this->m_Brand = inBrand;
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
	*	@brief	Set Number of Item
	*	@pre	none.
	*	@post	Number of Item is set.
	*	@param	inNum	 Number of Item
	*/
	void SetNum(int inNum) {
		this->m_Num = inNum;
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
	*	@param	inCID	Container ID
	*	@param	inRtime	Item Register time
	*	@param	inBrand	Brand name
	*	@param	inName	Item name
	*	@param	inNum	Number of Item
	*	@param	inItemNum	 Primary KeyNumber
	*/
	void SetRecord(int inUsage, int inCID, string inRtime, string inBrand, string inName, int inNum, int inItemNum) {
		SetUsage(inUsage);
		SetContainerId(inCID);
		SetRtime(inRtime);
		SetBrand(inBrand);
		SetName(inName);
		SetNum(inNum);
		SetItemNum(inItemNum);
	}

	/**
	*	@brief	Display Item usage on screen.
	*	@pre	Item usage is set.
	*	@post	Item usage is on screen.
	*/
	void DisplayUsageOnScreen();

	/**
	*	@brief	Display ContainerID on screen.
	*	@pre	ContainerID is set.
	*	@post	ContainerID is on screen.
	*/
	void DisplayContainerIdOnScreen();

	/**
	*	@brief	Display Item Register time on screen.
	*	@pre	Item Register time is set.
	*	@post	Item Register time is on screen.
	*/
	void DisplayRtimeOnScreen();

	/**
	*	@brief	Display Brand on screen.
	*	@pre	Brand is set.
	*	@post	Brand is on screen.
	*/
	void DisplayBrandOnScreen();

	/**
	*	@brief	Display Name on screen.
	*	@pre	Nameis set.
	*	@post	Name is on screen.
	*/
	void DisplayNameOnScreen();

	/**
	*	@brief	Display Number of item on screen.
	*	@pre	Number of item is set.
	*	@post	Number of item is on screen.
	*/
	void DisplayNumOnScreen();

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
	*	@brief	Set ContainerId from keyboard.
	*	@pre	none.
	*	@post	ContainerId is set.
	*/
	void SetContainerIdFromKB();

	/**
	*	@brief	Set Item Register time from keyboard.
	*	@pre	none.
	*	@post	Item Register time is set.
	*/
	void SetRtimeFromKB();

	/**
	*	@brief	Set Brand Name from keyboard.
	*	@pre	none.
	*	@post	Brand Name is set.
	*/
	void SetBrandFromKB();

	/**
	*	@brief	Set Item Name from keyboard.
	*	@pre	none.
	*	@post	Item Name is set.
	*/
	void SetNameFromKB();

	/**
	*	@brief	Set Number of Item from keyboard.
	*	@pre	none.
	*	@post	Number of Item is set.
	*/
	void SetNumFromKB();

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
	*	@brief	Set Register time from system.
	*	@pre	none.
	*	@post	Register time is set.
	*/
	void SetTimeFromSystem()
	{
		SYSTEMTIME time;
		GetLocalTime(&time);

		stringstream sTime;
		// month가 한자리 수일 경우 두자리 표시를 위해 0을 붙임.
		if (time.wMonth < 10)
			sTime << time.wYear << "0" << time.wMonth;
		else
			sTime << time.wYear << time.wMonth;

		// day가 한자리 수일 경우 두자리 표시를 위해 0을 붙임.
		if (time.wDay < 10)
			sTime << "0" << time.wDay;
		else
			sTime << time.wDay;

		// hour가 한자리 수일 경우 두자리 표시를 위해 0을 붙임.
		if (time.wHour < 10)
			sTime << "0" << time.wHour;
		else
			sTime << time.wHour;

		// minute가 한자리 수일 경우 두자리 표시를 위해 0을 붙임.
		if (time.wMinute < 10)
			sTime << "0" << time.wMinute;
		else
			sTime << time.wMinute;

		// second가 한자리 수일 경우 두자리 표시를 위해 0을 붙임.
		if (time.wSecond < 10)
			sTime << "0" << time.wSecond;
		else
			sTime << time.wSecond;

		m_RegisterTime = sTime.str();		// m_sTime에 시간 대입.
	}

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
	bool operator==(const ItemType &data) {
		return (this->m_ItemNumber == data.m_ItemNumber);
	}
	bool operator!=(const ItemType &data) {
		return !(*this == data);
	}
	bool operator<(const ItemType &data) {
		return (this->m_ItemNumber < data.m_ItemNumber);
	}

	bool operator<=(const ItemType &data) {
		return (*this == data || *this < data);
	}

	bool operator>(const ItemType &data) {
		return (this->m_ItemNumber > data.m_ItemNumber);
	}
	bool operator>=(const ItemType &data) {
		return !(*this < data);
	}

	void operator=(const ItemType &data) {
		m_Usage = data.GetUsage();
		m_ContainerId= data.GetContainerId();
		m_RegisterTime = data.GetRtime();
		m_Brand = data.GetBrand();
		m_Name = data.GetName();
		m_Num = data.GetNum();
		m_ItemNumber = data.GetItemNum();
	}

	friend ostream& operator<<(ostream& os, const ItemType &data) {
		os << endl;
		switch (data.m_Usage) {
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

		switch (data.m_ContainerId) {
		case 0:
			os << "\tPlace	: Etc" << endl;
			break;
		case 1:
			os << "\tPlace	: LivingRoom" << endl;
			break;
		case 2:
			os << "\tPlace	: Kitchen" << endl;
			break;
		case 3:
			os << "\tPlace	: Bathroom" << endl;
			break;
		case 4:
			os << "\tPlace	: Bedroom" << endl;
			break;
		case 5:
			os << "\tPlace	: Library" << endl;
			break;
		default:
			os << "\tPlace	: Unknown" << endl;
			break;
		}

		if (data.GetRtime() == "")
			os << "\tRegister Time	: Unknown" << endl;
		else {

			string year = data.m_RegisterTime.substr(0, 4);
			string month = data.m_RegisterTime.substr(4, 2);
			string day = data.m_RegisterTime.substr(6, 2);
			string hour = data.m_RegisterTime.substr(8, 2);
			string minute = data.m_RegisterTime.substr(10, 2);
			string second = data.m_RegisterTime.substr(12);

			os << "\tRegister Time    : " << year << "년 " << month << "월 " << day << "일 " << hour << "시 " << minute << "분 " << second << "초 " << endl;
		}

		os << "\tBrand   : " << data.m_Brand<< endl;
		os << "\tName   : " << data.m_Name<< endl;
		os << "\tNumber of Item   : " << data.m_Num<< endl;
		os << "\tPrimary Number   : " << data.m_ItemNumber<< endl;
		return os;
	}

private:
	int m_Usage; //물품의 종류
	int m_ContainerId; //물품이 저장될 위치
	string m_RegisterTime; // 물품을 프로그램에 등록한 시간 YYYYMMDDHHMMSS
	string m_Brand; // 물품의 회사명
	string m_Name; //물품명
	int m_Num; // 구매한 물품의 수
	int m_ItemNumber; // 물품번호 primary key
};

#endif	// _ITEMTYPE_H