/**
* @Author: Tian Qiao
* @Date:   2016-08-04T14:47:55+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-04T14:48:04+08:00
* @Inc: Google
* @Difficulty: Hard
* @Tag: Hash Table, Two pointer, String
*/


/*
Given a string, find the length of the longest substring T that contains at most 2 distinct characters.
For example, Given s = “eceba”,
T is "ece" which its length is 3.
*/

// 本解决方案中
// Two Pointers 分别是start和i两个指针，分别指向substring的首尾
// Hash 体现在对互异字符的计数上
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int ans = INT32_MIN;

        if(s.size()<2) return s.size();

        int distinctCnt = 0;
        int start = 0;
        //vector<int> cnt(26, 0); // 初始化26个字符数为0
        vector<int> cnt(128, 0); // 区分大小写
        for(int i=0; i<s.size(); i++) {
            cnt[s[i]]++;
            if(cnt[s[i]]==1) {
                distinctCnt++;
                while(distinctCnt > 2 && start<i) {
                    if(--cnt[s[start]]==0) distinctCnt--;
                    start++;
                }
            }
            ans = max(ans, i-start+1);
        }

        return ans;
    }
};


// https://discuss.leetcode.com/topic/11739/clean-11-lines-ac-answer-o-1-space-o-n-time/2
// I think it uses i and j to track the last indices of two characters.
// i is tracking the first character, j is tracking the second character.
// But I still like the hashmap solution because we can easily extend that solution to K distinct characters.
class Solution{
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int i = 0, j = -1;
        int maxLen = 0;
        for (int k = 1; k < s.size(); k++) {
            if (s[k] == s[k-1]) continue;
            if (j > -1 && s[k] != s[j]) {
                maxLen = max(maxLen, k - i);
                i = j + 1;
            }
            j = k - 1;
        }
        return maxLen > (s.size() - i) ? maxLen : s.size() - i;
    }
};
