// 按位序插入 带头节点
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

bool InitList(LinkList& L) {
	L = (LNode*)malloc(sizeof(LNode));
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

bool ListInsert(LinkList& L, int i, ElemType e) {
	if (i < 1)
		return false;
	LNode* p;
	int j = 0;
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}


// 按位序插入 不带头节点
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

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

bool ListInsert(LinkList& L, int i, ElemType e) {
	if (i < 1)
		return false;
	if (i = 1)
	{
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = e;
		s->next = L;
		return true;
	}

	LNode* p;
	int j = 0;
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}


// 后插操作  指定节点的后插
bool InsertNextNode(LNode* p, ElemType e) {
	if（p == NULL）
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)
		return false;

	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}