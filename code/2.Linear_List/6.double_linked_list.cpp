#include <iostream>

typedef struct DNode {
	ElemType data;
	struct DNode* prior, * next;
}DNode, *DLinkList;

// 初始化双链表  带头节点
bool InitDLinkList(DLinkList &L) {
	L = (DNode*)malloc(sizeof(DNode));
	if (L == NULL)
		return false;
	L->next = NULL;
	L->prior = NULL;
	return true;
}

void testDLinkList() {
	DLinkList L;
	InitDLinkList(L)
}

// p 节点后插入s节点
bool InsertNextDNode(DNode* p, DNode* s) {
	if (p == NULL || s == NULL)
		return false;
	s->next = p->next;
	if (p->next !== NULL)
		p->next->prior = s;
	s->prior = p;
	p->next = s;
	return true;
}

// 删除p节点的后继节点q
bool testDelete(DNode* p) {
	if (p == NULL)
		return false;
	DNode* q = p->next;
	if (q == NULL)
		return false;
	p->next = q->next;
	if (q->next != NULL) {
		q->next->prior = p;
	}
	else
	{
		p->next = NULL;
	}
	free(q);
	return true;
}

// 双链表的遍历
void demo(DNode *p) {
	while (p != NULL)
	{
		p = p->next;
	}
	// 后向遍历

	while (p != NULL)
	{
		p = p->prior
	}
	// 前向遍历

	while (p->prior != NULL)
	{
		p = p->prior;
	}
	// 前向跳过头节点
}