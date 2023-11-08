#include <iostream>

#define MaxLen 255;

typedef struct {
	char ch[MaxLen];
	int length;
}SString;

// ����������ʵ��
// ���Ӵ�
bool SubString(SString& Sub, SString S, int pos, int len) {
	// �жϷ�Χ�Ƿ�Խ��
	if (pos + len - 1 > S.length)
		return false;
	for (int i = pos; i < pos + len; i++)
		Sub.ch[i - pos + 1] = S.ch[i];
	Sub.length = len;
	return ture
}

// �Ƚϴ�С
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

// ��̬����ʵ��  ����˳��洢 ////////////////////////////////////////







typedef struct {
	char* ch;
	int length;
}HString;

// �������ȷ���洢����chָ�򴮵Ļ���ַ

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
