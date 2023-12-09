#include<iostream>
#include <bits/stdc++.h>

using namespace std;


#define MaxVertexNum 100
typedef struct ArcNode{
    int adjvex;     // 该弧所指向的顶点的位置
    struct ArcNode *nextarc;    // 指向下一条弧的指针
}ArcNode;

typedef struct VNode{
    VertexType data;
    ArcNode *firstarc;  // 指向第一条依附该顶点的弧的指针
}VNode, AdjList[MaxVertexNum];

typedef struct {
    AdjList vertices;   // 邻接表
    int vexnum, arcnum; // 顶点数和边数
} Graph;

int printList[MaxVertexNum];    // 输出序列
int indegree[MaxVertexNum];     // 记录所有结点的入度

bool ToplogicalSort(Graph G){
    // InitStack(S);
    stack<int> s;
    for (int i=0; i < G.vexnum; i++) {
        if (indegree[i]==0) {
            s.push(i);
        }
    }
    int count = 0;
    while(!s.empty()){
        int r = s.top();
        s.pop();
        printList[count++] = r;
        for (auto p=G.vertices[r].firstarc;p;p=p->nextarc){
            int v = p->adjvex;
            if(!(--indegree[v])) s.push(v);
        }
    }
    if (count < G.vexnum)
        return false;
    else
        return true;
}