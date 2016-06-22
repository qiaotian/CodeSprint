/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-06-22T20:17:26+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-06-22T20:17:53+08:00
* @License: Free License
*/


Given n pieces of wood with length L[i] (integer array). Cut them into small pieces to guarantee you could have equal or more than k pieces with the same length. What is the longest length you can get from the n pieces of wood? Given L & k, return the maximum length of the small pieces.

@Example
For L=[232, 124, 456], k=7, return 114.

@Challenge
O(n log Len), where Len is the longest length of the wood.


class Solution {
public:
    /**
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    /*
    int woodCut(vector<int> L, int k) {
        // write your code here
        long long sum = 0;
        int minValue = INT32_MAX;
        for(auto i:L) {
            sum+=i;
            minValue = min(minValue, i);
        }
        //int len = min((int)(sum/k), minValue); 不合理
        //int len = minValue;
        int len = (int)(sum/k);

        for(int i=len; i>0; i--) {
            int pieces = 0; // 段数
            for(auto j:L) {
                pieces += j/i;
            }
            if(pieces>=k) return i;
        }
        return -1;
    }
    */
    // 1. 求和会有溢出问题
    // 2. 某些木头可能没有用到，如果k很小，因此将答案的上限设置为最短木材不合理
    // 3. 解法思路有误

    // given the lenght of single small piece, return the number of pieces
    int count(vector<int>& L, int len) {
        int num = 0;
        for(auto i:L) {
            num+=i/len;
        }
        return num;
    }
    int woodCut(vector<int> L, int k) {
        if(L.empty()) return 0;
        //sort(L.begin(), L.end());
        int maxValue = INT32_MIN;

        for(auto i:L) maxValue = max(maxValue, i);

        long ll = 1, rr = maxValue;
        while(ll<=rr) {
            long mid = (ll+rr)/2;
            if(count(L, mid) >= k) ll = mid+1;
            else rr = mid-1;
        }
        return (int)rr;
    }
};
