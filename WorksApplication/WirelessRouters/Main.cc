/*
Input
The first line is two integers N(2<=N<=1000), M(1<=M<=N, M<=100) Then are N lines, each shows the satisfation S[i](1<=S[i]<=10) point of room i. Then are N-1 lines, each contains two integers x, y, which represents a door is between room x and y.

Output
Just output the maximum point of satisfation.

Limits
 Memory limit per test: 256 megabytes
 Time limit per test: The faster the better
*/

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
