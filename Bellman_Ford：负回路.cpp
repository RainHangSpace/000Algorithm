//https://kamacoder.com/problempage.php?pid=1153
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
using namespace std;


//�жϸ���·�ķ��� ���ɳڵ���n��ʱ minDist���ڼ�С ��˵�������˸���·
//ע�⣺������Ϊn-1���ɳ� û�и���·��minDistҲһֱ�ڼ�С �����޷��ж��ǲ��ǳ����˸���·
//��n���ɳ� ���û�и���· ��minDist��һ�������С
//���Ⲣ��˵�� �и���·ʱ ����n-1���ɳڻ�õ���ȷ�Ľ�� ����и���· ����õ���ȷ�Ľ�� ������Ҫ��ȥ������·
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
			if (minDist[node0] == INT_MAX) continue;//�����㻹û�и���minDist ������ ����һ���ɳ� �����ˣ�
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
	//��n��
	for (int node0 = 1; node0 <= n; ++node0) {
		for (auto node1 : adjaList[node0]) {
			if (minDist[node0] == INT_MAX) continue;//�����㻹û�и���minDist ������ ����һ���ɳ� �����ˣ�
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

