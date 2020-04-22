#ifndef _SINGLELINKEDLIST_H
#define _SINGLELINKEDLIST_H

#include <iostream>
#define MAXLINKED
using namespace std;


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
*	array based simple unsorted list.
*/

template<typename T>
class SingleLinkedList {
public:
	/**
	*	default constructor.
	*/
	SingleLinkedList();

	/**
	*	destructor.
	*/
	~SingleLinkedList();

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
	int Get(T &item);

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
	void GetNextItem(T &item);

	/**
	*	@brief	Display All the data.
	*	@pre	The list has to be initialized.
	*	@post	Print data.
	*/
	void Print();

	void operator=(const SingleLinkedList& data) {
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


private:
	NodeType<T>* m_pList;
	int m_Length;
	NodeType<T>* m_pCurPointer;
};

// Class constructor
template <typename T>
SingleLinkedList<T>::SingleLinkedList(){
	m_Length = 0;
	m_pList = nullptr;
	m_pCurPointer = nullptr;
}

// Class destructor
template <typename T>
SingleLinkedList<T>::~SingleLinkedList(){
	//����Ʈ���� ��� node ����
	MakeEmpty();
}

// Initialize list to empty state.
template <typename T>
void SingleLinkedList<T>::MakeEmpty(){
	// ����Ʈ���� ��� ��� ���� �ϰ� ����Ʈ�� length�� �ʱ�ȭ
	NodeType<T>* tempPtr;

	while (m_pList != nullptr){
		tempPtr = m_pList;
		m_pList = m_pList->next;
		delete tempPtr;
	}

	m_Length = 0;
}

// Get number of elements in the list.
template <typename T>
int SingleLinkedList<T>::GetLength() const{
	return m_Length;
}

// Add item into this list.
template <typename T>
int SingleLinkedList<T>::Add(T& item) {
	// ����Ʈ �ʱ�ȭ
	ResetList();

	// ����Ʈ�� �߰��� ���ο� node ��ü�� ���� ��带 ����ų ������ ����
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;

	// node ��ü�� �Է¹��� ������ ���� �� �ʱ�ȭ
	node->data = item;
	node->next = nullptr;

	// list �� node �� �������� �ʴ� ���
	if (!m_Length)	
		m_pList = node;
	
	// list �� node �� �ϳ� �̻� �����ϴ� ���
	else {
		// ���� ������ node �� �̵� �� ����
		while (1){
			// ���� ��带 ����Ű�� ������ ����
			pre = m_pCurPointer;

			// iteration �� �̿��� node ������ ����.
			GetNextItem(dummy);

			// node �����Ͱ� ������ node �� ����Ű�� �� �ڿ� ���ο� node ����.
			if (m_pCurPointer->next == nullptr) {
				// ������ node �� ���ο� node ����
				m_pCurPointer->next = node;
				break;
			}
		}
	}

	m_Length++;
	return 1;
}

// Delete an item into the list
template <typename T>
int SingleLinkedList<T>::Delete(T& item){
	bool moreToSearch, found;
	NodeType<T> *location, *predLoc;

	location = predLoc = m_pList;
	found = false;
	moreToSearch = (location != nullptr);

	if (m_pList->data == item){
		m_pList = location->next;
		delete location;

		found = true;
		m_Length--;
	}
	else{
		while (moreToSearch){
			if (item == location->data){
				predLoc->next = location->next;
				delete location;

				moreToSearch = (location != NULL);
				found = true;
				m_Length--;
				break;
			}
			predLoc = location;
			location = location->next;
			moreToSearch = (location != NULL);
		}
	}

	if (found)
		return 1;
	else
		return 0;
}


//Change value of item which is in this list.
template <typename T>
int SingleLinkedList<T>::Replace(T& item){
	bool moreToSearch, found;
	NodeType<T>* location;	//���� ����

	location = m_pList;
	found = false;
	moreToSearch = (location != nullptr);	//���� �ʱ�ȭ

	while (moreToSearch && !found) {	//����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
		if (item == location->data) {
			found = true;
			location->data = item;
		}	//��ġ�ϴ� �׸��� ã���� �� found�� ���� �������ְ� ����Ʈ�� �׸� item�� �������ش�.
		else {
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
int SingleLinkedList<T>::Get(T& item){
	bool moreToSearch, found;
	NodeType<T>* location;	//���� ����

	location = m_pList;
	found = false;
	moreToSearch = (location != nullptr);	//���� �ʱ�ȭ

	while (moreToSearch && !found) {	//����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
		if (item == location->data){
			found = true;
			item = location->data;
		}	//��ġ�ϴ� �׸��� ã���� �� found�� ���� �������ְ� item�� �ش� �׸��� �������ش�.
		else {
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
void SingleLinkedList<T>::ResetList(){
	// current pointer �ʱ�ȭ
	m_pCurPointer = nullptr;
}


// Gets the next element in list.
template <typename T>
void SingleLinkedList<T>::GetNextItem(T& item){
	// current pointer �� NULL�̶�� ó�� node�� ����Ŵ.
	if (m_pCurPointer == nullptr){
		m_pCurPointer = m_pList;
	}
	else
		//current position �� ���� ���� �̵�
		m_pCurPointer = m_pCurPointer->next;

	//item �� current position �� info �� ����
	item = m_pCurPointer->data;
}

template <typename T>
void SingleLinkedList<T>::Print() {	
	T tmpWalker;
	ResetList();
	int len = m_Length;
	while (len--) {
		GetNextItem(tmpWalker);
		cout << tmpWalker << endl;
	}
}


#endif	// _SINGLELINKEDLIST_H