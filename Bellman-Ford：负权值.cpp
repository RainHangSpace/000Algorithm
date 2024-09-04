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
	vector<bool> isInQue(n + 1);//��¼�ڵ��Ƿ��Ѿ��ڶ��� ����ڶ��������ٴμ������
								//���ۼ�����ٴ� �Ӷ�����ȡ��һ�ξͿ��Ը��º�minDist����
								//Ҳ��������˵ ǰ��ȡ���Ľڵ�����Ӱ���˶��ٴ���������ڵ� ����ڵ�Ҳ����Ҫȡ��һ�ξͿ��Ը��º�minDist����
								//��˵���� �Ƶ�һ�¾�������
								//���ǻ�˵������ֻҪ��û�и���·��minDist������������Сֵ������뼸�ζ���Ҳû������
								//���һ�����ͨ���ж�һ���ڵ��Ƿ񱻼�����д���n - 1�� ���жϳ�ͼ���и���·
								//��Ϊ����û�и���·��ͼ ���һ���ڵ�Ҳֻ�ܱ����n - 1��
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
