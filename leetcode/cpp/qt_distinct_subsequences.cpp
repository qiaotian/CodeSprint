/**
 * Delete some letters in string S to make S equals T
 */

class Solution {
public:
    int numDistinct(string s, string t) {
        int slen = s.size();
        int tlen = t.size();

        if(slen==0 || slen < tlen) return 0;

        vector<vector<int>> dp(slen+1, vector<int>(tlen+1, 0));

        //dp[0][0] = 1;
        for(int i=0; i<=slen; i++) dp[i][0] = 1;
        //for(int i=1; i<tlen; i++) dp[0][i] = 0;
        for(int i=1; i<=slen; i++) {
            for(int j=1; j<=i && j<=tlen; j++) {
                if(s[i-1]==t[j-1])
                    dp[i][j] = dp[i-1][j]+dp[i-1][j-1];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[slen][tlen];
    }
};
