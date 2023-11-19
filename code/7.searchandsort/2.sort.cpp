// 直接插入排序  有哨兵

void InsertSort(int L[], int n) {
    int i, j;
    for (i = 2; i < n; ++i) {
        if (L[i] < L[i-1]){
            L[0] = L[i];
            for (j = i-1; L[j] > L[0]; --j)
                L[j+1] = L[j];
            L[j+1] = L[0];
        }
    }
}

// 直接插入排序  无哨兵

void InsertSort(int L[], int n) {
    int i, j, tmp;
    for (i = 1; i < n; ++i) {
        if (L[i] < L[i-1]){
            tmp = L[i];
            for (j = i-1; L[j] > L[0]; --j)
                L[j+1] = L[j];
            L[j+1] = tmp;
        }
    }
}

// 折半插入
void halfSort(int L[], int n) {
    int l,r,mid;
    for(int i = 2; i < n; ++i) {
        l = 1; 
        r = i-1; 
        L[0] = L[i];
        while (l <= r) {
            mid = (l+r)/2;
            if (L[mid] >= L[0])
                r = mid - 1;
            else
                l = mid + 1;
        }
        for (int j = i-1; j > r; r--) {
            L[j+1] = L[j];
        }
        L[r+1] = L[0];
    }
}

// 希尔排序
void shellSort(int A[], int n) {
    int dk, i, j;
    for (dk = n/2; dk >= 1; dk = dk/2) {
        for(i = dk+1; i <= n; i++) {
            if (A[i] < A[i-dk]) {
                A[0] = A[i];
                for (j = i-dk; j>0 && A[0] < A[j]; j -= dk) {
                    A[j+dk] = A[j];
                }
                A[j+dk] = A[0];
            }
        }
    }
}

// 冒泡排序
void bubbleSort(int A[], int n) {
    int temp;
    for (int i = 0; i < n-1; i++) {
        bool flag = false;
        for (int j = n - 2; j >= i; j--) {
            if (A[j+1] < A[j]) {
                swap(A[j], A[j+1]);
                flag = true;
            }
        }
        if (!flag) {
            return;
        }
    }
}

// 快速排序
void quickSort(int A[], int head, int rear) {
    if (head < rear) {
        int pivot = A[head], h = head, r = rear;
        while (h < r) {
            while (h < r && A[r] > pivot) {
                r--;
            }
            A[h] = A[r];
            while (h < r && A[h] < pivot) {
                h++;
            }
            A[r] = A[h];
        }
        A[h] = pivot;
        quickSort(A, head, h - 1);
        quickSort(A, r + 1, rear);
    }
}

// 简单选择排序
void selectSort(int A[], int n) {
    int min;
    for (int i = 0; i < n - 1; ++i) {
        min = i;
        for (int j = i+1; j < n; j++) {
            if (A[min] > A[j]) {
                min = j;
            }
        }
        if (min != i)
            swap(A[min], A[i]);
    }
}

// 堆排序 其实就是先构建大根堆  然后进行交换排序
void buildLogic(int A[], int k, int n){
    A[0] = A[k];  // 用A[0]来存储根的值
    for (int i = 2*k; i < n; i *= 2){
        if(A[i] <= A[i+1]) {
            i++;
        }
        if (A[k] >= A[i]) break;
        else {
            A[k] = A[i];
            k = i;
        }
    }
    A[k] = A[0];
}

void buildBigHeap(int A[], int n){
    for (int i = n/2; i > 0; i--) {
        buildLogic(A, i, n);
    }
}


void heapSort(int A[], int n) {
    buildBigHeap(A, n);
    for (int i = n; i > 1; i--) {
        swap(A[i], A[1]);
        buildBigHeap(A, 1, i-1);
    }
}


// 二路归并排序
int *B = (int *)malloc(sizeof(int)*n);

void mergeSort(int A[], int head, int rear){
    if (head < rear) {
        int mid = (head + rear) / 2;
        int i, j, k;
        mergeSort(A, head, mid);
        mergeSort(A, mid+1, rear);
        for (i = head; i < rear; ++i) {
            B[i] = A[i];
        }
        for (i = head, j = mid+1, k = head; i <= mid && j <= rear; k++) {
            if (B[i] > B[j]) {
                A[k] = B[j++];
            }else {
                A[k] = B[i++];
            }
        }
        while (i <= mid) {
            A[k++] = B[i++];
        }
        while (j <= rear) {
            A[k++] = B[j++];
        }
    }
}

// 基数排序
#include <bits/stdc++.h>
using namespace std;
queue<int> q[10];
int A[10005];
/*
for ()
*/

void distribute(int A[], int n, int b) {
    int y = 1;
    while (b--) {
        y *= 10;
    }
    for (int i = 0; i <n; i++) {
        q[A[i]/y%10].push(A[i]);
    }
}

void collect(int A[]){
    int loc = 0;
    for (int i=0; i < 10; i++) {
        while (!q[i].empty()){
            A[loc++] = q[i].front();
            q[i].pop();
        }
    }
}

int main2(){
    int n, maxNum = -1e9;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        maxNum = max(A[i], maxNum);
    } 
    int b = 1;
    while (maxNum) {
        distribute(A, n, b);
        collect(A);
        maxNum /= 10;
        ++b;
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}
