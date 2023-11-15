#include <bits/stdc++.h>
using namespace std;

// 要实现并查集，就要用到树的数据结构
// 树的存储结构有很多种，双亲表示法，孩子表示法，孩子兄弟表示法等
// 考虑到查的操作是需要向上找根节点的  所以这里我们用双亲表示法最为合适

#define MaxSize 100

typedef struct{
    int data;
    int parent;
}PTNode;

typedef struct {
    PTNode nodes[MaxSize];
    int n;
}PTree;

// Find 查操作 返回x所属的根节点
int Find(int S[], int x) {
    while (S[x] >= 0) {
        x = S[x];
    }
    return x;
}

// Union 并操作  将两个集合合并为一个
bool Union(int S[], int R1, int R2) {
    if (R1 == R2) {
        return false;
    }
    S[R2] = R1;
    return true;
}

// 优化思路，因为要减少查找的时间开销，所以我们合并的目的就是
// 要让高度比较低的树合并到高度比较高的树下面
// 然后这个逻辑，就要求根节点的下标下面要记录根节点一共有多少个结点
// 所以我们就要把下标改为 -结点数  这样小于零就还是记录的是结点数
// 
bool Union2(int S[], int R1, int R2) {
    if (R1 == R2) {
        return false;
    }
    if (S[R2] > S[R1]) {
        S[R1] += S[R2];
        S[R2] = R1;
    } else {
        S[R2] += S[R1];
        S[R1] = R2;
    }
    return true;
}

// 并查集的进一步优化
// Find 查 操作优化，线遭到根节点，再压缩路径
int Find(int S[], int x){
    int root = x;
    while (S[root] > 0) root = S[root]; // 循环找到根
    while (x != root) {
        int t = S[x];
        S[x] = root;
        x = t;
    }
    return root;
}

// 并查集的使用
// 有n个点 m条无向边 求连通分量的个数
const int N = 101;
int f[N]; // 并查集的父亲数组

int getFather(int x){
    return x==f[x]?x:f[x] = getFather(f[x]); // 找到父亲
}

void merge(int x, int y){

}

int main(){
    int i,n,m;
    while (cin>>n>>m) {
        for (i = 1; i<=n;++i) {
            f[i] = i;       // 初始化每个元素的父亲都是自己
            int cnt = n;    // 一开始有n个联通分量
            while (m--) {
                int x, y;
                cin>>x>>y;
                int fx = getFather(x);
                int fy = getFather(y);
                if(fx != fy) {
                    cnt--;
                    f[fx] = fy; // 合并  这里可以优化  其实就是上面那个
                }
                cout << cnt <<endl;    
            }
        }
    }
    return 0;
}

// 油田问题
/*
就是会输入 n m 代表格子的行数和列数

一个格子如果是普通田地 就是 * 如果是油田就是 @

并且上下左右 右上右下 左上坐下 如果也有油田的话代表这就是同一片油田 请分析一共有多少片油田

例如输入

1 1
*
3 5
**@**
*@***
***@@
0 0

这种
*/

// 找到父节点
int getF(int x, int f[]) {
    return x==f[x]?x:f[x] = getF(f[x]);
}

int jc[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

int youtian() {
    int n, m;
    
    while (scanf("%d%d",&n, &m)!=EOF)
    {
        if (n==0 && m == 0) break;
        char s[n][m]; // 初始化存储字符的数组
        for (int a = 0; a < n; ++a) {
            scanf("%s", &s[a]);
        }
        int cnt = n * m; // 代表有多少个通量 每次判断对这个树木进行减少
        // 初始化并查集的存储数组
        int f[cnt];
        for (int t = 0; t < cnt; ++t) {
            f[t] = t; // 初始化自己为自己的父节点
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m ;++j) {
                if (s[i][j] == '*') {
                    cnt--;
                } 
                else {
                    for (int k = 0; k < 8; ++k) {
                        int nx = i + jc[k][0];
                        int ny = j + jc[k][1];
                        if (nx >= 0 && nx < n && ny >=0 && ny < m && s[nx][ny] == '@') {
                            int fx = getF(i*m+j, f);
                            int fy = getF(nx*m+ny, f);
                            if (fx != fy) {
                                cnt--;
                                f[fx] = fy;
                            }
                        }
                    }
                }
            }
        }
        printf("%d", cnt);
    }
    return 0;
}
