#ifndef _APPLICATION_H
#define _APPLICATION_H

class Application {
public:
	/**
	*	default constructor.
	*/
	Application() {
		m_Command = 0;

	}

	/**
	*	destructor.
	*/
	~Application() {}

	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int GetCommand();

	/**
	*	@brief	Add new record into Selected list.
	*	@pre	The list should be initialized.
	*	@post	new record is added into the the Selected list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddItem();

	/**
	*	@brief	Add new record into Master list.
	*	@pre	The Master list should be initialized.
	*	@post	new record is added into the the Master list and Container List together
	*	@param	data	The data which is put
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddItemToMasterList(ItemType data);

	/**
	*	@brief	Add new record into Master list.
	*	@pre	The Master list should be initialized.
	*	@post	new record is added into the the Master list and Container List together
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddItemToMasterListFromKB();

	/**
	*	@brief	Add new record into Temporary list.
	*	@pre	The Temporary list. should be initialized.
	*	@post	new record is added into the the Temporary list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddItemToTempList();

	/**
	*	@brief	Add new record into Container list from Temporary list.
	*	@pre	The Temporary list, Container list should be initialized.
	*	@post	new record is added into Container list from Temporary list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddItemToContainerFromTemp();

	/**
	*	@brief	Add new record into Container list from Temporary list, using Dequeue.
	*	@pre	The Temporary list, Container list should be initialized.
	*	@post	new record is added into Container list from Temporary list using Dequeue.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddItemToContainerFromTempFront();

	/**
	*	@brief	Display all Items in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllItem();


	/**
	*	@brief	Display all Items in the stroage.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayItembyLocation();

	/**
	*	@brief	Display all Photos in the storage.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayPhotobyLocation();

	/**
	*	@brief	Make Selected List Empty
	*	@pre	none.
	*	@post	The List is cleared
	*/
	void MakeEmpty();

	/**
	*	@brief	Open a file by file descriptor as an input file.
	*	@pre	a file for reading is exist.
	*	@post	open the file for reading.
	*	@param	fileName	a filename to open for reading.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenInFile(char* fileName);

	/**
	*	@brief	Open a file by file descriptor as an output file.
	*	@pre	list should be initialized.
	*	@post	open the file for writing.
	*	@param	fileName	a filename to open for writing.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenOutFile(char* fileName);

	/**
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile();

	/**
	*	@brief	Open a file as a write mode, and write all data into the file,
	*	@pre	The file is not opened.
	*	@post	the list is stored in the output file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile();

	/**
	*	@brief	Retreive item from keyboard input
	*	@pre	list should be initalized
	*	@post	Delete the item with same primary key
	*/
	void RetrieveItem();


	/**
	*	@brief	Retrieve item using binary search from keyboard input
	*	@pre	list should be initalized
	*	@post	find the item with same primary key
	*/
	void RetrieveItemFromMaster();

	/**
	*	@brief	Retrieve item using binary search from keyboard input
	*	@pre	list should be initalized
	*	@post	find the item with same primary key
	*/
	void RetrieveItemFromTemp();



	/**
	*	@brief	Delete item from keyboard input
	*	@pre	list should be initalized
	*	@post	Delete the item with same primary key
	*/
	void DeleteItem();

	/**
	*	@brief	Delete item using binary search from the Master List
	*	@pre	List should be initalized
	*	@post	Delete the item with same primary key from the Master List
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int DeleteItemFromMaster();

	/**
	*	@brief	Delete item using binary search from the Temporary List
	*	@pre	List should be initalized
	*	@post	Delete the item with same primary key from the Temporary List
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int DeleteItemFromTemp();

	/**
	*	@brief	Replace item using binary search from keyboard input
	*	@pre	list should be initalized
	*	@post	find the item in the list with same primary key and replace it with input parameter
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	void ReplaceItem();

	/**
	*	@brief	Replace item using binary search from the Master List
	*	@pre	List should be initalized
	*	@post	Replace the item with same primary key from the Master List
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReplaceItemFromMaster();

	/**
	*	@brief	Replace item using binary search from the Temporary List
	*	@pre	List should be initalized
	*	@post	Replace the item with same primary key from the Temporary List
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReplaceItemFromTemp();

	/**
	*	@brief	Search item by member usage from the keyboard input
	*	@pre	list should be initalized
	*	@post	find the item with the function SearchListByMemberUsage
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int RetreiveRecordByMemberUsage();

	/**
	*	@brief	Search item by member name from the keyboard input
	*	@pre	list should be initalized
	*	@post	find the item with the function SearchListByMemberName
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int RetreiveRecordByMemberName();

	/**
	*	@brief	Search item by member name
	*	@pre	list should be initalized
	*	@post	find the item in the list include name from param data
	*	@param	inData	input data
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int SearchListByMemberName(ItemType& inData);

	/**
	*	@brief	Search item by member usage
	*	@pre	list should be initalized
	*	@post	find the item in the list with same usage from param data
	*	@param	inData	input data
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int SearchListByMemberUsage(ItemType& inData);

	/**
	*	@brief	Add new Photo into Container
	*	@pre	The Container should be initialized.
	*	@post	new record is added into the the Selected Container
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddPhoto();

	/**
	*	@brief	Display all photos in the Container on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayPhoto();

	/**
	*	@brief	Delete Photo into Container
	*	@pre	The Container should be initialized.
	*	@post	Delete photo in the Selected Container
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int DeletePhoto();

	/**
	*	@brief	Update Photo into Container
	*	@pre	The Container should be initialized.
	*	@post	Update photo in the Selected Container
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int UpdatePhoto();

	/**
	*	@brief	Display all the Containers in the Storage
	*	@pre	StorageType should be initialized
	*	@post	Display All the Containers
	*/
	void DisplayAllContainer();

	/**
	*	@brief	Display all the Detail Containers in the Storage reference with MasterList
	*	@pre	StorageType and MasterList should be initialized
	*	@post	Display All the Containers with Details
	*/
	void DisplayAllDetailsContainer();

	/**
	*	@brief	Search item by Purchasing day from the keyboard input
	*	@pre	list should be initalized
	*	@post	find the item with the function SearchListByMemberPday
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int RetrieveByPday();

	/**
	*	@brief	Search item by Purchasing day
	*	@pre	list should be initalized
	*	@post	find the item in the list with Purchasing day from param data
	*	@param	inData1, inData2	input data
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int SearchListByMemberPday(ItemType& inData1, ItemType& inData2);

private:
	ifstream m_InFile; // input file
	ofstream m_OutFile; // output file
	int m_Command;  // input command from keyboard
	CMinHeap<ItemType> MasterList;
	SortedList<StorageType> StorageList;
	TempType TempList;
};
#endif	// _APPLICATION_H