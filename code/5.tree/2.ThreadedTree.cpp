#include <iostream>

#define MaxSize 100;

// 线索二叉树
typedef struct ThreadNode {
	ElemType data;
	struct ThreadNode* lchild, * rchild;
	int ltag, rtag;							// tag == 0 表示指向的是孩子，1表示指向的是线索
}ThreadNode, * ThreadThree;

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
		if (T->ltag == 0)
			PreOrder(T->lchild);  // lchild 不能是前驱结点
		PreOrder(T->rchild);
	}
}


/////////////////////////////////////////线索二叉树的前驱后继
// ================================ 中序线索二叉树找中序后继 ==========
// 找到以p为根的子树中，第一个被中序遍历的结点
ThreadNode* FirstNode(ThreadNode* p) {
	// 循环找到最坐下的结点
	while (p->ltag == 0)
	{
		p = p->lchild;
	}
	return p
}

// 在中序线索二叉树中找到结点p的后继结点
ThreadNode* NextNode(ThreadNode* p) {
	// 右子树中最左下的结点
	if (p->rtag == 0) return FirstNode(p->rchild);
	else
	{
		return p->rchild;
	}
}

// 对中序线索二叉树进行中序遍历 利用线索实现的非递归算法
void Inorder(ThreadNode* T) {
	for (ThreadNode* p = FirstNode(T); p != NULL; p = NextNode(p))
		visit(p);
}

// ================================ 中序线索二叉树找中序前驱 ==========
// 在中序线索二叉树中找到结点p的前驱结点
ThreadNode* LastNode(ThreadNode* p) {
	// 循环找到最坐下的结点
	while (p->rtag == 0)
	{
		p = p->rchild;
	}
	return p
}

ThreadNode* PreNode(ThreadNode* p) {
	// 左子树中最右下结点
	if (p->ltag == 0) return LastNode(p->lchild);
	else
	{
		return p->lchild;
	}
}

// 对中序线索二叉树进行逆向中序遍历
void RevInorder(ThreadNode* T) {
	for (ThreadNode* p = LastNode(T); p != NULL; p = PreNode(p))
		visit(p);
}

// ================================ 先序线索二叉树找先序后继 ==========
// 先序线索二叉树中 p->rtag == 1 则 next = p->rchild
// p -> rtag == 0   根=左=右 -> 根=（根=左=右）=右
// p的左孩子就是它的后继结点  如果没有左孩子，那就是 根=右 -> 根=（根=左=右）
// 没有左孩子  它的后继就是右孩子
//

ThreadNode* FirstNode(ThreadNode* p) {
	return p;
}

// 在先线索二叉树中找到结点p的后继结点
ThreadNode* NextNode(ThreadNode* p) {
	// 右子树中最左下的结点
	if (p->rtag == 0) return FirstNode(p->rchild);
	else
	{
		return p->rchild;
	}
}