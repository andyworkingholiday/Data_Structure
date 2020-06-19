#ifndef _ITEMTYPE_H
#define _ITEMTYPE_H
#include "Heart.h"

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
		m_StorageId = 0;
		m_ContainerId = -1;
		SetTimeFromSystem();
		m_Pday = -1;
		m_Brand = "";
		m_Name = "";
		m_Heart = false;
        m_Photo = "0";
		m_ItemNumber = -1;
	}

	/**
	*	parameterized constructor.
	*/
	ItemType(int inUsage, int inSID, int inCID, string inRtime, int inPday, string inBrand, string inName, bool inHeart, string inPhoto, int inItemNum) {
		this->m_Usage = inUsage;
		this->m_StorageId = inSID;
		this->m_ContainerId = inCID;
		this->m_RegisterTime = inRtime;
		this->m_Pday = inPday;
		this->m_Brand = inBrand;
		this->m_Name = inName;
		this->m_Heart = inHeart;
		this->m_Photo = inPhoto;
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
	*	@brief	Get Storage ID
	*	@pre	Storage ID is set.
	*	@post	none.
	*	@return	Storage ID
	*/
	int GetStorageId() const {
		return m_StorageId;
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
	*	@brief	Get Purchase day
	*	@pre	Item Purchasing day is set.
	*	@post	none.
	*	@return	Item Purchasing day
	*/
	int GetPday() const {
		return m_Pday;
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
	*	@brief	Get Heart of item
	*	@pre	Heart of item is set.
	*	@post	none.
	*	@return	Heart of item
	*/
	bool GetHeart() const {
		return m_Heart;
	}

	/**
	*	@brief	Get Item Photo Directory
	*	@pre	Photo Directory is set.
	*	@post	none.
	*	@return	Photo Directory
	*/
	string GetPhoto() const {
		return m_Photo;
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
	*	@brief	Set Storage ID
	*	@pre	none.
	*	@post	Storage ID is set.
	*	@param	inSID Storage ID
	*/
	void SetStorageId(int inSID) {
		this->m_StorageId = inSID;
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
	*	@brief	Set Item Purchasing day
	*	@pre	none.
	*	@post	Item Purchasing day is set.
	*	@param	inPday	Item Purchasing day
	*/
	void SetPday(int inPday) {
		this->m_Pday = inPday;
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
	*	@brief	Set Item heart
	*	@pre	none.
	*	@post	Item heart is set.
	*	@param	inHeart	Item heart
	*/
	void SetHeart(bool inHeart) {
		this->m_Heart = inHeart;
	}

	/**
	*	@brief	Set Photo Directory
	*	@pre	none.
	*	@post	Photo Directory is set.
	*	@param	inPhoto	Photo Directory
	*/
	void SetPhoto(string inPhoto) {
		this->m_Photo = inPhoto;
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
	*	@param	inSID	Storage ID
	*	@param	inCID	Container ID
	*	@param	inRtime	Item Register time
	*	@param	inPday	Item Purchase day
	*	@param	inBrand	Brand name
	*	@param	inName	Item name
	*	@param	inNum	Number of Item
	*	@param	inPhoto	Photo Directory
	*	@param	inItemNum	 Primary KeyNumber
	*/
	void SetRecord(int inUsage, int inSID, int inCID, string inRtime, int inPday, string inBrand, string inName, bool inHeart, string inPhoto, int inItemNum) {
		SetUsage(inUsage);
		SetStorageId(inSID);
		SetContainerId(inCID);
		SetRtime(inRtime);
		SetPday(inPday);
		SetBrand(inBrand);
		SetName(inName);
		SetHeart(inHeart);
		SetPhoto(inPhoto);
		SetItemNum(inItemNum);
	}

	/**
	*	@brief	Display Item usage on screen.
	*	@pre	Item usage is set.
	*	@post	Item usage is on screen.
	*/
	void DisplayUsageOnScreen();

	/**
	*	@brief	Display StorageID on screen.
	*	@pre	StorageID is set.
	*	@post	StorageID is on screen.
	*/
	void DisplayStorageIdOnScreen();

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
	*	@brief	Display Item Purchasing day on screen.
	*	@pre	Item Purchasing time is set.
	*	@post	Item Purchasing time is on screen.
	*/
	void DisplayPdayOnScreen();

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
	*	@brief	Display heart of item on screen.
	*	@pre	heart of item is set.
	*	@post	heart of item is on screen.
	*/
	void DisplayHeartOnScreen();

	/**
	*	@brief	Display Photo Directory on screen.
	*	@pre	Photo Directory is set.
	*	@post	Photo Directory is on screen.
	*/
	void DisplayPhotoOnScreen();

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
	*	@brief	Set StorageId from keyboard.
	*	@pre	none.
	*	@post	StorageId is set.
	*/
	void SetStorageIdFromKB();

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
	*	@brief	Set Item Purchasing day from keyboard.
	*	@pre	none.
	*	@post	Item Purchasing day is set.
	*/
	void SetPdayFromKB();

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
	*	@brief	Set Heart of Item from keyboard.
	*	@pre	none.
	*	@post	Heart of Item is set.
	*/
	void SetHeartFromKB();

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
		
		if (time.wMonth < 10)
			sTime << time.wYear << "0" << time.wMonth;
		else
			sTime << time.wYear << time.wMonth;

		
		if (time.wDay < 10)
			sTime << "0" << time.wDay;
		else
			sTime << time.wDay;

		
		if (time.wHour < 10)
			sTime << "0" << time.wHour;
		else
			sTime << time.wHour;

		
		if (time.wMinute < 10)
			sTime << "0" << time.wMinute;
		else
			sTime << time.wMinute;

		
		if (time.wSecond < 10)
			sTime << "0" << time.wSecond;
		else
			sTime << time.wSecond;

		m_RegisterTime = sTime.str();		
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

	/**
	*	@brief	Write a record into file.
	*	@pre	the target file is opened. And the list should be initialized.
	*	@post	the target file is included the new Item record.
	*	@param	fout	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFileLast(ofstream& fout);
	
	bool operator==(const ItemType& data) {
		return (this->m_ItemNumber == data.m_ItemNumber);
	}
	bool operator!=(const ItemType& data) {
		return !(*this == data);
	}
	bool operator<(const ItemType& data) {
		return (this->m_ItemNumber < data.m_ItemNumber);
	}

	bool operator<=(const ItemType& data) {
		return (*this == data || *this < data);
	}

	bool operator>(const ItemType& data) {
		return (this->m_ItemNumber > data.m_ItemNumber);
	}
	bool operator>=(const ItemType& data) {
		return !(*this < data);
	}

	void operator=(const ItemType& data) {
		m_Usage = data.GetUsage();
		m_StorageId = data.GetStorageId();
		m_ContainerId = data.GetContainerId();
		m_RegisterTime = data.GetRtime();
		m_Pday = data.GetPday();
		m_Brand = data.GetBrand();
		m_Name = data.GetName();
		m_Heart = data.GetHeart();
		m_Photo = data.GetPhoto();
		m_ItemNumber = data.GetItemNum();
	}

	friend ostream& operator<<(ostream& os, const ItemType& data) {
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

		switch (data.m_StorageId) {
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

		os << "\tContainer	: " << data.GetContainerId() << "�� ° Container" << endl;

		if (data.GetRtime() == "")
			os << "\tRegister Time	: Unknown" << endl;
		else {

			string year = data.m_RegisterTime.substr(0, 4);
			string month = data.m_RegisterTime.substr(4, 2);
			string day = data.m_RegisterTime.substr(6, 2);
			string hour = data.m_RegisterTime.substr(8, 2);
			string minute = data.m_RegisterTime.substr(10, 2);
			string second = data.m_RegisterTime.substr(12);

			os << "\tRegister Time    : " << year << "�� " << month << "�� " << day << "�� " << hour << "�� " << minute << "�� " << second << "�� " << endl;
		}

		os << "\tPurcahse day	: " << data.m_Pday << endl;
		os << "\tBrand   : " << data.m_Brand << endl;
		os << "\tName   : " << data.m_Name << endl;
		Heart heart;
		os << "\tLike	: ";
		if (data.GetHeart()) heart.Like();
		else heart.UnLike();
		os << "\tPrimary Number   : " << data.m_ItemNumber << endl;
		return os;
	}

private:
	int m_Usage; 
	int m_StorageId; 
	int m_ContainerId; 
	string m_RegisterTime; 
	int m_Pday;
	string m_Brand; 
	string m_Name; 
	bool m_Heart; 
	string m_Photo;
	int m_ItemNumber; 
};

#endif	// _ITEMTYPE_H
