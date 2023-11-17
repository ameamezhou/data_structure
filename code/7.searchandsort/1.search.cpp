#include <bits/stdc++.h>

using namespace std;

// 升序的顺序表查找
int sqSearch(int L[], int n, int key){
    if (key < L[0]) {
        return -1;
    }
    if (key == L[0]){
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (key == L[i]) return i;
        if (key > L[i-1] && key < L[i]) return -1;
    }
    return -1;
}

// 二分查找
int halfSearch(int data[], int length, int key){
    int l = 0, r = length - 1, mid;

    while (l <= r) {
        mid = (l + r) / 2;
        if (data[mid]==key) {
            return mid;
        }
        else if (data[mid] > key) {
            r = mid-1;
        } else {
            l = mid +1;
        }
    }
    return -1;
}