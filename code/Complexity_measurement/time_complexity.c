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
// 时间复杂度为 T(n) = O(n)

// T1(n) = 3n + 3
// T2(n) = n^2 + 3n + 10000 
// T3(n) = n^3 + n^2 + 100n +19999
// 时间复杂度分别为 O(n) O(n^2) O(n^3)

// 加法规则：多项相加 只保留最高此项
// 乘法规则：保留所有和n项相关的结果
//
// 常见比较：
// O(1) < O(log.2(n)) < O(n) < O(nlog.2(n)) < O(n^2) < O(n^3) < O(2^n) < O(n!) < O(n^n)

void test(int n) {
	int i = 1;
	while (i <= n) {
		i = i * 2;
		printf("i love you %d\n", i)
	}
}
// 指数递增型  T(n) = O(log.2(n))

void test1(int flag[], int n) {
	printf("111111\n");
	for (int i = 0; i < n; i++) {
		if (flag[i] == n) {
			printf("find num %d \n", n);
			break
		}
	}
}
// flag 数组中是乱序存放 1-n这些数
// 考虑最好的情况和最坏的情况  O(1)  O(n)
// 考虑平均情况  元素在任意一个位置的概率是相同的 那么概率也为 O(n)
// 评判算法的时间复杂度的时候是不考虑最好情况的  我们要考虑最坏情况和平均情况
// 

