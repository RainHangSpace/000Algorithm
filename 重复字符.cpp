#include <string>
#include <iostream>
#include <vector>
//ע�������������ظ��ַ���Ŀ֮�⻹������һ���β��������õ�����
using namespace std;
class Solution {
public:
	//����һ���ַ�����������һ�����ַ����в��ظ����ַ������أ������ظ����򷵻ش�дA
	char getFirstNonDuplicateChar(const string &s) {
		int hash[26] = {};
		int j = 0;
		for (int i = 0; i < s.size(); ++i) {
			++hash[s[i] - 'a'];
			while (j < s.size() && hash[s[j] - 'a'] > 1)++j;
		}
		return j < s.size() ? s[j] : 'A';//��ȫ�ظ��򷵻ش�дA
		/*for (auto i : hash) {
			cout << i << ' ' << endl;
		}*/
	}
};
void test_v(vector<int>& a) {
	/*for (auto i : a) {
		++i;
	}*///������ѭ�������β��ǲ������ã�������ı�ԭ�е����������ֵ
	for (auto i = a.begin(); i != a.end(); ++i) {
		++*i;
	}//�õ������Żᵱ�β�������ʱֱ�Ӹı�ԭ���������ֵ
}
int main() {
	vector<int> b = {1, 2, 3};
	vector<int>& c = b;
	Solution A;
	string s("aaaazhangyuhanzgyu");
	char a = A.getFirstNonDuplicateChar(s);
	cout << a << endl;
	//�����Ǽ���һ�����β�Ϊ���ö�ԭ���ݵ�Ӱ��Ĳ���
	test_v(c);
	for (auto i : b)cout << i;
	cout << endl;
	test_v(b);
	for (auto i : b)cout << i;
	cout << endl;
}