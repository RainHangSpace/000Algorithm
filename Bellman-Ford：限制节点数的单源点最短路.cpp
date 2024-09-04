//https://kamacoder.com/problempage.php?pid=1154
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
//SPFA 也就是队列优化的Bellman-Ford算法 更加适合稀疏图
//当边数增加时，其时间复杂度会趋近于传统的Bellman-Ford算法
//但是队列的数据出入也需要时间 所以反而会比传统方法慢
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> adjaList(n + 1);
	while (m--) {
		int s, t, l;
		cin >> s >> t >> l;
		adjaList[s].push_back({ t, l });
	} 
	int start, end, k;
	cin >> start >> end >> k;
	++k;//经过k个城市 边有k+1条
	vector<int> minDist(n + 1, INT_MAX);
	vector<int> minDistCopy(n + 1);
	//这里是重点：当有负回路时，我们需要严格更新每一次minDist
	//当没有负回路时，minDist是收敛的，无论你更新多少次minDist，都会得到最终正确的结果，只要大于n-1次
	//那么如果输入的边比较顺序，如先给1->2，再给2->3，这样其实在第一次松弛的时候，就可能已经得到了1到3的最小距离值了
	//但是不用在乎这个，无论顺序怎样，x次松弛，就会得到距离源节点x边的节点的最小距离值，即便此时x+1边的节点也有可能已经是最小值了
	//无所谓 因为到了最小值就收敛住了 不会再小了
	//然而，当有负回路时，minDist是不会收敛的，每一次都会进一步减小其中的值
	//所以这时我们就要在乎x次松弛会不会提前把x+1边的节点已经减到理论上的最小值了，因为这时我们再进行x+1次松弛，对于x+1节点就已经不对了，其值就更小了
	//因此必须严格松弛x次，不能让当次松弛因边给出的顺序问题而导致有更多边得到松弛
	//也就是说 松弛x次 就得到x边的节点的最小距离值 而x+1边的节点严格需要再一次松弛
	//说起来很绕，但是做起来简单，就是拷贝一次minDist，更新minDist用拷贝的上一次的值判断，这样就不会过多地更新其它节点，而只是更新必要的节点


	queue<int> que;
	que.push(start);
	minDist[start] = 0;
	vector<bool> isInQueue(n + 1);
	isInQueue[start] = true;
	//看起来简单 但是队列的出入也是很耗时的
	while (!que.empty() && k--) {
		int queSize = que.size();
		minDistCopy = minDist;
		//cout << k << '\n';
		for (int i = 0; i < queSize; ++i) {
			int node0 = que.front();
			que.pop();
			isInQueue[node0] = false;
			for (auto node1 : adjaList[node0]) {
				int from = node0;
				int to = node1.first;
				int distance = node1.second;
				//cout << "from: " << from << "to" << to << '\n';
				if (minDist[to] > minDistCopy[from] + distance) {
					minDist[to] = minDistCopy[from] + distance;
					if(!isInQueue[to])
						que.push(to);
				}
			}
		}
	}

	if (minDist[end] != INT_MAX) {
		cout << minDist[end] << endl;
		return 0;
	}
	cout << "unreachable" << endl;
	return 0;
}


