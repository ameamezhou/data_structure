#include <iostream>

#define MaxLen 255;

typedef struct {
	char ch[MaxLen];
	int length;
}SString;

// 基本操作的实现
// 求子串
bool SubString(SString& Sub, SString S, int pos, int len) {
	// 判断范围是否越界
	if (pos + len - 1 > S.length)
		return false;
	for (int i = pos; i < pos + len; i++)
		Sub.ch[i - pos + 1] = S.ch[i];
	Sub.length = len;
	return ture
}

// 比较大小
int StrCompare(SString S, SString T) {
	for (int i = 1; i <= S.length && i <= T.length; i++) {
		if (S.ch[i] != T.ch[i])
			return S.ch[i] - T.ch[i];
	}
	return S.length - T.length;
}

int Index(SString S, SString T) {
	if (T.length > S.length)
		return 0;
	int i = 1;
	int n = S.length;
	int m = T.length;
	SString sub;
	while (i <= n - m + 1) {
		SubString(sub, S, i, m);
		if (StrCompare(sub, T) != 0) ++i;
		else
		{
			return i;
		}
	}
	return 0;
}

// 静态数组实现  定长顺序存储 ////////////////////////////////////////







typedef struct {
	char* ch;
	int length;
}HString;

// 按串长度分配存储区，ch指向串的基地址

void InitString() {
	HString S;
	S.ch = (char*)malloc(MaxLen * sizeof(char));
	S.length = 0
}

typedef struct {
	char ch;
	struct StringNode* next;
}StringNode, * String;


typedef struct {
	char ch[4];
	struct StringNode* next;
}StringNode, * String;
