#include <iostream>
#include <vector>
#include <iomanip>  // 添加这个头文件以便使用 setw 和 left
using namespace std;

class TreeAncestor {
public:
    constexpr static int Log = 16;
    vector<vector<int>> ancestors;

    TreeAncestor(int n, vector<int>& parent) {
        ancestors = vector<vector<int>>(n, vector<int>(Log, -1));
        for (int i = 0; i < n; i++) {
            ancestors[i][0] = parent[i];
        }
        for (int j = 1; j < Log; j++) {
            for (int i = 0; i < n; i++) {
                if (ancestors[i][j - 1] != -1) {
                    ancestors[i][j] = ancestors[ancestors[i][j - 1]][j - 1];
                }
            }
        }
    }

    void printAncestors() {
        for (const auto& row : ancestors) {
            for (int val : row) {
                cout << setw(3) << right << val << " ";  // 设置宽度为3，并左对齐
            }
            cout << endl;
        }
    }
};

int main() {
    vector<int> parent = { -1, 0, 0, 1, 1, 2, 4, 5, 5, 7 };
    TreeAncestor treeAncestor(10, parent);
    treeAncestor.printAncestors();
    return 0;
}
