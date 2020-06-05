#ifndef _SORTEDLIST_H
#define _SORTEDLIST_H

/**
*	array based simple sorted list.
*/
template<typename T>
class SortedList {
public:

	/**
	*	default constructor.
	*/
	SortedList();

	/**
*	@brief	Allocate dynamic array whose size is max.
*	@pre	none.
*	@post	Member of items points the allocated array.
*/
	SortedList(int max);

	/**
	*	destructor.
	*/
	~SortedList();

	/**
	*	@brief	resize the list
	*	@pre	none.
	*	@post	list resized
	*/
	void resize(int max);

	/**
	*	@brief	Make list empty.
	*	@pre	none.
	*	@post	clear list.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get a number of records in current list.
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in current list.
	*/
	int GetLength();

	/**
	*	@brief	Check capacity of list is full.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list capacity reached to the upper bound, otherwise return false.
	*/
	bool IsFull();

	/**
	*	@brief	Check capacity of list is empty.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list capacity reached to the lower bound, otherwise return false.
	*/
	bool IsEmpty();

	/**
	*	@brief	Print all the items in the List on screen
	*	@pre	List has been initialized.
	*	@post	None.
	*/
	void Print();

	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetList();

	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextItem(T& data);

	/**
	*	@brief	add a new data into list.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Add(T& data);

	/**
	*	@brief	id�� ��ġ�ϴ� item�� ã�Ƽ� �ش� item�� �����Ѵ�.
	*	@pre	�μ� data�� �ִ� id�� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	list ���� �ش� item�� ���ŵȴ�.
	*	@param	data	�����ϰ��� �ϴ� id�� �Էµ� ItemType��.
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
	int Delete(T& data);

	/**
	*	@brief	����Ž���� ���� id�� ��ġ�ϴ� list�� item�� ã�Ƽ� ��ȯ�Ѵ�.
	*	@pre	����.
	*	@post	�迭 ���� �Ѱܹ��� item�� id�� ��ġ�ϴ� ���� ã�Ƽ� data�� ��ȯ�ȴ�.
	*	@param	data	ã���� �ϴ� id�� �Էµ� ItemType��.
	*	@return	����(�߰�)�� 1, ���н� 0�� �����Ѵ�.
	*/
	int Replace(T& data);

	/**
	*	@brief	item�� ã�Ƽ� �ش� item�� ��ȯ�Ѵ�.
	*	@pre	�μ� data�� �ִ� id�� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	list ������ ã�� item�� data�� �Էµȴ�.
	*	@param	data	ã���� �ϴ� id�� �Էµ� ItemType��. �߰��� item�� ���ϵȴ�.
	*	@return	����(�߰�)�� 1, ���н� 0�� �����Ѵ�.
	*/
	int Retrieve_SeqS(T& data);

	/**
	*	@brief	����Ž���� ���� id�� ��ġ�ϴ� list�� item�� ã�Ƽ� ��ȯ�Ѵ�.
	*	@pre	����.
	*	@post	�迭 ���� �Ѱܹ��� item�� id�� ��ġ�ϴ� ���� ã�Ƽ� data�� ��ȯ�ȴ�.
	*	@param	data	ã���� �ϴ� id�� �Էµ� ItemType��.
	*	@return	����(�߰�)�� index ��, ���н� -1�� �����Ѵ�.
	*/
	int RetrieveByBS(T& data);

	/**
	*	@brief	����Ž���� ���� id�� ��ġ�ϴ� list�� item�� ã�Ƽ� ��ȯ�Ѵ�.
	*	@pre	����.
	*	@post	�迭 ���� �Ѱܹ��� item�� id�� ��ġ�ϴ� ���� ã�Ƽ� data�� ��ȯ�ȴ�.
	*	@param	data	ã���� �ϴ� id�� �Էµ� ItemType��.
	*	@return	����(�߰�)�� index ��, ���н� -1�� �����Ѵ�.
	*/
	int RetrieveByBS_noCopy(T& data);

private:
	T* m_Array; // list array.
	int m_Length; // number of elements in list.
	int m_CurPointer; // iterator pointer.
	int m_Maxsize; // Max size.
};

template<typename T>
SortedList<T>::SortedList() {
	m_Maxsize = MAXSIZE;
	m_Length = 0;
	ResetList(); //��� �������� �ʱ�ȭ�����ش�.
	m_Array = new T[m_Maxsize]; //m_Array�� ũ�Ⱑ MAXSIZE�� �迭�� �����.
}

template<typename T>
SortedList<T>::SortedList(int max) {
	m_Maxsize = max; // parameter�� ���� max ������ maxsize�� �����Ѵ�.
	m_Length = 0;
	ResetList(); //��� �������� �ʱ�ȭ�����ش�.
	m_Array = new T[m_Maxsize];  //m_Array�� ũ�Ⱑ max�� �迭�� �����.
}

template<typename T>
SortedList<T>::~SortedList() {
	delete[] m_Array; //�����Ҵ��ߴ� �޸𸮸� �������ش�.
}

// ũ�⸦ �缳���Ѵ�.
template<typename T>
void SortedList<T>::resize(int max) {
	delete[] m_Array;
	m_Maxsize = max; // parameter�� ���� max ������ maxsize�� �����Ѵ�.
	m_Length = 0;
	ResetList(); //��� �������� �ʱ�ȭ�����ش�.
	m_Array = new T[m_Maxsize];  //m_Array�� ũ�Ⱑ max�� �迭�� �����.
}

// Make list empty.
template<typename T>
void SortedList<T>::MakeEmpty() {
	m_Length = 0;
}

// Get a number of records in current list.
template<typename T>
int SortedList<T>::GetLength() {
	return m_Length;
}

// Check capacity of list is full.
template<typename T>
bool SortedList<T>::IsFull() {
	if (m_Length == m_Maxsize)
		return true;
	return false;
}

// Check capacity of list is Empty
template<typename T>
bool SortedList<T>::IsEmpty() {
	if (!m_Length)
		return true;
	return false;
}

// Add data to list
template<typename T>
int SortedList<T>::Add(T& data) {
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
		T CurItem;
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

//Print All the data
template<typename T>
void SortedList<T>::Print() {
	T item;
	ResetList();
	int len = m_Length;
	// Stack ���� ��� element ���.
	while (len--) {
		if (GetNextItem(item) >= 0)
			cout << item << endl;
		else break;
	}
}

// Initialize list iterator.
template<typename T>
void SortedList<T>::ResetList() {
	m_CurPointer = -1;
}

// move list iterator to the next item in list and get that item.
template<typename T>
int SortedList<T>::GetNextItem(T& data) {
	m_CurPointer++;
	if (m_CurPointer == m_Maxsize) return -1;
	data = m_Array[m_CurPointer];
	return m_CurPointer;
}

// sorted list�� �ε��� 0���� ���������� Ž���մϴ�.
template<typename T>
int SortedList<T>::Retrieve_SeqS(T& data) {
	T CurItem;
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

// Delete data using binary search
template<typename T>
int SortedList<T>::Delete(T& data) {
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

// Replace data using binary search
template<typename T>
int SortedList<T>::Replace(T& data) {
	int index = RetrieveByBS_noCopy(data); //����Ž���� ����Ͽ� �ش� index �޾ƿ�
	if (index != -1) { // ������ primary number �߰� �� param data�� �ش� index�� ī���Ѵ�.
		m_Array[index] = data;
		return 1;
	}
	else return 0; // ������ primary number ���� �� �� index�� -1 �Ͻ� return 0
}

// Binary search
template<typename T>
int SortedList<T>::RetrieveByBS(T& data) {
	int start = 0, end = m_Length - 1, mid; //start= 0, end = ����Ʈ�� ��, mid= �� �߰�
	while (end - start >= 0) {
		mid = (start + end) / 2;
		if (m_Array[mid] == data) { // ������ primary number �߰� �� �ش� index�� return
			data = m_Array[mid];
			return mid;
		}
		else if (m_Array[mid] > data) end = mid - 1; // param data�� mid�� data���� �۴ٴ� ���� 0�� mid ���̿� data�� ���� �� �ִٴ� ��
		else start = mid + 1; // param data�� mid�� data���� ũ�ٴ� ���� mid�� end ���̿� data�� ���� �� �ִٴ� ��
	}
	return -1; // �߰� ���� �� -1 return
}

// Binary search
template<typename T>
int SortedList<T>::RetrieveByBS_noCopy(T& data) {
	int start = 0, end = m_Length - 1, mid; //start= 0, end = ����Ʈ�� ��, mid= �� �߰�
	while (end - start >= 0) {
		mid = (start + end) / 2;
		if (m_Array[mid] == data) { // ������ primary number �߰� �� �ش� index�� return
			return mid;
		}
		else if (m_Array[mid] > data) end = mid - 1; // param data�� mid�� data���� �۴ٴ� ���� 0�� mid ���̿� data�� ���� �� �ִٴ� ��
		else start = mid + 1; // param data�� mid�� data���� ũ�ٴ� ���� mid�� end ���̿� data�� ���� �� �ִٴ� ��
	}
	return -1; // �߰� ���� �� -1 return
}


#endif	// _SORTEDLIST_H