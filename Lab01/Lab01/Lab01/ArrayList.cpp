#include "ArrayList.h"
#include "ItemType.h"
using namespace std;

//List 비우기
void ArrayList::MakeEmpty() {
	m_Length = 0;
}

//List의 담긴 Item의 갯수를 return
int ArrayList::GetLength() {
	return m_Length;
}

// List가 MAXSIZE 만큼 채워져있을 시 true, 아닐 시 false
bool ArrayList::IsFull() {
	if (m_Length == MAXSIZE) {
		printf("\tList is Full!\n");
		return true;
	}
	return false;
}

// List가 아예 비워져있을 시 true, 아닐 시 false
bool ArrayList::IsEmpty() {
	if (!m_Length) {
		printf("\tList is Empty!\n");
		return true;
	}
	return false;
}

// List에 순차적으로 Item 추가 
int ArrayList::Add(ItemType data) {
	if (!IsFull()) {
		m_Array[m_Length] = data;
		m_Length++;
		return 1;
	}
	return 0;
}

// 검색 Iterator를  초기화
void ArrayList::ResetList() {
	m_CurPointer = -1;
}

// Pointer의 위치를 한 칸 이동하여 그 때의 인덱스를 반환한다.
// 그리고 함수의 parameter인 data에는 그 인덱스의 변수가 복사된다.
// 만일 List가 Full 일 시 -1을 반환한다.
int ArrayList::GetNextItem(ItemType& data) {
	m_CurPointer++;
	if (m_CurPointer == MAXSIZE) return -1;
	data = m_Array[m_CurPointer];
	return m_CurPointer;
}

// parameter data의 primary key와 일치하는 것이 있는지 List를 처음부터 순차적으로 돌면서 확인한다.
// 있을 때는 그때의 index를 반환하고 없을 시 -1을 반환한다.
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

// parameter data의 primary key와 일치하는 것이 있는지 List를 처음부터 순차적으로 돌면서 확인한다.
// 있을 때는 그 list의 data를 삭제하고 뒤에 있는 data들을 한칸 앞으로 땡긴다.
// 없을 시 0을 반환한다.
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

// parameter data의 primary key와 일치하는 것이 있는지 List를 처음부터 순차적으로 돌면서 확인한다.
// 있을 때 함수의 parameter data를 List 해당 인덱스로 대체시킨다.
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