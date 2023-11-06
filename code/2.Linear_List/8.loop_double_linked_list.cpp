#include <iostream>

typedef struct DNode {
	ElemType data;
	DNode* prior, * next;
}DNode, *DLinkList;

bool InitDLinkList(DLinkList &L) {
	L = (DNode*)malloc(sizeof(DNode));
	if (L == NULL)
		return false;
	L->next = L;
	L->prior = L;
	return true;
}

bool Empty(DLinkList L) {
	if (L->next == L)
		return true;
	else
		return false;
}

// �жϽڵ�p�Ƿ�Ϊ˫����ı�β�ڵ�
bool isTail(DLinkList L, DNode* p) {
	if (p->next == L)
		return true;
	else
		return false;
}

// ѭ��˫����ɾ��p�ĺ�̽ڵ�q
bool testDelete(DNode* p, DNode* q) {
	p->next = q->next;
	q->next->prior = p;
	free(q);
	return true
}