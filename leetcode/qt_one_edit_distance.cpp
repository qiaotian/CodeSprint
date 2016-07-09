/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-10T02:45:31+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-10T03:53:08+08:00
* @Inc: Snapchat, Uber, Faceboot, Twitter
* @Difficulty: Medium
*/

/*
Given two strings S and T, determine if they are both one edit distance apart.
*/

// TLE
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size();
        int m = t.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        //iota(dp[0].begin(), dp[0].end(), 0);
        for(int i=0; i<m+1; i++) dp[0][j] = i;
        for(int i=0; i<n+1; i++) dp[i][0] = i;

        for(int i=1; i<m+1; i++) {
            for(int j=1; j<n+1; j++) {
                if(s[i-1]==t[j-1]) DP[i][j] = DP[i-1][j-1];
                else {
                    DP[i][j] = min(DP[i-1][j-1]+1, min(DP[i-1][j]+1, DP[i][j-1]+1));
                }
            }
        }
        return DP[m][n]==1;
    }
};


// https://discuss.leetcode.com/category/169/one-edit-distance
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.length(), n = t.length();
        if (m > n) return isOneEditDistance(t, s);
        if (n - m > 1) return false;
        bool mismatch = false;
        for (int i = 0; i < m; i++) {
            if (s[i] != t[i]) {
                if (m == n) s[i] = t[i];
                else s.insert(i, 1, t[i]);
                mismatch = true;
                break;
            }
        }
        return (!mismatch && n - m == 1) || (mismatch && s == t);
    }
};
