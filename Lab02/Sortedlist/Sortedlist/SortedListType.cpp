#include "SortedListType.h"
#include "ItemType.h"
using namespace std;

void SortedListType::MakeEmpty() {
	m_Length = 0;
}

int SortedListType::GetLength() {
	return m_Length;
}

bool SortedListType::IsFull() {
	if (m_Length == MAXSIZE) 
		return true;
	return false;
}

bool SortedListType::IsEmpty() {
	if (!m_Length) 
		return true;
	return false;
}



int SortedListType::Add(ItemType data) {
	if (IsEmpty()) {
		m_Array[0] = data;
		m_Length++;
		return 1;
	}
	else if (IsFull()) {
		printf("\tList is Full\n");
		return 0;
	}

	else {
		ResetList();
		ItemType CurItem;
		GetNextItem(CurItem);
		while (m_CurPointer < m_Length) {
			if (CurItem.CompareByID(data) == LESS)
				GetNextItem(CurItem);
			else if (CurItem.CompareByID(data) == GREATER) {
				for (int idx = m_Length - 1; idx >= m_CurPointer; idx--) 
					m_Array[idx + 1] = m_Array[idx];
				m_Array[m_CurPointer] = data;
				m_Length++;
				return 1;
			}

		}
		m_Array[m_CurPointer] = data;
		m_Length++;
		return 1;
	}
}

void SortedListType::ResetList() {
	m_CurPointer = -1;
}

int SortedListType::GetNextItem(ItemType& data) {
	m_CurPointer++;
	if (m_CurPointer == MAXSIZE) return -1;
	data = m_Array[m_CurPointer];
	return m_CurPointer;
}

int SortedListType::Get(ItemType& data) {
	ItemType CurItem;
	ResetList();
	GetNextItem(CurItem);
	while (m_CurPointer < m_Length) {
		switch (CurItem.CompareByID(data)) {
		case EQUAL:
			data.CopyRecord(CurItem);
			return 1;
		case LESS:
			return 0;
		default:
			GetNextItem(CurItem);
			break;
		}
	}
	return 0;
}

int SortedListType::Delete(ItemType data) {
	if (Get(data)) {
		if (m_CurPointer != m_Length - 1) {
			for (int idx = m_CurPointer; idx < m_Length - 1; idx++)
				m_Array[idx] = m_Array[idx + 1];
		}
		m_Length--;
		return 1;
	}

	return 0;
}

int SortedListType::Replace(ItemType data) {
	if (Get(data)) {
		m_Array[m_CurPointer].CopyRecord(data);
		return 1;
	}
	return 0;
}

int SortedListType::GetByBinarySearch(ItemType& data) {
	int start = 0, end = m_Length - 1, mid;
	while (end - start >= 0) {
		mid = (start + end) / 2;
		if (m_Array[mid].CompareByID(data) == EQUAL) {
			data.CopyRecord(m_Array[mid]);
			return 1;
		}
		else if (m_Array[mid].CompareByID(data) == GREATER) end = mid - 1;
		else start = mid + 1;
	}
	return 0;
}