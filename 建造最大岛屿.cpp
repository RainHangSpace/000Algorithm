//给定一个由 1（陆地）和 0（水）组成的矩阵，你最多可以将矩阵中的一格水变为一块陆地，在执行了此操作之后，矩阵中最大的岛屿面积是多少。
//岛屿面积的计算方式为组成岛屿的陆地的总数。岛屿是被水包围，并且通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设矩阵外均被水包围。

//4 5
//1 1 0 0 0
//1 1 0 0 0
//0 0 1 0 0
//0 0 0 1 1

//输出： 6


//思路 ： 给每一块岛屿编号 编号对应岛屿面积 再遍历0地块 根据其毗邻的岛屿 加算面积 记录最大值
//不能单纯的把岛屿的每一块地块标记成面积 因为岛屿有可能同时毗邻0地块的多个方向 这样如果不能分辨是否为同一块岛屿 就会出现重复累加的情况
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<int, int> mapIsland;
int islandCurArea = 0;
int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };
void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int islandIndex) {
	for (int i = 0; i < 4; ++i) {
		int xNext = x + dir[i][0];
		int yNext = y + dir[i][1];
		if (xNext < 0 || yNext < 0 || xNext >= grid.size() || yNext >= grid[0].size()) continue;

		if (!visited[xNext][yNext] && grid[xNext][yNext] == 1) {
			visited[xNext][yNext] = true;
			grid[xNext][yNext] = islandIndex;
			++islandCurArea;
			dfs(grid, visited, xNext, yNext, islandIndex);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m));
	vector<vector<bool>> visited(n, vector<bool>(m));
	for (auto& i : grid)
		for (auto& j : i)
			cin >> j;
	int islandIndex = 2;//岛屿编号从2开始
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!visited[i][j] && grid[i][j] == 1) {
				grid[i][j] = islandIndex;
				visited[i][j] = true;
				islandCurArea = 1;
				dfs(grid, visited, i, j, islandIndex);
				mapIsland[islandIndex] = islandCurArea;
				islandIndex++;
			}
		}
	}
	cout << '\n';
	for (auto i : grid) {
		for (auto j : i) {
			cout << j << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	for (auto& i : mapIsland)
		cout << i.first << "->" << i.second << '\n';
	cout << '\n';
	int res = 0;
	bool allEarth = true;//如果全是陆地 则输出n*m
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == 0) {
				int cur = 1;//当前人工岛面积 初始值为一块0块地的面积
				unordered_set<int> set;//去重
				for (int k = 0; k < 4; ++k) {
					int iNext = i + dir[k][0];
					int jNext = j + dir[k][1];
					if (iNext < 0 || jNext < 0 || iNext >= grid.size() || jNext >= grid[0].size()) continue;
					
					if (mapIsland.count(grid[iNext][jNext]) && set.find(grid[iNext][jNext]) == set.end()) {
						set.insert(grid[iNext][jNext]);
						cur += mapIsland[grid[iNext][jNext]];
						cout << i << ' ' << j << "->" << iNext << ' ' << jNext << " cur : " << cur << "\n";
					}
				}
				res = max(res, cur);
			}
		}
	}
	if (allEarth) {
		cout << n * m << endl;
		return 0;
	}
	cout << '\n' << res << endl;
	return 0;
}