#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
using namespace std;


int main() {
	int num;
	cin >> num;
	string s;
	vector<string> vec;
	
	cin.ignore(100, '\n');
	for (int j = 0; j < num; ++j) {
		//getline(cin, s, ' ');
		cin >> s;
		cout << s << '\n';
		if (vec.size() < 2)
			vec.push_back(s);
		else {
			int k = 0;
			bool equal = true;
			for (auto it = vec.rbegin(); k < 2; ++it, ++k) {
				if (*it != s) {
					equal = false;
					vec.push_back(s);
					break;
				}
			}
			if (equal) {
				vec.pop_back();
				vec.pop_back();
			}
		}
	}
	if (vec.empty())
		cout << 0;
	for (auto i : vec) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
