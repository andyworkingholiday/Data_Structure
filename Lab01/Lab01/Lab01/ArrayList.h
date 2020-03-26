#ifndef _UNSORTEDLIST_H
#define _UNSORTEDLIST_H

#include <iostream>
#include "ItemType.h"
using namespace std;
#define MAXSIZE 5

class ArrayList {
public:
	ArrayList() {
		MakeEmpty();
		ResetList();
	}

	~ArrayList() {}

	void MakeEmpty();
	int GetLength();
	bool IsFull();
	bool IsEmpty();
	int Add(ItemType data);
	void ResetList();
	int GetNextItem(ItemType& data);
	int Get(ItemType& data);
	int Delete(ItemType data);
	int Replace(ItemType data);

private:
	ItemType m_Array[MAXSIZE];
	int m_Length;
	int m_CurPointer;
};

#endif	// _UNSORTEDLIST_H