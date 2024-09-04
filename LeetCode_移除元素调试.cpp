#include <vector>
#include <iostream>
using namespace std;

int main(){
	vector<vector<int>> matrix = { {1,2,3},{4,5,6},{7,8,9} };
	vector<int> nums ;
	auto begin = nums.end();
	int right = nums.size() - 1;
	cout << right<< endl;
	cout << matrix[1][1] << endl;
	return 0;
}