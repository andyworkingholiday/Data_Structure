#ifndef _MINHEAP_H
#define _MINHEAP_H

#include "CHeapBase.h"


/**
*	CMinHeap 클래스.
*/
template <typename T>
class CMinHeap : public CHeapBase<T> {
public:
	/**
	*	생성자.
	*/
	CMinHeap();

	/**
	*	생성자 - 배열의 최대 길이.
	*/
	CMinHeap(int size);

	/**
	*	@brief	위에서 아래로 내려오면서 Heap 크기를 비교하여 정렬하는 가상함수.
	*	@pre	Heap가 초기화되어야한다.
	*	@post	Heap의 데이터를 비교하여 정렬한다.
	*	@param	iparent	내려가는 데이터.
	*	@param	ibottom	마지막 데이터.
	*/
	virtual void ReheapDown(int iparent, int ibottom);

	/**
	*	@brief	아래에서 위로 올라가면서 Heap 크기를 비교하여 정렬하는 가상함수.
	*	@pre	Heap가 초기화되어야한다.
	*	@post	Heap의 데이터를 비교하여 정렬한다.
	*	@param	iroot	첫번째 데이터.
	*	@param	ibottom	올라가는 데이터.
	*/
	virtual void ReheapUp(int iroot, int ibottom);

	/**
	*	@brief	Heap의 데이터를 삭제하는 가상함수.
	*	@pre	Heap가 초기화되어야한다.
	*	@post	Heap의 데이터를 삭제한다.
	*	@param	item	ItemType형의 삭제 할 데이터.
	*	@param	found	삭제할 데이터를 찾았는지 아닌지 확인.
	*	@param	ibottom	검색 중인 배열 위치.
	*/
	virtual void DeleteNode(T& item, bool& found, int iparent);

	/**
	*	@brief	Heap의 데이터를 대체하는 순수가상함수.
	*	@pre	Heap가 초기화되어야한다.
	*	@post	Heap의 데이터를 대체한다.
	*	@param	item	ItemType형의 대체 할 데이터.
	*	@param	found	대체할 데이터를 찾았는지 아닌지 확인.
	*	@param	ibottom	검색 중인 배열 위치.
	*/
	virtual void ReplaceNode(T& item, bool& found, int iparent);

	/**
	*	@brief	Heap의 데이터를 검색하는 가상함수.
	*	@pre	Heap가 초기화되어야한다.
	*	@post	Heap의 데이터를 검색한다.
	*	@param	item	ItemType형의 검색 할 데이터.
	*	@param	found	검색할 데이터를 찾았는지 아닌지 확인.
	*	@param	ibottom	검색 중인 배열 위치.
	*/
	virtual void RetrieveNode(T& item, bool& found, int iparent);
};


// 생성자
template <typename T>
CMinHeap<T>::CMinHeap() {
	this->m_iLastNode = 0;
	this->m_nMaxSize = MAXHEAPSIZE;
	this->m_CurPointer = -1;
	this->m_pHeap = new T[this->m_nMaxSize];

}


// 생성자 - 배열의 최대 길이.
template <typename T>
CMinHeap<T>::CMinHeap(int size)
{
	this->m_iLastNode = 0;
	this->m_nMaxSize = size;
	this->m_CurPointer = -1;
	this->m_pHeap = new T[this->m_nMaxSize];
}


// 위에서 아래로 내려오면서 Heap 크기를 비교하여 정렬하는 가상함수
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


// 아래에서 위로 올라가면서 Heap 크기를 비교하여 정렬하는 가상함수.
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


// Heap의 데이터를 삭제하는 가상함수.
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

// Heap의 데이터를 대체하는 가상함수.
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


// Heap의 데이터를 검색하는 가상함수.
template <typename T>
void CMinHeap<T>::RetrieveNode(T& item, bool& found, int iparent) {
	int leftChild;
	int rightChild;

	leftChild = iparent * 2 + 1;
	rightChild = iparent * 2 + 2;

	if (this->m_pHeap[iparent] == item) { // 검색하려는 데이터 발견

		item = this->m_pHeap[iparent];
		found = true;
	}
	if (leftChild < this->m_iLastNode && !found)
		RetrieveNode(item, found, leftChild); // 왼쪽으로 검색
	if (rightChild < this->m_iLastNode && !found)
		RetrieveNode(item, found, rightChild); // 왼쪽으로 검색
}


#endif	// _MINHEAP_H