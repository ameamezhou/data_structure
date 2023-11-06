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

// 判断节点p是否为双链表的表尾节点
bool isTail(DLinkList L, DNode* p) {
	if (p->next == L)
		return true;
	else
		return false;
}

// 循环双链表删除p的后继节点q
bool testDelete(DNode* p, DNode* q) {
	p->next = q->next;
	q->next->prior = p;
	free(q);
	return true
}