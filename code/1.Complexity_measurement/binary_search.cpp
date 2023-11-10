#include <bits/stdc++.h>

using namespace std;
int binary_search(vector<int> a, int t) { // 二分查找
    int l = 0, r = a.size()-1;
    while (l <= r) {
        int m = (l+r)/2;
        if (a[m] == t) return m;
        else if (a[m]<t) l = m + 1;
        else r = m - 1;
    }
}