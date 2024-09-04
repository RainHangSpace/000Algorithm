//https://kamacoder.com/problempage.php?pid=1191
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
//�������� ����������ͼ �ҵ��������� 
//��bfs Ҫһ���԰����Ϊ0�Ľڵ㶼�ŵ�������ȥ
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> inDegree(n);
	vector<vector<int>> adjacentList(n);

	while (m--) {
		int s, t;
		cin >> s >> t;
		++inDegree[t];
		adjacentList[s].push_back(t);
	}
	/*for (auto i : inDegree)
		cout << i << ' ';
	cout << '\n';
	for (auto i : adjacentList) {
		for (auto j : i)
			cout << j << ' ';
		cout << '\n';
	}*/
	vector<int> res;
	queue<int> que;
	for (int i = 0; i < n; ++i) {
		if (inDegree[i] == 0)
			que.push(i);
	}
	while (!que.empty()) {
		int orign = que.front(); que.pop();
		res.push_back(orign);

		for (auto& i : adjacentList[orign]) {
			--inDegree[i];
			if (inDegree[i] == 0)
				que.push(i);
		}
	}
	if (res.size() == n){
		for (int i = 0; i < res.size() - 1; ++i)
			cout << res[i] << ' ';
		cout << res[res.size() - 1] << endl;
	}
	else
		cout << -1 << endl;
	return 0;

}
