#include <stack>
#include <iostream>

using namespace std;
class MyQueue {
public:
	stack<int> stIn;
	stack<int> stOut;
	MyQueue() {

	}
	void push(int x) {
		stIn.push(x);
	}
	int pop() {
		int res;
		if (stOut.empty()) {
			while (!stIn.empty()) {
				stOut.push(stIn.top());
				stIn.pop();
			}
		}
		res = stOut.top();
		stOut.pop();
		return res;
	}
	int peek() {
		int res = this->pop();
		stOut.push(res);
		return res;
	}
	bool empty() {
		return stIn.empty() && stOut.empty();
	}
};
int main() {
	MyQueue queA;
	queA.push(1);
	queA.push(2);
	cout << queA.pop() << endl;
	cout << queA.peek() << endl;
	queA.push(3);
	queA.push(4);
	queA.push(5);
	cout << queA.pop() << endl;
	cout << queA.pop() << endl;
	cout << queA.pop() << endl;
	cout << queA.pop() << endl;

	
}