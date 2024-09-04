//������Euclidԭ�����gcd��չ�㷨ʱ����Ҫ�õ���˼���ǵݹ飬����εݹ��أ��ݹ��˼·��ʲô�أ�
//�����ǽ�����һ����ֳ������⣬Ȼ������С�������⿪ʼ���˵ݹ飬�Ӷ����ԭ����
//��ô��Ҫ������С��������ʲô�������趨��a,b��bΪ0ʱ����ôa������󹫱�������ô����ϵ������1,0
//ȷ������С������֮��Ѱ�ҵ����߼���Ȼ��ó����ƹ�ʽ��������
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
