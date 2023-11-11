#include <bits/stdc++.h>

using namespace std;

void tentotwo(int x){
    stack<int> s;
    while (x) {
        int k = x%2;
        s.push(k);
        x = x/2;
    }

    while (!s.empty()) {
        printf("%d", s.top());
        s.pop();
    }
    printf("\n");
}

bool judge(string s) {
    stack<char> st;
    for (int i = 0; i<s.size(); i++) {
        if (s[i]=='(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
        else{
            if (s.empty()) return false;
            if (s[i]==')' && st.top() == '(') st.pop();
            else if (s[i]==']' && st.top() == '[') st.pop();
            else if (s[i]=='}' && st.top() == '{') st.pop();
            else return false;
        }
    }
    if (!st.empty()) return false;

    return true;
}

int main(){
    string s;
    while(cin>>s){
        if (judge(s))
            puts("yes");
        else
            puts("no");
    }
    return 0;
}