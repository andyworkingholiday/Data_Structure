#pragma once
/**
*	@brief	���� ����Ʈ�� Iterator Class
*	@author	������
*/
class HtgListIterator
{
	friend class HeterogeneousList;
private:
	const HeterogeneousList &list;
	BaseNode *current;
public:
	HtgListIterator(const HeterogeneousList& copy) :list(copy), current(copy.first->rlink) {}
	~HtgListIterator();

	bool NotHeader();	// list�� ���� ���Ұ� ������ ���������� �˻� 
	BaseNode* Next();	// current node�� data�� ��ȯ�ϰ� current ���� ������ �̵�  
};

