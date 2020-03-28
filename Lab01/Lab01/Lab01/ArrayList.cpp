#include "ArrayList.h"
#include "ItemType.h"
using namespace std;

//List ����
void ArrayList::MakeEmpty() {
	m_Length = 0;
}

//List�� ��� Item�� ������ return
int ArrayList::GetLength() {
	return m_Length;
}

// List�� MAXSIZE ��ŭ ä�������� �� true, �ƴ� �� false
bool ArrayList::IsFull() {
	if (m_Length == MAXSIZE) {
		printf("\tList is Full!\n");
		return true;
	}
	return false;
}

// List�� �ƿ� ��������� �� true, �ƴ� �� false
bool ArrayList::IsEmpty() {
	if (!m_Length) {
		printf("\tList is Empty!\n");
		return true;
	}
	return false;
}

// List�� ���������� Item �߰� ������ primary key�� ������ �߰��� ���Ѵ�.
int ArrayList::Add(ItemType data) {
	if (!IsFull()) {
		if (Get(data) == -1) {
			m_Array[m_Length] = data;
			m_Length++;
			return 1;
		}
		else printf("\n\t Same SongNumber has found.\n");
		return 0;
	}
	return 0;
}

// �˻� Iterator��  �ʱ�ȭ
void ArrayList::ResetList() {
	m_CurPointer = -1;
}

// Pointer�� ��ġ�� �� ĭ �̵��Ͽ� �� ���� �ε����� ��ȯ�Ѵ�.
// �׸��� �Լ��� parameter�� data���� �� �ε����� ������ ����ȴ�.
// ���� List�� Full �� �� -1�� ��ȯ�Ѵ�.
int ArrayList::GetNextItem(ItemType& data) {
	m_CurPointer++;
	if (m_CurPointer == MAXSIZE) return -1;
	data = m_Array[m_CurPointer];
	return m_CurPointer;
}

// parameter data�� primary key�� ��ġ�ϴ� ���� �ִ��� List�� ó������ ���������� ���鼭 Ȯ���Ѵ�.
// ���� ���� �׶��� index�� ��ȯ�ϰ� ���� �� -1�� ��ȯ�Ѵ�.
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

// parameter data�� primary key�� ��ġ�ϴ� ���� �ִ��� List�� ó������ ���������� ���鼭 Ȯ���Ѵ�.
// ���� ���� �� list�� data�� �����ϰ� �ڿ� �ִ� data���� ��ĭ ������ �����.
// ���� �� 0�� ��ȯ�Ѵ�.
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

// parameter data�� primary key�� ��ġ�ϴ� ���� �ִ��� List�� ó������ ���������� ���鼭 Ȯ���Ѵ�.
// ���� �� �Լ��� parameter data�� List �ش� �ε����� ��ü��Ų��.
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