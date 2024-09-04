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
	int s2c, c2t, s2c2t;//s,c,t 分别是起点 当前点 终点
			//需要注意的是s2c是当前的消耗，是已经实际走了多少步
			//而c2t是预估消耗
	int stepNums;
public:
	knight(int x, int y, int s2c, int c2t, int steps = 0) :
		xx{ x }, yy{ y }, s2c{ s2c }, c2t{ c2t }, s2c2t{s2c + c2t}, stepNums(steps) {	
	}
	bool operator < (const knight& k) const {
		return k.s2c2t < s2c2t;
		//这里的意思是：“this.s2c2t大于k.s2c2t的话 this就是‘小’的那个”
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
		priority_queue<knight> que;	//优先队列默认大顶堆，“小的”就要往下沉，也就是s2c2t比较大的话就要放下沉
									//实则实现了一个s2c2t的小顶堆
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