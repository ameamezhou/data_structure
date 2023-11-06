#include <iostream>

#define MaxSize 10
typedef struct {
	ElemType data[MaxSize];
	int top;
} SqStack;

void InitStack(SqStack &S) {
	S->top = -1;   // ����ָ��0 ��Ϊû������
}

void testStack() {
	SqStack S;
	InitStack(S);
}

// ��Ԫ����ջ
bool Push(SqStack& S, ElemType x) {
	if (S.top == MaxSize - 1)
		return false;
	S.top = S.top + 1;
	S.data[S.top] = x;
	// ��������ݿ���дΪ S.data[++S.top] = x �����Ϊһ��
	return true;
}

// ��ջ
bool Pop(SqStack& S, ElemType& x) {
	if (S.top == -1)
		return false;
	x = S.data[S.top];
	S.top = S.top - 1;
	// x = S.data[S.top--];
	return true;
} 

// ��ȡջ��Ԫ��
bool GetTop(SqStack S, ElemType &x) {
	if (S.top == -1)
		return false;
	x = S.data[S.top];
	return true;
}

