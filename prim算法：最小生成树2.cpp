//https://kamacoder.com/problempage.php?pid=1053
//�������ҷ���С�������ľ�������Ľڵ� ������С������ ���·���С�������ڵ������������С�����������
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
	minDist[1] = 0;//�����һ������� ����ѡ��ڵ�1
	int res = 0;

	//��С���Ż�prim�㷨
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
				pq.push({ i, minDist[i] });//�ڵ����С�������֮�� Ҫ������ѹ�뵽pq�дӶ���¼�����µ�����ڵ�
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
	//����С���ѵĵ�����ʽ
	//for (int i = 1; i <= n; ++i) {
	//	//ֻ��Ҫִ��n�� prim�㷨��ά���ڵ�ļ��� ����Ҫִ��n��

	//	int minVal = INT_MAX;
	//	int minNode = 0;
	//	for (int j = 1; j <= n; ++j) {
	//		//�Ҿ�����С����������ķ����ڵ�
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