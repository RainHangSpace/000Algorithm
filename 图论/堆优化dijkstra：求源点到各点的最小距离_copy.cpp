#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

class node {
public:
	int index;
	int minCost;

	node(int i, int minC):index(i), minCost(minC) {;}

	bool operator<(const node& rhs) const {
		//operator<���߼��ǣ�lhs(Ҳ�������this)�Ƿ�С��rhs
		return minCost > rhs.minCost;
		//minCost�������rhs��minCost���������ȼ���С��
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	vector< vector< pair<int, int> > > adjaList(n + 1);
	
	while (m--) {
		int s, t, l;
		cin >> s >> t >> l;
		adjaList[s].push_back({t, l});
	}

	vector<bool> visited(n + 1);
	vector<int> minDist(n + 1, INT_MAX);
	priority_queue<node> pq;

	int start = 1;
	int end = n;
	pq.push(node(1, 0));
	minDist[start] = 0;

	while (!pq.empty()) {
		node curNode = pq.top();
		pq.pop();

		if(visited[curNode.index])continue;
		cout << "ѡ�У�" << curNode.index << '\n';
		visited[curNode.index] = true;

		for (auto i : adjaList[curNode.index]) {
			int nextNodeIndex = i.first;
			int cur2nextCost = i.second;
			if (visited[nextNodeIndex])continue;
			if (minDist[nextNodeIndex] > curNode.minCost + cur2nextCost) {
				minDist[nextNodeIndex] = curNode.minCost + cur2nextCost;
				cout << "������У�" << nextNodeIndex << " ��ԭ����룺" << minDist[nextNodeIndex] << '\n';
				pq.push(node(nextNodeIndex, minDist[nextNodeIndex]));
			}
			for (auto i : minDist)
				cout << i << ' ';
			cout << '\n';
		}
	}
	if (minDist[end] == INT_MAX) {
		cout << -1;
		return 0;
	}
	cout << minDist[end] << endl;
	return 0;
}