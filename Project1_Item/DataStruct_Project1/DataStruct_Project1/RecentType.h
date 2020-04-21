#ifndef _RECENTTYPE_H
#define _RECENTTYPE_H

#include "ItemType.h"
#include "StackList.h"
#include <iostream>
using namespace std;

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

private:
	int NumofItems; // 물건이 담긴 갯수
	int MaxItems; // 물건 허용 갯수
	StackList<ItemType> rItemList; // ItemType가 담기는 Stack
};

#endif	// RECENTTYPE_H
