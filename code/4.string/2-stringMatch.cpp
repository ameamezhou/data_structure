#include <iostream>

#define MaxLen 255;
// 字符串的朴素匹配
typedef struct {
	char ch[MaxLen];
	int length;
}SString;
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
// 其实就是string的index。和朴素匹配的逻辑是一摸一样的  这里一定要记住

// 直接通过数组下标实现朴素算法
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
// 最差时间复杂度 O(m*n)

// KMP 算法
// 算法实现
int KMPMatch(SString S, SString T, int next[]) {
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length) {
		if (j==0 || S.ch[i] == T.ch[i]) {
			++i;
			++j;
		}
		else {
			j = index[j];
		}
	}
	if (j > T.length)
		return i - T.length;
	else
		return 0;
}
// 最差时间复杂度 O(m + n)