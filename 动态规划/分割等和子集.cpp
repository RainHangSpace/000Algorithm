#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;
        int target = sum >> 1;
        vector<int> dp(target + 1);
        //dp[j]指重量为j的背包能装的最大价值
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = dp.size() - 1; j >= nums[i]; --j) {   
            //滚动数组：因为只靠左面的值就可以迭代dp，所以从右向左迭代即可用一维数组完成二维数组的工作
            //背包重量为j，所以j要大于等于物品的重量nums[i]
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
               //物品的价值也是nums[i]
            }
            cout << "nums[" << i << "]=" << nums[i] << ": dp = { ";
            for (auto k : dp)
                cout << k << ' ';
            cout << " }\n";
        }
        if (dp.back() == target) return true;
        else return false;
    }
};
int main() {            
    Solution H;
    vector<int> nums {1, 5, 11, 5};
    cout << H.canPartition(nums) << endl;
    return 0;
}