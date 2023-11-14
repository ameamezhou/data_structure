#include <bits/stdc++.h>

using namespace std;

typedef struct BiSTNode{
    int key;
    struct BiSTNode *lchild, *rchild;
}BiSTNode, *BiSTree;

BiSTNode *SearchBST(BiSTree T, int key){
    if(T == NULL) return NULL;
    else if (T->key == key) return T;
    else if (T->key > key)
        return SearchBST(T->rchild, key);
    else if (T->key < key)
        return SearchBST(T->lchild, key);
}

bool InsertBST(BiSTree &T, int key) {
    if (T==NULL) {
        T = (BiSTree)malloc(sizeof(BiSTNode));
        T->key = key;
        T->lchild = NULL;
        T->rchild = NULL;
        return true;
    }
    if (key == T->key) {
        return false;
    }
    if (key > T->key) {
        return InsertBST(T->rchild, key);
    } else {
        return InsertBST(T->lchild, key);
    }
}

void CreateBST(BiSTree &T, int data[], int length) {
    T = NULL;
    for (int i = 0; i < length; i++) {
        InsertBST(T, data[i]);
    }
}

void Delete(BiSTNode *&p) {
    if(p->rchild == NULL){//右子树空只需重接它的左子树
        BiSTNode *q=p;
        p=p->lchild;
        free(q);
    }
    else if(p->lchild == NULL){
        BiSTNode *q=p;
        p=p->rchild;
        free(q);
    }
    else{//左右子树都不为空
        BiSTNode *q=p;
        BiSTNode *s=p->lchild;
        while(s->rchild != NULL){
            q=s;
            s=s->rchild;
        }
        p->key=s->key;
        if(q!=p) q->rchild =s->lchild;//删除结点的左孩子有左子树
        else q->lchild =s->lchild;//删除结点的左孩子无右子树
        free(s);
    }
    return;

}

bool DeleteBST(BiSTree &T, int key) {
    if (T == NULL) return false;
    else if (T->key == key) {
        Delete(T);
    }else if(T->key>key)
        DeleteBST(T->lchild,key);
    else DeleteBST(T->rchild,key);
}