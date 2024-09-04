//https://kamacoder.com/problempage.php?pid=1047
#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n + 1, vector<int>(n + 1, INT_MAX));
	while (m--) {
		int s, t, l;
		cin >> s >> t >> l;
		grid[s][t] = l;
	}

	vector<int> minDist(n + 1, INT_MAX);
	vector<int> visited(n + 1);

	int start = 2;
	int end = n;
	minDist[start] = 0;
	vector<int> parent(n + 1);//记录算法完成之后的每个节点的父节点 0为start的父节点
	for (int i = 1; i <= n; ++i) {
		//找未选中距离最小节点
		int minVal = INT_MAX;
		int curMin = 0; //当前距离最小的未选中节点
		for (int j = 1; j <= n; ++j) {
			if (!visited[j] && minDist[j] < minVal) {
				minVal = minDist[j];
				curMin = j;
			}
		}
		//选中该节点
		visited[curMin] = true;
		//更新minDist数组
		for (int j = 1; j <= n; ++j) {
			if (!visited[j] && grid[curMin][j] != INT_MAX && minVal + grid[curMin][j] < minDist[j]) {//从源点到curMin再到j的距离 小于 之前源点到j的最小距离 则更新
				minDist[j] = minVal + grid[curMin][j];
				//记录路径要记录j节点的父节点 而不能记curMin的子节点 因为curMin有可能是好几个j的父节点
				parent[j] = curMin;
			}
		}
		// 		cout << "select :" << curMin << 
	}
	//打印路径
	for (int i = 1; i <= n; ++i) {
		cout << parent[i] << "->" << i << '\n';
	}
	//打印start 到 end的路径
	vector<int>path;
	int cur = end;
	while (cur) {
		path.push_back(cur);
		cur = parent[cur];
	}
	for (int i = path.size() - 1; i >= 0; --i)
		cout << path[i] << ' ';
	cout << '\n';


	if (minDist[end] == INT_MAX) {
		cout << -1 << endl;
		return 0;
	}
	cout << minDist[end] << endl;
	return 0;

}
