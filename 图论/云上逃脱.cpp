//dijkstra算法题
//在云上多个业务节点之间选择最快的逃生节点集，并考虑每个节
// 点的剩余业务容量。有一个网络时延表，表示每个节点到其他节
// 点的通信延迟；还有一个剩余业务容量表，表示每个节点的剩余
// 业务容量。在一个节点故障时，需要选择一个或多个逃生节点，
// 确保逃生路径的时延最小，并且逃生节点集各节点剩余容量的总
// 和足够容纳故障节点的业务量，当故障节点与多个节点最短距离
// 相同，优先选择编号较小的节点容灾，如果逃生节点集中多个节
// 点最短距离相同时按编号从小到大的顺序排列。
// 编号从0开始
// 4				节点个数
//-1 5 - 1 8		边权重 -1表示无边
//5 - 1 1 3			
//- 1 1 - 1 4
//8 3 4 - 1
//10 20 15 25		各节点能承受的业务量
//2					故障节点编号
//50				需要处理的业务量
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
class node{
public:
    int index;
    int minCost;//节点到原点的最小花费
    node() = default;
    node(int i, int mCost):index{i}, minCost{mCost}{;}
    bool operator<(const node& rhs) const {
        return minCost > rhs.minCost;
    }
    bool operator>(const node& rhs) const {
        return minCost < rhs.minCost;
    }
};
int main() {
    int n;
    cin >> n;
    vector< vector<int> > grid(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    vector<int> nodeCapacity(n);
    for (int i = 0; i < n; ++i) {
        cin >> nodeCapacity[i];
    }
    int start, targetNum;
    cin >> start >> targetNum;
    int end = n - 1;

    vector<int> minDist(n, INT_MAX);
    vector<bool> visited(n);
    priority_queue<node> pq;
    minDist[start] = 0;
    pq.push(node(start, 0));
    while (!pq.empty()) {
        node cur = pq.top();
        pq.pop();

        if(visited[cur.index])continue;
        visited[cur.index] = true;

        for (int i = 0; i < n; ++i) {
            if(grid[cur.index][i] == -1 || visited[i]) continue;
            if(minDist[i] > cur.minCost + grid[cur.index][i]) {
                minDist[i] = cur.minCost + grid[cur.index][i];
                pq.push(node(i, minDist[i]));
            }
        }
    }
    vector<node> resVec(n);
    for (int i = 0; i < n; ++i) {
        resVec[i] = node(i, minDist[i]);
    }
    sort (resVec.begin(), resVec.end(), greater<node>());
    // for (auto i : resVec) {
    //     if (i.index == start) continue;
    //     cout << i.index << ": " << i.minCost << '\n';
    //     targetNum -= nodeCapacity[i.index];
    //     cout << "targetNum = " << targetNum << '\n';
    // }
    for (auto i : resVec) {
        if (i.index == start) continue;
        cout << i.index << ' ';
        targetNum -= nodeCapacity[i.index];
        if (targetNum < 0) break;
    }
    cout << endl;    
}



//#include <iostream>
//#include <vector>
//#include <queue>
//#include <limits>
//#include <functional> // 为了使用greater<>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//
//    vector<vector<int>> matrix(n, vector<int>(n));
//    for (auto& row : matrix) {
//        for (auto& element : row) {
//            cin >> element;
//        }
//    }
//
//    vector<int> remainingCapacity(n);
//    for (auto& capacity : remainingCapacity) {
//        cin >> capacity;
//    }
//
//    int faultNode, cnt;
//    cin >> faultNode >> cnt;
//
//    // Dijkstra
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;//小顶堆
//    vector<int> dist(n, numeric_limits<int>::max());//距离，故障节点到i节点的距离
//    dist[faultNode] = 0;//故障节点到故障节点没有意义
//    pq.push({ 0, faultNode });//故障节点作为初始小顶堆的顶
//
//    while (!pq.empty()) {
//        auto [d, u] = pq.top();//拿出堆顶节点(距离故障节点最近距离的节点)的距离值 和 节点索引
//        pq.pop();
//
//        if (d > dist[u]) continue;//如果堆顶节点到故障节点的距离 大于 堆顶节点到故障节点的距离？？？这里所表达的意思是
//                                    //当dist[u]被更新了多次时，就会出现d比dist[u]大的情况，这说明这个d已经过时了，需要跳过
//        for (int v = 0; v < n; ++v) {
//            if (matrix[u][v] != -1 && dist[v] > d + matrix[u][v]) {
//                dist[v] = d + matrix[u][v];//如果遍历节点到故障节点的距离 大于 遍历节点到堆顶节点再到故障节点的距离 则 更新遍历节点到故障节点的距离
//                pq.push({ dist[v], v });//更新之后再次加入小顶堆
//            }
//        }
//    }
//
//    deque<pair<int, int>> tmp;
//    for (int i = 0; i < n; ++i) {
//        if (dist[i] == numeric_limits<int>::max())continue;//如果有与故障节点不联通的点，跳过
//        tmp.push_back({ dist[i], i });
//    }
//    sort(tmp.begin(), tmp.end());
//
//    vector<int> res;
//    while (cnt > 0 && !tmp.empty()) {
//        auto [d, u] = tmp.front();
//        tmp.pop_front();
//        if (u == faultNode) continue;
//        res.push_back(u);
//        cnt -= remainingCapacity[u];
//    }
//
//    for (auto& id : res) {
//        cout << id << " ";
//    }
//    cout << endl;
//
//    return 0;
//}
// 下面是自己又练习了一遍
//#include <iostream>
//#include <string>
//#include <vector>
//#include <utility>
//#include <functional>
//#include <queue>
//#include <limits>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<vector<int>>graph(n, vector<int>(n));
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < n; ++j) {
//			cin >> graph[i][j];
//		}
//	}
//
//	vector<int>nodeCapacity(n);
//	for (int i = 0; i < n; ++i) {
//		cin >> nodeCapacity[i];
//	}
//
//	int faultNode, neededSaveNum;
//	cin >> faultNode >> neededSaveNum;
//
//	//定义一个小顶堆 用来进行dijkstra算法
//	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//	//定义一个存储各节点到故障节点的距离的向量，初始值为整形最大值；
//	vector<int> dist2fault(n, numeric_limits<int>::max());
//	dist2fault[faultNode] = 0;//故障节点到自己的距离是0；
//
//	pq.push({ dist2fault[faultNode], faultNode });
//	while (!pq.empty()) {
//		auto [CurNodeDist2Fault, CurNode] = pq.top();
//		pq.pop();
//		//除去过时信息
//		if (CurNodeDist2Fault > dist2fault[CurNode])continue;
//		for (int j = 0; j < n; ++j) {
//			if (j == CurNode)continue;
//			if (graph[CurNode][j] != -1 && dist2fault[j] > CurNodeDist2Fault + graph[CurNode][j]) {
//				//如果遍历节点j到故障节点的距离 大于 
//				//故障节点到当前节点 + 当前节点到遍历节点j的距离和
//				//则 更新
//				dist2fault[j] = CurNodeDist2Fault + graph[CurNode][j];
//				pq.push({ dist2fault[j], j });//并压入到小顶堆，因为某个节点更新了，那么所以与之关联的节点都可能需要更新
//			}	
//		}
//	}
//	deque<pair<int, int>> dq;
//	for (int i = 0; i < n; ++i) {
//		if (dist2fault[i] == numeric_limits<int>::max())continue;
//		dq.push_back({ dist2fault[i], i });
//	}
//	sort(dq.begin(), dq.end());
//	
//	for (auto i : dq) {
//		if (i.second == faultNode)continue;
//		cout << i.second << ' ';
//		neededSaveNum -= nodeCapacity[i.second];
//		if (neededSaveNum < 0) break;
//	}
//	return 0;
//}