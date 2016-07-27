/**
* @Author: Tian Qiao
* @Date:   2016-07-26T13:29:24+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-26T13:29:32+08:00
* @Inc: Microsoft
* @Difficulty: Hard
* @Tag: Binary Search Tree, DP
*/

/*
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.
Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.


Notes:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
*/


// 错误解法
// max(min(val))
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = m==0?0:dungeon[0].size();
        vector<vector<int>> remain(m, vector<int>(n, 0)); //路径上当前最大存血量
        vector<vector<int>> damage(m, vector<int>(n, 0)); //路径上历史最低存血量

        remain[0][0] = dungeon[0][0];
        damage[0][0] = dungeon[0][0];
        for(int i=1; i<m; i++) {
            remain[i][0] = remain[i-1][0]+dungeon[i][0];
            damage[i][0] = min(damage[i-1][0], remain[i][0]);
        }
        for(int j=1; j<n; j++) {
            remain[0][j] = remain[0][j-1]+dungeon[0][j];
            damage[0][j] = min(damage[0][j-1], remain[0][j]);
        }
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                remain[i][j] = max(remain[i-1][j], remain[i][j-1])+dungeon[i][j];
                damage[i][j] = min(remain[i][j], max(damage[i-1][j], damage[i][j-1]));
            }
        }
        return damage[m-1][n-1]>=0?1:(-1*damage[m-1][n-1]+1);
    }
};


// https://discuss.leetcode.com/topic/6912/c-dp-solution
// 更多解释: http://bookshadow.com/weblog/2015/01/07/leetcode-dungeon-game/
// Use hp[i][j] to store the min hp needed at position (i, j),
// then do the calculation from right-bottom to left-up.
class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int M = dungeon.size();
        int N = dungeon[0].size();
        // hp[i][j] represents the min hp needed at position (i, j)
        // Add dummy row and column at bottom and right side
        vector<vector<int> > hp(M + 1, vector<int>(N + 1, INT_MAX));
        //int hp[M+1][N+1] = {INT_MAX}; 二维数组初始化不能用这种形式
        hp[M][N - 1] = 1; // 经过最后一关hp[M-1][N-1]向下行走至少剩下1滴血
        hp[M - 1][N] = 1; // 经过最后一关hp[M-1][N-1]向右行走至少剩下1滴血
        for (int i = M - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                int need = min(hp[i + 1][j], hp[i][j + 1]) - dungeon[i][j];
                hp[i][j] = need <= 0 ? 1 : need;
            }
        }
        return hp[0][0];
    }
};
