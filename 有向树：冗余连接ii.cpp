//https://kamacoder.com/problempage.php?pid=1182
#include <vector>
#include <iostream>
//������һ��������ͨͼ ��ɾ��һ����֮����Ա��һ�������� <==> ���ͼ��һ�������� + һ����������
//����Ĺؼ��������Ϊ2 �Լ� ��
//���Ϊ2ʱ˵����������ָ����һ���ڵ�  ����������˵ ֻ����һ�����ڵ� ���Ա���ɾ������һ����
//����ͻ�������������Ƿ��ڻ��� 1��������ڻ��У���ɾ������ֵ������ߣ���ĿҪ�󣩣�2�������һ���߲��ڻ��У���ֻ��ɾ���ڻ��е�������
//��������һ�����3��û�г������Ϊ2�Ľڵ㣬���ʱֻ�л��ڸ��ɾ�����ɻ��������߼��ɣ����ұ�ɾ���������ߵ��յ���Ϊû���˸��ڵ����Գ�Ϊ�����ĸ�
using namespace std;
class unionSet{
private:
	vector<int> root;
public:
	unionSet(int n) {
		root.resize(n);
		for (int i = 0; i < n; ++i)
			root[i] = i;
	}
	int find(int node) {
		return node == root[node] ? node : root[node] = find(root[node]);
	}
	bool isSame(int node1, int node2) {
		node1 = find(node1);
		node2 = find(node2);
		return node1 == node2;
	}
	void join(int node1, int node2) {
		node1 = find(node1);
		node2 = find(node2);
		if (node1 == node2)
			return;
		root[node2] = node1;
		return;
	}
};
bool afterRemoveStillTree(int targetIndex, vector<vector<int>>& edge) {
	unionSet unionSet1(edge.size() + 1);
	for (int i = 0; i < edge.size(); ++i) {
		if (i == targetIndex)
			continue;
		unionSet1.join(edge[i][0], edge[i][1]);
	}
	return unionSet1.isSame(edge[targetIndex][0], edge[targetIndex][1]);//�������targetIndex������ ���ϵ������㻹��һ�������� ˵��ɾ��֮������һ����
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> edge;
	vector<int> target;//��¼���Ϊ2�Ľڵ�������ߵ��±�
	vector<int> degree( n + 1 );//���
	int s, t;
	//��¼��� ����¼���Ϊ2�Ľڵ��漰�ı� ��һ���Ǻ���ֵı� �ڶ������ȳ��ֵı�
	for (int i = 0; i < n; ++i) {
		cin >> s >> t;
		edge.push_back({ s, t });
		++degree[t];
		if (degree[t] == 2) {
			target.push_back(i);//��¼�ڶ���ָ��t�ı�
			for (int j = 0; j < n; ++j) {
				if (edge[j][1] == t) {
					target.push_back(j);//��¼ָ��t����һ����
					break;
				}
					
			}
		}
	}
	cout << '\n';
	if (target.size() != 0) {
		if (afterRemoveStillTree(target[0], edge)) {
			//��ɾtarget[0]���� ��Ϊ���Ǻ���ֵı� ������� ������һ����
			cout << edge[target[0]][0] << ' ' << edge[target[0]][1] << endl;
		}
		else {
			cout << edge[target[1]][0] << ' ' << edge[target[1]][1] << endl;
		}
	}
	else {
		//���û�����Ϊ2�ĵ㣬��ɾ���ɻ��������߼���
		unionSet unionSet1(n + 1);
		for (auto i : edge) {
			if (!unionSet1.isSame(i[0], i[1])) {
				unionSet1.join(i[0], i[1]);
			}
			else {
				cout << i[0] << ' ' << i[1] << endl;
			}
		}
	}
		
	cout << "\nedge:\n";
	for (auto i : edge) {
		for (auto j : i)
			cout << j << ' ';
		cout << '\n';
	}
	cout << "\ntarget:\n";
	for (auto i : target) {
		cout << i;
		cout << '\n';
	}


	return 0;
}