#define MaxSize 10
struct Node {
	ElemType data;
	int next;     // ��һ��Ԫ�ص������±�
}

void testSLinkList() {
	struct Node a[MaxSize];
}

// ��һ��д��
#define MaxSize 10
typedef struct Node {
	ElemType data;
	int next;     // ��һ��Ԫ�ص������±�
} SLinkList[MaxSize];
// ����д���ȼ���
#define MaxSize 10
struct Node {
	ElemType data;
	int next;     // ��һ��Ԫ�ص������±�
};

typedef struct Node SLinkList[MaxSize];
// ������ SLinkList���� һ������Ϊ MaxSize �� Node ����

void testSLinkList() {
	SLinkList a;
}