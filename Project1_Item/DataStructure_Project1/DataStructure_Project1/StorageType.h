#ifndef _STORAGETYPE_H
#define _STORAGETYPE_H

/**
*	Container information class.
*/
class StorageType {
public:

	/**
	*	default constructor.
	*/
	StorageType() {
		StorageId = -1;
		Location = "";
		CurrentNum = 0;
	}

	/**
	*	@brief	Get Storage ID
	*	@pre	Storage ID is set.
	*	@post	none.
	*	@return	Storage ID
	*/
	int GetStorageId() {
		return StorageId;
	}

	/**
	*	@brief	Get Location
	*	@pre	Location is set.
	*	@post	none.
	*	@return	Location
	*/
	string GetLocation() {
		return Location;
	}

	/**
	*	@brief	Get Number of Containers
	*	@pre	none.
	*	@post	none.
	*	@return	Number of Containers
	*/
	int GetNumofContainer() {
		return ContainerList.GetLength();
	}

	/**
	*	@brief	Set Storage ID
	*	@pre	none.
	*	@post	Storage ID is set.
	*	@param	inid Storage ID
	*/
	void SetStorageId(int inId);

	/**
	*	@brief	Set StorageId from keyboard.
	*	@pre	none.
	*	@post	StorageId is set.
	*/
	void SetStorageIdFromKB();

	/**
	*	@brief	Search Container
	*	@pre	ContainerList should be initialized.
	*	@post	copy the data which is find.
	*	@param	data	data which is copied.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int SearchContainer(ContainerType& data);

	/**
	*	@brief	add a new Container into ContainerList
	*	@pre	ContainerList should be initialized.
	*	@post	added the new Container into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddContainer(ContainerType& data);

	/**
	*	@brief	Find the Container with same primary key and delete Container from ContainerList
	*	@pre	Id in the param data must be initialized.
	*	@post	Delete Container from the list
	*	@param	data	data want to delete
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int DeleteContainer(ContainerType& data);

	/**
	*	@brief	Find the Container with same primary key and Update item from ContainerList
	*	@pre	Id in the param data must be initialized.
	*	@post	Update Container from the list
	*	@param	data	data want to update
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int UpdateContainer(ContainerType& data);

	/**
	*	@brief	Print all the Container info in the ContainerList
	*	@pre	list has been initialized.
	*	@post	None.
	*/
	void DisplayAllContainer();

	/**
	*	@brief	Print all the Container info in the ContainerList
	*	@pre	list has been initialized.
	*	@post	None.
	*/
	void DisplayAllDetailContainer(DoublySortedLinkedList<ItemType>& ref);

	/**
	*	@brief	Print all the Container Items in the ContainerList
	*	@pre	list has been initialized.
	*	@post	None.
	*/
	void DisplayAllItem();

	/**
	*	@brief	Print all the Container Photos in the ContainerList
	*	@pre	list has been initialized.
	*	@post	None.
	*/
	void DisplayAllPhoto();

	// 연산자 오버로딩
	bool operator==(const StorageType &data) {
		return (this->StorageId == data.StorageId);
	}
	bool operator!=(const StorageType &data) {
		return !(*this == data);
	}
	bool operator<(const StorageType &data) {
		return (this->StorageId < data.StorageId);
	}

	bool operator<=(const StorageType &data) {
		return (*this == data || *this < data);
	}

	bool operator>(const StorageType &data) {
		return (this->StorageId > data.StorageId);
	}
	bool operator>=(const StorageType &data) {
		return !(*this < data);
	}

	void operator=(StorageType &data) {
		StorageId = data.GetStorageId();
		Location = data.GetLocation();
		CurrentNum = data.GetNumofContainer();
		ContainerList = data.ContainerList;
	}

private:
	int StorageId; // 물건이 담기는 위치정보의 변수형
	string Location; // 컨테이너가 담기는 위치 string
	int CurrentNum; // 컨테이너가 담긴 갯수
	SingleSortedLinkedList<ContainerType> ContainerList; // 컨테이너 리스트
};

#endif	// CONTAINERTYPE_H