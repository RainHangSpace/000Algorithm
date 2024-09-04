//https://kamacoder.com/problempage.php?pid=1182
#include <vector>
#include <iostream>
//有这样一个有向连通图 其删除一条边之后可以变成一棵有向树 <==> 这个图由一颗有向树 + 一条有向边组成
//此题的关键在于入度为2 以及 环
//入度为2时说明有两条边指向了一个节点  而对于树来说 只能有一个父节点 所以必是删除其中一条边
//这里就会出现这两条边是否都在环中 1：如果都在环中，就删除后出现的那条边（题目要求）；2：如果有一条边不在环中，就只能删除在环中的那条边
//还有另外一种情况3：没有出现入度为2的节点，则此时只有环在搞鬼，删除最后成环的那条边即可，而且被删掉的这条边的终点因为没有了父节点所以称为了树的根
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
	return unionSet1.isSame(edge[targetIndex][0], edge[targetIndex][1]);//如果不加targetIndex这条边 边上的两个点还在一个集合里 说明删除之后仍是一棵树
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> edge;
	vector<int> target;//记录入度为2的节点的两条边的下标
	vector<int> degree( n + 1 );//入度
	int s, t;
	//记录入度 并记录入度为2的节点涉及的边 第一条是后出现的边 第二条是先出现的边
	for (int i = 0; i < n; ++i) {
		cin >> s >> t;
		edge.push_back({ s, t });
		++degree[t];
		if (degree[t] == 2) {
			target.push_back(i);//记录第二次指向t的边
			for (int j = 0; j < n; ++j) {
				if (edge[j][1] == t) {
					target.push_back(j);//记录指向t的另一条边
					break;
				}
					
			}
		}
	}
	cout << '\n';
	if (target.size() != 0) {
		if (afterRemoveStillTree(target[0], edge)) {
			//先删target[0]试试 因为它是后出现的边 如果不行 就是另一条边
			cout << edge[target[0]][0] << ' ' << edge[target[0]][1] << endl;
		}
		else {
			cout << edge[target[1]][0] << ' ' << edge[target[1]][1] << endl;
		}
	}
	else {
		//如果没有入度为2的点，则删除成环的那条边即可
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