#include "DiffTypeDLinkInherit.h"


////////////////////////////////////////////////////////////////////////////////////
// BaseNode�� member function  
///////////////////////////////////////////////////////////////////////////////////
//<<����>>
BaseNode::BaseNode()
{
	rlink = 0;
	llink = 0;
}


////////////////////////////////////////////////////////////////////////////////////
// List member function
////////////////////////////////////////////////////////////////////////////////////
List::List()
{   
	first = new RectangleNode();
	first->rlink = first->llink = first;	//�ڽ��� ����Ű�� doubly linked�� ����
}


// List�� ����� ��� ����� �޸𸮸� ������Ų��. 
List::~List()
{
	DeleteAllNode();
	delete first;
}


// List�� ����� ��� ����� �޸𸮸� ������Ų��. 
void List::DeleteAllNode()
{   
	BaseNode *tmp, *p;
	for(p = first->rlink; p != first; )
	{	
		tmp = p;
		p = p->rlink;
		delete tmp;
	}
	first->llink = first->rlink = first;	// empty list�� ���� 
}



// list �ڿ� newNode�� �߰� 
void List::Attach(BaseNode *newNode)
{
	BaseNode *lastNode = first->llink;  // lastNode

	newNode->llink = lastNode;
	newNode->rlink = first;
	lastNode->rlink = newNode;
	first->llink = newNode;
}

//?? ����, assignment
// ��� primitive�� draw �Ѵ�.
void List::drawAll() 
{
	// this�����͸� �Ѱܼ� iterator ��ü�� �ϳ� �����Ѵ�.
	// iterator�� �̿��Ͽ� �ۼ��϶�.
	ListIterator iterator(*this);

	while (iterator.NotHeader())
	{
		iterator.current->display();
		iterator.Next();
	}
	
}


///////////////////////////////////////////////////////////////////////////////////////
//=================ListIterator Member Function ========================
///////////////////////////////////////////////////////////////////////////////////////
// list�� ���� ���Ұ� Header�� �ƴ��� �˻�

Boolean ListIterator::NotHeader()
{
	if(current != list.first)  //header�� �ƴ��� Ȯ�� 
		return TRUE;
	else
		return FALSE;
}


// current �ڷḦ �����ϰ� current �����͸� ���������� �̵�  
BaseNode* ListIterator:: Next()
{
	current = current->rlink;
	return current->llink;
}


//?? ���� : ���� �ʱ�ȭ �Ͻÿ�.
//?? assignment : define creator. intialize a variables
// �ϳ��� ���� attribute�� ����
// deife a circle and attribute
CircleNode::CircleNode(Point center,Point boundary,int attrib)
{
	this->center = center;
	this->boundary = boundary;
	this->curNum = attrib;
}

CircleNode::~CircleNode()
{
}

//?? ���� : �� ����� ������ ����Ͻÿ�.
//?? assignment : print out the circle information on the screen.
void CircleNode:: display()
{
	cout << "�� ����� ������ ����մϴ�." << endl;
	cout << "center��ǥ	: " << "(" << center.x << ", " << center.y << ")" << endl;
	cout << "boundary��ǥ	: " << "(" << boundary.x << ", " << boundary.y << ")" << endl;
	cout << "curNum		: " << this->curNum << endl;
}

//?? ���� : ����忡�� �ʿ��� �߽����� ������� �Է� �޾� �����Ͻÿ�.
//?? assignment : input the two point defining a circle from keyboard
void CircleNode:: draw()
{
	cout << "���� �߽����� x��ǥ���� y��ǥ���� �Է��ϼ��� : " << endl;
	cout << "x��ǥ�� : ";
	cin >> center.x;
	cout << "y��ǥ�� : ";
	cin >> center.y;
	cout << "���� ������� x��ǥ���� y��ǥ���� �Է��ϼ��� : " << endl;
	cout << "x��ǥ�� : ";
	cin >> boundary.x;
	cout << "y��ǥ�� : ";
	cin >> boundary.y;
	
}



//?? ����
//?? assignment : intialize a rectangle object
RectangleNode::RectangleNode(Point start, Point end,int attrib)  // rectangle�� ���� 
{
	this->start = start;
	this->end = end;
	this->curNum = attrib;
}

RectangleNode::~RectangleNode()
{
}

//?? ����
//?? assignment : display the two points defining the current rectangle
void RectangleNode:: display()
{
	cout << "���簢�� ����� ������ ����մϴ�." << endl;
	cout << "start��ǥ	: " << "(" << start.x << ", " << start.y << ")" << endl;
	cout << "end��ǥ	: " << "(" << end.x << ", " << end.y << ")" << endl;
	cout << "curNum		: " << this->curNum << endl;
}

//?? ����
//?? assignment : read in the two points definding a rectagnle
void RectangleNode:: draw()
{
	cout << "���簢���� �߽����� x��ǥ���� y��ǥ���� �Է��ϼ��� : " << endl;
	cout << "x��ǥ�� : ";
	cin >> start.x;
	cout << "y��ǥ�� : ";
	cin >> start.y;
	cout << "���� ������� x��ǥ���� y��ǥ���� �Է��ϼ��� : " << endl;
	cout << "x��ǥ�� : ";
	cin >> end.x;
	cout << "y��ǥ�� : ";
	cin >> end.y;
}


PolygonNode::PolygonNode(Point vert[], int NumOfP,int attrib)
{
	if (NumOfP < MAXPOINTS)	NumOfPoints = NumOfP;
	else	NumOfPoints = MAXPOINTS - 1;

	attribute = attrib;
	for (int i = 0; i < NumOfPoints; i++)
		vertex[i] = vert[i];
}

void PolygonNode:: display()
{
	cout<<"<< Polygon >>\n";
	for (int i = 0; i < NumOfPoints; i++)
		cout << " Vertex " << i << " : ( " << vertex[i] << " )\n";
	cout << endl;
}


//?? ���� : ������ ��忡�� ���� �߰��ϴ� �Լ��� �ۼ��Ͻÿ�.
//?? assignment : write a function adding a point to the polygon object.
Boolean PolygonNode:: AddPoints(Point t)
{
	if (NumOfPoints < MAXPOINTS)
	{
		vertex[NumOfPoints].Init(t.x, t.y);
		return TRUE;
	}
	else
	{
		cout << "�� �̻� ���� �߰��� �� �����ϴ�." << endl;
		return FALSE;
	}
}

//?? ���� :�������� ���� �ʿ��� ������ �Է� �޴� �Լ��� �ۼ��Ͻÿ�.
//?? assignment : display the points defining the current polygon
void PolygonNode:: draw()
{
	cout << "�ٰ����� �̷�� ���� x��ǥ���� y��ǥ���� �Է��ϼ��� : " << endl;
	cout << "x��ǥ�� : ";
	cin >> vertex[NumOfPoints].x;
	cout << "y��ǥ�� : ";
	cin >> vertex[NumOfPoints].y;
}