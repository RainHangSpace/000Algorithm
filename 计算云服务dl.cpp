#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

//华为考题 mid 
//我们将云服务看做一棵树，每个云服务在发布前尚未解决的问题称为云服务的遗留问题（云服务的遗留问题包含以该云服务为根节点的树上所有节点的问题），DI值（遗留问题缺陷密度）可以作为评估云服务发布的指标，当云服务DI值小于等于阈值时才准许云服务发布，否则视为风险云服务，需要问题整改完成后重新进行发布评估。现有一批云服务树，已给出云服务树各节点的问题数量，请通过计算输出风险云服务的个数。
//
//计算公式：DI值≤5×严重问题数＋2×一般问题数，其中每个节点的不同级别问题数量需要将该节点及该节点为根节点的所有子节点的相应级别问题数量求和。
/*
* 第一行输入M和N(M≤100000，N≤1000)，使用空格分隔，M表示代表云服务阈值，N表示接下来有N行问题统计数据；
接下来输入一个N∗4的矩阵表，行内使用空格分隔，第一列Ai为服务节点，第二列Bi为Ai的父节点，如果Ai为云服务则无父节点，此时Bi用∗号表示(Ai和Bi取值为字符串，1≤字符串长度≤5，均由小写英文字母或∗号组成)，第三列Ci为问题级别（Ci取值为{0,1}，0表示严重问题，1表示一般问题），第四列Di为该节点该级别的问题数量(Di≤1000)。
说明：输入保证只出现树的关系，不会出现连通图的情况。
*/
//解法：
/*
* 1 构建数据结构
* 2 遍历
* 3 算法
*/
using namespace std;
template <typename key, typename val>
using umap = unordered_map<key, val>;

template <typename T>
using uset = unordered_set<T>;

uset<string> roots;
umap<string, uset<string>> graph;
umap<string, pair<int, int>> problemNum;

pair<int, int> dfs(const string& cur) {
    if (graph[cur].empty())
        return { problemNum[cur].first, problemNum[cur].second };
    auto [lev1, lev0] = problemNum[cur];
    for (auto& child : graph[cur]) {
        auto [temp1, temp0] = dfs(child);
        lev1 += temp1;
        lev0 += temp0;
    }
    return { lev1, lev0 };
}

int main()
{
    int M, N;
    cin >> M >> N;

    

    //构建数据结构
    for (int i = 0; i < N; ++i) {
        string cur, father;
        int level, num;
        cin >> cur >> father >> level >> num;
        if (father == "*") {
            roots.insert(cur);
        }
        else {
            graph[father].insert(cur);
        }
        if (level == 0) {
            problemNum[cur].first = num;
        }
        else {
            problemNum[cur].second = num;
        }
    }

    int count = 0;
    for (auto& root : roots) {
        auto [lev1, lev0] = dfs(root);
        int di = lev1 * 5 + lev0 * 2;
        if ( di > M)
            ++count;
        cout << "di = " << di << '\n';
    }
    cout << count;
    
    
}

/*//AI给出的算法
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

map<string, set<string>> graph;
map<string, int> lvl1s;
map<string, int> lvl2s;
set<string> fathers;

pair<int, int> dfs(const string& node) {
    int lvl1 = lvl1s[node];
    int lvl2 = lvl2s[node];
    for (const string& child : graph[node]) {
        auto[l1, l2] = dfs(child);
        lvl1 += l1;
        lvl2 += l2;
    }
    return {lvl1, lvl2};
}

int main() {
    int M, N;
    cin >> M >> N;

    for (int i = 0; i < N; ++i) {
        string node, fa;
        int lvl, cnt;
        cin >> node >> fa >> lvl >> cnt;

        if (fa != "*") {
            graph[fa].insert(node);
        } else {
            fathers.insert(node);
        }

        if (lvl == 0) {
            lvl1s[node] = cnt;
        } else {
            lvl2s[node] = cnt;
        }
    }

    int count = 0;
    for (const string& f : fathers) {
        auto [c1, c2] = dfs(f);
        if (5 * c1 + 2 * c2 > M) {
            ++count;
        }
    }

    cout << count << endl;
    return 0;
}
*/
