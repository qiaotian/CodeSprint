#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, m;
    vector<int> stfa; // the satisfation point list
    vector<pair<int, int>> cnct; // the connections among rooms
    cin >> n >> m;
    int tmp;
    for(int i=0; i<n; i++) stfa.push_back(cin >> tmp);
    for(int i=0; i<n-1; i++) cnct.push_back({cin >> tmp, cin >> tmp});

    vector<vector<int>> neigbs(n+1, vector<int>());
    for(auto p:cnct) {
        neigbs[p.first].push_back(p.second);
        neigbs[p.second].push_back(p.first);
    }

    int ans = 0;
    for(auto i:neigbs) {
        for(aut)
    }

    return 0;
}
