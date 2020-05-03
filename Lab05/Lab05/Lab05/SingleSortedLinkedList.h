#pragma once

#ifndef _SINGLESORTEDLINKEDLIST_H
#define _SINGLESORTEDLINKEDLIST_H

/**
*	Structure for NodeType to use in Linked structure.
*/
template <typename T>
struct NodeType
{
	T data;	///< A data for each node.
	NodeType* next;	///< A node pointer to point succeed node.
};

/**
*	Simple unsorted list class for managing items.
*/
template <typename T>
class SingleSortedLinkedList {
public:
	/**
	*	default constructor.
	*/
	SingleSortedLinkedList();

	/**
	*	destructor.
	*/
	~SingleSortedLinkedList();

	/**
	*	@brief	Initialize list to empty state.
	*	@pre	None
	*	@post	List is empty.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get number of elements in the list.
	*	@pre	None.
	*	@post	Function value = number of elements in list.
	*	@return	Number of elements in this list.
	*/
	int GetLength() const;

	/**
	*	@brief	Add item into appropriate spot of this list.
	*	@pre	List is not full. item is not in list.
	*	@post	Item is inserted in this list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int Add(T& item);

	/**
	*	@brief	Delete item from this list.
	*	@pre	List is not empty. the item exists in list.
	*	@post	Item is deleted from this list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int Delete(T& item);

	/**
	*	@brief	Change value of item which is in this list.
	*	@pre	List is not empty. the item exists in list.
	*	@post	Item's value is changed.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int Replace(T& item);

	/**
	*	@brief	Retrieve list element whose key matches item's key (if present).
	*	@pre	Key member of item is initialized.
	*	@post	If there is an element whose key matches with item's key then the element's record is copied to the item.
	*	@return	1 if any element's primary key matches with item's, otherwise 0.
	*/
	int Get(T& item);

	/**
	*	@brief	Initialize current pointer for an iteration through the list.
	*	@pre	None.
	*	@post	current pointer is prior to list. current pointer has been initialized.
	*/
	void ResetList();

	/**
	*	@brief	Get the next element in list.
	*	@pre	current pointer is defined. Element at current pointer is not last in list.
	*	@post	current pointer is updated to next position. item is a copy of element at current pointer.
	*/
	void GetNextItem(T& item);

	/**
	*	@brief	Display All the data.
	*	@pre	The list has to be initialized.
	*	@post	Print data.
	*/
	void Print();

	void operator=(SingleSortedLinkedList& data) {
		// ���� ��� �ʱ�ȭ
		MakeEmpty();

		// obj ����Ʈ�� ������ ���
		if (data.GetLength()){
			// obj curPtr �ʱ�ȭ
			data.ResetList();

			T item;
			//��� ����
			int len = data.GetLength();
			while (len--) {
				data.GetNextItem(item);
				Add(item);
			}
				
		}
	}

	friend ostream& operator<<(ostream& os, SingleSortedLinkedList& data) {
		T item;
		data.ResetList();
		
		int len = data.GetLength();
		while (len--) { //��� ������ŭ �ݺ�
			data.GetNextItem(item);
			os << item << endl; // ������ ���
		}
		return os;
	}

private:
	NodeType<T>* m_pList;	///< Pointer for pointing a first node.
	NodeType<T>* m_pCurPointer;	///< Node pointer for pointing current node to use iteration.
	int m_nLength;	///< Number of node in the list.
};


// Class constructor
template <typename T>
SingleSortedLinkedList<T>::SingleSortedLinkedList() {
	m_nLength = 0;
	m_pList = nullptr;
	m_pCurPointer = nullptr;
}


// Class destructor
template <typename T>
SingleSortedLinkedList<T>::~SingleSortedLinkedList() {
	//����Ʈ���� ��� node ����
	MakeEmpty();
}


// Initialize list to empty state.
template <typename T>
void SingleSortedLinkedList<T>::MakeEmpty() {
	// ����Ʈ���� ��� ��� ���� �ϰ� ����Ʈ�� length�� �ʱ�ȭ
	NodeType<T>* tempPtr;
	while (m_pList != nullptr){
		tempPtr = m_pList;
		m_pList = m_pList->next;
		delete tempPtr;
	}

	m_nLength = 0;
}


// Get number of elements in the list.
template <typename T>
int SingleSortedLinkedList<T>::GetLength() const {
	return m_nLength;
}


// Add item into this list.
template <typename T>
int SingleSortedLinkedList<T>::Add(T& item) {
	// ����Ʈ �ʱ�ȭ
	ResetList();

	// ����Ʈ�� �߰��� ���ο� node ��ü�� ���� ��带 ����ų ������ ����
	NodeType<T>* node = new NodeType<T>;
	NodeType<T>* pre;
	T dummy;
	bool bFound = false;

	// node ��ü�� �Է¹��� ������ ���� �� �ʱ�ȭ
	node->data = item;
	node->next = nullptr;

	// list �� node �� �������� �ʴ� ���
	if (!m_nLength){
		m_pList = node;
	}
	// list �� node �� �ϳ� �̻� �����ϴ� ���
	else {
		// ���� ������ node �� �̵� �� ����
		while (1){
			// ���� ��带 ����Ű�� ������ ����
			pre = m_pCurPointer;
			// iteration �� �̿��� node ������ ����.
			GetNextItem(dummy);

			if (m_pCurPointer->data > node->data) {
				if (pre == nullptr) {
					node->next = m_pCurPointer;
					m_pList = node;
					break;
				}	//���� �ڸ� �� ���Ұ� �������� ���� �� ù��° ���ҷ� ����.
				node->next = m_pCurPointer;
				pre->next = node;
				break;
			}	//���� ����Ű�� ������ data���� node�� data������ Ŭ ��� pre ���ڸ��� ����.

			// node �����Ͱ� ������ node �� ����Ű�� �� �ڿ� ���ο� node ����.
			if (m_pCurPointer->next == nullptr){
				// ������ node �� ���ο� node ����
				m_pCurPointer->next = node;
				break;
			}
		}
	}

	m_nLength++;

	return 1;
}

//Delete item from this list.
template <typename T>
int SingleSortedLinkedList<T>::Delete(T& item) {
	bool moreToSearch, found;
	NodeType<T>* pre = nullptr;	//���� ����

	m_pCurPointer = m_pList;
	found = false;
	moreToSearch = (m_pCurPointer != nullptr);	//���� �ʱ�ȭ

	while (moreToSearch && !found)	{ //����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
		if (item == m_pCurPointer->data){ //���� ����Ű�� ������ ���� item�� ���� ��ġ�� ��
			found = true;	//ã�����Ƿ� found �� ����
			if (pre == nullptr)
				m_pList = m_pCurPointer->next;	//�׸� ������ �ٸ� ���Ұ� ���� �� �׸��� ���� ���Ҹ� ù��° ���ҷ� �Ѵ�.
			else {
				pre->next = m_pCurPointer->next;
				delete m_pCurPointer;
			}	//������ ������ ���� ���Ҹ� '����Ű�� �׸��� ���� ����'�� �ٲ۴�.
			m_nLength--;	//����Ʈ�� ���̸� 1 �ٿ��ش�.
		}
		else{
			pre = m_pCurPointer;
			m_pCurPointer = m_pCurPointer->next;
			moreToSearch = (m_pCurPointer != nullptr);
		}	//��ġ���� ���� �� ���� ���Ҹ� ����Ų��. ��, pre�� ������ ���Ҹ� ����Ų��.
	}

	if (found)
		return 1;
	else
		return 0;	//������ �����ϸ� 1, �ƴϸ� 0�� �����Ѵ�.
}

//Change value of item which is in this list.
template <typename T>
int SingleSortedLinkedList<T>::Replace(T& item){
	bool moreToSearch, found;
	NodeType<T>* location;	//���� ����

	location = m_pList;
	found = false;
	moreToSearch = (location != nullptr);	//���� �ʱ�ȭ

	while (moreToSearch && !found){ //����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
		if (item == location->data){
			found = true;
			location->data = item;
		}	//��ġ�ϴ� �׸��� ã���� �� found�� ���� �������ְ� ����Ʈ�� �׸� item�� �������ش�.
		else{
			location = location->next;
			moreToSearch = (location != nullptr);
		}	//ã�� ������ �� ���� �׸����� location�� �ű�� �� ���� nullptr�̸� ����Ʈ�� ���̹Ƿ� moreToSearch�� ���� �������ش�.
	}

	if (found)
		return 1;
	else
		return 0;	//������ �����ϸ� 1, �׷��� ���ϸ� 0�� �����Ѵ�.
}

// Retrieve list element whose key matches item's key (if present).
template <typename T>
int SingleSortedLinkedList<T>::Get(T& item){
	bool moreToSearch, found;
	NodeType<T>* location;	//���� ����

	location = m_pList;
	found = false;
	moreToSearch = (location != nullptr);	//���� �ʱ�ȭ

	while (moreToSearch && !found){ //����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
		if (item == location->data){
			found = true;
			item = location->data;
		}	//��ġ�ϴ� �׸��� ã���� �� found�� ���� �������ְ� item�� �ش� �׸��� �������ش�.
		else{
			location = location->next;
			moreToSearch = (location != nullptr);
		}	//ã�� ������ �� ���� �׸����� location�� �ű�� �� ���� nullptr�̸� ����Ʈ�� ���̹Ƿ� moreToSearch�� ���� �������ش�.
	}

	if (found)
		return 1;
	else
		return 0;	//ã���� 1, �׷��� ���ϸ� 0�� �����Ѵ�.
}


// Initializes current pointer for an iteration through the list.
template <typename T>
void SingleSortedLinkedList<T>::ResetList(){
	// current pointer �ʱ�ȭ
	m_pCurPointer = nullptr;
}


// Gets the next element in list.
template <typename T>
void SingleSortedLinkedList<T>::GetNextItem(T& item) {
	// current pointer �� NULL�̶�� ó�� node�� ����Ŵ.
	if (m_pCurPointer == nullptr) {
		m_pCurPointer = m_pList;
	}
	else
		//current position �� ���� ���� �̵�
		m_pCurPointer = m_pCurPointer->next;

	//item �� current position �� info �� ����
	item = m_pCurPointer->data;
}

template <typename T>
void SingleSortedLinkedList<T>::Print() {
	T tmpWalker;
	ResetList();
	int len = m_nLength;
	while (len--) {
		GetNextItem(tmpWalker);
		cout << tmpWalker << endl;
	}
}

#endif	// _SORTEDSINGLELINKEDLIST_H