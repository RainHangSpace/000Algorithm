//https://kamacoder.com/problempage.php?pid=1053

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


//kruskal算法是维护边的集合，贪心策略是尽可能将路程小的边放到集合中，且不能让图成环

class unionSet
{
public:
	unionSet(int n) : root(n) {
		for (int i = 0; i < n; ++i) {
			root[i] = i;
		}
	}
	int find(int node) {
		return node == root[node] ? node : root[node] = find(root[node]);
	}
	bool unite(int node1, int node2) {
		node1 = find(node1);
		node2 = find(node2);
		if (node1 == node2)return false;//如果没有合并 也就是返回false 则说明node1 和 node2 是在一个集合中的
		root[node2] = node1;
		return true;
	}

private:
	vector<int> root;
};

int main() {
	int n, m;
	cin >> n >> m;
	unionSet uset(n + 1);//因为节点是从1开始编号的 所以不用下标0
	vector<vector<int>> edges;
	while (m--) {
		int s, t, l;
		cin >> s >> t >> l;
		edges.push_back({ s, t, l });
	}
	sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
		return a[2] < b[2];
		});
	//return 0;
	int res = 0;
	for (int i = 0; i < edges.size(); ++i) {
		if (uset.unite(edges[i][0], edges[i][1])) {
			res += edges[i][2];
			for (auto i : edges[i])
				cout << i << ' ';
			cout << res << '\n';
		}
		else {
			
		}
	}
	cout << res << endl;
}

