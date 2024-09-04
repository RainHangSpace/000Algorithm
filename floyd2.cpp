#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n, m, p1, p2, val;
    cin >> n >> m;

    vector<vector<int>> grid(n + 1, vector<int>(n + 1, 10005));  // 因为边的最大距离是10^4

    for (int i = 0; i < m; i++) {
        cin >> p1 >> p2 >> val;
        grid[p1][p2] = val;
        grid[p2][p1] = val; // 注意这里是双向图

    }
    cout << "k = " << 0 << ": \n";
    for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v) {
            if (grid[u][v] == 10005) {
                cout << setw(3) << right << "M";
                continue;
            }
            cout << setw(3) << right << grid[u][v];
        }
        cout << '\n';
    }
    // 开始 floyd
    for (int k = 1; k <= n; k++) {
        cout << "k = " << k << ": \n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
                if (grid[i][j] == 10005) {
                    cout << setw(3) << right << "M";
                    continue;
                }
                cout << setw(3) << right << grid[i][j];
            }
            cout << '\n';
        }
    }
    // 输出结果
    int z, start, end;
    cin >> z;
    while (z--) {
        cin >> start >> end;
        if (grid[start][end] == 10005) cout << -1 << endl;
        else cout << grid[start][end] << endl;
    }
}
