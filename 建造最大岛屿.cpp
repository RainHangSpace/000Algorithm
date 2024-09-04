//����һ���� 1��½�أ��� 0��ˮ����ɵľ����������Խ������е�һ��ˮ��Ϊһ��½�أ���ִ���˴˲���֮�󣬾��������ĵ�������Ƕ��١�
//��������ļ��㷽ʽΪ��ɵ����½�ص������������Ǳ�ˮ��Χ������ͨ��ˮƽ�����ֱ���������ڵ�½�����Ӷ��ɵġ�����Լ�����������ˮ��Χ��

//4 5
//1 1 0 0 0
//1 1 0 0 0
//0 0 1 0 0
//0 0 0 1 1

//����� 6


//˼· �� ��ÿһ�鵺���� ��Ŷ�Ӧ������� �ٱ���0�ؿ� ���������ڵĵ��� ������� ��¼���ֵ
//���ܵ����İѵ����ÿһ��ؿ��ǳ���� ��Ϊ�����п���ͬʱ����0�ؿ�Ķ������ ����������ֱܷ��Ƿ�Ϊͬһ�鵺�� �ͻ�����ظ��ۼӵ����
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
	int islandIndex = 2;//�����Ŵ�2��ʼ
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
	bool allEarth = true;//���ȫ��½�� �����n*m
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == 0) {
				int cur = 1;//��ǰ�˹������ ��ʼֵΪһ��0��ص����
				unordered_set<int> set;//ȥ��
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