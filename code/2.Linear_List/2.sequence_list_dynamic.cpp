// ��̬����
#include <stdio.h>
#define InitSize 10

typedef struct {
	int *data;
	int MaxSize;
	int length;
}SeqList;


// ��̬������ͷ��ڴ�ռ�
// c -- malloc free ����
// L.data = (ElemType *)malloc(sizeof(ElemType) * InitSize)
// c++ -- new��delete �ؼ���


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

// ��ֵ����  ����λ��
int LocateElem(SeqList L, ElemType e) {
	for (int i = 0; i < L.length; i++)
		if (L.data[i] == e)
			return i + 1;
	return 0;