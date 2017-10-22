/**
* @Author: Tian Qiao
* @Date:   2016-07-25T00:45:22+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-25T00:45:28+08:00
* @Inc: Facebook
* @Difficulty: Hard
*/


/*
There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Follow up:
Could you solve it in O(nk) runtime?
*/

// Key:
// 通过记录最小值和次小值，可以求得子数组最小值
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.empty() || costs[0].empty()) return 0;
        int n = costs.size();
        int k = costs[0].size();

        vector<int> minCosts(k, 0);
        int smallest = 0, second_smallest = 0;
        for(int i=0; i<n; i++) {
            vector<int> cacheCosts = minCosts;
            for(int j=0; j<k; j++) {
                minCosts[j] = (cacheCosts[j]==smallest?second_smallest:smallest)+costs[i][j];
                //cout << minCosts[j] << endl;
            }

            second_smallest = INT32_MAX, smallest = INT32_MAX;
            for(int j=0; j<k; j++) {
                second_smallest = minCosts[j]<=smallest?smallest:min(second_smallest, minCosts[j]);
                smallest = min(smallest, minCosts[j]);
            }
            //cout << smallest << " " << second_smallest << endl;
        }

        int ans = INT32_MAX;
        for(auto i:minCosts) ans = min(ans, i);

        return ans;
    }
};
