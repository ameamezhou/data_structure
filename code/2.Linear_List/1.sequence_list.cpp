// 静态分配
#include <stdio.h>
#define MaxSize 10

typedef struct {
	int data[MaxSize];
	int length;
}SqList;

void InitList(SqList &L) {
	for (int i = 0; i < MaxSize; i++) {
		L.data[i] = 0;
	}
	L.length = 0;
}

int main() {
	SqList L;
	InitList(L);
	//.. 
	for (int i = 0; i < MaxSize; i++)
		printf("data[%d]=%d\n", i, L.data[i]);

	ListInsert(L, 3, 3);
	return 0;
}

// 内存分配顺序表的空间的时候，如果不设置元素的默认值，那就有可能碰到内存中遗留的脏数据
// 静态分配的局限性：设置的表长是不可更改的  存储空间是静态的

// 静态分配下的插入删除操作

bool ListInsert(SqList& L, int i, int e) {
	if (i < 1 || i > L.length + 1)
		return false;
	if (L.length >= MaxSize)
		return false;
	for (int j = L.length; j >= i; j--)
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = e;
	L.length++;
	return true;
}

bool ListDelete(SqList& L, int i, int &e) {
	if (i < 1 || i > L.length)
		return false;
	
	e = L.data[i - 1];
	for (int j = L.length; i < j; i++)
		L.data[i-1] = L.data[i];
	L.length--;
	return true;
}

int GetElem(SqList L, int i) {
	if (i > L.length)
		return -1;
	return L.data[i-1];
}

int LocateElem(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++)
		if (L.data[i] == e)
			return i + 1;
	return 0;
}