#include <iostream>

#define MaxSize 10;
typedef struct {
	ElemType data[MaxSize];
	int front, rear;
}SqQueue;

// 初始化队列
void InitQueue(SqQueue& Q) {
	Q.rear = Q.front = 0;
}

void testQueue() {
	SqQueue Q;
	InitQueue(Q)
}

// 判空
bool QueueEmpty(SqQueue Q) {
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}

// 入队  直接想到的解法  但是要考虑到队头会出队  所以这里重新写一个对比
bool EnQueue_error(SqQueue& Q, ElemType x) {
	if (Q.rear == MaxSize)
		return false;
	Q.data[Q.rear] = x;
	Q.rear++;
	return true;
}
// 取余之后就会在满了之后重新回到队头
bool EnQueue(SqQueue& Q, ElemType x) {
	if ((Q.rear + 1) % MaxSize == Q.front) // 判断尾指针的下一个位置是不是就是头指针
		return false;
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MaxSize;
	return true;
}

// 出队操作
bool DeQueue(SqQueue& Q, ElemType& x) {
	if (Q.rear  == Q.front) // 判断尾指针的下一个位置是不是就是头指针
		return false;
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	return true;
}

// 获得队头元素
bool DeQueue(SqQueue Q, ElemType& x) {
	if (Q.rear == Q.front)
		return false;
	x = Q.data[Q.front];
	return true;
}

// 解决空间浪费问题
typedef struct {
	ElemType data[MaxSize];
	int front, rear;
	int size;
}SqQueue1;
// 用size来判断队空队满就行了  easy

/// 队列的链式实现 ////////////
typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}LinkNode;

typedef struct {
	LinkNode* front, * rear;
}LinkQueue;

// ======================== 带头节点 ================
void initQueue(LinkQueue &Q) {
	// 头尾都指向头指针
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}

void testLinkQueue() {
	LinkQueue Q;
	initQueue(Q);
}

// 入队
void EnQueue(LinkQueue& Q, ElemType x) {
	LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
}

// 出队
bool DeQueue(LinkQueue& Q, ElemType& x) {
	if (Q.front == Q.rear)
		return false;
	LinkNode* p= Q.front->next;
	x = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return true;
}

// ======================== 不带头节点 ================
void initQueueNoHead(LinkQueue& Q) {
	// 头尾都指向NULL
	Q.front = Q.rear = NULL;
}

bool IsEmpty(LinkQueue Q) {
	if (Q.front == NULL)
		return true;
	else
		return false;
}

// 入队
void EnQueue(LinkQueue& Q, ElemType x) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	if (Q.front == NULL) {
		Q.front = s;
		Q.rear = s;
	}
	else {
		Q.rear->next = s;
		Q.rear = s;
	}
}

// 出队
bool DeQueue(LinkQueue& Q, ElemType& x) {
	if (Q.front == Q.rear == NULL)
		return false;
	LinkNode* p = Q.front;
	x = p->data;
	Q.front = p->next;
	if (Q.rear == p) {
		Q.rear = NULL;
		Q.front = NULL;
	}
	free(p);
	return true;
}