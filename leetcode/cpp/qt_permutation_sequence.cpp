/**
* @Author: Tian Qiao
* @Date:   2016-07-14T02:08:23+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-14T02:11:39+08:00
* @Inc: Twitter
* @Difficulty: Medium
*/


/*
The set [1,2,3,…,n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.
Note: Given n will be between 1 and 9 inclusive.
*/


class Solution {
public:
    string getPermutation(int n, int k) {
        // k is one-based
        k--;
        string s;
        vector<int> increase(n,1);
        iota(increase.begin(), increase.end(), 1);

        vector<int> factorial(n+1, 1);
        for(int i=1; i<=n; i++) {
            factorial[i] = factorial[i-1]*i;
        }

        for(int i=0; i<n; i++) {
            // 第0位到第n-1位
            int idx = k/factorial[n-1-i];
            int digit = idx>=n?increase[0]:increase[idx];
            increase.erase(increase.begin()+idx);
            k = k%factorial[n-1-i];
            s+=to_string(digit);
        }
        return s;
    }
};
