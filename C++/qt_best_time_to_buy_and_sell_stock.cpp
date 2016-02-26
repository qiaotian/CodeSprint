class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int minprice = INT32_MAX;
        for(int price : prices) {
            if(price < minprice) minprice = price;
            res = max(res, price - minprice);
        }
        return res;
    }
};
