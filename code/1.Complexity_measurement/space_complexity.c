void test(int n) {
	int i = 1;
	while (i <= n) {
		i++;
		printf("111111%d", i);
	}
}
// ���������ģ��ô��  �㷨��������Ҫ���ڴ�ռ䶼�ǹ̶�����  ��ô�㷨�Ŀռ临�Ӷ� S(n) = O(1)
// S ���� space

void test1(int n) {
	int flag[n];
	int i;
}
// ������� int ����ռ 4bit ��ô�����ڴ�ռ�Ϊ 4 + 4n + 4 = 4n + 8   �ռ临�Ӷ�Ϊ O(n)

void test2(int n) {
	int flag[n][n];
	int other[n];
	int i;
}
// O(n^2)

void test3(int n) {
	int flag[n][n];
	int other[n];
	int i;
}
// ������һ��  ȡ���  O(n^2)

// �������õ�ʱ��Ҳ�ᵼ���ڴ濪��������
void lvU(int n) {
	int a, b, c;
	// ...
	if (n > 1) {
		lvU(n - 1)
	};
	printf("count %d", n);
}

int main_forlvU() {
	lvU(5);
}
// ÿһ�ε��ö����� n �� a b c �Ĵ洢���ݹ���õ��º�������Ŀ���������������������ģΪn ��ô�ռ临�Ӷ�ҲΪ O(n)
// �ռ临�Ӷ�һ��Ͷ�Ӧ���õ����
void lvU(int n) {
	int flag[n];
	// ...
	if (n > 1) {
		lvU(n - 1)
	};
	printf("count %d", n)
}
// �����õ�ʱ���ǻ�ı�ÿ�εݹ������ռ�Ļ�  ��������ʾ  ��Ҫ�õȲ�������ͣ��õ��˴ε��õĿռ临�Ӷ�Ϊ O(n)