/*
 *


Given a string s and a string t, check if s is subsequence of t.

You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
s = "abc", t = "ahbgdc"

Return true.

Example 2:
s = "axc", t = "ahbgdc"

Return false.

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

 *
 *
 */

// two pointers i and j
class Solution {
public:
    bool isSubsequence(string s, string t) {
        for(int i=0, j=0; i<s.size(); i++) {
            while(j<t.size() && t[j]!=s[i]) j++;
            if(j>=t.size()) return false;
            j++; // t[j]==s[i]的时候j也需要自增
        }
        return true;
    }
};

// Official method is to use DP and Binary Search
class Solution {
public:
    bool isSubsequence(string s, string t) {
        //build a record to store the index of each char in t
        vector<vector<int>> record(26);
        //add positions for all 26 characters
        for(int i = 0; i < t.size(); i++) {
            record[t[i]-'a'].push_back(i);
        }
        //check if each char in s is in the legal place
        int index = -1;
        for(int i = 0; i < s.size(); i++) {
			// find the first index that greater than "index"
            auto iter = upper_bound(record[s[i]-'a'].begin(), record[s[i]-'a'].end(), index);
            if(iter == record[s[i]-'a'].end()) return false;
            index = *iter;
        }
        return true;
    }
};
