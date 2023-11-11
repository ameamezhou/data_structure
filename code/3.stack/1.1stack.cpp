#include <bits/stdc++.h>

using namespace std;

#define MaxSize 10;
typedef struct stack{
    int a[10];
    int top;
}SqStack;

void InitStack(SqStack &s){
    s.top = -1;
}

void push(SqStack &s, int a) {
    s.top++;
    s.a[s.top] = a;
}

void pop(SqStack &s, int &x) {
    x = s.a[s.top];
    s.top--;
}

bool GetTop(SqStack s, int &x) {
    if (s.top == 0)
        return false;
    x = s.a[s.top-1];
    return true;
}


int main(){
    int a[100];
    int top = 0;

    return 0;
}