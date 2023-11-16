#include <bits/stdc++.h>
using namespace std;

// 1118 继续畅通工程
/*
继续畅通工程:
省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通(但不一定有直接的公路相连，只要能间接通过公路可达即可)。
得到现城镇道路统计表，表中列出了任意两城镇间修建道路的费用，以及该道路是否已经修通状态。请写程序并计算最修路畅通需要的最低成本。

输入
测试输入包括村庄数目N;随后的 N(N+1)/2 行对应村庄间道路的成本及修建状态，每行给4个正整数，分别是两个村庄的编号(1-N)
此两村庄间道路的成本，以及修建状态，1表示已建，0表示未建

当N为0时输入结束

输入样例
3
1 2 1 0
1 3 2 0
2 3 4 0
3
1 2 1 0
1 3 2 0
2 3 4 1
0
*/

#define N 100
int f[N];
// 整理思路  把每个结点独立出来，然后如果连成边了  就用并查集讲 B结点的下标设为A结点的下标
// 然后因为要让维修成本最低  所以这里我们直接用排序  优先选成本最低的路径
int getF(int x){
    if (x == f[x]) {
        return x;
    }
    return getF(f[x]);
}

typedef struct edge{
    int x, y; // 记录结点编号
    int weight; // 记录权重
}edge;

int doLogic(vector<edge> e, int n){
    int result = 0;
    for (int k = 0; k < e.size(); ++k){
        int fx = getF(e[k].x);
        int fy = getF(e[k].y);
        if (fx != fy) {
            result += e[k].weight;
            f[fx] = fy;
        }
    }
    return result;
}

int cmp(edge A, edge B){
    return A.weight < B.weight;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF) {
        if (n == 0){
            break;
        }
        int m = n * (n-1)/2;
        vector<edge> e(m);
        
        for (int j = 0; j < n; ++j) {
            f[j] = j;
        }
        int w, c;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d%d", e[i].x, e[i].y, &w, &c);
            if (c==1) {
                e[i].weight = 0;
            } else {
                e[i].weight = w;
            }
        }
        sort(e.begin(),e.end(),cmp);
        printf("%d", doLogic(e, n));

    }
    return 0;
}