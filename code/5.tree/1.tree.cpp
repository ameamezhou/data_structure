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

// 线索二叉树
typedef struct ThreadNode {
	ElemType data;
	struct ThreadNode* lchild, * rchild;
	int ltag, rtag;							// tag == 0 表示指向的是孩子，1表示指向的是线索
}ThreadNode, *ThreadThree;

// 二叉树线索化代码实现


// 辅助全局变量  用于查找结点p的前驱
ThreadNode* p;

ThreadNode* final = NULL;

void visit(ThreadNode* q) {
	if (q->lchild == NULL) { // 左子树为空，建立前驱线索
		q->lchild = pre;
		q->ltag = 1;
	}
	if (pre != NULL && pre->rchild == NULL) {
		pre->rchild = q;
		pre->rtag = 1;
	}
	pre = q;
}

// 线序线索化的话这里改成先序遍历的逻辑就行，后序也一样
// 
// 土方法找到中序前驱
void MidOrder(BiTree T) {
	if (T != NULL) {
		MidOrder(T->lchild);
		visit(T);
		MidOrder(T->rchild);
	}
}
ThreadNode* pre = NULL;
// 中序线索化二叉树T
void CreateInThread(ThreadNode T) {
    pre = NULL;
	if (T != NULL) {
		MidOrder(T);
		if (pre->rchild == NULL)
			pre->rtag = 1;
	}
}

// 这里构建线序线索化时，会有无限循环的问题，因为是先根后左，而visit会在根结点的时候
// 给左结点增加一个指向，下一步往左结点走的时候会走到上一个结点 (自己画图分析下)
// 就会有问题  所以pre这里还有一步要修改下
// 
void PreThread(ThreadNode T) {
	if (T != NULL) {
		visit(T);
		if (T->ltag==0)
			PreOrder(T->lchild);  // lchild 不能是前驱结点
		PreOrder(T->rchild);
	}
}