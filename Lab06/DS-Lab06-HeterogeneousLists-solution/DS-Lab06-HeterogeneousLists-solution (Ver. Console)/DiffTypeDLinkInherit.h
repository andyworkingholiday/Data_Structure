#ifndef _DIFFTYPEDLINKINHERIT_H
#define _DIFFTYPEDLINKINHERIT_H

#include <iostream>
using namespace std;

#define MAXPOINTS 500
enum Boolean { FALSE, TRUE };

struct Point
{
	int x;
	int y;

	void Init(int c, int e) { x = c; y = e;};	// ��� �ʱ�ȭ
	
	//?? ����
	//?? assignment : print out a point to screen
	Point operator = (Point& b)
	{
		// Solution
		this->x = b.x;
		this->y = b.y;

		return *this;
	};
	
	friend ostream &operator << (ostream& out, Point t)
	{ 
		out << t.x << " , ";
		out << t.y;
		return out;
	};

	//?? ����
	//?? assignment : input a point from keyboard
	friend istream &operator >> (istream& in, Point& t)
	{ 
		// Solution
		in >> t.x;
		in >> t.y;

		return in;
	};
};


//================================ BaseNode class ���� ===============================
//	�������� graphic primitive���� �ϳ��� �����Ͽ� �����ϰ� ó���� �� �ְ� �Ѵ�.
//	- �ϳ��� linked list�� �����Ѵ�. 
//	- ������ �����ϰ� primitive�� �Է�(draw) ���(display) �Ѵ�. virtual �Լ��� �̿�  

//================================ Defie BaseNode class ===============================
//	generate a heterogeneous linked list that can handle graphic primitives
//	can display and draw the primitives independently from the type of primitives by using virtual functions

class BaseNode
{
	friend class List;
	friend class ListIterator;
public:
	BaseNode();
	virtual void draw()=0;  // pure virtual function ���� �����Լ� 
	virtual void display()=0;
	int GetAttribute() {
		return attribute;
	}

protected:
	int attribute;
	BaseNode *rlink;  //������(��) ��带 ����Ű�� ������
	BaseNode *llink;  //����(��) ��带 ����Ű�� ������
};


//================================ Derived Node class ���� ===============================
//?? ���� : �簢�� Ŭ���� ���.
//?? ���� : �� Ŭ���� ���.
// ������ ������ �������� CircleNode Ŭ������ �����϶�.
// ������ �� �� ���, �߽����� ��������� �����Ѵ�.


//================================ Define Derived Node class ===============================
//?? assignment : Define rectangle class
//?? assignment: define circle class
// A circle can be define by two points; center and one on the boundary

// Rectangle class
class RectangleNode : public BaseNode
{
public:
	RectangleNode() 
	{
		attribute = 1;
		curNum = 0; 
		start.Init(0,0); 
		end.Init(0, 0);
	}
	RectangleNode(Point start, Point end,int attrib);
	~RectangleNode();
	void display();
	void draw();

private:
	int curNum;
	Point start;
	Point end;
};

// Circle class
class CircleNode : public BaseNode
{
public:
	CircleNode() 
	{
		attribute = 2;
		curNum = 0; 
		center.Init(0,0); 
		boundary.Init(0,0);
	}
	CircleNode(Point center,Point boundary,int attrib);
	~CircleNode();
	void display();
	void draw();

private:
	int curNum;
	Point center;
	Point boundary;
};

// Polygon class
class PolygonNode : public BaseNode 
{
public:
	PolygonNode()	
	{
		attribute = 3;
		NumOfPoints = 0; 
	};
	PolygonNode(Point Vertex[], int NumOfPoints, int attrib);
	void display(); // ȭ�鿡 ���
	void draw(); // ���� 
	Boolean AddPoints(Point t); // add vertex to the list
private:
	int NumOfPoints;
	Point vertex[MAXPOINTS];
};



//================================== List class   ================================= 
class List
{
	friend class ListIterator;
public:
	List();
	~List();
	void Attach(BaseNode* a); // ��带 ������ ��, �ǵڿ� �߰� 
	void drawAll(); // ��� primitive�� draw �Ѵ�. 
	void DeleteAllNode(); // Header�� ������ ����Ʈ�� ����� ��� ��� ���� 
private:
	BaseNode *first;  // linked List�� ���� 
};


//==================================== Iterator class =========================
class ListIterator
{
	friend class List;
public:
	ListIterator(const List &l) : list(l), current(l.first->rlink)	{};
	Boolean NotHeader(); // list�� ���� ���Ұ� ������ ���������� �˻� 
	BaseNode* Next();		// current node�� data�� ��ȯ�ϰ� current ���� ������ �̵�  
private:
	const List &list;
	BaseNode *current;
};


#endif