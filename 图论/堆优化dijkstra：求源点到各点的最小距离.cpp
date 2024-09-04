//https://kamacoder.com/problempage.php?pid=1047
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <climits>
//#include <functional>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> grid (n + 1);
	vector<bool> visited(n + 1);
	vector<int> minDist(n + 1, INT_MAX);

	//关于priority_queue的比较逻辑如何使用：
	/*如果是函数对象 cmp就是一个类型 直接放到模板里就可以了 
	而如果是lambda表达式 因为其没有类型 所以需要确定其类型
	然后再将lambda表达式作为参数传入priority_queue*/
	priority_queue < pair<int, int>, 
					vector<pair<int, int>>, 
					function<bool(const pair<int, int>&, const pair<int, int>&)>> 
		pq([](const pair<int, int>& a, const pair<int, int>& b) {
					return a.second > b.second;
			});

	while (m--) {
		int s, t, l;
		cin >> s >> t >> l;
		grid[s].push_back({ t, l });
	}
	//根据题设设置
	int start = 1;
	int end = n;
	//初始化
	minDist[start] = 0;
	pq.push({start, 0});
	//堆优化的dijkstra
	while (!pq.empty()) {
		//找到未选中的最近距离节点
		int minNode = pq.top().first;
		int minVal = pq.top().second;
		pq.pop();
		if (visited[minNode]) continue;
		//选中它！
		visited[minNode] = true;

		//更新minDist
		for (auto i : grid[minNode]) {
			if (!visited[i.first] && minVal + i.second < minDist[i.first]) {
				minDist[i.first] = minVal + i.second;
				pq.push({ i.first, minDist[i.first] });//堆里放的是未被选中的节点 堆顶放的是距离最近的
			}
			for (auto i : minDist)
				cout << i << ' ';
			cout << '\n';
		}
		
	}
	if (minDist[n] == INT_MAX) {
		cout << -1 << endl;
		return 0;
	}
	cout << minDist[end] << endl;
	return 0;
}