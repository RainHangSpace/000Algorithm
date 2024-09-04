//#include <iostream>
//#include <algorithm>
//#include <string>
//
//int main() {
//    std::string s = "123";
//    // 确保字符串是按字典序排列的，以便从最小的排列开始
//    std::sort(s.begin(), s.end());
//
//    do {
//        std::cout << s << '\n';
//    } while (std::next_permutation(s.begin(), s.end()));
//
//    return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>
bool nextPermutation(std::vector<int>& nums) {
    //1 找到非递增后缀的前一个索引，也即非递减序列的最后一个索引
    int i = nums.size() - 1 - 1;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        --i;
    }
    if (i >= 0) {
        //2 如果有这样的索引，则为了找到字典序稍大一点的排列，需要从右向左找稍大于nums[i]的元素，并互换二者，最后将非递增后缀逆序
        int j = nums.size() - 1;
        while (nums[j] <= nums[i]) {
            --j;
        }
        std::swap(nums[i], nums[j]);
    }//2 如果没有这样的索引，则整个序列都是非递增的，也即最大的字典序排列，没有其他排列了，返回即可
    else {
        return false;
    }
    //3 最后要把i之后的非递增序列翻转成非递减序列，因为非递减序列就是最小字典序
    std::reverse(nums.begin() + i + 1, nums.end());
    return true;
}

int main() {
    // 初始化vector为最小排列
    std::vector<int> nums = { 1, 1, 2};
    sort(nums.begin(), nums.end());
    do {
        for (auto num : nums) {
            std::cout << num << ' ';
        }
        std::cout << std::endl;
    } while (nextPermutation(nums));
    return 0;
}
