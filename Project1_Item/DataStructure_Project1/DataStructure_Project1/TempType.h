#ifndef _TEMPTYPE_H
#define _TEMPTYPE_H

/**
*	Temporary Type information class.
*/
class TempType {
public:

	/**
	*	default constructor.
	*/
	TempType() {
		NumofItems = 0;
	}

	/**
	*	@brief	Check capacity of tItemList is full.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if tItemList capacity reached to the upper bound, otherwise return false.
	*/
	int IsFull();

	/**
	*	@brief	Check capacity of tItemList is Empty
	*	@pre	none.
	*	@post	none.
	*	@return	return true if tItemList capacity reached to the lower bound, otherwise return false.
	*/
	int IsEmpty();

	/**
	*	@brief	Get Frontdata from the tItemlist
	*	@pre	tItemlist should be initialized.
	*	@post	Copy item to data
	*	@param	data data which is copied.
	*/
	void Frontdata(ItemType& data);

	/**
	*	@brief	Make list empty.
	*	@pre	none.
	*	@post	clear list.
	*/
	void MakeEmpty();

	/**
	*	@brief	add a new Item into tItemList
	*	@pre	tItemList should be initialized.
	*	@post	added the new Item into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	void Add(ItemType data);

	/**
	*	@brief	Delete item from the Front of titemList
	*	@pre	Id in the param data must be initialized.
	*	@post	Delete item from the Front of titemList
	*	@param	data	data which is copied
	*/
	void DeltefromFront(ItemType& data);

	/**
	*	@brief	Get Number of Items
	*	@pre	NumofItems is set.
	*	@post	none.
	*	@return	Number of Items
	*/
	int GetNum();

	/**
	*	@brief	Get Next Items
	*	@pre	tItemList is set.
	*	@post	none.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int GetNextItem(ItemType& data);

	/**
	*	@brief	Reset Pointer
	*	@pre	tItemList is set.
	*	@post	none.
	*/
	void ResetPointer();

	/**
	*	@brief	Print all the items in the tItemlist on screen
	*	@pre	tItemlist has been initialized.
	*	@post	None.
	*/
	void Display();

	/**
	*	@brief	Print the item front of tItemlist on screen
	*	@pre	None.
	*	@post	None.
	*/
	void DisplayFront();

	/**
	*	@brief	Find the item with same primary key and delete item from titemList
	*	@pre	Id in the param data must be initialized.
	*	@post	Delete item from the titemList
	*	@param	data	data want to delete
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Delete(ItemType& data);

	/**
	*	@brief	move list iterator to the next item and search the data
	*	@pre	tItemlist has been initialized.
	*	@post	search item
	*	@param	data	the data want to find it does not need to be initialized.
	*	@return	if find the item return 1,  oterwise return 0.
	*/
	int Search(ItemType& data);

	/**
	*	@brief	move list iterator to the next item and Replace the data
	*	@pre	tItemlist has been initialized.
	*	@post	search item and Replace it
	*	@param	data	the data want to Replace it does not need to be initialized.
	*	@return	if find the item return 1,  oterwise return 0.
	*/
	int Replace(ItemType& data);

private:
	int NumofItems; // 물건이 담긴 갯수
	QList<ItemType> tItemList; // ItemType가 담기는 QList
};

#endif	// TEMPTYPE_H