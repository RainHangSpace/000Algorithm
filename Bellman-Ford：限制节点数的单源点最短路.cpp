//https://kamacoder.com/problempage.php?pid=1154
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
//SPFA Ҳ���Ƕ����Ż���Bellman-Ford�㷨 �����ʺ�ϡ��ͼ
//����������ʱ����ʱ�临�ӶȻ������ڴ�ͳ��Bellman-Ford�㷨
//���Ƕ��е����ݳ���Ҳ��Ҫʱ�� ���Է�����ȴ�ͳ������
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
	++k;//����k������ ����k+1��
	vector<int> minDist(n + 1, INT_MAX);
	vector<int> minDistCopy(n + 1);
	//�������ص㣺���и���·ʱ��������Ҫ�ϸ����ÿһ��minDist
	//��û�и���·ʱ��minDist�������ģ���������¶��ٴ�minDist������õ�������ȷ�Ľ����ֻҪ����n-1��
	//��ô�������ı߱Ƚ�˳�����ȸ�1->2���ٸ�2->3��������ʵ�ڵ�һ���ɳڵ�ʱ�򣬾Ϳ����Ѿ��õ���1��3����С����ֵ��
	//���ǲ����ں����������˳��������x���ɳڣ��ͻ�õ�����Դ�ڵ�x�ߵĽڵ����С����ֵ�������ʱx+1�ߵĽڵ�Ҳ�п����Ѿ�����Сֵ��
	//����ν ��Ϊ������Сֵ������ס�� ������С��
	//Ȼ�������и���·ʱ��minDist�ǲ��������ģ�ÿһ�ζ����һ����С���е�ֵ
	//������ʱ���Ǿ�Ҫ�ں�x���ɳڻ᲻����ǰ��x+1�ߵĽڵ��Ѿ����������ϵ���Сֵ�ˣ���Ϊ��ʱ�����ٽ���x+1���ɳڣ�����x+1�ڵ���Ѿ������ˣ���ֵ�͸�С��
	//��˱����ϸ��ɳ�x�Σ������õ����ɳ���߸�����˳������������и���ߵõ��ɳ�
	//Ҳ����˵ �ɳ�x�� �͵õ�x�ߵĽڵ����С����ֵ ��x+1�ߵĽڵ��ϸ���Ҫ��һ���ɳ�
	//˵�������ƣ������������򵥣����ǿ���һ��minDist������minDist�ÿ�������һ�ε�ֵ�жϣ������Ͳ������ظ��������ڵ㣬��ֻ�Ǹ��±�Ҫ�Ľڵ�


	queue<int> que;
	que.push(start);
	minDist[start] = 0;
	vector<bool> isInQueue(n + 1);
	isInQueue[start] = true;
	//�������� ���Ƕ��еĳ���Ҳ�Ǻܺ�ʱ��
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


