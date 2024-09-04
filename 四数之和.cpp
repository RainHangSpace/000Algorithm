#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4)return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; ++i) {
            if (nums[i] > 0 && nums[i] > target)return result;
            if (i > 0 && nums[i] == nums[i - 1])continue;
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                if (nums[j] > 0 && nums[i] + nums[j] > target) {
                    cout << nums[j];
                    return result;
                }
                if (j > i + 1 && nums[j] == nums[j - 1])continue;
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    if (nums[i] + nums[j] < target - nums[left] - nums[right])++left;
                    else if (nums[i] + nums[j] > target - nums[left] - nums[right])--right;
                    else {
                        result.push_back({ nums[i], nums[j], nums[left], nums[right] });
                        while (left < right && nums[left] == nums[++left]);
                        while (left < right && nums[right] == nums[--right]);
                    }
                }
            }

        }
        return result;
    }
};
int main() {
    Solution a;
    vector<int> nums = { -2,-1,0,0,1,2,3,4,5 };
    a.fourSum(nums, 0);

    return 0;
}