#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int maxSize;
    int length;
    int *data;
} SqList;

SqList Create(int maxSize, int length){
    SqList L;
    L.data = (int*)malloc(sizeof(int)*maxSize);
    
    // malloc 会返回 void * 类型的指针，这里用 int *进行强制转换并赋值给L.data
    
    L.length = length;
    L.maxSize = maxSize;
    // 给顺序表空间赋值
    for (int i = 0; i < L.length; i++)
        scanf("%d", &L.data[i]);
    
    return L;
}

int FindIndex(SqList L, int data){
    for (int i = 0; i < L.length; i++){
        if (L.data[i] == data){
            return i;
        }
    }

    return -1;
}

int main(){
    // int data;
    // char c;
    // scanf("%d %c", &data, &c);
    // printf("%d%c", data, c);
    SqList L = Create(10, 3);
    for (int i = 0; i < L.length; i++)
        printf("%d", L.data[i]);

    return 0;
}

bool Delete(SqList &L, int i, int &x){
    if (i < 1 || i > L.length)
        return false;
    x = L.data[i-1];
    for (int j = L.length; i < j; i++)
		L.data[i-1] = L.data[i];
    L.length--;
    return true;
}

// 在某个元素后面插入
bool Insert(SqList &L , int pos, int data){
    if(pos<0||pos >= L.length)
        return false;
    if (L.length == L.maxSize){
        int *p = (int *)realloc(L.data, sizeof(int)*L.maxSize*2);
        L.data = p;
        L.maxSize *= 2;
    }
    for (int i = L.length-1; i>=pos; i--){
        L.data[i+1] = L.data[i];
    }
    L.data[pos+1] = data;
    L.length++;
    return true;
}

SqList Merge(SqList LA, SqList LB) {
    SqList L;
    int *p = (int *)realloc(LA.data, sizeof(int)*(LA.length + LB.length)>LA.maxSize?LA.length+LB.length:LA.maxSize);

    LA.data = p;
    for (int i=0; i <LB.length; i++) {
        if (FindIndex(LA, LB.data[i]) == -1)
            LA.data[LA.length++] = LB.data[i];
    }
    LA.maxSize = (LA.length + LB.length)>LA.maxSize?LA.length+LB.length:LA.maxSize;
    return LA;
}

// 删除升序顺序表的多余元素
bool DeleteRepeatedElem(SqList &L) {
    if (L.length == 0)
        return false;
    int length = 1;
    for (int i = 1; i< L.length; i++) {
        if (L.data[i]!=L.data[length - 1])
        {
            L.data[length++] = L.data[i];
        }
    }
    return true;
}

// 合并升序顺序表 LA LB
SqList Merge2(SqList LA, SqList LB) {
    SqList LC;
    LC.data = (int *)malloc(sizeof(int)*(LA.length+LB.length));
    LC.length = 0;
    LC.maxSize = LA.length+LB.length;
    int i = 0, j = 0;
    int k = 0;
    while (i < LA.length && j < LB.length) {
        if (LA.data[i] >= LB.data[j]){
            LC.data[k] = LB.data[j];
            j++;
        } else{
            LC.data[k] = LA.data[i];
            i++;
        }
         k++;
    }
    while (i < LA.length) {
        LC.data[k++] = LA.data[i++];
    }
    while (j < LB.length) {
        LC.data[k++] = LB.data[j++];
    }
    LC.length = k;
    return LC;

}