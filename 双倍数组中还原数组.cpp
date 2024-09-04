#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    //�ҵ�ԭʼ����
    //����㷨�ᳬʱ��˫��ѭ����ʱ�临�Ӷ�̫���ˣ������ÿ���ָ�룬�����ö��У����������Ϸ������ö��е���⣬���˾��ú�����
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