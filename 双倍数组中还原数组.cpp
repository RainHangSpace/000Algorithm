#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    //找到原始数组
    //这个算法会超时，双重循环，时间复杂度太高了，可以用快慢指针，或者用队列，我在力扣上发布了用队列的题解，个人觉得很巧妙
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2 == 1) return vector<int>();
        sort(changed.begin(), changed.end());
        int n = changed.size();
        vector<bool> used(n, false);
        vector<int> res;
        for (int i = 0; i < n - 1; ++i) {
            if (used[i]) {
                continue;
            }
            for (int j = i + 1; j < n; ++j) {
                if (used[j]) {
                    if (j == n - 1) {
                        return vector<int>();
                    }
                    continue;
                }
                if (changed[j] == changed[i] * 2) {
                    used[j] = true;
                    used[i] = true;
                    res.push_back(changed[i]);
                    break;
                }
                if (j == n - 1) {
                    return vector<int>();
                }
            }
        }
        return res;
    }
};

int main() {
    Solution A;
    vector<int> input{ 4, 2, 2, 2 };
    vector<int> res = A.findOriginalArray(input);
    for (auto i : res) {
        cout << i << ' ';
    }
    cout << endl;
}