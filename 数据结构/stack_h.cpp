//≤‚ ‘stack_h_h
#include"stack_h.h"
#include<iostream>
using namespace std;
int main() {
	istream& is(cin);
	string str;
	stack_h stack0;
	while (is >> str && !stack0.full()) {
		stack0.push(str);
	}
	cout << "the size of stack0 is " << stack0.size() << endl;
	
	stack0.peek(str);
	cout << "peek:" << str << endl;
	stack0.pop(str);
	cout << "pop..." << endl;
	stack0.peek(str);
	cout << "peek:" << str << endl;

	int cnt;
	if (stack0.find("zhang"))
	{
		cout << "yes, there are the words zhang" << endl;
		cnt = stack0.count("zhang");
		cout << "cnt of zhang is " << cnt << endl;
	}
}