#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto beg = nums.cbegin();
        auto end = nums.cend();
        auto middle = beg + (end - beg) / 2;
        while (middle != end && *middle != target  ) {/* 先判断迭代器是否等于尾后迭代器*/
            if (target < *middle) {
                end = middle;
            }
            else {
                beg = middle + 1;
            }
            middle = beg + (end - beg) / 2;
        }
        if (middle == end)
            return -1;
        else
            return middle - nums.cbegin();
    }

};
int main()
{
    vector<int> nums = { -1 };
    Solution search;
    search.search(nums, 2);
    return 0;
}