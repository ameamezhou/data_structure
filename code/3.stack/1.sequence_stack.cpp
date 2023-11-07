#include <iostream>

#define MaxSize 10
typedef struct {
	ElemType data[MaxSize];
	int top;
} SqStack;

void InitStack(SqStack &S) {
	S->top = -1;   // 不能指向0 因为没有数据
}

void testStack() {
	SqStack S;
	InitStack(S);
}

// 新元素入栈
bool Push(SqStack& S, ElemType x) {
	if (S.top == MaxSize - 1)
		return false;
	S.top = S.top + 1;
	S.data[S.top] = x;
	// 上面的内容可以写为 S.data[++S.top] = x 两句合为一句
	return true;
}

// 出栈
bool Pop(SqStack& S, ElemType& x) {
	if (S.top == -1)
		return false;
	x = S.data[S.top];
	S.top = S.top - 1;
	// x = S.data[S.top--];
	return true;
} 

// 读取栈顶元素
bool GetTop(SqStack S, ElemType &x) {
	if (S.top == -1)
		return false;
	x = S.data[S.top];
	return true;
}

///////// 共享栈 //////////////////
typedef struct {
	ElemType data[MaxSize];
	int top0, top1;
} ShareSqStack;

void InitShareStack(ShareSqStack& S) {
	S.top0 = -1;
	S.top1 = MaxSize;
}

// 通过定义一个只能从头节点进行插入删除的单链表构建一个单链表
typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}LNode, *LiStack;

// 不带头节点的链栈/////////////////////////////////////
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