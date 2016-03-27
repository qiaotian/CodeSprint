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

// Time: O(N*N*M)

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int increase_charisma_points(vector<vector<int>>&costs, int M) {
    int ans = INT32_MIN;
    int N = costs.size();
    vector<vector<int>> dp(N, vector<int>(M+1, INT32_MAX));
    for(int i=0; i<N; i++) dp[i][0] = 0;

    // 优化：统计计算过程中已经使用超过M个action points节点的个数，如果
    // 数目达到N个，那么说明所有节点都已经超过M action points，直接跳出
    // 返回ans
    // 更进一步优化是当数目达到N-1个时就跳出，因为N-1超出M action points,
    // 那么下一步一定会全部超过M，因此可以提前返回ans
    unordered_set<int> finished;
    
    // 计算从j节点出发挣i个charisma points，事少需要多少action points
    for(int i=1; i<=M; i++) {
        for(int j=0; j<N; j++) {
            //if(dp[j].back()>M) continue; 
            // 对于第j个节点
            for(int k=0; k<N; k++) {
                // 第k个节点到第j个节点
                if(k==j) continue;
                dp[j][i] = min(dp[k][i-1]+costs[k][j], dp[j][i]);
                if(dp[j][i]<=M) ans = max(ans, dp[j][k]);
                else finished.insert(j);
                if(finished.size()==N-1) return ans;
            }
        }
    }

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


