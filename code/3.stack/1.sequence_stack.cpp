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

///////// ����ջ //////////////////
typedef struct {
	ElemType data[MaxSize];
	int top0, top1;
} ShareSqStack;

void InitShareStack(ShareSqStack& S) {
	S.top0 = -1;
	S.top1 = MaxSize;
}

// ͨ������һ��ֻ�ܴ�ͷ�ڵ���в���ɾ���ĵ�������һ��������
typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}LNode, *LiStack;

// ����ͷ�ڵ����ջ/////////////////////////////////////
bool InitNoHeadLinkStack(LiStack &S){
	S = NULL;
	return true;
}

bool InsertNoHeadLinkStack(LiStack& S, ElemType e) {
	LNode* p = (LNode*)malloc(sizeof(LNode));
	if (p == NULL)
		return false;
	p = S->next;
	S->data = e;
	S->next = p;
	return true;
}

bool DeleteNoHeadLinkStack(LiStack& S, ElemType &e) {
	LNode* p = S->next;
	e = S.data;
	S->next = p->next;
	free(p);
	return true;
}