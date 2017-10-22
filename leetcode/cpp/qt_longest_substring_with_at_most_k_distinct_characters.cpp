/**
* @Author: Tian Qiao
* @Date:   2016-08-04T15:23:03+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-04T15:23:07+08:00
* @Inc: Google
* @Difficulty: Hard
* @Difficulty: Hash Table, String
*/

/**
Given a string, find the length of the longest substring T that contains at most k distinct characters.
For example, Given s = “eceba” and k = 2,
T is "ece" which its length is 3.
*/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size();
        if(k==0 || n==0) return 0;

        int ans = INT32_MIN;
        int start = 0; // 子串起点
        int distinctCnt = 0; //子串中互异字符数目
        vector<int> cnt(128, 0); // 子串中各互异字符的数目
        for(int i=0; i<n; i++) {
            cnt[s[i]]++;
            //if(cnt[s[i]]==1) {
            distinctCnt+=cnt[s[i]]==1;
            while(distinctCnt>k && start<=i) {
                if(--cnt[s[start++]]==0) distinctCnt--;
            }
            //}
            ans = max(ans, i-start+1);
        }
        return ans;
    }
};
