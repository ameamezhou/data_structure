// ��λ����� ��ͷ�ڵ�
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

// �ж��Ƿ�Ϊ��
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


// ��λ����� ����ͷ�ڵ�
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

// �ж��Ƿ�Ϊ��
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


// ������  ָ���ڵ�ĺ��
bool InsertNextNode(LNode* p, ElemType e) {
	if��p == NULL��
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)
		return false;

	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}