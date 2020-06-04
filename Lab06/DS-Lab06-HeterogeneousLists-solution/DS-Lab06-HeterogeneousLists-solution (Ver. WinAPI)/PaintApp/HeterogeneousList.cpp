#include "stdafx.h"
#include "HeterogeneousList.h"


HeterogeneousList::HeterogeneousList()
{
	first = new RectangleNode();
	first->rlink = first->llink = first;//�ڽ��� ����Ű�� doubly linked�� ����
	num = 0;
}


HeterogeneousList::~HeterogeneousList()
{
}

void HeterogeneousList::UpdateLast()
{
	first->llink->update(); // �������� �˻�(���� ���̱� ������)
}

void HeterogeneousList::DisplayAll(HDC hdc)
{
	HtgListIterator iter(*this);
	while (iter.NotHeader())
	{
		iter.current->display(hdc); // ���� ��带 ���. Virtual �Լ� 
		iter.Next();  // �����͸� ������ �̵� 
	}
}

void HeterogeneousList::DeleteAllNode()
{
	BaseNode *tmp, *p;
	for (p = first->rlink; p != first; ) {
		tmp = p;
		p = p->rlink;
		delete tmp;
	}
	first->llink = first->rlink = first; // empty list�� ���� 
	num = 0;
}

void HeterogeneousList::Attach(BaseNode * newNode)
{
	BaseNode *lastNode = first->llink;  // lastNode
	newNode->llink = lastNode;
	newNode->rlink = first;
	lastNode->rlink = newNode;
	first->llink = newNode;
	num++;
}
