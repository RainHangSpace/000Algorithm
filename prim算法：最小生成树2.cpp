//https://kamacoder.com/problempage.php?pid=1053
//三步：找非最小生成树的距离最近的节点 加入最小生成树 更新非最小生成树节点距生成树的最小距离距离数组
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

class cmp {
public:
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n + 1, vector<int>(n + 1, -1));
	while (m--) {
		int s, t, l;
		cin >> s >> t >> l;
		grid[s][t] = l;
		grid[t][s] = l;
	}
	vector<bool> visited(n + 1);
	vector<int> minDist(n + 1, INT_MAX);
	minDist[1] = 0;//随便找一个点就行 这里选择节点1
	int res = 0;

	//最小堆优化prim算法
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>pq;
	pq.push({ 1, minDist[1] });
	while (!pq.empty()) {
		pair<int, int> minNode = pq.top();
		pq.pop();
		if (visited[minNode.first])continue;
		
		visited[minNode.first] = true;

		for (int i = 0; i < grid[minNode.first].size(); ++i) {
			if (grid[minNode.first][i] == -1) continue;
			if (!visited[i] && grid[minNode.first][i] < minDist[i]) {
				minDist[i] = grid[minNode.first][i];
				pq.push({ i, minDist[i] });//节点的最小距离更新之后 要把其再压入到pq中从而记录到最新的最近节点
			}
		}

	}
	int result = 0;
	for (int i = 0; i < visited.size(); ++i) {
		if (visited[i])
			result += minDist[i];
	}
	cout << '\n';
	cout << result << endl;
	//不用小顶堆的迭代方式
	//for (int i = 1; i <= n; ++i) {
	//	//只需要执行n次 prim算法是维护节点的集合 所以要执行n次

	//	int minVal = INT_MAX;
	//	int minNode = 0;
	//	for (int j = 1; j <= n; ++j) {
	//		//找距离最小生成树最近的非树节点
	//		if (!visited[j] && minDist[j] < minVal) {
	//			minVal = minDist[j];
	//			minNode = j;
	//		}
	//	}

	//	visited[minNode] = true;
	//	res += minVal;
	//	cout << minNode << ' ';

	//	for (int j = 1; j <= n; ++j) {
	//		if (!visited[j] && grid[minNode][j] != -1 && grid[minNode][j] < minDist[j]) {
	//			minDist[j] = grid[minNode][j];
	//		}
	//	}
	//}
	///*int res = 0;
	//for (int i = 0; i < visited.size(); ++i) {
	//	if (visited[i])
	//		res += minDist[i];
	//}*/
	//cout << '\n';
	//cout << res << endl;
}