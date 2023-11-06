#include <iostream>

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, *LinkList;

bool InitList(LinkList &L) {
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL)
		return false;
	L->next = L;
	return true;
}