#include <iostream>

#define MaxSize 100;
struct TreeNode {
	ElemType value;		// 节点中的数据元素
	bool isEmpty;		// 结点是否为空
};

TreeNode t[MaxSize];

void initTree(TreeNode &t[]) {
	for (int i = 0; i < MaxSize; i++) {
		t[i].isEmpty = true;
	}
}

/////////// 上面顺序存储
/////////////////////////// 分割线 /////////////////////
/////////// 下面链式存储

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

BiTNode *Create(){
	int d;
	scanf("%d", &d);
	ElemType data;
	data.value = d;
	if (data.value == -1) {
		return NULL;
	}
	BiTree T = (BiTNode *)malloc(sizeof(BiTNode));
	T->data = data;
	T->lchild = Create();
	T->rchild = Create();

	return T;
}

// 插入新节点
/*
BiTNode * p = (BiTNode *) malloc(sizeof(BiTNode));
p->data = {2};
p->lchild = NULL;
p->rchild = NULL;
root->lchild = p;
*/

// 先序遍历代码:
void PreOrder(BiTree T) {
	if (T != NULL) {
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

void PreOrder2(BiTree T){
	stack<BiTree> s;
	BiTNode *p = T;
	while (p || !s.empty()) {
		if (p) {
			printf("%d ", p->data);
			s.push(p);
			p = p->lchild;
		}
		else {
			p = s.top();
			s.pop();
			p = p->rchild;
		}
	}
}

// 中序遍历代码
void MidOrder(BiTree T) {
	if (T != NULL) {
		MidOrder(T->lchild);
		visit(T);
		MidOrder(T->rchild);
	}
}


// 后序遍历代码
void afterOrder(BiTree T) {
	if (T != NULL) {
		afterOrder(T->lchild);
		afterOrder(T->rchild);
		visit(T);
	}
}

// 非递归的后续遍历
struct element{
	BiTNode *ptr;
	int flag;
}

// 层序遍历
// 链式队列结点
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
	EnQueue(Q, T); // 根节点入队
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

#include <bits/stdc++.h>
using namespace std;

void levelOrder(BiTree T) {
	queue<BiTNode *> q;
	BiTree p = NULL;
	q.push(T);
	while (!q.empty()){
		p = q.front();
		q.pop();
		if (p->lchild != NULL)
			q.push(p->lchild);
		if (p->rchild != NULL)
			q.push(p->rchild);
	}
}