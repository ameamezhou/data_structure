#include <iostream>

#define MaxLen 255
// �ַ���������ƥ��
typedef struct {
	char ch[MaxLen];
	int length;
}SString;
// ���Ӵ�
bool SubString(SString& Sub, SString S, int pos, int len) {
	// �жϷ�Χ�Ƿ�Խ��
	if (pos + len - 1 > S.length)
		return false;
	for (int i = pos; i < pos + len; i++)
		Sub.ch[i - pos + 1] = S.ch[i];
	Sub.length = len;
	return true;
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
// ��ʵ����string��index��������ƥ����߼���һ��һ����  ����һ��Ҫ��ס

// ֱ��ͨ�������±�ʵ�������㷨
int SimpleMatch(SString S, SString T) {
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length) {
		if (S.ch[i] == T.ch[i]) {
			++i;
			++j;
		}
		else {
			i = i - j + 1;
			j = 1;
		}
	}
	if (j > T.length)
		return i - T.length;
	else
		return 0;
}
// ���ʱ�临�Ӷ� O(m*n)

// KMP �㷨
#include <bits/stdc++.h>
using namespace std;
vector<int> getNext(string t) {
	int i=0, j=-1, n =t.size();
	vector<int>Next(n+1);
	Next[0] = -1;
	while(i < n) {
		if(j == -1 || t[i] == t[j]) {
			++i; ++j;
			Next[i] = j;
		}
		else j = Next[j];
	}
	for (i = 0; i<n; i++) printf("%d ", Next[i]+1);
	printf("\n");
	return Next;
}
// �㷨ʵ��
int KMPMatch(SString S, SString T, int next[]) {
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length) {
		if (j==0 || S.ch[i] == T.ch[i]) {
			++i;
			++j;
		}
		else {
			j = next[j];
		}
	}
	if (j > T.length)
		return i - T.length;
	else
		return 0;
}
// ���ʱ�临�Ӷ� O(m + n)