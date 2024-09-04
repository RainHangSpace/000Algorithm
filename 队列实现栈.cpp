#include <queue>
#include <iostream>
#include <string>
using namespace std;
class MyStack {
public:
	queue<int> que;
	MyStack() {

	}
	void push(int x) {
		que.push(x);
	}
	int pop() {
		int que_size = que.size() - 1;
		while (que_size--) {
			que.push(que.front());
			que.pop();
		}
		int res = que.front();
		que.pop();
		return res;
	}
	int top() {
		return que.back();
	}
	bool empty() {
		return que.empty();
	}
};
int main() {
	MyStack stA;
	stA.push(1);
	stA.push(2);
	cout << stA.pop() << endl;
	cout << stA.top() << endl;
	stA.push(3);
	stA.push(4);
	stA.push(5);
	cout << stA.pop() << endl;
	cout << stA.pop() << endl;
	cout << stA.pop() << endl;
	cout << stA.pop() << endl;

}