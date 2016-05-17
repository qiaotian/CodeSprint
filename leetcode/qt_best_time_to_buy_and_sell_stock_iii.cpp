// DP
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int states[2][4] = {INT_MIN, 0, INT_MIN, 0}; // 0: 1 buy, 1: one buy/sell, 2: 2 buys/1 sell, 3, 2 buys/sells
        int len = prices.size(), i, cur = 0, next =1;
        for(i=0; i<len; ++i)
        {
            states[next][0] = max(states[cur][0], -prices[i]);
            states[next][1] = max(states[cur][1], states[cur][0]+prices[i]);
            states[next][2] = max(states[cur][2], states[cur][1]-prices[i]);
            states[next][3] = max(states[cur][3], states[cur][2]+prices[i]);
            swap(next, cur);
        }
        return max(states[cur][1], states[cur][3]);
    }
};

/**
 * 动态规划的过程中，往往需要记录不止一个状态，
 * 不仅迭代之间有依赖关系，一次迭代内的状态之间也可能会有依赖关系
 * Wrong idea:
 * find out four integers a, b, c and d (a < b < c < d) to 
 * maxmize prices[d] - prices[c] + prices[b] - prices[a]
 *
 * Right idea:
 * https://leetcode.com/discuss/48151/my-c-solution-o-n-time-o-1-space-8ms
 * /
