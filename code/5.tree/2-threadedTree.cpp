#include <bits/stdc++.h>
using namespace std;

typedef struct ThreadNode{
    int data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
}ThreadNode, *ThreadTree;


void InThread(ThreadTree T, ThreadNode *&pre) {
    if (T == NULL)
        return;
    
    InThread(T->lchild, pre);
    // visit
    if (T->lchild == NULL) {
        T->lchild = pre;
        T->ltag = 1;    
    }
    if (pre != NULL && pre->rchild == NULL) {
        pre->rchild = T;
        pre->rtag = 1;
    }
    pre = T;

    InThread(T->rchild, pre);
}

void CreateInThread(ThreadTree &T){
    ThreadNode *pre = NULL;
    if (T != NULL) {
        InThread(T, pre);
        if (pre->rchild == NULL) {
            pre->rtag = 1;
        }
    }
    
}

ThreadNode* FirstNode(ThreadTree T) {
	ThreadNode *p = T;
    // 循环找到最左下的结点
	while (p->ltag == 0)
	{
		p = p->lchild;
	}
	return p;
}

ThreadNode* NextNode(ThreadNode *p) {
    if (p->rtag == 0) 
        return FirstNode(p->rchild);
    return p->rchild;
}

void InOrderByThread(ThreadTree T) {
    for (ThreadNode *p = FirstNode(T); p!=NULL; p=NextNode(p)) {
        printf("%d ", p->data);
    }
}



// 找到最后一个结点
ThreadNode *Final(ThreadTree T) {
    ThreadNode *p = T;
    while(p->rtag == 0) {
        p = p->rchild;
    }
    return p;
}


// 找出前驱后继
// 前驱
ThreadNode *FrontNode(ThreadNode *p) {
    if (p->ltag == 0) {
        return Final(p->lchild);
    }
    return p->lchild;
}

// 后继就是 nextNode
ThreadNode* NextNode(ThreadNode *p);

// 先序遍历线索二叉树
void PreThread(ThreadTree T, ThreadNode *&pre) {
    if (T == NULL)
        return;

    // visit
    if (T->lchild == NULL) {
        T->lchild = pre;
        T->ltag = 1;    
    }
    if (pre != NULL && pre->rchild == NULL) {
        pre->rchild = T;
        pre->rtag = 1;
    }
    pre = T;
    if (T->ltag == 0)
        InThread(T->lchild, pre);
    InThread(T->rchild, pre);
}