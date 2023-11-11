#include <bits/stdc++.h>

using namespace std;

typedef struct LNode{
    struct LNode *next;
    int data;
}*LinkList, LNode;

int main(){
    LinkList L; // 这里是直接构造了一个指针
    LinkList L1 = Create(5);
    LNode *p = L1->next;
    while (p != NULL) {
        // if (p->data == xxx)  找到具体某个指针
        printf("%d ", p->data);
        p = p->next;
    }

    LinkList L2 = HCreate(5);
    LNode *p = L2->next;
    while (p != NULL) {
        // if (p->data == xxx)  找到具体某个指针
        printf("%d ", p->data);
        p = p->next;
    }


}

// 尾插法
LinkList Create(int length) {
    LinkList L = (LNode *) malloc(sizeof(LNode));
    // L = new LNode();
    L->next = NULL;
    LNode *p = L;
    while ((length--)!=0) {
        p->next = (LNode *)malloc(sizeof(LNode));
        p = p->next;
        scanf("%d", &p->data);
    }
    p->next = NULL;
    return L;
}

// 头插法
LinkList HCreate(int length) {
    LinkList L = (LNode *) malloc(sizeof(LNode));
    // L = new LNode();
    L->next = NULL;
    while ((length--)!=0) {
        LNode *p = (LNode *)malloc(sizeof(LNode));
        scanf("%d", &p->data);
        p->next = L->next;
        L->next = p;
    }
    return L;
}

// 删除 
bool Delete(LinkList &L, LNode x) {

} 

// 合并 集合 A B
void Merge(LinkList &LA, LinkList &LB){
    LNode *p, *q = LB->next, *r, *t = LA->next;
    free(LB);
    while (q!=NULL) {
        p = t;
        while (p != NULL && p->data != q->data)
            p = p->next;

        r=q;
        q=q->next;
        if (p==NULL){
            r->next=LA->next;
            LA->next = r;
        } else {
            free(r);
        }
    }
}

void DeleteRepeatedElem(LinkList &L) {
    LNode *p = L->next;
    if (p==NULL) 
        return;
    LNode *q = p->next;
    while (q != NULL) {
        if (q->data != p->data)
        {
            p->next->data = q->data;
            p=p->next;
        }
        q=q->next;
    }

}