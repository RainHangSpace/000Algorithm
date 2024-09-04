//4.1实现一个stack class
#ifndef STACK_H_H
#define STACK_H_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class stack_h;


class stack_h {
public:
	bool pop(string& mem);
	bool push(const string& mem);
	bool peek(string& mem) const;
	bool full() const;
	bool empty() const { return _stack.empty(); }

	bool find(const string& mem) const;
	int count(const string& mem) const;

	int size() const { return _stack.size(); }
private:
	vector<string> _stack;
};


inline bool
stack_h::full() const {
	return _stack.size() == _stack.max_size();
}


bool stack_h:: push(const string& mem) {
	if (full())
		return false;
	_stack.push_back(mem);
	return true;
}
bool stack_h::pop(string& mem) {
	if (empty())
		return false;
	mem = _stack.back();
	_stack.pop_back();
	return true;
}
bool stack_h::peek(string& mem) const {
	if (empty())
		return false;
	mem = _stack.back();
	return true;
}

#include<algorithm>
bool
stack_h::find(const string& mem) const{
	vector<string>::const_iterator end_it = _stack.end();
	return std::find(_stack.begin(), end_it, mem) != end_it;
}

int
stack_h::count(const string& mem) const {
	return std::count(_stack.begin(), _stack.end(), mem);
}
#endif // !STACK_H_H


	