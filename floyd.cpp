//https://kamacoder.com/problempage.php?pid=1155
#include <iostream>
#include <string>
#include <vector>
#include <climits>
constexpr auto MAX_DIST = 10005;
using namespace std;

//floyd：其核心是动态规划，考虑所有节点是否能够成为中间途径的节点：dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j])
//k从1取到n，则每个dp[i][j]都是最短距离
int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> grid(n + 1, vector<int>(n + 1, MAX_DIST));
	while (m--) {
		int s, t, l;
		cin >> s >> t >> l;
		grid[s][t] = l;
		grid[t][s] = l;
	}

	for (int mid = 1; mid <= n; ++mid) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				grid[i][j] = min(grid[i][j], grid[i][mid] + grid[mid][j]);
			}
		}
	}
	
	int q;
	cin >> q;
	while (q--) {
		int start, end;
		cin >> start >> end;
		if (grid[start][end] == MAX_DIST) {
			cout << -1 << '\n';
			continue;
		}
		cout << grid[start][end] << '\n';
	}
}
