#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> stfa;            // the satisfation of all rooms
    vector<pair<int, int>> cnct; // the connections among rooms, no cycle inside
    vector<vector<int>> neigbs(n+1, vector<int>()); // the neighbours of all rooms
    //unordered_map<int, vector<int>> neigbs;
    vector<int> total(n, 0);     // the total satisfation of all rooms

    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        stfa.push_back(tmp);
    }
    for(int i=0; i<n-1; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        cnct.push_back({tmp1, tmp2});
    }
    for(auto p:cnct) {
        neigbs[p.first-1].push_back(p.second-1);
        neigbs[p.second-1].push_back(p.first-1);
    }
    for(int i=0; i<n; i++) {
        int t = stfa[i];
        for(auto r:neigbs[i]) t += stfa[r];
        total[i] = t;
    }

    int ans = 0;
    for(int i=0; i<m; i++) {
        // find the max satisfaction value
        int maxRoom = 0;
        for(int j=0; j<n; j++) {
            if(total[j]>total[maxRoom]) maxRoom = j;
        }
        //
        ans += total[maxRoom];
        //
        total[maxRoom] = 0;
        for(auto r:neigbs[maxRoom]) {
            total[r] = total[r]-stfa[maxRoom]-stfa[r];
            for(auto s:neigbs[r]) total[s] -= stfa[r];
            stfa[r] = 0;
        }
        stfa[maxRoom] = 0;
    }
    cout << ans << endl;

    return 0;
}
