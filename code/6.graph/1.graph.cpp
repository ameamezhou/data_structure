#include <bits/stdc++.h>
using namespace std;

#define MaxVertexNum 100
typedef struct {
    char Vex[MaxVertexNum];                 // 存放节点
    int Edge[MaxVertexNum][MaxVertexNum];   // 二维数组 邻接矩阵  存放边的关系
    int vexNum, arcNum;
}MGraph;
// 实际使用
int a[MaxVertexNum][MaxVertexNum];

// 如果要用邻接矩阵存储带权图
#define INFINITY 1000000 // 存储最大的int值  用来表示无穷(带权图里无穷就代表无边) 0或者无穷都能表示无边
typedef char VertexType;
typedef int EdgeType;
typedef struct{
    VertexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexNum, arcNum;
}MEGraph;

// 邻接表法   顺序+链式存储
// 边/弧
typedef struct ArcNode {
    int adjVex;     // 边/弧 指向哪个结点
    struct ArcNode *next; // 指向下一条弧的指针
    // InfoType info;  // 边权值
}ArcNode, *ArcList;

// 记录顶点
typedef struct VNode{
    VertexType data;
    ArcNode *First;   // 第一条边
}VNode, AdjList[MaxVertexNum];

// 用邻接表存储的图
typedef struct {
    AdjList vertices;
    int vexNum, arcNum;
}ALGraph;

// 使用
vector<vector<int>> e;
vector<int> e[N];

///////////////////////////////////// 算法 //////////////////////////////////
// 邻接矩阵转化为邻接表
void del(ArcList &L) {
    if (L != NULL) {
        del(L->next);
        free(L);
    }
}

void MtoAL(MGraph &M, ALGraph &T) {
    T.vexNum = M.vexNum;
    for (int i = 1; i < T.vexNum; ++i) {
        del(T.vertices[i].First->next);
    }
    for (int i = 1; i <= T.vexNum; ++i) {
        for (int j = 1; j <= T.vexNum; ++j) {
            if (M.Edge[i][j] == 1) {
                ArcNode *p = new ArcNode();
                p->adjVex = j;   // j是第几列  也就是指向的结点
                ArcNode *L = T.vertices[i].First; // 获取头节点
                p->next = L->next;
                L->next = p;
            }
        }
    }
}

// 邻接表转化为邻接矩阵
void ALtoM(MGraph &M, ALGraph &T) {
    // M T 邻接矩阵  邻接表
    M.vexNum = T.vexNum;
    for(int i = 1; i<M.vexNum; ++i) {
        for (int j = 1; j < M.vexNum; ++j) {
            M.Edge[i][j] = 0; // 初始化
        }
    }

    for (int i = 1; i <= T.vexNum; ++i) {
        ArcNode *p = T.vertices[i].First;
        while(p->next != NULL) {
            M.Edge[i][p->adjVex] = 1;
            p = p->next;
        }
    }

}

