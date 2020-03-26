#include "ArrayList.h"
#include "ItemType.h"
using namespace std;

void ArrayList::MakeEmpty() {
	m_Length = 0;
}

int ArrayList::GetLength() {
	return m_Length;
}

bool ArrayList::IsFull() {
	if (m_Length == MAXSIZE) {
		printf("\tList is Full!\n");
		return true;
	}
	return false;
}

bool ArrayList::IsEmpty() {
	if (!m_Length) {
		printf("\tList is Empty!\n");
		return true;
	}
	return false;
}

int ArrayList::Add(ItemType data) {
	if (!IsFull()) {
		m_Array[m_Length] = data;
		m_Length++;
		return 1;
	}
	return 0;
}

void ArrayList::ResetList() {
	m_CurPointer = -1;
}

int ArrayList::GetNextItem(ItemType& data) {
	m_CurPointer++;
	if (m_CurPointer == m_Length) return -1;
	data = m_Array[m_CurPointer];
	return m_CurPointer;
}

int ArrayList::Get(ItemType& data) {
	ResetList();
	m_CurPointer++;
	for (m_CurPointer; m_CurPointer < m_Length; m_CurPointer++) {
		if (data == m_Array[m_CurPointer]) {
			data = m_Array[m_CurPointer];
			return m_CurPointer;
		}
	}
	return -1;
}


int ArrayList::Delete(ItemType data) {
	ResetList();
	m_CurPointer++;
	bool flag = false;
	for (m_CurPointer; m_CurPointer < m_Length; m_CurPointer++) {
		if (data == m_Array[m_CurPointer]) {
			flag = true;
			break;
		}
	}

	if (flag) {
		if (m_CurPointer != m_Length - 1) {
			for (m_CurPointer; m_CurPointer < m_Length - 1; m_CurPointer++) {
				m_Array[m_CurPointer] = m_Array[m_CurPointer + 1];
			}
		}
		m_Length--;
		return 1;
	}
	else return 0;
}

int ArrayList::Replace(ItemType data) {
	ResetList();
	m_CurPointer++;
	for (m_CurPointer; m_CurPointer < m_Length; m_CurPointer++) {
		if (data == m_Array[m_CurPointer]) {
			m_Array[m_CurPointer] = data;
			return 1;
		}
	}
	return 0;
}