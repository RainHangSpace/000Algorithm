//测试一下小顶堆在压入相同值的元素时会怎么处理
//结论：小顶堆在插入相同值时，栈顶元素不变，但是由于其是完全二叉树，所以会因为维护树结构而改变压入元素的相同位置
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class node{
public:
    int index;
    int minCost;//节点到原点的最小花费
    node(int i, int mCost):index{i}, minCost{mCost}{;}
    bool operator<(const node& rhs) const {
        return minCost > rhs.minCost;
    }
};

int main() {
    priority_queue<node> pq;
    pq.push(node(1, 1));
    pq.push(node(2, 1));
    pq.push(node(3, 1));
    pq.push(node(4, 1));
    pq.push(node(5, 1));
    pq.push(node(6, 1));
    pq.push(node(7, 1));
    pq.push(node(8, 1));
    pq.push(node(9, 1));
    pq.push(node(0, 1));

    while (!pq.empty()) {
        cout << pq.top().index << '\n';pq.pop();
    }
    cout << endl;
    return 0;
}
