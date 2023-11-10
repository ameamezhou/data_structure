#include <iostream>

#define MaxSize 100;

// ����������
typedef struct ThreadNode {
	ElemType data;
	struct ThreadNode* lchild, * rchild;
	int ltag, rtag;							// tag == 0 ��ʾָ����Ǻ��ӣ�1��ʾָ���������
}ThreadNode, * ThreadThree;

// ����������������ʵ��


// ����ȫ�ֱ���  ���ڲ��ҽ��p��ǰ��
ThreadNode* p;

ThreadNode* final = NULL;

void visit(ThreadNode* q) {
	if (q->lchild == NULL) { // ������Ϊ�գ�����ǰ������
		q->lchild = pre;
		q->ltag = 1;
	}
	if (pre != NULL && pre->rchild == NULL) {
		pre->rchild = q;
		pre->rtag = 1;
	}
	pre = q;
}

// �����������Ļ�����ĳ�����������߼����У�����Ҳһ��
// 
// �������ҵ�����ǰ��
void MidOrder(BiTree T) {
	if (T != NULL) {
		MidOrder(T->lchild);
		visit(T);
		MidOrder(T->rchild);
	}
}
ThreadNode* pre = NULL;
// ����������������T
void CreateInThread(ThreadNode T) {
	pre = NULL;
	if (T != NULL) {
		MidOrder(T);
		if (pre->rchild == NULL)
			pre->rtag = 1;
	}
}

// ���ﹹ������������ʱ����������ѭ�������⣬��Ϊ���ȸ����󣬶�visit���ڸ�����ʱ��
// ����������һ��ָ����һ���������ߵ�ʱ����ߵ���һ����� (�Լ���ͼ������)
// �ͻ�������  ����pre���ﻹ��һ��Ҫ�޸���
// 
void PreThread(ThreadNode T) {
	if (T != NULL) {
		visit(T);
		if (T->ltag == 0)
			PreOrder(T->lchild);  // lchild ������ǰ�����
		PreOrder(T->rchild);
	}
}


/////////////////////////////////////////������������ǰ�����
// ================================ ���������������������� ==========
// �ҵ���pΪ���������У���һ������������Ľ��
ThreadNode* FirstNode(ThreadNode* p) {
	// ѭ���ҵ������µĽ��
	while (p->ltag == 0)
	{
		p = p->lchild;
	}
	return p
}

// �������������������ҵ����p�ĺ�̽��
ThreadNode* NextNode(ThreadNode* p) {
	// �������������µĽ��
	if (p->rtag == 0) return FirstNode(p->rchild);
	else
	{
		return p->rchild;
	}
}

// ��������������������������� ��������ʵ�ֵķǵݹ��㷨
void Inorder(ThreadNode* T) {
	for (ThreadNode* p = FirstNode(T); p != NULL; p = NextNode(p))
		visit(p);
}

// ================================ ��������������������ǰ�� ==========
// �������������������ҵ����p��ǰ�����
ThreadNode* LastNode(ThreadNode* p) {
	// ѭ���ҵ������µĽ��
	while (p->rtag == 0)
	{
		p = p->rchild;
	}
	return p
}

ThreadNode* PreNode(ThreadNode* p) {
	// �������������½��
	if (p->ltag == 0) return LastNode(p->lchild);
	else
	{
		return p->lchild;
	}
}

// �������������������������������
void RevInorder(ThreadNode* T) {
	for (ThreadNode* p = LastNode(T); p != NULL; p = PreNode(p))
		visit(p);
}

// ================================ ���������������������� ==========
// ���������������� p->rtag == 1 �� next = p->rchild
// p -> rtag == 0   ��=��=�� -> ��=����=��=�ң�=��
// p�����Ӿ������ĺ�̽��  ���û�����ӣ��Ǿ��� ��=�� -> ��=����=��=�ң�
// û������  ���ĺ�̾����Һ���
//

ThreadNode* FirstNode(ThreadNode* p) {
	return p;
}

// �����������������ҵ����p�ĺ�̽��
ThreadNode* NextNode(ThreadNode* p) {
	// �������������µĽ��
	if (p->rtag == 0) return FirstNode(p->rchild);
	else
	{
		return p->rchild;
	}
}