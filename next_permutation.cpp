//#include <iostream>
//#include <algorithm>
//#include <string>
//
//int main() {
//    std::string s = "123";
//    // ȷ���ַ����ǰ��ֵ������еģ��Ա����С�����п�ʼ
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
    //1 �ҵ��ǵ�����׺��ǰһ��������Ҳ���ǵݼ����е����һ������
    int i = nums.size() - 1 - 1;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        --i;
    }
    if (i >= 0) {
        //2 �������������������Ϊ���ҵ��ֵ����Դ�һ������У���Ҫ�����������Դ���nums[i]��Ԫ�أ����������ߣ���󽫷ǵ�����׺����
        int j = nums.size() - 1;
        while (nums[j] <= nums[i]) {
            --j;
        }
        std::swap(nums[i], nums[j]);
    }//2 ���û�����������������������ж��Ƿǵ����ģ�Ҳ�������ֵ������У�û�����������ˣ����ؼ���
    else {
        return false;
    }
    //3 ���Ҫ��i֮��ķǵ������з�ת�ɷǵݼ����У���Ϊ�ǵݼ����о�����С�ֵ���
    std::reverse(nums.begin() + i + 1, nums.end());
    return true;
}

int main() {
    // ��ʼ��vectorΪ��С����
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
