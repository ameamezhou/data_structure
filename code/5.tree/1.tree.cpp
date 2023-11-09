#include <iostream>

#define MaxSize 100;
struct TreeNode {
	ElemType value;		// �ڵ��е�����Ԫ��
	bool isEmpty;		// ����Ƿ�Ϊ��
};

TreeNode t[MaxSize];

void initTree(TreeNode &t[]) {
	for (int i = 0; i < MaxSize; i++) {
		t[i].isEmpty = true;
	}
}

/////////// ����˳��洢
/////////////////////////// �ָ��� /////////////////////
/////////// ������ʽ�洢

struct ElemType {
	int value;
};

typedef struct BiTNode {
	ElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, *BiTree;

BiTree root = NULL;
void initBiTree(BiTree& b) {
	b = (BiTree)malloc(sizeof(BiTNode));
	b->data = { 1 };
	b->lchild = NULL;
	b->rchild = NULL;
}

// �����½ڵ�
/*
BiTNode * p = (BiTNode *) malloc(sizeof(BiTNode));
p->data = {2};
p->lchild = NULL;
p->rchild = NULL;
root->lchild = p;
*/

// �����������:
void PreOrder(BiTree T) {
	if (T != NULL) {
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

// �����������
void MidOrder(BiTree T) {
	if (T != NULL) {
		MidOrder(T->lchild);
		visit(T);
		MidOrder(T->rchild);
	}
}


// �����������
void afterOrder(BiTree T) {
	if (T != NULL) {
		afterOrder(T->lchild);
		afterOrder(T->rchild);
		visit(T);
	}
}

// �������
// ��ʽ���н��
typedef struct LinkNode {
	BiTNode* data;
	struct LinkNode* next;
}LinkNode;

typedef struct {
	LinkNode* front, * rear;
}LinkQueue;

void levelOrder(BiTree T) {
	LinkQueue Q;
	InitQueue(Q);
	BiTree p;
	EnQueue(Q, T); // ���ڵ����
	while (!isEmpty(Q))
	{
		DeQueue(Q, p);
		visit(p);
		if (p->lchild != NULL)
			EnQueue(Q, p->lchild);
		if (p->rchild != NULL)
			EnQueue(Q, p->rchild);
	}
}

// ����������
typedef struct ThreadNode {
	ElemType data;
	struct ThreadNode* lchild, * rchild;
	int ltag, rtag;							// tag == 0 ��ʾָ����Ǻ��ӣ�1��ʾָ���������
}ThreadNode, *ThreadThree;

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
		if (T->ltag==0)
			PreOrder(T->lchild);  // lchild ������ǰ�����
		PreOrder(T->rchild);
	}
}