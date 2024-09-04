#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    // vector<string> path = vector<string>(1, "JFK");
    vector<string> pathVec = vector<string>(1, "JFK");
    void backTracking(vector<string>& res, vector<vector<string>>& tickets, vector<bool>& used, string path) {
        //cout<<"pathVec.size: "<< pathVec.size() << endl;
        if (pathVec.size() >= tickets.size() + 1) {
            // cout << "pathVec:\n";
            // for(auto i : pathVec)
            //     cout << i << ' ';
            // cout << endl;
            if (!res.empty() && res > pathVec)
                res = pathVec;
            if (res.empty())res = pathVec;
            // cout << "res:\n";
            // for(auto i : res)
            //     cout << i << ' ';
            // cout << endl;
            return;
        }
        for (int i = 0; i < tickets.size(); ++i) {
            if (tickets[i][0] != path)continue;
            if (used[i])continue;
            if (i > 0 && tickets[i] == tickets[i - 1] && used[i] == false)continue;
            // path = tickets[i][1];
            pathVec.push_back(tickets[i][1]);
            used[i] = true;
            // pathVec.push_back(path);
            backTracking(res, tickets, used, tickets[i][1]);
            used[i] = false;
            pathVec.pop_back();
        }
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        // for(auto i : tickets){
        //     for(auto j : i)
        //         cout << j << ' ';
        // }

        // sort(tickets.begin(), tickets.end());
        sort(tickets.begin(), tickets.end());
        pathVec.clear();
        pathVec.push_back("JFK");
        vector<bool> used(tickets.size(), false);
        backTracking(res, tickets, used, "JFK");
        // cout << '\nres: ';
        // for(auto i : res)
        //     cout << i << ' ';
        // cout << endl;
        return res;
    }
};

int main() {
    Solution A;
    vector<vector<string>> tickets = { {"AXA","EZE"},{"EZE","AUA"},{"ADL","JFK"},{"ADL","TIA"},{"AUA","AXA"},{"EZE","TIA"},{"EZE","TIA"},{"AXA","EZE"},{"EZE","ADL"},{"ANU","EZE"},{"TIA","EZE"},{"JFK","ADL"},{"AUA","JFK"},{"JFK","EZE"},{"EZE","ANU"},{"ADL","AUA"},{"ANU","AXA"},{"AXA","ADL"},{"AUA","JFK"},{"EZE","ADL"},{"ANU","TIA"},{"AUA","JFK"},{"TIA","JFK"},{"EZE","AUA"},{"AXA","EZE"},{"AUA","ANU"},{"ADL","AXA"},{"EZE","ADL"},{"AUA","ANU"},{"AXA","EZE"},{"TIA","AUA"},{"AXA","EZE"},{"AUA","SYD"},{"ADL","JFK"},{"EZE","AUA"},{"ADL","ANU"},{"AUA","TIA"},{"ADL","EZE"},{"TIA","JFK"},{"AXA","ANU"},{"JFK","AXA"},{"JFK","ADL"},{"ADL","EZE"},{"AXA","TIA"},{"JFK","AUA"},{"ADL","EZE"},{"JFK","ADL"},{"ADL","AXA"},{"TIA","AUA"},{"AXA","JFK"},{"ADL","AUA"},{"TIA","JFK"},{"JFK","ADL"},{"JFK","ADL"},{"ANU","AXA"},{"TIA","AXA"},{"EZE","JFK"},{"EZE","AXA"},{"ADL","TIA"},{"JFK","AUA"},{"TIA","EZE"},{"EZE","ADL"},{"JFK","ANU"},{"TIA","AUA"},{"EZE","ADL"},{"ADL","JFK"},{"ANU","AXA"},{"AUA","AXA"},{"ANU","EZE"},{"ADL","AXA"},{"ANU","AXA"},{"TIA","ADL"},{"JFK","ADL"},{"JFK","TIA"},{"AUA","ADL"},{"AUA","TIA"},{"TIA","JFK"},{"EZE","JFK"},{"AUA","ADL"},{"ADL","AUA"},{"EZE","ANU"},{"ADL","ANU"},{"AUA","AXA"},{"AXA","TIA"},{"AXA","TIA"},{"ADL","AXA"},{"EZE","AXA"},{"AXA","JFK"},{"JFK","AUA"},{"ANU","ADL"},{"AXA","TIA"},{"ANU","AUA"},{"JFK","EZE"},{"AXA","ADL"},{"TIA","EZE"},{"JFK","AXA"},{"AXA","ADL"},{"EZE","AUA"},{"AXA","ANU"},{"ADL","EZE"},{"AUA","EZE"} };
    vector<string> res = A.findItinerary(tickets);
    for (auto i : res)
        cout << i << ' ';
    cout << endl;
}