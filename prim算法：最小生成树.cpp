//https://kamacoder.com/problempage.php?pid=1053

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include<unordered_set>
using namespace std;


//一个邻接表 一个哈希表
//哈希表用来记录路径的长度
// prim 算法用来维护节点的集合 让每次得到的节点集合之间的路程都是最小的
// 可以这样想 对于i到j节点构成的最小生成树 是由i到j-1节点构成的最小生成树加上距离此生成树最近的节点构成的


// 定义 pair<int, int> 的哈希函数
//class pair_hash {
//public:
//	template <class T1, class T2>
//	size_t operator () (const pair<T1, T2>& pair) const {
//		auto hash1 = hash<T1>{}(pair.first);//临时定义了一个hash模板类的临时实例对象 用于接收pair.first参数
//		auto hash2 = hash<T2>{}(pair.second);
//		return hash1 ^ hash2;  // XOR 或其他组合方式
//	}
//};


class pairHash {
public:
	size_t operator()(const pair<int, int>& p) const {
		return hash<int>{}(p.first) ^ hash<int>{}(p.second);
	}
};
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adjacentList(n + 1);//节点从1开始计数
	unordered_map<pair<int, int>, int, pairHash> lengthMap;
	while (m--) {
		int s, t, l;
		cin >> s >> t >> l;
		adjacentList[s].push_back(t);
		adjacentList[t].push_back(s);//无向图
		lengthMap[{s, t}] = l;
		lengthMap[{t, s}] = l;

	}
	vector<int> primVec{1};//把节点1放进去 最少输入两个节点
	unordered_set<int> set;//去重
	set.insert(1);
	int res = 0;
	for (int i = 1; i <= n - 1; ++i) {
		//迭代次数为n-1次，因为有n个节点，要找n-1条边。
		int tCurMin = 0;
		int sCurMin = 0;
		int lengthCurMin = 10001;//题设最大值到10000
		for (auto s : primVec) {
			for (auto t : adjacentList[s]) {
				if (set.count(t)) continue;
				if (lengthCurMin > lengthMap[{s, t}]) {
					lengthCurMin = lengthMap[{s, t}];
					tCurMin = t;
					sCurMin = s;
				}
			}
		}
		cout << sCurMin << " -> " << tCurMin << '\n';
		res += lengthCurMin;
		primVec.push_back(tCurMin);
		set.insert(tCurMin);
	}
	cout << '\n';
	cout << res << endl;
	return 0;

}
