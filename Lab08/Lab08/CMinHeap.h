#ifndef _MINHEAP_H
#define _MINHEAP_H

#include "CHeapBase.h"


/**
*	CMinHeap Ŭ����.
*/
template <typename T>
class CMinHeap : public CHeapBase<T> {
public:
	/**
	*	������.
	*/
	CMinHeap();

	/**
	*	������ - �迭�� �ִ� ����.
	*/
	CMinHeap(int size);

	/**
	*	@brief	������ �Ʒ��� �������鼭 Heap ũ�⸦ ���Ͽ� �����ϴ� �����Լ�.
	*	@pre	Heap�� �ʱ�ȭ�Ǿ���Ѵ�.
	*	@post	Heap�� �����͸� ���Ͽ� �����Ѵ�.
	*	@param	iparent	�������� ������.
	*	@param	ibottom	������ ������.
	*/
	virtual void ReheapDown(int iparent, int ibottom);

	/**
	*	@brief	�Ʒ����� ���� �ö󰡸鼭 Heap ũ�⸦ ���Ͽ� �����ϴ� �����Լ�.
	*	@pre	Heap�� �ʱ�ȭ�Ǿ���Ѵ�.
	*	@post	Heap�� �����͸� ���Ͽ� �����Ѵ�.
	*	@param	iroot	ù��° ������.
	*	@param	ibottom	�ö󰡴� ������.
	*/
	virtual void ReheapUp(int iroot, int ibottom);

	/**
	*	@brief	Heap�� �����͸� �����ϴ� �����Լ�.
	*	@pre	Heap�� �ʱ�ȭ�Ǿ���Ѵ�.
	*	@post	Heap�� �����͸� �����Ѵ�.
	*	@param	item	ItemType���� ���� �� ������.
	*	@param	found	������ �����͸� ã�Ҵ��� �ƴ��� Ȯ��.
	*	@param	ibottom	�˻� ���� �迭 ��ġ.
	*/
	virtual void DeleteNode(T& item, bool& found, int iparent);

	/**
	*	@brief	Heap�� �����͸� ��ü�ϴ� ���������Լ�.
	*	@pre	Heap�� �ʱ�ȭ�Ǿ���Ѵ�.
	*	@post	Heap�� �����͸� ��ü�Ѵ�.
	*	@param	item	ItemType���� ��ü �� ������.
	*	@param	found	��ü�� �����͸� ã�Ҵ��� �ƴ��� Ȯ��.
	*	@param	ibottom	�˻� ���� �迭 ��ġ.
	*/
	virtual void ReplaceNode(T& item, bool& found, int iparent);

	/**
	*	@brief	Heap�� �����͸� �˻��ϴ� �����Լ�.
	*	@pre	Heap�� �ʱ�ȭ�Ǿ���Ѵ�.
	*	@post	Heap�� �����͸� �˻��Ѵ�.
	*	@param	item	ItemType���� �˻� �� ������.
	*	@param	found	�˻��� �����͸� ã�Ҵ��� �ƴ��� Ȯ��.
	*	@param	ibottom	�˻� ���� �迭 ��ġ.
	*/
	virtual void RetrieveNode(T& item, bool& found, int iparent);
};


// ������
template <typename T>
CMinHeap<T>::CMinHeap() {
	this->m_iLastNode = 0;
	this->m_nMaxSize = MAXHEAPSIZE;
	this->m_CurPointer = -1;
	this->m_pHeap = new T[this->m_nMaxSize];

}


// ������ - �迭�� �ִ� ����.
template <typename T>
CMinHeap<T>::CMinHeap(int size)
{
	this->m_iLastNode = 0;
	this->m_nMaxSize = size;
	this->m_CurPointer = -1;
	this->m_pHeap = new T[this->m_nMaxSize];
}


// ������ �Ʒ��� �������鼭 Heap ũ�⸦ ���Ͽ� �����ϴ� �����Լ�
template <typename T>
void CMinHeap<T>::ReheapDown(int iparent, int ibottom) {
	int minChild, leftChild, rightChild;
	leftChild = iparent * 2 + 1;
	rightChild = iparent * 2 + 2;

	if (leftChild <= ibottom) {
		if (leftChild == ibottom) minChild = leftChild;

		else {
			if (this->m_pHeap[leftChild] > this->m_pHeap[rightChild])
				minChild = rightChild;
			else
				minChild = leftChild;
		}

		if (this->m_pHeap[iparent] > this->m_pHeap[minChild]) {
			this->Swap(iparent, minChild);
			ReheapDown(minChild, ibottom);
		}
	}
}


// �Ʒ����� ���� �ö󰡸鼭 Heap ũ�⸦ ���Ͽ� �����ϴ� �����Լ�.
template <typename T>
void CMinHeap<T>::ReheapUp(int iroot, int ibottom) {
	int iparent;
	if (ibottom > iroot) {
		iparent = (ibottom - 1) / 2;

		if (this->m_pHeap[iparent] > this->m_pHeap[ibottom]) {
			this->Swap(iparent, ibottom);
			ReheapUp(iroot, iparent);
		}
	}

}


// Heap�� �����͸� �����ϴ� �����Լ�.
template <typename T>
void CMinHeap<T>::DeleteNode(T& item, bool& found, int iparent) {
	int leftChild, rightChild;
	leftChild = iparent * 2 + 1;
	rightChild = iparent * 2 + 2;

	if (this->m_pHeap[iparent] == item) {
		item = this->m_pHeap[iparent];
		this->m_pHeap[iparent] = this->m_pHeap[this->m_iLastNode - 1];

		ReheapDown(iparent, this->m_iLastNode - 2);
		found = true;
		return;
	}

	if (leftChild < this->m_iLastNode && !found)
		DeleteNode(item, found, leftChild);
	if (rightChild < this->m_iLastNode && !found)
		DeleteNode(item, found, rightChild);
}

// Heap�� �����͸� ��ü�ϴ� �����Լ�.
template <typename T>
void CMinHeap<T>::ReplaceNode(T& item, bool& found, int iparent) {
	int leftChild, rightChild;
	leftChild = iparent * 2 + 1;
	rightChild = iparent * 2 + 2;

	if (this->m_pHeap[iparent] == item) {
		this->m_pHeap[iparent] = item;
		found = true;
	}

	if (leftChild < this->m_iLastNode && !found)
		ReplaceNode(item, found, leftChild);
	if (rightChild < this->m_iLastNode && !found)
		ReplaceNode(item, found, rightChild);
}


// Heap�� �����͸� �˻��ϴ� �����Լ�.
template <typename T>
void CMinHeap<T>::RetrieveNode(T& item, bool& found, int iparent) {
	int leftChild;
	int rightChild;

	leftChild = iparent * 2 + 1;
	rightChild = iparent * 2 + 2;

	if (this->m_pHeap[iparent] == item) { // �˻��Ϸ��� ������ �߰�

		item = this->m_pHeap[iparent];
		found = true;
	}
	if (leftChild < this->m_iLastNode && !found)
		RetrieveNode(item, found, leftChild); // �������� �˻�
	if (rightChild < this->m_iLastNode && !found)
		RetrieveNode(item, found, rightChild); // �������� �˻�
}


#endif	// _MINHEAP_H