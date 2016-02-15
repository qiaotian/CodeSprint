// Greedy method is wrong
/*
class Solution {
public:
    int dp(int amount, int top, vector<int>& coins) {
        // amount: the remaining balance
        // top: the index of the largest coin avaiable now
        if(amount==0) return 0;
        for(int i=top; i>=0; i--) {
            if(amount < coins[i]) continue;
            int steps = dp(amount-coins[i], i, coins);
            if(steps != -1) return steps+1;
        }
        return -1;
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        return dp(amount, coins.size()-1, coins);
    }
};
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT32_MAX);
        dp[0] = 0;
        for(auto coin : coins) {
            // recalculte(update) the minmum number of coins needed when new kind of 
            // coin taken into consideration
            for(int i=coin; i<=amount; i++) {
                if(dp[i-coin] != INT32_MAX) dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }
        return dp[amount]==INT32_MAX?-1:dp[amount];
    }
};


/**
 * WARNING
 * greedy method cannot solve this problem, for instance coins = {1, 4, 6}, amount = 8
 * the right ans is {4, 4}, however outputs {6, 1, 1}.
 * 
 * REFERENCE
 * https://segmentfault.com/a/1190000004212264
 * 
 * /
