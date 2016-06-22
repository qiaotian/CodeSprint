/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-03-06T19:00:06+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-06-21T19:31:33+08:00
* @License: Free License
*/

// @注意： i次购买j是甩卖的最大获益并非一定要用i次购买j次售卖，i、j只是上限次数

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k == 0) return 0;
        if (k>n/2) {
            int ans = 0;
            for (int i=1; i<n; ++i){
                ans += max(prices[i] - prices[i-1], 0);
            }
            return ans;
        }

        vector<vector<long>> states(2, vector<long>(2*k, INT32_MIN));
        int curr = 0, next = 1;
        for(int i = 0; i < 2*k; i++) {
            if(i%2) {
                states[0][i] = 0;
                states[1][i] = 0;
            }
        }

        long res = INT32_MIN;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 2*k; j++) {
                if(j == 0) {
                    states[next][j] = max(states[curr][j], -(long)prices[i]);
                    continue;
                }
                states[next][j] = max(states[curr][j], states[curr][j-1]+(j%2?1:-1)*prices[i]);
                res = max(res, states[next][j]);
            }
            swap(next, curr);
        }

        return (int)res;
    }
};


// 内存消耗减小一半
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k<1) return 0;

        int n = prices.size();
        if (k > n/2){
            int ans = 0;
            for (int i=1; i<n; ++i){
                ans += max(prices[i] - prices[i-1], 0);
            }
            return ans;
        }

       //  int states[2*k]= {INT32_MIN}; 只有第一个被成功赋值
        vector<int> states(2*k, INT32_MIN);
        for(int i = 0; i < 2*k; i++) {
            // init all buy with negative infinite
            // init all sell with zeros
            if(i%2) states[i] = 0;
        }

        int res = INT32_MIN;
        int pre, cur = 0; // 将当前和前一个状态缓存，以免被覆盖
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 2*k; j++) {
                cur = states[j];
                if(j == 0) states[j] = max(states[j], -prices[i]);
                else states[j] = max(states[j], pre+(j%2?1:-1)*prices[i]);
                pre = cur;
                res = max(res, states[j]);
            }
        }

        return res;
    }
};


/**
 * 当k过大时，即k的数目已经超过实际最大交易数，
 * 那么这种情况应当做单独考虑
 * 否则会超时，并出错
 * /
