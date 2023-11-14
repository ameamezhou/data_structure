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
void PrintAncester(BiTree T, int x) {
    BiTNode* s[1000]; // 局部设置一个栈
    int top = -1;     // 栈顶指针   
    BiTNode *p = T, *r = NULL; // r用来记录上一次弹出的结点，不能一直陷入右节点循环
    while (top > -1|| p != NULL) {
        if (p != NULL) {
            s[++top] = p;
            p = p->lchild;
        } else {
            p = s[top];
            if (p->rchild != NULL && p->rchild != r) {
                p = p->rchild; // 这里如果不设置弹出条件  就会有右节点弹出，回到上一节点，然后继续发现右节点存在，继续访问，变成死循环
            } else {
                // visit
                if (p->data == x) {
                    if (top == 0) {
                        // top = 0 说明是根节点  没有祖先结点
                        // printf 说明情况
                        return;
                    }
                    for(int i = 0; i < top; ++i) {
                        // printf("%d", s[i]->data);
                    }
                    // printf("\n");
                    return;
                }
                --top;
                r = p;
                p = NULL;
            }
        }
    }
    // 如果在这里还没找到x 那就说明不存在
    // printf("没有x结点")
}


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

// 结点与祖先结点的最大差值
// 非递归算法
// 这里直接和找x结点一样   修改一下visit部分的内容就行 
// 采用后续遍历，这样就能让祖先结点都存在栈中
int findMaxDiff(BiTree T) {
    BiTNode* s[1000]; // 局部设置一个栈
    int top = -1;     // 栈顶指针   
    BiTNode *p = T, *r = NULL;
    int max = 0, m = 0; // max记录最大值， m 为循环比较值
    while (top > -1 || p != NULL) {
        if (p!=NULL) {
            s[++top] = p;
            p = p->lchild;
        }else {
            p = s[top];
            if (p->rchild != NULL && p->rchild != r) {
                p = p->rchild;
            } else {
                // visit
                for (int i = 0; i < top; i++) {
                    m = abs(s[i]->data - p->data);
                    if (m >= max) {
                        max = m;
                    }
                }
                --top;
                r = p;
                p = NULL;
            }
        }
    }
    return max;
}

// 递归算法求最大差值
int result = 0;
void findMaxDiff2(BiTree T, int max, int min) {
    if (T==NULL) {
        return;
    }
    if (T->data >= max) {
        max = T->data;
    }
    if (T->data <= min) {
        min = T->data;
    }
    if (max - min > result) {
        result = max - min;
    }

    findMaxDiff2(T->lchild, max, min);
    findMaxDiff2(T->rchild, max, min);
}

// 求二叉树的直径
// 什么是二叉树的直径？
// 直径长度是任意两个节点路径长度中的最大值
// 就等于说如果我左子树特别大  右子树特别短  我们就可以只看左子树的直径 = 二叉树的直径
// 用全局变量存储最大直径长
int Diameter = 0;
int CalculateDiameter(BiTree T) {
    if (T == NULL) return 0;

    int ld = CalculateDiameter(T->lchild);
    int rd = CalculateDiameter(T->rchild);
    Diameter = Diameter>(ld+rd)?Diameter:(ld+rd);
    return (ld>rd?ld:rd) + 1;
}