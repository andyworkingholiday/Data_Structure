#ifndef _RECENTTYPE_H
#define _RECENTTYPE_H

/**
*	Recent Type information class.
*/
class RecentType {
public:

	/**
	*	default constructor.
	*/
	RecentType() {
		NumofItems = 0;
		MaxItems = 3;
	}

	/**
	*	@brief	Check capacity of rItemList is full.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if rItemList capacity reached to the upper bound, otherwise return false.
	*/
	int IsFull();

	/**
	*	@brief	Get Bottomdata from the rItemlist
	*	@pre	rItemlist should be initialized.
	*	@post	Copy item to data
	*	@param	data data which is copied.
	*/
	void Bottomdata(ItemType& data);

	/**
	*	@brief	Make list empty.
	*	@pre	none.
	*	@post	clear list.
	*/
	void MakeEmpty();

	/**
	*	@brief	add a new Item into rItemList
	*	@pre	rItemList should be initialized.
	*	@post	added the new Item into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	void Add(ItemType data);

	/**
	*	@brief	Delete item from the Bottom of ritemList
	*	@pre	Id in the param data must be initialized.
	*	@post	Delete item from the Bottom of ritemList
	*/
	void DeletefromBottom();

	/**
	*	@brief	Get Number of Items
	*	@pre	NumofItems is set.
	*	@post	none.
	*	@return	Number of Items
	*/
	int GetNum();

	/**
	*	@brief	Print all the items in the tItemlist on screen
	*	@pre	tItemlist has been initialized.
	*	@post	None.
	*/
	void Display();

	/**
	*	@brief	Find the item with same primary key and delete item from ritemList
	*	@pre	Id in the param data must be initialized.
	*	@post	Delete item from the ritemList
	*	@param	data	data want to delete
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Delete(ItemType& data);

	/**
	*	@brief	move list iterator to the next item and search the data
	*	@pre	rItemlist has been initialized.
	*	@post	search item
	*	@param	data	the data want to find it does not need to be initialized.
	*	@return	if find the item return 1,  oterwise return 0.
	*/
	int Search(ItemType& data);

	/**
	*	@brief	move list iterator to the next item and Replace the data
	*	@pre	rItemlist has been initialized.
	*	@post	search item and Replace it
	*	@param	data	the data want to Replace it does not need to be initialized.
	*	@return	if find the item return 1,  oterwise return 0.
	*/
	int Replace(ItemType& data);

private:
	int NumofItems; // 물건이 담긴 갯수
	int MaxItems; // 물건 허용 갯수
	Stack<ItemType> rItemList; // ItemType가 담기는 Stack
};

#endif	// RECENTTYPE_H