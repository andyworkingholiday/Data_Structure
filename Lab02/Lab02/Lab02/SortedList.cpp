#include "SortedList.h"
#include "ItemType.h"
using namespace std;

// Make list empty.
void SortedListType::MakeEmpty() {
	m_Length = 0;
}

// Get a number of records in current list.
int SortedListType::GetLength() {
	return m_Length;
}

// Check capacity of list is full.
bool SortedListType::IsFull() {
	if (m_Length == MAXSIZE)
		return true;
	return false;
}

// search item by using primary key
bool SortedListType::IsEmpty() {
	if (!m_Length)
		return true;
	return false;
}

// Add data to list
int SortedListType::Add(ItemType data) {
	if (IsEmpty()) { // 리스트가 비어있을 시 첫번 째 인덱스에 추가
		m_Array[0] = data;
		m_Length++;
		return 1;
	}
	else if (IsFull()) return 0; // 리스트 가득 찼을 시 0 return
	

	else if (data > m_Array[m_Length - 1]) { // 가장 끝의 인덱스보다 값이 클경우
		if (RetrieveByBS(data) == -1) { //만일 이진탐색 시 해당 데이터가 없어야 add가 됩니다.
			m_Array[m_Length] = data;
			m_Length++;
			return 1;
		}
		printf("\n\t Same KeyNumber has found.\n"); // 이진탐색으로 인해 발견을 할 시 add가 되지 않습니다.
		return 0;
	}

	else { 
		ResetList();
		ItemType CurItem;
		GetNextItem(CurItem); // 인덱스를 하나씩 더해가면서 param data와 비교합니다.
		while (m_CurPointer < m_Length) {
			if (CurItem < data) // param data가 더 클 시 다음 인덱스와 비교
				GetNextItem(CurItem);
			else if (CurItem > data) { // 해당 인덱스의 primary number가 더 클 시 뒤에 있는 데이터를 한칸 뒤로 땡긴다.
				for (int idx = m_Length - 1; idx >= m_CurPointer; idx--)
					m_Array[idx + 1] = m_Array[idx];
				m_Array[m_CurPointer] = data;
				m_Length++;
				return 1;
			}
			else {  // 동일한 데이터가 발견될 시 add하지 않고 return 0
				printf("\n\t Same KeyNumber has found.\n");
				return 0;
			}

		}
		m_Array[m_CurPointer] = data;
		m_Length++;
		return 1;
	}
}

// Initialize list iterator.
void SortedListType::ResetList() {
	m_CurPointer = -1;
}

// move list iterator to the next item in list and get that item.
int SortedListType::GetNextItem(ItemType& data) { 
	m_CurPointer++;
	if (m_CurPointer == MAXSIZE) return -1;
	data = m_Array[m_CurPointer];
	return m_CurPointer;
}

// sorted list를 인덱스 0부터 순차적으로 탐색합니다.
int SortedListType::Retrieve_SeqS(ItemType& data) { 
	ItemType CurItem;
	ResetList();
	GetNextItem(CurItem);
	while (CurItem < data && m_CurPointer < m_Length) {
		GetNextItem(CurItem);
	}
	
	if (CurItem == data) { // primary number가 같을 경우 1 return
		data = CurItem;
		return 1;
	}
	else return 0;
}


int SortedListType::Delete(ItemType data) {
	int index = RetrieveByBS(data); //이진탐색을 사용하여 해당 index 받아옴
	if (index != -1) { // 동일한 primary number 발견 시 그 뒤에 있는 data를 한칸 뒤로 땡긴다.
		if (index != m_Length - 1) {
			for (int idx = index; idx < m_Length - 1; idx++)
				m_Array[idx] = m_Array[idx + 1];
		}
		m_Length--;
		return 1;
	}

	return 0; // 동일한 primary number 없을 시 즉 index가 -1 일시 return 0
}

int SortedListType::Replace(ItemType data) {
	ItemType dummy = data; 
	int index = RetrieveByBS(dummy); //이진탐색을 사용하여 해당 index 받아옴
	if (index != -1) { // 동일한 primary number 발견 시 param data를 해당 index에 카피한다.
		m_Array[index] = data;
		return 1;
	}
	else return 0; // 동일한 primary number 없을 시 즉 index가 -1 일시 return 0
}

int SortedListType::RetrieveByBS(ItemType& data) {
	int start = 0, end = m_Length - 1, mid; //start= 0, end = 리스트의 끝, mid= 그 중간
	while (end - start >= 0) { 
		mid = (start + end) / 2;
		if (m_Array[mid]==data) { // 동일한 primary number 발견 시 해당 index를 return
			data.CopyRecord(m_Array[mid]);
			return mid;
		}
		else if (m_Array[mid]>data) end = mid - 1; // param data가 mid의 data보다 작다는 것은 0과 mid 사이에 data가 있을 수 있다는 것
		else start = mid + 1; // param data가 mid의 data보다 크다는 것은 mid과 end 사이에 data가 있을 수 있다는 것
	}
	return -1; // 발견 못할 시 -1 return
}