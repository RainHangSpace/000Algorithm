#include <string>
#include <iostream>
#include <vector>
using namespace std;
void getNext(vector<int>& next, const string& s) {
	int pre = 0;//ָ��ǰ׺�����һ��Ԫ��
	int post = 1;//ָ���׺�����һ��Ԫ��
	next[0] = -1;
	next[1] = 0;
	while (post < s.size()) {//nextҪ��s��������1����������ֵѡ��s������
		if (pre == -1 || s[pre] == s[post]) {//pre=-1��ֱ����next[post] = 0 ���ɡ�
			next[post + 1] = pre + 1;//next[post+1]��¼����post��ָ���鹫��ǰ��׺�ĳ��ȡ������������±�ʱ�����ǹ���ǰ׺�ĺ���һ��Ԫ��
			++pre;
			++post;
		}
		else {
			pre = next[pre];//��pre=0����s[post] != s[0]����next[0]=-1��ֵ����pre��
		}
	}
}
int strStr(const string& haystack, const string& needle) {
	vector<int> next(needle.size() + 1, 0);
	getNext(next, needle);
	int j = 0;
	for (int i = 0; i < haystack.size(); ++i) {
		while (haystack[i] == needle[j]) {
			++j;
			++i;
			if (j == needle.size()) return i - needle.size();
		}
		if (j > 0) {
			//cout << "��" << j << "�˻ص�" << next[j] << "\n" << endl;
			j = next[j];//�˵��γ��ȵĹ���ǰ��׺
			--i;	//���j>0,��˵��ģ�崮�ﻹ�й���ǰ��׺������ԣ����������һ�β���Ҫpostָ�������
					//������Ҫ����һ��ѭ���Ƚ��µĹ���ǰ��׺�ܲ�����
		}	
	}
	return -1;

}
void main() {
	string s = "abaababaababaab";
	vector<int> next(s.size()+1, 0);
	cout << -1 << " ";
	for (auto i : s) {
		cout << i << " ";
	}
	cout << '\n';
	getNext(next, s);
	for (auto i : next) {
		cout << i << " ";
	}
	cout << "\n" << strStr(s, "aabbaabb") << endl;

}

