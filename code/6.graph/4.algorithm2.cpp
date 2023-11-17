#include <bits/stdc++.h>

using namespace std;

#define N 100
// 找到图中从s到t的所有路径
typedef struct {
    int arcs[N][N];
    int vexNum;
}MGraph;

int F[N]; // 结点标志位

void dfs(MGraph G, int s, int t, int n, vector<int> r){
    F[s] = 1;
    r.push_back(s);
    if (s == t) {
        for (int a = 0; a < n; a++) {
            if (r[a] != -1)
                printf("%d", r[a]);
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!F[i] && G.arcs[s][i]){
            dfs(G, i, t, n, r);
        }
    }
    F[s] = 0;
    r.pop_back();
}

void TrvalDfs(MGraph G, int s, int t){
    if (s == t) {
        return;
    }
    int n = G.vexNum;
    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        result[i] = -1;
    }
    F[s] = 1;
    // dologic
    dfs(G, s, t, n, result);
}

int main(){
    int n, m, x, y;
    MGraph G;
    scanf("%d%d", &n, &m);
    G.vexNum = n;
    for (int i = 0; i < n; ++i) {
        F[i] = 0;
        for (int j = 0; j < m; ++j) {
            G.arcs[i][j] = 0;
        }
    }
    for (int t = 0; t < m; ++t){
        scanf("%d%d", &x, &y);
        G.arcs[x][y] = 1;
    }


    return 0;
}

// pp 逃亡 // 三维  一般不会考这么难  学习算法思想
typedef struct Node{
    int x, y, z;
    int t;
}Node;
// 记录结点信息

// 可移动坐标
int jc[6][3] = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};

void bfs(Node &n, int x, int y, int z){

}


// 迪杰斯特拉算法
/*
题目描述
在带权有向图G中，给定一个源点v，求从v到G中的其余各项顶点的最短路径问题，也叫做单源点最短路径问题

读入一个有向图的带权邻接矩阵(数组表示) 建立有向图并按照以上描述中的算法求出源点至没一个其他顶点的最短路径长度

输入第一行包括两个正整数n 和 s，表示途中共有n个顶点，且源点为s，其中n不超过50，s小于n
以后的n行每行都有n个用空格隔开的整数，对于第i行的第j个整数，如果大于0则表示i到j的有向边，权重为对应的整数数值，如果为0，则表示没有有向边，当ij相等时，恒为0

输出 只有一行，一共 n -1 个整数，表示源点到其他没一个顶点的最短路径长度，若不存在从源点到相应顶点的路径 输出 -1

输入
4 1
0 3 0 1
0 0 4 0
2 0 0 0
0 0 1 0

样例输出: 6 4 1
*/



#define N 50
typedef struct MGraph1{
    int arcs[N][N];
    int vexNum;
}MGraph1;
int inf = 999999999;

int flag[N];

int dologic(MGraph1 G, int s){
    int i, n = G.vexNum;
    vector<int> t; // 记录到源点的最短距离
    flag[s] = 1;
    for (i = 0; i < n; ++i) {
        t[i] = G.arcs[s][i]; // 先赋予s行的举例进行初始化
    }
    for (int j = 1; j < n; ++j) {
        int index, tmp = inf; // index 用来存储需要加入flag的点的索引， tmp用来临时存储对比选取的最小路径
        for (int k = 0; k < n; ++k) {
            if (!flag[k] && t[k] < tmp) {
                index = k;
                tmp = t[k];
            }
        }
        if (tmp == inf) {
            for (i = 0; i < n; ++i) {
                if(!flag[i]) t[i] == -1;  // 这个情况是如果后面不能再连接点了，我们就要把还没连接的点都删掉
            }
            break;
        }
        flag[index] = 1;

        for(i = 0; i < n; ++i) {
            if(!flag[i] && t[index] + G.arcs[index][i] < t[i]) t[i] = t[index] + G.arcs[index][i]; // 先检测 s -> index 当前的最短距离
            // 若 s->index + index -> i < s->i 则更新 s -> i 的举例
        }
    }
    for (i = 0; i < n; ++i) {
        if (i != s) {
            printf("%d ", t[i]);
        }
    }
    printf("\n");
}

int djtsl(){
    int n, s;
    MGraph1 G;
    scanf("%d,%d", &n, &s);
    for (int i = 0; i < n; ++i) {
        flag[i] = 0;
        for (int j = 0; j < n; ++j) {
            scanf("%d",&G.arcs[i][j]);
            if (G.arcs[i][j] == 0) G.arcs[i][j] = inf;
        }
    }
    dologic(G, s);
    return 0;
}


// 盗贼团伙
/*
给定n个城市之间的交通图，城市i j 有路可通 则 i j之间有边相连，边上的权值表示i到j的道路长度。现打算在这n个城市中
选定一个城市建立应急中心，试问应该在那个城市，才能使距离中心最远的城市到中心的路程最短 涉及算法解决

输入样式

3 3
1 2 3
1 3 4
2 3 1   城市 i 城市 j 距离 x
输出 2 号城市 最短3
*/

typedef struct MGraph3{
    int arcs[N][N];
    int vexNum;
}MGraph3;

int f[N];

int dologic2(MGraph3 &G){
    int n = G.vexNum;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (G.arcs[i][j] > G.arcs[i][k] + G.arcs[k][j]){
                    G.arcs[i][j] = G.arcs[i][k] + G.arcs[k][j];
                }
            }
        }
    }
}

int main2(){
    int n, m;
    int x, y, w;
    MGraph3 G;
    scanf("%d%d", &n, &m);
    G.vexNum = n;
    for (int i = 0; i < n; ++i) {
        f[i] = 0;
        for (int j = 0; j < n; ++j) {
            G.arcs[i][j] = inf;
        }
    }
    while (m--){
        scanf("%d%d%d", &x, &y, &w);
        G.arcs[x][y] = w;
        if (G.arcs == 0) G.arcs[x][y] = inf;
    }
    dologic2(G);
    int apart = inf, index;
    for (int center = 0; center < n; center++) {
        int maxApart = 0;
        for(int k = 0; k < n; k++) {
            maxApart = max(maxApart, G.arcs[center][k]);
        }
        if (maxApart < apart) {
            apart = maxApart;
            index = center;
        }
    }
    printf("%d %d", index, apart);


    return 0;
}

// 拓扑排序
/*
由某个几何上的一个偏序得到该集合上的一个全序，这个操作被称为拓扑排序
说白了就是一个个先把没有入度的结点删掉，然后看输出的顺序

如果到最后场上不存在结点了  那就说明不存在环

若存在环，则结点无法完全删除

我们可以用邻接表存储有向图，并通过 栈\队列 来暂存结点为0的顶点

输入 第一行包括一个正整数n 表示途中有n个顶点   n <= 50

以后的n行有n个空格隔开的整数0 1， 对于第i行j列表示 i->j 的有向边，如果没边的时候就输入 0

输出: 按照题目依次输出图的拓扑有序序列，每个整数后一个空格  要注意换行
如果有环 则输出 error
*/

int f[N];

void dologic3(MGraph3 G){
    int n = G.vexNum;
    stack<int> s; // 用栈来记录应该走哪些点
    vector<int> EdgeNum(n); // 记录每个点有多少条边
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; j++)
        {
            if (G.arcs[i][j]) EdgeNum[j]++;
        }
    }
    for (int k = 0; k < n; ++k) {
        if (EdgeNum[k]!=0) s.push(k);
    }
    vector<int> result;
    while (!s.empty()) {
        int p = s.top();
        result.push_back(p);
        s.pop();
        for (int i = 0; i < n; ++i) {
            if (G.arcs[p][i]) {
                EdgeNum[i]--;
                if (EdgeNum[i] == 0) {
                    s.push(i);
                }
            }   
        }
    }
    if (result.size() < n) {
        printf("ERROR");
    } else {
        for (int i = 0; i < n; ++i) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }

}

int main3(){
    int n;
    MGraph3 G;
    scanf("%d", &n);
    G.vexNum = n;
    int num;
    for (int i = 0; i < n ; ++i) {
        f[i] = 0;
        for (int j = 0; j < n; ++j) {
            scanf("%d", &num);
            if (num == 0)
                G.arcs[i][j] = inf;
            else 
                G.arcs[i][j] = num;
        }
    }

}



