// best
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // it will return nil when prices is empty if delete this line
        if(prices.size() < 2) return 0;
        int profit = 0, i = 0;
        while(i < prices.size() - 1) {
            // find the low value
            while(prices[i] > prices[i+1] && i < prices.size()-1) i++;
            // buy in
            profit -= prices[i];
            // find the high value
            while(prices[i] <= prices[i+1] && i < prices.size()-1) i++;
            // sell out
            profit += prices[i];
        }
        return profit;
    }
};

/**
 * WARNING
 * Why the testcase '[]' will return nil?
 * /
