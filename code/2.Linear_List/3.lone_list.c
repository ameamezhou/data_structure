
struct LNode {
	ElemType data;
	struct LNode* next;
};

struct LNode *p = (struct LNode*)malloc(sizeof(struct LNode));

typedef struct LNode LNode;
LNode* p = (LNode*)malloc(sizeof(LNode));

typedef struct NewLNode {
	ElemType data;
	struct NewLNode* next;
}NewLNode, *LinkList;

NewLNode* GetElem(LinkList L, int i) {
	int j = 1;
	LNode* p = L->next;
	if (i == 0)
		return L;
	if (i < 1)
		return NULL;
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	return p;
}

// 不带头结点的单链表
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, *LinkList;

bool InitList(LinkList& L) {
	L = NULL;
	return true;
}

void test() {
	LinkList L;
	InitList(L);
	//...
}

// 判断是否为空
bool Empty(LinkList L) {
	if (L == NULL)
		return true;
	else
		return false;
}

//////////////////////////  带头结点的单链表
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

bool InitList(LinkList& L) {
	L = (LNode *)malloc(sizeof(LNode));
	if (L == NULL)
		return false;
	L->next = NULL;
	return true;
}

void test() {
	LinkList L;
	InitList(L);
	//...
}

// 判断是否为空
bool Empty(LinkList L) {
	if (L->next == NULL)
		return true;
	else
		return false;
}

/// 两者比较  不带头节点写代码回更麻烦点
// 对于第一个数据节点和后续数据节点的处理需要用到不同的代码逻辑
// 对空表和非空表的处理需要用不同的代码逻辑
//