/**
* @Author: Tian Qiao
* @Date:   2016-07-04T18:19:33+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-04T18:42:58+08:00
* @Inc: LinkedIn
* @Difficulty: Medium
*/



_______________________________________________________________________________
There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.
_______________________________________________________________________________


class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        // 第i栋房子涂成红、绿、蓝三种颜色的最低开销
        if(costs.empty()) return 0;

        int minR = costs[0][0], minG = costs[0][1], minB = costs[0][2];
        for(int i=1; i<costs.size(); i++) {
            int cacheR = minR, cacheG = minG, cacheB = minB;
            minR = min(cacheG, cacheB) + costs[i][0];
            minG = min(cacheR, cacheB) + costs[i][1];
            minB = min(cacheR, cacheG) + costs[i][2];
        }
        return min(minR, min(minG, minB));
    }
};
