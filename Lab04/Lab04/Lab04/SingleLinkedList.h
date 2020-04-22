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
		// 기존 노드 초기화
		MakeEmpty();

		// obj 리스트가 존재할 경우
		if (data.GetLength()){
			// obj curPtr 초기화
			data.ResetList();

			T item;
			//노드 복사
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
	//리스트내의 모든 node 제거
	MakeEmpty();
}

// Initialize list to empty state.
template <typename T>
void SingleLinkedList<T>::MakeEmpty(){
	// 리스트내의 모든 노드 제거 하고 리스트의 length를 초기화
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
	// 리스트 초기화
	ResetList();

	// 리스트에 추가할 새로운 node 객체와 이전 노드를 가리킬 포인터 선언
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;

	// node 객체에 입력받은 데이터 설정 및 초기화
	node->data = item;
	node->next = nullptr;

	// list 에 node 가 존재하지 않는 경우
	if (!m_Length)	
		m_pList = node;
	
	// list 에 node 가 하나 이상 존재하는 경우
	else {
		// 가장 마지막 node 로 이동 후 삽입
		while (1){
			// 이전 노드를 가리키는 포인터 갱신
			pre = m_pCurPointer;

			// iteration 을 이용해 node 포인터 갱신.
			GetNextItem(dummy);

			// node 포인터가 마지막 node 를 가리키면 그 뒤에 새로운 node 삽입.
			if (m_pCurPointer->next == nullptr) {
				// 마지막 node 와 새로운 node 연결
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
	NodeType<T>* location;	//변수 선언

	location = m_pList;
	found = false;
	moreToSearch = (location != nullptr);	//변수 초기화

	while (moreToSearch && !found) {	//리스트의 끝이 아니면서 아직 찾지 않았으면 반복한다.
		if (item == location->data) {
			found = true;
			location->data = item;
		}	//일치하는 항목을 찾았을 때 found의 값을 변경해주고 리스트의 항목에 item을 복사해준다.
		else {
			location = location->next;
			moreToSearch = (location != nullptr);
		}	//찾지 못했을 때 다음 항목으로 location을 옮기고 그 값이 nullptr이면 리스트의 끝이므로 moreToSearch의 값을 변경해준다.
	}

	if (found)
		return 1;
	else
		return 0;	//수정에 성공하면 1, 그렇지 못하면 0을 리턴한다.
}

// Retrieve list element whose key matches item's key (if present).
template <typename T>
int SingleLinkedList<T>::Get(T& item){
	bool moreToSearch, found;
	NodeType<T>* location;	//변수 선언

	location = m_pList;
	found = false;
	moreToSearch = (location != nullptr);	//변수 초기화

	while (moreToSearch && !found) {	//리스트의 끝이 아니면서 아직 찾지 않았으면 반복한다.
		if (item == location->data){
			found = true;
			item = location->data;
		}	//일치하는 항목을 찾았을 때 found의 값을 변경해주고 item에 해당 항목을 복사해준다.
		else {
			location = location->next;
			moreToSearch = (location != nullptr);
		}	//찾지 못했을 때 다음 항목으로 location을 옮기고 그 값이 nullptr이면 리스트의 끝이므로 moreToSearch의 값을 변경해준다.
	}

	if (found)
		return 1;
	else
		return 0;	//찾으면 1, 그렇지 못하면 0을 리턴한다.
}

// Initializes current pointer for an iteration through the list.
template <typename T>
void SingleLinkedList<T>::ResetList(){
	// current pointer 초기화
	m_pCurPointer = nullptr;
}


// Gets the next element in list.
template <typename T>
void SingleLinkedList<T>::GetNextItem(T& item){
	// current pointer 이 NULL이라면 처음 node를 가리킴.
	if (m_pCurPointer == nullptr){
		m_pCurPointer = m_pList;
	}
	else
		//current position 을 다음 노드로 이동
		m_pCurPointer = m_pCurPointer->next;

	//item 에 current position 의 info 를 삽입
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