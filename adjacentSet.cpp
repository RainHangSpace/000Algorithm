//https://kamacoder.com/problempage.php?pid=1179
#include <vector>
#include <iostream>

using namespace std;

class unionSet {
private:
    vector<int> root;
public:
    unionSet(int n) {
        root.resize(n);
        for (int i = 1; i < root.size(); ++i)
            root[i] = i;
    }

    // void init();

    int find(int cur);

    bool isSame(int cur1, int cur2);

    void join(int father, int son);
};

// void unionSet::init() {

// }

int unionSet::find(int cur) {
    return cur == root[cur] ? cur : root[cur] = find(root[cur]);
}

bool unionSet::isSame(int cur1, int cur2) {
    cur1 = find(cur1);
    cur2 = find(cur2);
    return cur1 == cur2;
}

void unionSet::join(int father, int son) {
    father = find(father);
    son = find(son);
    if (father == son) return;
    root[son] = father;
    return;
}

int main() {
    int n, m;
    cin >> n >> m;
    unionSet unionSet1(n + 1);
    // union1.init();
    int s, t;
    while (m--) {
        cin >> s >> t;
        unionSet1.join(s, t);
    }
    cin >> s >> t;
    if (unionSet1.isSame(s, t)){
        cout << 1 << endl;
        return 0;
    }
    cout << 0 << endl;
    return 0;
}