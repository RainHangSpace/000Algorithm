#include <string>
#include <iostream>
using namespace std;
int getStr(string& s) {
    int slow = 0;
    int fast = 0;
    while (fast < s.size()) {
        if (s[fast] != '#') {
            s[slow++] = s[fast++];
        }
        else {
            --slow;
            ++fast;
        }
    }
    return slow;
}
int main() {
    string s = "ab#c";
    int s_size = getStr(s);
    s.resize(s_size);
    for (auto i : s) {
        cout << i;
    }
    cout << endl;

    return 0;
}