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

	//����priority_queue�ıȽ��߼����ʹ�ã�
	/*����Ǻ������� cmp����һ������ ֱ�ӷŵ�ģ����Ϳ����� 
	�������lambda���ʽ ��Ϊ��û������ ������Ҫȷ��������
	Ȼ���ٽ�lambda���ʽ��Ϊ��������priority_queue*/
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
	//������������
	int start = 1;
	int end = n;
	//��ʼ��
	minDist[start] = 0;
	pq.push({start, 0});
	//���Ż���dijkstra
	while (!pq.empty()) {
		//�ҵ�δѡ�е��������ڵ�
		int minNode = pq.top().first;
		int minVal = pq.top().second;
		pq.pop();
		if (visited[minNode]) continue;
		//ѡ������
		visited[minNode] = true;

		//����minDist
		for (auto i : grid[minNode]) {
			if (!visited[i.first] && minVal + i.second < minDist[i.first]) {
				minDist[i.first] = minVal + i.second;
				pq.push({ i.first, minDist[i.first] });//����ŵ���δ��ѡ�еĽڵ� �Ѷ��ŵ��Ǿ��������
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