#ifndef PCH_H
#define PCH_H

// TODO: 여기에 미리 컴파일하려는 헤더 추가

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <Windows.h>
using namespace std;

#define FILENAMESIZE 1024
#define maxQueue 21
#define maxStack 20
#define MAXSIZE 20
#define MAXLINKED 20
#define pause { cout << "\t"; system("pause"); }

enum ITEMKIND { ex1 = 0, ex2, ex3 };

// List
#include "UnsortedList.h"
#include "SortedList.h"
#include "QList.h"
#include "Stack.h"
#include "SingleSortedLinkedList.h"
#include "DoublyIterator.h"
#include "DoublySortedLinkedList.h"

// Type
#include "UserType.h"
#include "ItemType.h"
#include "SimpleItemType.h"
#include "ContainerType.h"
#include "TempType.h"
#include "RecentType.h"
#include "StorageType.h"
#include "Heart.h"

// App
#include "LoginApplication.h"
#include "MainApplication.h"

#endif //PCH_H
