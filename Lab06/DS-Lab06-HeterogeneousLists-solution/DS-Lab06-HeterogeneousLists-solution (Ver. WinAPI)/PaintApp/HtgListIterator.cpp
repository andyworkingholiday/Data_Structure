#include "stdafx.h"
#include "HtgListIterator.h"

HtgListIterator::~HtgListIterator()
{
}

bool HtgListIterator::NotHeader()
{
	if (current != list.first)  //header�� �ƴ��� Ȯ�� 
		return true;
	else
		return false;
}

BaseNode * HtgListIterator::Next()
{
	current = current->rlink;
	return current->llink;
}
