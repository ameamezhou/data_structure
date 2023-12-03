// 实现并查集
#include <bits/stdc++.h>

using namespace std;
// 初始化一个并查集的存储数组
#define N 100

int flag[N];

void dsuInit(int n){
    for (int i = 0; i < n; ++i) {
        flag[i] = i;  // 初始化将每个点看作自己的顶头上司
    }
}

int findHead(int index) {  // 找到 index 这个节点的父节点
    int iHead = flag[index];
    while (iHead != flag[iHead]) {
        iHead = flag[iHead];  // 有可能是 1 -> 2 -> 3 -> 4 -> 4 这么一个流程，1的父节点其实是4，所以我们要一直找到4这个结点
    }
    flag[index] = iHead; // 为了优化下次查找，我们就在这里修改它的父节点信息，并降低树的高度
    return flag[index];
}

bool test(int a, int b){  // 查看是否存在环
    int aHead = findHead(a);
    int bHead = findHead(b);
    return aHead == bHead;
}

void merge(int a, int b){
    // 存在环就跳过，进行下一次判断
    if (!test(a, b)) {
        int aHead = findHead(a);
        int bHead = findHead(b);
        flag[aHead] = bHead;
    }
}