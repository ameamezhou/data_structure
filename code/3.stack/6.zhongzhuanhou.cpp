#include <bits/stdc++.h>
using namespace std;

string inToPost(string s){
    string ans;
    stack<char>op; // 一个字符栈
    for (int i=0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') ans+=s[i];
        else {
            if (s[i] == '^') {
                while(!op.empty()&&op.top() == '^') {
                    ans.push_back(op.top());
                    op.pop();
                }
            }
            else if (s[i] == '*' || s[i] == '/') {
                while (!op.empty() && op.top() != '+' && op.top() != '-') {
                    ans.push_back(op.top());
                    op.pop();
                }
            }
            else {
                while (!op.empty()) {
                    ans.push_back(op.top());
                    op.pop();
                }
            }
            op.push(s[i]);
        }
    }
    while (!op.empty()) {
        ans.push_back(op.top());
        op.pop();
    }
    return ans;
}


// 涉及括号的中缀转后缀
// 直接设置一下各个运算符的优先级
int id(char c) {
    if (c=='(') return 1;
    if (c == '+' || c == '-') return 3;
    if (c == '*' || c == '/') return 5;
    if (c == '^') return 7;
    return 9;
}

int od(char c) {
    if (c=='(') return 7;
    if (c == '+' || c == '-') return 2;
    if (c == '*' || c == '/') return 4;
    if (c == '^') return 6;
    return 1;
}

string InToPost(string s){
    string ans;
    stack<char> op;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            ans+=s[i];
        }
        else {
            if (s[i] == ')'){
                while (!op.empty() && op.top() != '(') {
                    ans.push_back(op.top());
                    op.pop();
                }
                op.pop();
            }
            else {
                while (!op.empty() && id(op.top()) > od(s[i])) {
                    ans.push_back(op.top());
                    op.pop();
                }
                op.push(s[i]);
            }
        }
    }
    while (!op.empty()) {
        ans.push_back(op.top());
        op.pop();
    }
    return ans;
}


int main(){
    string s;
    while (cin>>s) cout << InToPost(s) << endl;
    return 0;
}