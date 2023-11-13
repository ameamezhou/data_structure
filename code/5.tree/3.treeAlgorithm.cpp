#include <bits/stdc++.h>

using namespace std;

// 求二叉树高度
typedef struct BiTNode{
    int data;
    BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

int main(){

}

BiTNode *BuildTree(){
    int data;
    scanf("%d", &data);
    if (data == -1) {
        return NULL;
    }
    BiTree T = (BiTNode *)malloc(sizeof(BiTNode));
    T->data = data;
    T->lchild = BuildTree();
    T->rchild = BuildTree();
    return T;
}

// 求二叉树高度 递归
int Depth(BiTree T){
    if (T == NULL) return 0;
    int ld = Depth(T->lchild);
    int rd = Depth(T->rchild);
    return (ld>rd?ld:rd) + 1;
}

// 求二叉树高度 非递归
int Depth2(BiTree T) {
    if (T == NULL) return 0;
    BiTNode* p;
    BiTNode* L[105];
    int front = -1, rear = -1; // 投指针和尾指针
    int depth = 0, last = 0; // 深度 和 当前遍历层的最后一个结点位置
    L[++rear] = T;
    while(front < rear) {
        p = L[++front];
        if (p->lchild != NULL) {
            L[++rear] = p->lchild;
        }
        if (p->rchild != NULL) {
            L[++rear] = p->rchild;
        }
        if (front == last) {
            depth++;
            last = rear;
        }
    }
    return depth;
}

int width(BiTree T) {
    if (T == NULL) return 0;
    BiTNode* p;
    BiTNode* L[105];
    int front = -1, rear = -1; // 投指针和尾指针
    int width = 1, last = 0; // 深度结果 和临时深度变量 和 当前遍历层的最后一个结点位置
    L[++rear] = T;
    while(front < rear) {
        p = L[++front];
        if (p->lchild != NULL) {
            L[++rear] = p->lchild;
        }
        if (p->rchild != NULL) {
            L[++rear] = p->rchild;
        }
        if (front == last) {
            width =width>=(rear - last)?width:(rear - last);
            last = rear;
        }
    }   
    return width;
}

// 在二叉树中查找值为 x 的结点，试编写算法打印值为 x 的结点的所有祖先(值为 x 的结点不多于一个)


// 给出二叉树的中序和后序遍历还原二叉树(pipioj1269)
// intl 是先序遍历的起始点， intr 是先序遍历的结尾位置
// postl 是后续遍历的起始位置， postr 是后续遍历的结尾位置
BiTNode *CreateBiTreeByInAndPost(int in[], int inl, int inr, int post[], int postl, int postr) {
    if (inl > inr || postl > postr)
        return NULL;
    BiTree T = (BiTNode *)malloc(sizeof(BiTNode));
    T->data = post[postr];
    int flag = 0;
    for (;flag < inr; flag++) {
        if (in[flag] == post[postr])
            break;
    }
    //对于后续遍历数组 post 来说 flag - inl - 1 就是左段的长度  postl + flag - inl 就是右段的起始
    T->lchild = CreateBiTreeByInAndPost(in, inl, flag-1, post, postl, postl + flag - inl - 1);
    T->rchild = CreateBiTreeByInAndPost(in, flag+1, inr, post, postl + flag - inl, postr-1);
    return T;
}

