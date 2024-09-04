//�ֵ� strList �д��ַ��� beginStr �� endStr ��ת��������һ������������γɵ����У�
//
//�����е�һ���ַ����� beginStr��
//
//���������һ���ַ����� endStr��
//
//ÿ��ת��ֻ�ܸı�һ���ַ���
//
//ת�������е��м��ַ����������ֵ� strList �е��ַ�����
//
//���������ַ��� beginStr �� endStr ��һ���ֵ� strList���ҵ��� beginStr �� endStr �����ת�������е��ַ�����Ŀ�����������������ת�����У����� 0��
//
//��������
//
//��һ�а���һ������ N����ʾ�ֵ� strList �е��ַ��������� �ڶ��а��������ַ������ÿո�������ֱ���� beginStr �� endStr�� ���� N �У�ÿ��һ���ַ��������� strList �е��ַ�����
//
//�������
//
//���һ������������� beginStr ת���� endStr ��Ҫ�����ת�������е��ַ������������������������ת�����У������ 0��
//
//����ʾ��
//
//6
//abc def
//efc
//dbc
//ebc
//dec
//dfc
//yhn
//���ʾ��
//
//4
//
//��ʾ��Ϣ
//
//�� startStr �� endStr���� strList ����̵�·��Ϊ abc->dbc->dec->def������������Ϊ 4
//
//���ݷ�Χ��
//
//2 <= N <= 500

//˼·����ͼ �ù��� �����ѵ��ĵ�һ��·����������� ע�⣺���ѵĻ���Ҫ������map����ȥ�أ���Ϊ����Ҫȥ�أ�����Ҫ��¼ÿ���ڵ��Ӧ��·�����ȣ�������һζ�شӶ�����ȡ��һ���ͼ�һ����
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool yes(string& lhs, string& rhs) {
	// �ж�lhs�ɲ�����ת����rhs ��ת��������ֻ���滻һ���ַ�
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

	//�����ڽӱ�
	vector<vector<int>> graph(strVec.size());
	for (int i = 0; i < strVec.size(); ++i) {
		for (int j = i + 1; j < strVec.size(); ++j) {
			if (yes(strVec[i], strVec[j])) {
				graph[i].push_back(j);
				graph[j].push_back(i);//����ͼ
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
	que.push(0);//�����Ž�ȥ
	int res = 1;
	unordered_map<int, int> map;	//��ϣ��ȥ�� ��ӳ��ȥ�ص�ͬʱ ��¼ÿ���ڵ��Ӧ��·������
	map.insert({0, 1});//0�ڵ� ��Ӧ��·�������� 1
	//������ȱ���
	while (!que.empty()) {
		int cur = que.front();
		int length = map[cur];//��¼��ʱ�ڵ��·������
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