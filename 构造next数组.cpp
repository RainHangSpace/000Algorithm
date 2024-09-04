#include <string>
#include <iostream>
#include <vector>
using namespace std;
void getNext(vector<int>& next, const string& s) {
	int pre = 0;//指向前缀的最后一个元素
	int post = 1;//指向后缀的最后一个元素
	next[0] = -1;
	next[1] = 0;
	while (post < s.size()) {//next要比s的容量大1，这里上限值选择s的容量
		if (pre == -1 || s[pre] == s[post]) {//pre=-1则直接让next[post] = 0 即可。
			next[post + 1] = pre + 1;//next[post+1]记录的是post所指数组公共前后缀的长度——长度在作下标时正好是公共前缀的后面一个元素
			++pre;
			++post;
		}
		else {
			pre = next[pre];//若pre=0，则s[post] != s[0]，则next[0]=-1的值赋给pre。
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
			//cout << "从" << j << "退回到" << next[j] << "\n" << endl;
			j = next[j];//退到次长度的公共前后缀
			--i;	//如果j>0,就说明模板串里还有公共前后缀，还有裕量，所以这一次不需要post指针递增，
					//而是需要在下一个循环比较新的公共前后缀能不能用
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

