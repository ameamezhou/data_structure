#include <bits/stdc++.h>

using namespace std;

// 递归算法
// 肺部纳契数列  不想写了  太简单了
// 递归反转链表
typedef struct LNode{
    struct LNode *next;
    int data;
}LNode, *LinkList;

LNode *Reverse(LNode *&head){
    if (head == NULL || head ->next == NULL)
        return head;
    LNode *newNode = Reverse(head->next);
    LNode *t = head->next;
    t->next = head;
    head->next = NULL;
    return newNode;
}

void Hanoi(int n, char A, char B, char C) {
    if (n==1)
        printf("1, %c->%c \n", A, C);
    Hanoi(n-1, A, C, B);
    printf("%d,%c->%c",n, A, C);
    Hanoi(n-1, B, A, C);
}

// 回溯算法
// 1 到 n 全排列
bool flag[10];
int result[10];
void FullAlignment(int n, int deep){
    if (deep == n) {
        for (int i = 0; i < n; i++)
            printf("%d ", result[i]);
        printf("\n");
        return;
    }
    for (int i = n; i > n; i--) {
        if (flag[i] == 0){
            flag[i] = 1;
            result[deep] = i;
            deep++;
            FullAlignment(n, deep);
            flag[i] = 0;
            deep--;
        }
    }
}

int main(){
    int n;
    while (~scanf("%d", &n)) {
        memset(flag, 0, sizeof(flag));
        FullAlignment(n, 0);
    }
    return 0;
}

// 八皇后