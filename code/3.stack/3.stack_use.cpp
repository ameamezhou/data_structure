#include <iostream>

// parenthesis matching  ����ƥ��

#define MaxSize 10;
typedef struct {
	char data[MaxSize];
	int top;
}SqStack;

void InitStack(SqStack& S) {
	S->top = -1;
}

bool StackEmpty(SqStack S) {
	if (S.top == -1)
		return true;
	else
		return false;
}

bool Push(SqStack& s, char x) {
	if (s.top == MaxSize - 1)
		return false;
	s.top = s.top + 1;
	s.data[s.top] = x;
	return true;
}

bool Pop(SqStack& s, char& x) {
	if StackEmpty(s)
		return false;
	x = s.data[s.top];
	s.top--;
	return true;
}

bool bracketCheck(char str[], int length) {
	SqStack s;
	InitStack(s);
	for (int i = 0; i < length; i++) {
		if (char[i] == '(' || char[i] == '[' || char[i] == '{') {
			if !Push(s, char[i]); {
				return false;
			}
		}else {
			if StackEmpty(s)
				return false;
			char p;
			Pop(s, p);
			if (p == '(' && char[i] != ')')
				return false;
			if (p == '[' && char[i] != '}')
				return false;
			if (p == '{' && char[i] != '}')
				return false;
		}
	}
	return true;
}

// ���ʽ�����ֵ�Ӧ��

// ��׺���ʽ
// ��׺ת��׺


// ��׺���ʽ

// ǰ׺���ʽ