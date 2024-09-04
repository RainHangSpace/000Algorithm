//在利用Euclid原理求解gcd拓展算法时，主要用到的思想是递归，而如何递归呢，递归的思路是什么呢？
//首先是将问题一点点拆分成子问题，然后解决最小的子问题开始回退递归，从而解决原问题
//那么就要考虑最小的问题是什么：这里设定当a,b中b为0时，那么a就是最大公倍数，那么贝祖系数就是1,0
//确定了最小的问题之后，寻找递推逻辑，然后得出递推公式，结束。
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using eleType = pair<int, pair<int, int>>;
eleType Extended_gcd ( int a, int b) {
	if (b == 0) {
		return { a, {1, 0} };
	}
	eleType cur = Extended_gcd( b, a % b);
	int x = cur.second.second;
	int y = cur.second.first - (a / b) * x;
	cout << a << " * " << cur.second.first << " + " << b << " * " << cur.second.second << " = " << cur.first << "\n";
	return { cur.first, {x, y} };
}

int main() {
	eleType res;
	int a = 2336, b = 1314;
	res = Extended_gcd(2336, 1314);
	cout << a << " * " << res.second.first << " + " << b << " * " << res.second.second << " = " << res.first;
	cout << endl;
	return 0;
}
