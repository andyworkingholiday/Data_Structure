#ifndef _STORAGETYPE_H
#define _STORAGETYPE_H

#include "ItemType.h"
#include "ContainerType.h"
#include "SortedList.h"
#include "SortedSingleLinkedList.h"

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
		MaxNum = 5;
	}

	StorageType(int maxs) {
		StorageId = -1;
		Location = "";
		CurrentNum = 0;
		MaxNum = maxs;
	}

	/**
	*	@brief	Get Storage ID
	*	@pre	Storage ID is set.
	*	@post	none.
	*	@return	Storage ID
	*/
	int GetStorageId() const {
		return StorageId;
	}

	/**
	*	@brief	Get Location
	*	@pre	Location is set.
	*	@post	none.
	*	@return	Location
	*/
	string GetLocation() const {
		return Location;
	}

	/**
	*	@brief	Get Number of Containers
	*	@pre	none.
	*	@post	none.
	*	@return	Number of Containers
	*/
	int GetNumofContainer() const {
		return CurrentNum;
	}

	/**
	*	@brief	Get Maxnumber
	*	@pre	none.
	*	@post	none.
	*	@return	MaxNumber of Containers
	*/	
	int GetMaxNum() const{
		return MaxNum;
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
	void DisplayAllDetailContainer(SortedList<ItemType>& ref);

	/**
	*	@brief	Print all the Container Items in the ContainerList
	*	@pre	list has been initialized.
	*	@post	None.
	*/
	void DisplayAllItem();

	// ������ �����ε�
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
		MaxNum=data.GetMaxNum();
		ContainerList = data.ContainerList;
	}

private:
	int StorageId; // ������ ���� ��ġ������ ������
	string Location; // �����̳ʰ� ���� ��ġ string
	int CurrentNum; // �����̳ʰ� ��� ����
	int MaxNum; // �����̳ʰ� �ִ� ��� �� �ִ� ����
	SortedSingleLinkedList<ContainerType> ContainerList; // �����̳� ����Ʈ
};

#endif	// CONTAINERTYPE_H