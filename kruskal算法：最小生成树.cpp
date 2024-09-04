//https://kamacoder.com/problempage.php?pid=1053

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


//kruskal�㷨��ά���ߵļ��ϣ�̰�Ĳ����Ǿ����ܽ�·��С�ı߷ŵ������У��Ҳ�����ͼ�ɻ�

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
		if (node1 == node2)return false;//���û�кϲ� Ҳ���Ƿ���false ��˵��node1 �� node2 ����һ�������е�
		root[node2] = node1;
		return true;
	}

private:
	vector<int> root;
};

int main() {
	int n, m;
	cin >> n >> m;
	unionSet uset(n + 1);//��Ϊ�ڵ��Ǵ�1��ʼ��ŵ� ���Բ����±�0
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

