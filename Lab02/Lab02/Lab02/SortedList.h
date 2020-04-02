#ifndef _SORTEDLIST_H
#define _SORTEDLIST_H

#include <iostream>
#include "ItemType.h"
using namespace std;
#define MAXSIZE 5

class SortedListType {
public:
	SortedListType() {
		MakeEmpty();
		ResetList();
	}

	~SortedListType() {}

	void MakeEmpty();
	int GetLength();
	bool IsFull();
	bool IsEmpty();
	void ResetList();
	int GetNextItem(ItemType& data);
	int Add(ItemType data);
	int Delete(ItemType data);
	int Replace(ItemType data);
	int Retrieve_SeqS(ItemType& data);
	int RetrieveByBS(ItemType& data);

private:
	ItemType m_Array[MAXSIZE];
	int m_Length;
	int m_CurPointer;
};

#endif	// _SORTEDLIST_H