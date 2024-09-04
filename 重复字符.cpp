#include <string>
#include <iostream>
#include <vector>
//注：这里除了完成重复字符题目之外还测试了一下形参中用引用的作用
using namespace std;
class Solution {
public:
	//给定一个字符串，检索第一个在字符串中不重复的字符并返回，若都重复，则返回大写A
	char getFirstNonDuplicateChar(const string &s) {
		int hash[26] = {};
		int j = 0;
		for (int i = 0; i < s.size(); ++i) {
			++hash[s[i] - 'a'];
			while (j < s.size() && hash[s[j] - 'a'] > 1)++j;
		}
		return j < s.size() ? s[j] : 'A';//若全重复则返回大写A
		/*for (auto i : hash) {
			cout << i << ' ' << endl;
		}*/
	}
};
void test_v(vector<int>& a) {
	/*for (auto i : a) {
		++i;
	}*///用上述循环无论形参是不是引用，都不会改变原有的向量里面的值
	for (auto i = a.begin(); i != a.end(); ++i) {
		++*i;
	}//用迭代器才会当形参是引用时直接改变原有向量里的值
}
int main() {
	vector<int> b = {1, 2, 3};
	vector<int>& c = b;
	Solution A;
	string s("aaaazhangyuhanzgyu");
	char a = A.getFirstNonDuplicateChar(s);
	cout << a << endl;
	//这里是加了一个对形参为引用对原数据的影响的测试
	test_v(c);
	for (auto i : b)cout << i;
	cout << endl;
	test_v(b);
	for (auto i : b)cout << i;
	cout << endl;
}