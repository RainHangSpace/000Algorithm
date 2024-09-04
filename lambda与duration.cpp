#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 使用普通函数
        auto start = chrono::high_resolution_clock::now();
        sort(people.begin(), people.end(), cmp);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        cout << "Using function: " << duration.count() << " seconds" << endl;

        // 使用 lambda 表达式
        start = chrono::high_resolution_clock::now();
        sort(people.begin(), people.end(), [](vector<int> a, vector<int> b) { 
            if (a[0] != b[0]) return a[0] > b[0];
            return a[1] < b[1];
            });
        end = chrono::high_resolution_clock::now();
        duration = end - start;
        cout << "Using lambda: " << duration.count() << " seconds" << endl;

        // 其他代码省略
        return people;
    }
};

int main() {
    vector<vector<int>> people = { {7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2} };
    Solution solution;
    solution.reconstructQueue(people);
    return 0;
}