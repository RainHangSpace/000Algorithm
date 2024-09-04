//https://kamacoder.com/problempage.php?pid=1152
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
using namespace std;


int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> adjaList(n + 1);
	while (m--) {
		int s, t, l;
		cin >> s >> t >> l;
		adjaList[s].push_back({ t, l });
	}
	int start = 1;
	int end = n;
	vector<int> minDist(n + 1, INT_MAX);
	minDist[start] = 0;

	queue<int> que;
	que.push(start);
	vector<bool> isInQue(n + 1);//记录节点是否已经在队列 如果在队列无需再次加入队列
								//无论加入多少次 从队列中取出一次就可以更新好minDist数组
								//也可以这样说 前面取出的节点无论影响了多少次现在这个节点 这个节点也仅需要取出一次就可以更新好minDist数组
								//多说无益 推到一下就明白了
								//但是话说回来：只要是没有负回路，minDist最后会收敛到最小值，多加入几次队列也没有问题
								//而且还可以通过判断一个节点是否被加入队列大于n - 1次 而判断出图中有负回路
								//因为对于没有负回路的图 最多一个节点也只能被添加n - 1次
	isInQue[start] = true;
	while (!que.empty()){
			int node0 = que.front();
			que.pop();
			isInQue[node0] = false;
			for (auto node1 : adjaList[node0]) {
				if (minDist[node1.first] > minDist[node0] + node1.second) {
					minDist[node1.first] = minDist[node0] + node1.second;
					if (!isInQue[node1.first]) {
						que.push(node1.first);
						isInQue[node1.first] = true;
					}
				}
			}
		for (auto i : minDist)
			cout << i << ' ';
		cout << '\n';
	}
	if (minDist[end] != INT_MAX) {
		cout << minDist[end] << endl;
		return 0;
	}
	cout << "unconnected" << endl;
	return 0;

}
