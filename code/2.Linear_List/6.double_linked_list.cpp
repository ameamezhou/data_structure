#include <iostream>

typedef struct DNode {
	ElemType data;
	struct DNode* prior, * next;
}DNode, *DLinkList;

// ��ʼ��˫����  ��ͷ�ڵ�
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

// p �ڵ�����s�ڵ�
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

// ɾ��p�ڵ�ĺ�̽ڵ�q
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

// ˫����ı���
void demo(DNode *p) {
	while (p != NULL)
	{
		p = p->next;
	}
	// �������

	while (p != NULL)
	{
		p = p->prior
	}
	// ǰ�����

	while (p->prior != NULL)
	{
		p = p->prior;
	}
	// ǰ������ͷ�ڵ�
}