#pragma once
/**
*	@brief	�پ��� ������ ������ ���� ����Ʈ
*	@author	������
*/
class HeterogeneousList
{
	friend class HtgListIterator;
	friend class BaseNode;

private:
	BaseNode* first;  // linked List�� ���� 
	int num;

public:
	HeterogeneousList();
	~HeterogeneousList();

	void UpdateLast();

	void DisplayAll(HDC hdc);				// ��� primitive�� draw �Ѵ�. 
	void DeleteAllNode();					// Header�� ������ ����Ʈ�� ����� ��� ��� ���� 
	bool NotEmpty() { if (num == 0) return FALSE; else return TRUE; };

	void Attach(BaseNode* newNode);			// ��带 ������ ��, �ǵڿ� �߰�
};