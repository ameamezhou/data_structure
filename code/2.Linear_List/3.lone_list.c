
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

// ����ͷ���ĵ�����
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

// �ж��Ƿ�Ϊ��
bool Empty(LinkList L) {
	if (L == NULL)
		return true;
	else
		return false;
}

//////////////////////////  ��ͷ���ĵ�����
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

// �ж��Ƿ�Ϊ��
bool Empty(LinkList L) {
	if (L->next == NULL)
		return true;
	else
		return false;
}

/// ���߱Ƚ�  ����ͷ�ڵ�д����ظ��鷳��
// ���ڵ�һ�����ݽڵ�ͺ������ݽڵ�Ĵ�����Ҫ�õ���ͬ�Ĵ����߼�
// �Կձ�ͷǿձ�Ĵ�����Ҫ�ò�ͬ�Ĵ����߼�
//