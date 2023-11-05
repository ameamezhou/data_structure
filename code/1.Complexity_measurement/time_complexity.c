void loveYou(int n) {
	int i = 1;
	while (i <= n) {
		i++;
		printf("I love you %d", i)
	}
}

int main() {
	loveYou(3000);
}
// ʱ�临�Ӷ�Ϊ T(n) = O(n)

// T1(n) = 3n + 3
// T2(n) = n^2 + 3n + 10000 
// T3(n) = n^3 + n^2 + 100n +19999
// ʱ�临�Ӷȷֱ�Ϊ O(n) O(n^2) O(n^3)

// �ӷ����򣺶������ ֻ������ߴ���
// �˷����򣺱������к�n����صĽ��
//
// �����Ƚϣ�
// O(1) < O(log.2(n)) < O(n) < O(nlog.2(n)) < O(n^2) < O(n^3) < O(2^n) < O(n!) < O(n^n)

void test(int n) {
	int i = 1;
	while (i <= n) {
		i = i * 2;
		printf("i love you %d\n", i)
	}
}
// ָ��������  T(n) = O(log.2(n))

void test1(int flag[], int n) {
	printf("111111\n");
	for (int i = 0; i < n; i++) {
		if (flag[i] == n) {
			printf("find num %d \n", n);
			break
		}
	}
}
// flag �������������� 1-n��Щ��
// ������õ������������  O(1)  O(n)
// ����ƽ�����  Ԫ��������һ��λ�õĸ�������ͬ�� ��ô����ҲΪ O(n)
// �����㷨��ʱ�临�Ӷȵ�ʱ���ǲ�������������  ����Ҫ����������ƽ�����
// 

