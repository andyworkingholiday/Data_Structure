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
	if (IsEmpty()) { // ����Ʈ�� ������� �� ù�� ° �ε����� �߰�
		m_Array[0] = data;
		m_Length++;
		return 1;
	}
	else if (IsFull()) return 0; // ����Ʈ ���� á�� �� 0 return
	

	else if (data > m_Array[m_Length - 1]) { // ���� ���� �ε������� ���� Ŭ���
		if (RetrieveByBS(data) == -1) { //���� ����Ž�� �� �ش� �����Ͱ� ����� add�� �˴ϴ�.
			m_Array[m_Length] = data;
			m_Length++;
			return 1;
		}
		printf("\n\t Same KeyNumber has found.\n"); // ����Ž������ ���� �߰��� �� �� add�� ���� �ʽ��ϴ�.
		return 0;
	}

	else { 
		ResetList();
		ItemType CurItem;
		GetNextItem(CurItem); // �ε����� �ϳ��� ���ذ��鼭 param data�� ���մϴ�.
		while (m_CurPointer < m_Length) {
			if (CurItem < data) // param data�� �� Ŭ �� ���� �ε����� ��
				GetNextItem(CurItem);
			else if (CurItem > data) { // �ش� �ε����� primary number�� �� Ŭ �� �ڿ� �ִ� �����͸� ��ĭ �ڷ� �����.
				for (int idx = m_Length - 1; idx >= m_CurPointer; idx--)
					m_Array[idx + 1] = m_Array[idx];
				m_Array[m_CurPointer] = data;
				m_Length++;
				return 1;
			}
			else {  // ������ �����Ͱ� �߰ߵ� �� add���� �ʰ� return 0
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

// sorted list�� �ε��� 0���� ���������� Ž���մϴ�.
int SortedListType::Retrieve_SeqS(ItemType& data) { 
	ItemType CurItem;
	ResetList();
	GetNextItem(CurItem);
	while (CurItem < data && m_CurPointer < m_Length) {
		GetNextItem(CurItem);
	}
	
	if (CurItem == data) { // primary number�� ���� ��� 1 return
		data = CurItem;
		return 1;
	}
	else return 0;
}


int SortedListType::Delete(ItemType data) {
	int index = RetrieveByBS(data); //����Ž���� ����Ͽ� �ش� index �޾ƿ�
	if (index != -1) { // ������ primary number �߰� �� �� �ڿ� �ִ� data�� ��ĭ �ڷ� �����.
		if (index != m_Length - 1) {
			for (int idx = index; idx < m_Length - 1; idx++)
				m_Array[idx] = m_Array[idx + 1];
		}
		m_Length--;
		return 1;
	}

	return 0; // ������ primary number ���� �� �� index�� -1 �Ͻ� return 0
}

int SortedListType::Replace(ItemType data) {
	ItemType dummy = data; 
	int index = RetrieveByBS(dummy); //����Ž���� ����Ͽ� �ش� index �޾ƿ�
	if (index != -1) { // ������ primary number �߰� �� param data�� �ش� index�� ī���Ѵ�.
		m_Array[index] = data;
		return 1;
	}
	else return 0; // ������ primary number ���� �� �� index�� -1 �Ͻ� return 0
}

int SortedListType::RetrieveByBS(ItemType& data) {
	int start = 0, end = m_Length - 1, mid; //start= 0, end = ����Ʈ�� ��, mid= �� �߰�
	while (end - start >= 0) { 
		mid = (start + end) / 2;
		if (m_Array[mid]==data) { // ������ primary number �߰� �� �ش� index�� return
			data.CopyRecord(m_Array[mid]);
			return mid;
		}
		else if (m_Array[mid]>data) end = mid - 1; // param data�� mid�� data���� �۴ٴ� ���� 0�� mid ���̿� data�� ���� �� �ִٴ� ��
		else start = mid + 1; // param data�� mid�� data���� ũ�ٴ� ���� mid�� end ���̿� data�� ���� �� �ִٴ� ��
	}
	return -1; // �߰� ���� �� -1 return
}