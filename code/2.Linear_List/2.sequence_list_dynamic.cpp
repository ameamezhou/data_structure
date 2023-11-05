// 静态分配
#include <stdio.h>
#define InitSize 10

typedef struct {
	int *data;
	int MaxSize;
	int length;
}SeqList;


// 动态申请和释放内存空间
// c -- malloc free 函数
// L.data = (ElemType *)malloc(sizeof(ElemType) * InitSize)
// c++ -- new、delete 关键字


void InitList(SeqList& L) {
	L.data = (int*)malloc(InitSize * sizeof(int));
	L.length = 0;
	L.MaxSize = InitSize;
}


void IncreaseSize(SeqList& L, int len) {
	int *p = L.data;
	L.data = (int*)malloc((L.MaxSize+len) * sizeof(int));
	for (int i=0; i < L.length; i++) {
		L.data[i] = p[i];
	}
	L.MaxSize = L.MaxSize + len;
	free(p);
}
int main() {
	SeqList L;
	InitList(L);
	//.. 
	IncreaseSize(L, 5);
	return 0;
}

int GetElem(SeqList L, int i) {
	return L.data[i-1];
}

// 按值查找  返回位序
int LocateElem(SeqList L, ElemType e) {
	for (int i = 0; i < L.length; i++)
		if (L.data[i] == e)
			return i + 1;
	return 0;