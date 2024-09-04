//https://kamacoder.com/problempage.php?pid=1053

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include<unordered_set>
using namespace std;


//һ���ڽӱ� һ����ϣ��
//��ϣ��������¼·���ĳ���
// prim �㷨����ά���ڵ�ļ��� ��ÿ�εõ��Ľڵ㼯��֮���·�̶�����С��
// ���������� ����i��j�ڵ㹹�ɵ���С������ ����i��j-1�ڵ㹹�ɵ���С���������Ͼ��������������Ľڵ㹹�ɵ�


// ���� pair<int, int> �Ĺ�ϣ����
//class pair_hash {
//public:
//	template <class T1, class T2>
//	size_t operator () (const pair<T1, T2>& pair) const {
//		auto hash1 = hash<T1>{}(pair.first);//��ʱ������һ��hashģ�������ʱʵ������ ���ڽ���pair.first����
//		auto hash2 = hash<T2>{}(pair.second);
//		return hash1 ^ hash2;  // XOR ��������Ϸ�ʽ
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
	vector<vector<int>> adjacentList(n + 1);//�ڵ��1��ʼ����
	unordered_map<pair<int, int>, int, pairHash> lengthMap;
	while (m--) {
		int s, t, l;
		cin >> s >> t >> l;
		adjacentList[s].push_back(t);
		adjacentList[t].push_back(s);//����ͼ
		lengthMap[{s, t}] = l;
		lengthMap[{t, s}] = l;

	}
	vector<int> primVec{1};//�ѽڵ�1�Ž�ȥ �������������ڵ�
	unordered_set<int> set;//ȥ��
	set.insert(1);
	int res = 0;
	for (int i = 1; i <= n - 1; ++i) {
		//��������Ϊn-1�Σ���Ϊ��n���ڵ㣬Ҫ��n-1���ߡ�
		int tCurMin = 0;
		int sCurMin = 0;
		int lengthCurMin = 10001;//�������ֵ��10000
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
