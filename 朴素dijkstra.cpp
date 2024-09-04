//https://kamacoder.com/problempage.php?pid=1047
#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n + 1, vector<int>(n + 1, INT_MAX));
	while (m--) {
		int s, t, l;
		cin >> s >> t >> l;
		grid[s][t] = l;
	}

	vector<int> minDist(n + 1, INT_MAX);
	vector<int> visited(n + 1);

	int start = 2;
	int end = n;
	minDist[start] = 0;
	vector<int> parent(n + 1);//��¼�㷨���֮���ÿ���ڵ�ĸ��ڵ� 0Ϊstart�ĸ��ڵ�
	for (int i = 1; i <= n; ++i) {
		//��δѡ�о�����С�ڵ�
		int minVal = INT_MAX;
		int curMin = 0; //��ǰ������С��δѡ�нڵ�
		for (int j = 1; j <= n; ++j) {
			if (!visited[j] && minDist[j] < minVal) {
				minVal = minDist[j];
				curMin = j;
			}
		}
		//ѡ�иýڵ�
		visited[curMin] = true;
		//����minDist����
		for (int j = 1; j <= n; ++j) {
			if (!visited[j] && grid[curMin][j] != INT_MAX && minVal + grid[curMin][j] < minDist[j]) {//��Դ�㵽curMin�ٵ�j�ľ��� С�� ֮ǰԴ�㵽j����С���� �����
				minDist[j] = minVal + grid[curMin][j];
				//��¼·��Ҫ��¼j�ڵ�ĸ��ڵ� �����ܼ�curMin���ӽڵ� ��ΪcurMin�п����Ǻü���j�ĸ��ڵ�
				parent[j] = curMin;
			}
		}
		// 		cout << "select :" << curMin << 
	}
	//��ӡ·��
	for (int i = 1; i <= n; ++i) {
		cout << parent[i] << "->" << i << '\n';
	}
	//��ӡstart �� end��·��
	vector<int>path;
	int cur = end;
	while (cur) {
		path.push_back(cur);
		cur = parent[cur];
	}
	for (int i = path.size() - 1; i >= 0; --i)
		cout << path[i] << ' ';
	cout << '\n';


	if (minDist[end] == INT_MAX) {
		cout << -1 << endl;
		return 0;
	}
	cout << minDist[end] << endl;
	return 0;

}
