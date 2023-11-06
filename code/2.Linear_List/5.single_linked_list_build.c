// ��ʼ��һ����ͷ�ڵ�ĵ�����

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

// ��λ����  β�巨
bool ListInsert(LinkList& L, int i, ElemType e) {
	if (i < 1)
		return false;
	LNode* p = L;
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


// ʵ��β�巨
LinkList List_tailInsert(LinkList& L) {
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	LNode* s, * r = L;
	scanf("%d", &x);
	while (x != -1) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;
	return L
}

// ʵ��ͷ�巨
LinkList List_headInsert(LinkList& L) {
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	scanf("%d", &x);
	while (x != -1) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}