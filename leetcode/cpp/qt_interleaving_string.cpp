/**
* @Author: Tian Qiao
* @Date:   2016-07-22T18:10:38+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-22T18:10:50+08:00
* @Difficulty: Hard (Medium Actually)
*/


/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/


// TLE(用递归BackTracking, 可以预见会超时，一定使用DP)
// for test case
/*
"bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa"
"babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab"
"babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab"
*/
/*
class Solution {
public:
    bool helper(string& s1, string& s2, string& s3, int i, int j, int k) {
        if(i>=s1.size() && j>=s2.size() && k>=s2.size()) return true;

        if(s1[i]!=s3[k] && s2[j]!=s3[k]) return false;

        if(i<s1.size() && s1[i]==s3[k] && helper(s1, s2, s3, i+1, j, k+1)) return true;
        if(j<s2.size() && s2[j]==s3[k] && helper(s1, s2, s3, i, j+1, k+1)) return true;

        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.empty()||s2.empty()) return s1+s2==s3;
        if(s1.size()+s2.size() != s3.size()) return false;
        return helper(s1, s2, s3, 0, 0, 0);
    }
};*/

// O(M*N)
class Solution {
public:
    vector<vector<int>> dp;
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if(n1+n2!=n3) return false;
        dp.resize(n1+1, vector<int>(n2+1, -1));

        for(int i=0; i<=n1; i++) {
            // i is the amount of characters provided by s1
            for(int j=0; j<=n2; j++) {
                // j is the amount of characters provided by s2
                if(i==0 && j==0) {
                    dp[i][j]=i+j;
                }
                else if(i==0 && j!=0) {
                    if(s2[j-1]==s3[i+j-1] && dp[i][j-1]==i+j-1) dp[i][j] = i+j;
                }
                else if(i!=0 && j==0) {
                    if(s1[i-1]==s3[i+j-1] && dp[i-1][j]==i+j-1) dp[i][j] = i+j;
                }
                else{
                    if((s1[i-1]==s3[i+j-1] && dp[i-1][j]==i+j-1)||\
                       (s2[j-1]==s3[i+j-1] && dp[i][j-1]==i+j-1)) dp[i][j] = i+j;
                }
            }
        }
        return dp[s1.size()][s2.size()]==s1.size()+s2.size();
    }
};
