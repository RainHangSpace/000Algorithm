//https://kamacoder.com/problempage.php?pid=1153
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
using namespace std;


//判断负回路的方法 当松弛到第n次时 minDist还在减小 就说明出现了负回路
//注意：这是因为n-1次松弛 没有负回路的minDist也一直在减小 所以无法判断是不是出现了负回路
//而n次松弛 如果没有负回路 则minDist就一定不会减小
//但这并不说明 有负回路时 进行n-1次松弛会得到正确的结果 如果有负回路 还想得到正确的结果 可能需要先去掉负回路
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

	for (int i = 1; i <= n - 1; ++i) {
		for (int node0 = 1; node0 <= n; ++node0) {
			if (minDist[node0] == INT_MAX) continue;//如果起点还没有更新minDist 则跳过 等下一轮松弛 别忘了！
			for (auto node1 : adjaList[node0]) {
				if (minDist[node1.first] > minDist[node0] + node1.second) {
					minDist[node1.first] = minDist[node0] + node1.second;
				}
			}
		}
		/*for (auto i : minDist)
			cout << i << ' ';
		cout << '\n';*/
	}
	//第n次
	for (int node0 = 1; node0 <= n; ++node0) {
		for (auto node1 : adjaList[node0]) {
			if (minDist[node0] == INT_MAX) continue;//如果起点还没有更新minDist 则跳过 等下一轮松弛 别忘了！
			if (minDist[node1.first] > minDist[node0] + node1.second) {
				cout << "circle" << endl;
				return 0;
			}
		}
	}
	if (minDist[end] != INT_MAX) {
		cout << minDist[end] << endl;
		return 0;
	}
	cout << "unconnected" << endl;
	return 0;

}

