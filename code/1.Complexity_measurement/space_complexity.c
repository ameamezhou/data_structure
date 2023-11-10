void test(int n) {
	int i = 1;
	while (i <= n) {
		i++;
		printf("111111%d", i);
	}
}
// 无论问题规模怎么变  算法运行所需要的内存空间都是固定的两  那么算法的空间复杂度 S(n) = O(1)
// S 就是 space

void test1(int n) {
	int flag[n];
	int i;
}
// 这里假设 int 类型占 4bit 那么总体内存空间为 4 + 4n + 4 = 4n + 8   空间复杂度为 O(n)

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
// 跟极限一样  取最大  O(n^2)

// 函数调用的时候也会导致内存开销的增加
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
// 每一次调用都会有 n 和 a b c 的存储，递归调用导致函数过多的开销，所以我们这个问题规模为n 那么空间复杂度也为 O(n)
// 空间复杂度一般就对应调用的深度
void lvU(int n) {
	int flag[n];
	// ...
	if (n > 1) {
		lvU(n - 1)
	};
	printf("count %d", n)
}
// 当调用的时候是会改变每次递归的所需空间的话  例如上所示  就要用等差数列求和，得到此次调用的空间复杂度为 O(n)