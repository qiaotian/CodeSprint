/**
* @Author: Tian Qiao
* @Date:   2016-07-19T21:44:05+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-19T21:44:39+08:00
* @Inc: Google
* @Difficulty: Meidum
*/

/*
We are playing the Guess Game. The game is as follows:
I pick a number from 1 to n. You have to guess which number I picked.
Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.
However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.

Example:
n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.
You end up paying $5 + $7 + $9 = $21.
Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.

Hint:
1. The best strategy to play the game is to minimize the maximum loss you could possibly face. Another strategy is to minimize the expected loss. Here, we are interested in the first scenario.
2. Take a small example (n = 3). What do you end up paying in the worst case?
Check out this article if you're still stuck.
3. The purely recursive implementation of minimax would be worthless for even a small n. You MUST use dynamic programming.
4. As a follow-up, how would you modify your code to solve the problem of minimizing the expected loss, instead of the worst-case loss?
*/

// "maxmin": 求出x从1到n的所有最小花费，中找到最大的那只返回
class Solution {
public:
    int pay(vector<vector<int>>& dp, int s, int e) {
        int ans = INT32_MAX;
        if(s >= e) return 0;
        if(dp[s][e] != 0) return dp[s][e];
        for(int i=s; i<=e; i++) {
            int tmp = i + max(pay(dp, s, i-1), pay(dp, i+1, e));
            ans = min(ans, tmp);
        }
        dp[s][e] = ans;
        return ans;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        return pay(dp, 1, n);
    }
};
