#define MaxSize 10
struct Node {
	ElemType data;
	int next;     // 下一个元素的数组下标
}

void testSLinkList() {
	struct Node a[MaxSize];
}

// 另一种写法
#define MaxSize 10
typedef struct Node {
	ElemType data;
	int next;     // 下一个元素的数组下标
} SLinkList[MaxSize];
// 这种写法等价于
#define MaxSize 10
struct Node {
	ElemType data;
	int next;     // 下一个元素的数组下标
};

typedef struct Node SLinkList[MaxSize];
// 可以用 SLinkList定义 一个长度为 MaxSize 的 Node 数组

void testSLinkList() {
	SLinkList a;
}