#include "SortedList.h"
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
	else if (IsFull()) return 0;

	else if (data > m_Array[m_Length - 1]) {
		if (RetrieveByBS(data) == -1) {
			m_Array[m_Length] = data;
			m_Length++;
			return 1;
		}
		printf("\n\t Same KeyNumber has found.\n");
		return 0;
	}

	else {
		ResetList();
		ItemType CurItem;
		GetNextItem(CurItem);
		while (m_CurPointer < m_Length) {
			if (CurItem < data)
				GetNextItem(CurItem);
			else if (CurItem > data) {
				for (int idx = m_Length - 1; idx >= m_CurPointer; idx--)
					m_Array[idx + 1] = m_Array[idx];
				m_Array[m_CurPointer] = data;
				m_Length++;
				return 1;
			}
			else {
				printf("\n\t Same KeyNumber has found.\n");
				return 0;
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

int SortedListType::Retrieve_SeqS(ItemType& data) {
	ItemType CurItem;
	ResetList();
	GetNextItem(CurItem);
	while (CurItem < data && m_CurPointer < m_Length) {
		GetNextItem(CurItem);
	}
	
	if (CurItem == data) {
		data = CurItem;
		return 1;
	}
	else return 0;
}

int SortedListType::Delete(ItemType data) {
	int index = RetrieveByBS(data);
	if (index != -1) {
		if (index != m_Length - 1) {
			for (int idx = index; idx < m_Length - 1; idx++)
				m_Array[idx] = m_Array[idx + 1];
		}
		m_Length--;
		return 1;
	}

	return 0;
}

int SortedListType::Replace(ItemType data) {
	ItemType dummy = data;
	int index = RetrieveByBS(dummy);
	if (index != -1) {
		m_Array[index] = data;
		return 1;
	}
	else return 0;
}

int SortedListType::RetrieveByBS(ItemType& data) {
	int start = 0, end = m_Length - 1, mid;
	while (end - start >= 0) {
		mid = (start + end) / 2;
		if (m_Array[mid]==data) {
			data.CopyRecord(m_Array[mid]);
			return mid;
		}
		else if (m_Array[mid]>data) end = mid - 1;
		else start = mid + 1;
	}
	return -1;
}