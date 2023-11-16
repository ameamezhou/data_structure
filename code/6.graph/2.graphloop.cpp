#include <bits/stdc++.h>

using namespace std;

#define N 100
typedef struct {            // 邻接矩阵
    int vexNum;
    int arcs[N][N];
}MGraph;

typedef struct LGraph {     // 邻接表
    int vexNum;
    vector<int> vertices[N];
}LGraph;

bool vis[N]; // 记录结点是否被访问
void dfs(MGraph G, int x) { // 深度优先遍历，x是访问的当前节点
    printf("%d", x);
    vis[x] = 1;
    for (int i = 0; i < G.vexNum; ++i) {
        if (G.arcs[x][i] && !vis[i]) dfs(G,i);
    }
}

void dfsTravl(MGraph G) { // dfs 调用
    for (int i = 0; i < G.vexNum; i++)
    {
        for (int j = 0; j < G.vexNum; j++)
        {
            if(!vis[i]) dfs(G,i);
        }
    }
}

// 广度优先遍历
void bfs(LGraph G, int x) {
    queue<int> q;
    q.push(x);
    vis[x] = 1;
    while (!q.empty()){
        int p = q.front();
        for (int i = 0; i < G.vertices[p].size(); ++i){
            int y = G.vertices[p][i];
            if (!vis[y]) {
                q.push(y);
                vis[y] = 1;
            }
        }
    }
}

void bfsTravl(LGraph G){
    for (int i = 0; i < G.vexNum; ++i) {
        for (int j = 0; j < G.vexNum; j++)
        {
            if (!vis[i]) bfs(G, i);
        }
    }
}

// 最小生成树
int prim(MGraph G) {    // 普利姆算法
    int n = G.vexNum;
    int result;
    vector<int> f(n);
    f[0] = 1;
    for (int i = 1; i < n; ++i) {
        int index = 0, temp, flag = 0;
        for (int j = 0; j < n; ++j) {
            if (!f[j]) {
                if (!flag) {
                    temp = G.arcs[i][j];
                    index = j;
                } else {
                    if (G.arcs[i][j] < temp) {
                        index = j;
                        temp = G.arcs[i][j];
                    }  
                }
            }
        }
        result += temp;
        f[index] = 1;
    }
    return result;
}


int main (){
    return 0;
}