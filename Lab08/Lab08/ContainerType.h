#ifndef _CONTAINERTYPE_H
#define _CONTAINERTYPE_H

/**
*	Container information class.
*/
class ContainerType {
public:

	/**
	*	default constructor.
	*/
	ContainerType() {
		ContainerId = -1;
		NumofItem = 0;
		NumofPhoto = 0;
	}

	/**
	*	@brief	Check capacity of SimpleItemList is full.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if SimpleItemList capacity reached to the upper bound, otherwise return false.
	*/
	bool IsItemFull();

	/**
	*	@brief	Check capacity of SimpleItemList is Empty
	*	@pre	none.
	*	@post	none.
	*	@return	return true if SimpleItemList capacity reached to the lower bound, otherwise return false.
	*/
	bool IsItemEmpty();

	/**
	*	@brief	Check capacity of PhtoList is full.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if PhtoList capacity reached to the upper bound, otherwise return false.
	*/
	bool IsPhotoFull();

	/**
	*	@brief	Check capacity of PhtoList is Empty.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if PhtoList capacity reached to the lower bound, otherwise return false.
	*/
	bool IsPhotoEmpty();

	/**
	*	@brief	Get Container ID
	*	@pre	Container ID is set.
	*	@post	none.
	*	@return	Container ID
	*/
	int GetContainerId() const {
		return ContainerId;
	}

	/**
	*	@brief	Get Number of Items
	*	@pre	none.
	*	@post	none.
	*	@return	Number of Items
	*/
	int GetNumofItem() const {
		return NumofItem;
	}

	/**
	*	@brief	Get Number of Photos
	*	@pre	none.
	*	@post	none.
	*	@return	Number of Photos
	*/
	int GetNumofPhoto() const {
		return NumofPhoto;
	}

	/**
*	@brief	Set Container ID
*	@pre	none.
*	@post	Container ID is set.
*	@param	inid Container ID
*/
	void SetContainerId(int inId);

	/**
	*	@brief	Set ContainerId from keyboard.
	*	@pre	none.
	*	@post	ContainerId is set.
	*/
	void SetContainerIdFromKB();

	/**
	*	@brief	add a new Item into SimpleItemList
	*	@pre	SimpleItemList should be initialized.
	*	@post	added the new Item into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	void AddItem(SimpleItemType& data);


	/**
	*	@brief	Find the item with same primary key and delete item from SimpleitemList
	*	@pre	Id in the param data must be initialized.
	*	@post	Delete item from the list
	*	@param	data	data want to delete
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int DeleteItem(SimpleItemType& data);

	/**
	*	@brief	Find the item with same primary key and Update item from SimpleitemList
	*	@pre	Id in the param data must be initialized.
	*	@post	Update item from the list
	*	@param	data	data want to update
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int UpdateItem(SimpleItemType& data);

	/**
	*	@brief	add a new Photo into PhotoList
	*	@pre	PhotoList should be initialized.
	*	@post	added the new Photo into the PhotoList
	*	@param	s	new Photoname
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddPhoto(string s);

	/**
	*	@brief	Find the Photo with same name and delete item from PhotoList
	*	@pre	s in the param data must be initialized.
	*	@post	Delete Photo from the Photolist
	*	@param	s	Photoname want to delete
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int DeletePhoto(string& s);

	/**
	*	@brief	Find the Photo with same name and update item from PhotoList
	*	@pre	s in the param data must be initialized.
	*	@post	Update Photo from the Photolist
	*	@param	s	Photoname want to update
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int UpdatePhoto(string s);

	/**
	*	@brief	Print all the items in the SimpeItemlist on screen
	*	@pre	list has been initialized.
	*	@post	None.
	*/
	void DisplayAllItem();

	/**
	*	@brief	Print all the items in the SimpePhotolist on screen
	*	@pre	list has been initialized.
	*	@post	None.
	*/
	void DisplayAllPhoto();

	/**
	*	@brief	Print all the items with detail in the SimpleItemList
	*	@pre	list has been initialized.
	*	@post	None.
	*/
	void DisplayAllDetailsItem(CMinHeap<ItemType>& ref);

	/**
	*	@brief	Search usage by member name
	*	@pre	SimpleItemlist should be initalized
	*	@post	find the item in the Simpleitemlist with same name from param data
	*	@param	data	input data
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int FindByName(SimpleItemType data);

	/**
	*	@brief	Search usage by member usage
	*	@pre	SimpleItemlist should be initalized
	*	@post	find the item in the Simpleitemlist with same usage from param data
	*	@param	data	input data
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int FindByUsage(SimpleItemType data);

	/**
	*	@brief	Search item by member name from the keyboard input
	*	@pre	SimpleItemlist should be initalized
	*	@post	find the item with the function FindByName
	*/
	void FindNameFromKB();

	/**
	*	@brief	Search item by usage name from the keyboard input
	*	@pre	SimpleItemlist should be initalized
	*	@post	find the item with the function FindByUsage
	*/
	void FindUsageFromKB();

	// 연산자 오버로딩
	bool operator==(const ContainerType &data) {
		return (this->ContainerId == data.ContainerId);
	}
	bool operator!=(const ContainerType &data) {
		return !(*this == data);
	}
	bool operator<(const ContainerType &data) {
		return (this->ContainerId < data.ContainerId);
	}

	bool operator<=(const ContainerType &data) {
		return (*this == data || *this < data);
	}

	bool operator>(const ContainerType &data) {
		return (this->ContainerId > data.ContainerId);
	}
	bool operator>=(const ContainerType &data) {
		return !(*this < data);
	}

	void operator=(const ContainerType &data) {
		ContainerId = data.GetContainerId();
		NumofItem = data.GetNumofItem();
		NumofPhoto = data.GetNumofPhoto();
		SimpleItemList = data.SimpleItemList;
		PhotoList = data.PhotoList;
	}

	friend ostream& operator<<(ostream& os, const ContainerType& _item) {
		os << "\n\tContainer ID : " << _item.ContainerId << endl;
		os << "\n\tItem List    : " << endl;
		os << _item.SimpleItemList << endl;
		os << "\n\tPhoto List    : " << endl;
		os << _item.PhotoList << endl;
		return os;
	}

private:
	int ContainerId; // 물건이 담기는 컨테이너 번호
	int NumofItem; // 물건이 담긴 갯수
	int NumofPhoto; // 사진이 담긴 갯수
	UnsortedList<SimpleItemType> SimpleItemList; // SimpleItemType가 담기는 UnsortedList
	UnsortedList<string> PhotoList; // 사진을 찍은 위치가 담기는 UnsortedList
};

#endif	// CONTAINERTYPE_H