#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;




class ThroneInheritance {
private:
    unordered_map<string, vector<string>> edges;
    unordered_set<string> deaths;
public:
    ThroneInheritance(string kingName) { edges[kingName] = {}; }

    void birth(string parentName, string childName) {
        edges[parentName].emplace_back(move(childName));
    }

    void death(string name) {
        deaths.insert(name);
    }
    void show() {
        for (auto edge : edges) {
            cout << edge.first << ": ";
            for (auto child : edge.second) {
                cout << child << ' ';
            }
            cout << '\n';
        }
    }
    void dfs_show(string cur) {
        cout << cur << ' ';
        for(auto edge : edges[cur])
            dfs_show(edge);
    }
    vector<string> getInheritanceOrder() {
    }
};

int main() {
    ThroneInheritance A("king");
    A.birth("king", "a");
    A.birth("king", "b");
    A.birth("a", "c");
    A.birth("a", "d");
    A.birth("c", "e");
    A.birth("c", "f");
    A.birth("d", "g");
    A.birth("d", "h");
    
    A.show();
    cout << '\n';
    A.dfs_show("king");


    vector<int> vec0;
    vec0.push_back(1);
    return 0;
}