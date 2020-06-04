#pragma once
/**
*	@brief	������ �θ� Class
*	@author	������
*/
class BaseNode
{
	friend class HeterogeneousList;
	friend class HtgListIterator;

protected:
	BaseNode*	rlink;			//������(��) ��带 ����Ű�� ������
	BaseNode*	llink;			//����(��) ��带 ����Ű�� ������
	bool		isComplete;		//������ �׸��Ⱑ ����Ǿ����� �Ǵ�

	COLORREF	color;			//��
	int			penSize;		//�������
	bool		isEmpty;		//ä���� �׸������� �Ǵ�

public:
	BaseNode();
	~BaseNode();

	virtual void update() = 0;
	virtual void display(HDC hdc) = 0;
};

