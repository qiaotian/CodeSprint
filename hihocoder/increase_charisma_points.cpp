/*

Time Limit:10000ms
Case Time Limit:1000ms
Memory Limit:256MB
Description
Little Ho is playing a role-playing game. There are N cities in the game which are numbered from 1 to N. Every time Little Ho moves to another city his charisma (a kind of character attribute) will increase by 1 point no matter whether the city is visited before. For example if Little Ho’s moving path is 1->2->3->2->3->1 his charisma will increase by 5.

Little Ho wants to maximize his charisma. However moving between cities costs action points. More precisely moving from city i to city j costs him Aij action points. Little Ho wants to know how many points of charisma he can get by using no more than M action points? He may start at any city.

Input
Line 1: N and M, the number of cities and the initial action points.

Line 2~N+1: An N x N matrix A. Aij is the action point cost as described above.

For 30% of the data: 2≤N≤5，1≤M≤50，0≤Aij≤10

For 60% of the data: 2≤N≤50，1≤M≤2000，0≤Aij≤10

For 100% of the data: 2≤N≤100，1≤M≤1,000,000,000，0≤Aij≤20

Output
The maximum points of charisma Little Ho can get.

Sample Hint
The optimal path is 1->2->3->1->2.


Sample Input
3 10
0 2 3
4 0 2
3 4 0
Sample Output
4

*/

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int increase_charisma_points(vector<vector<int>>&costs, int M) {
    int ans = INT32_MIN;

    return ans;
}

int main(void) {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> costs(N, vector<int>(N, 0));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> costs[i][j];
        }
    }
    
    int ans = increase_charisma_points(costs, M);
    cout << ans <<endl;

    return 0;
}


