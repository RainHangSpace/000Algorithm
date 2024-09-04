#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> ivec{ 0,1,2,3,4,5,6,7,8,9 };
	int sought = 1;
	cout << "Enter the num you want between 0 and 9 is :" << endl;
	cin >> sought;
	if (sought < 0 || sought>9) {
		cout << "err!" << endl;
		return -1;
	}
	auto beg = ivec.begin(), end = ivec.end();
	auto mid = ivec.begin() + ivec.size() / 2;
	int iteratorTimes = 0;
	while (beg != end && *mid != sought)
	{
		if (*mid < sought)
			beg = mid + 1;
		else
			end = mid;
		cout << "[begin, end) = ["  << beg - ivec.begin() << ", " << end - ivec.begin();
		mid = beg + (end - beg) / 2;
		cout << "), mid = " << mid - ivec.begin() << ", *mid = " << *mid << '\n';
		iteratorTimes++;
	}
	cout << *mid << endl;
	cout << "iteratorTimes = " << iteratorTimes << endl;
	return 0;
}
