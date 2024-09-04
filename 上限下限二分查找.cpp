#include <iostream>
#include <string>
#include <vector>
using namespace std;

//�����½�
int lowBound(vector<int>& nums, int target) {
    //���ڵ���target�ĵ�һ������
    int l = 0;
    int r = nums.size();
    while (l < r) {
        int m = (l + r) / 2;
        if (nums[m] < target) {
            l = m + 1;
        }
        else {
            r = m;
        }
    }
    return l;
}
//�����Ͻ�
int highBound(vector<int>& nums, int target) {
    //����target�ĵ�һ������
    int l = 0;
    int r = nums.size();
    while (l < r) {
        int m = (l + r) / 2;
        if (nums[m] <= target) {
            l = m + 1;
        }
        else {
            r = m;
        }
    }
    return l;
}
int main() {
    vector<int> nums{ 5,7,7,8,8,10 };
    int low = lowBound(nums, 5);
    cout << low << '\n';
    low = lowBound(nums, 6);
    cout << low << '\n';
    low = lowBound(nums, 7);
    cout << low << '\n';
    low = lowBound(nums, 8);
    cout << low << '\n';
    low = lowBound(nums, 9);
    cout << low << '\n';
    low = lowBound(nums, 10);
    cout << low << '\n';
    cout << "=========\n";
    int high = highBound(nums, 5);
    cout << high << '\n';
    high = highBound(nums, 6);
    cout << high << '\n';
    high = highBound(nums, 7);
    cout << high << '\n';
    high = highBound(nums, 8);
    cout << high << '\n';
    high = highBound(nums, 9);
    cout << high << '\n';
    high = highBound(nums, 10);
    cout << high << endl;
    return 0;
}
