//https://kamacoder.com/problempage.php?pid=1203

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<vector<int>> earth(1001, vector<int>(1001));
int dir[8][2] = {	-2, -1, -1, -2,
					2, 1, 1, 2,
					2, -1, 1, -2,
					-2, 1, -1, 2 };
class knight {
private:
	int xx, yy;
	int s2c, c2t, s2c2t;//s,c,t �ֱ������ ��ǰ�� �յ�
			//��Ҫע�����s2c�ǵ�ǰ�����ģ����Ѿ�ʵ�����˶��ٲ�
			//��c2t��Ԥ������
	int stepNums;
public:
	knight(int x, int y, int s2c, int c2t, int steps = 0) :
		xx{ x }, yy{ y }, s2c{ s2c }, c2t{ c2t }, s2c2t{s2c + c2t}, stepNums(steps) {	
	}
	bool operator < (const knight& k) const {
		return k.s2c2t < s2c2t;
		//�������˼�ǣ���this.s2c2t����k.s2c2t�Ļ� this���ǡ�С�����Ǹ���
	}
	int x() {
		return xx;
	}
	int y() {
		return yy;
	}
	int stepSum() {
		return stepNums;
	}
	int curConsume() {
		return s2c;
	}
	void move(int xnext, int ynext) {
		xx = xnext;
		yy = ynext;
	}
};
int EuclidDist(int s1, int s2, int t1, int t2) {
	return (t1 - s1) * (t1 - s1) + (t2 - s2) * (t2 - s2);
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		int s1, s2, t1, t2;
		cin >> s1 >> s2 >> t1 >> t2;
		priority_queue<knight> que;	//���ȶ���Ĭ�ϴ󶥶ѣ���С�ġ���Ҫ���³���Ҳ����s2c2t�Ƚϴ�Ļ���Ҫ���³�
									//ʵ��ʵ����һ��s2c2t��С����
		que.push(knight(s1, s2, 0, EuclidDist(s1, s2, t1, t2)));
		while (!que.empty()) {
			knight k0 = que.top();
			que.pop();

			if (k0.x() == t1 && k0.y() == t2) {
				cout << k0.stepSum() << '\n';
				break;
			}
				
			int steps = k0.stepSum() + 1;
			for (int i = 0; i < 8; ++i) {
				int xnext = k0.x() + dir[i][0];
				int ynext = k0.y() + dir[i][1];
				if (xnext < 1 || ynext < 1 || xnext > 1000 || ynext > 1000)
					continue;
				que.push(knight(xnext, ynext, k0.curConsume() + 5, EuclidDist(xnext, ynext, t1, t2), steps));
			}
		}
	}
	return 0;
}