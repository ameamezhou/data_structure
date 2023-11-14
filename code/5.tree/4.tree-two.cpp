#include <bits/stdc++.h>
using namespace std;

// 双亲表示法
typedef struct {
    char data;
    int parent;
}PTNode;

typedef struct {
    PTNode nodes[100];
    int n;
}PTree;

// 孩子表示法
struct CTPod {
    int child;
    struct CTPod *next;
};

typedef struct {
    char data;
    struct CTPod *firstChild;
}CTNode;

typedef struct {
    CTNode nodes[100];
    int n;
}CTree;

// 树转二叉树 -> 左孩子 右兄弟
typedef struct CSNode{
    int data;
    struct CSNode *lchild, *rbrother;
};
