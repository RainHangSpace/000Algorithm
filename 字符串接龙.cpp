//字典 strList 中从字符串 beginStr 和 endStr 的转换序列是一个按下述规格形成的序列：
//
//序列中第一个字符串是 beginStr。
//
//序列中最后一个字符串是 endStr。
//
//每次转换只能改变一个字符。
//
//转换过程中的中间字符串必须是字典 strList 中的字符串。
//
//给你两个字符串 beginStr 和 endStr 和一个字典 strList，找到从 beginStr 到 endStr 的最短转换序列中的字符串数目。如果不存在这样的转换序列，返回 0。
//
//输入描述
//
//第一行包含一个整数 N，表示字典 strList 中的字符串数量。 第二行包含两个字符串，用空格隔开，分别代表 beginStr 和 endStr。 后续 N 行，每行一个字符串，代表 strList 中的字符串。
//
//输出描述
//
//输出一个整数，代表从 beginStr 转换到 endStr 需要的最短转换序列中的字符串数量。如果不存在这样的转换序列，则输出 0。
//
//输入示例
//
//6
//abc def
//efc
//dbc
//ebc
//dec
//dfc
//yhn
//输出示例
//
//4
//
//提示信息
//
//从 startStr 到 endStr，在 strList 中最短的路径为 abc->dbc->dec->def，所以输出结果为 4
//
//数据范围：
//
//2 <= N <= 500

//思路：建图 用广搜 广搜搜到的第一个路径就是最近的 注意：广搜的话需要考虑用map进行去重，因为不光要去重，还需要记录每个节点对应的路径长度，而不是一味地从队列中取出一个就加一长度
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool yes(string& lhs, string& rhs) {
	// 判断lhs可不可以转换成rhs ：转换规则是只能替换一个字符
	if (lhs.size() != rhs.size()) return false;
	int temp = 0;
	for (int i = 0; i < lhs.size(); ++i) {
		if (lhs[i] == rhs[i])
			++temp;
	}
	if (temp == lhs.size() - 1) return true;
	return false;
}

int main() {
	int numDict;
	string beginStr, str, endStr;
	cin >> numDict >> beginStr >> endStr;
	vector<string> strVec{beginStr};
	for (int i = 0; i < numDict; ++i) {
		cin >> str;
		strVec.push_back(str);
	}
	strVec.push_back(endStr);

	//建：邻接表
	vector<vector<int>> graph(strVec.size());
	for (int i = 0; i < strVec.size(); ++i) {
		for (int j = i + 1; j < strVec.size(); ++j) {
			if (yes(strVec[i], strVec[j])) {
				graph[i].push_back(j);
				graph[j].push_back(i);//无向图
			}
		}
	}
	/*int iii = 0;
	for (auto i : graph) {
		cout << iii++ << ": ";
		for (auto j : i)
			cout << j << ' ';
		cout << '\n';
	}*/
	queue<int> que;
	que.push(0);//把起点放进去
	int res = 1;
	unordered_map<int, int> map;	//哈希表去重 用映射去重的同时 记录每个节点对应的路径长度
	map.insert({0, 1});//0节点 对应的路径长度是 1
	//广度优先遍历
	while (!que.empty()) {
		int cur = que.front();
		int length = map[cur];//记录此时节点的路径长度
		que.pop();
		for (auto i : graph[cur]) {
			if (map.count(i)) continue;

			

			if (i == graph.size() - 1) {
				cout << length + 1 << endl;
				return 0;
			}

			map.insert({ i, length + 1 });
			que.push(i);
		}
	}
	cout << 0 << endl;
	return 0;
}