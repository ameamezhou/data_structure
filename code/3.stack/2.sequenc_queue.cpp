#include <iostream>

#define MaxSize 10;
typedef struct {
	ElemType data[MaxSize];
	int front, rear;
}SqQueue;

// ��ʼ������
void InitQueue(SqQueue& Q) {
	Q.rear = Q.front = 0;
}

void testQueue() {
	SqQueue Q;
	InitQueue(Q)
}

// �п�
bool QueueEmpty(SqQueue Q) {
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}

// ���  ֱ���뵽�Ľⷨ  ����Ҫ���ǵ���ͷ�����  ������������дһ���Ա�
bool EnQueue_error(SqQueue& Q, ElemType x) {
	if (Q.rear == MaxSize)
		return false;
	Q.data[Q.rear] = x;
	Q.rear++;
	return true;
}
// ȡ��֮��ͻ�������֮�����»ص���ͷ
bool EnQueue(SqQueue& Q, ElemType x) {
	if ((Q.rear + 1) % MaxSize == Q.front) // �ж�βָ�����һ��λ���ǲ��Ǿ���ͷָ��
		return false;
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MaxSize;
	return true;
}

// ���Ӳ���
bool DeQueue(SqQueue& Q, ElemType& x) {
	if (Q.rear  == Q.front) // �ж�βָ�����һ��λ���ǲ��Ǿ���ͷָ��
		return false;
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	return true;
}

// ��ö�ͷԪ��
bool DeQueue(SqQueue Q, ElemType& x) {
	if (Q.rear == Q.front)
		return false;
	x = Q.data[Q.front];
	return true;
}

// ����ռ��˷�����
typedef struct {
	ElemType data[MaxSize];
	int front, rear;
	int size;
}SqQueue1;
// ��size���ж϶ӿն���������  easy

/// ���е���ʽʵ�� ////////////
typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}LinkNode;

typedef struct {
	LinkNode* front, * rear;
}LinkQueue;

// ======================== ��ͷ�ڵ� ================
void initQueue(LinkQueue &Q) {
	// ͷβ��ָ��ͷָ��
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}

void testLinkQueue() {
	LinkQueue Q;
	initQueue(Q);
}

// ���
void EnQueue(LinkQueue& Q, ElemType x) {
	LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
}

// ����
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

// ======================== ����ͷ�ڵ� ================
void initQueueNoHead(LinkQueue& Q) {
	// ͷβ��ָ��NULL
	Q.front = Q.rear = NULL;
}

bool IsEmpty(LinkQueue Q) {
	if (Q.front == NULL)
		return true;
	else
		return false;
}

// ���
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

// ����
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