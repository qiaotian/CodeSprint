/**
* @Author: Tian Qiao
* @Date:   2016-07-27T23:04:43+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-27T23:05:06+08:00
* @Difficulty: Hard
*/

/*
Given a pattern and a string str, find if str follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.

Examples:
pattern = "abab", str = "redblueredblue" should return true.
pattern = "aaaa", str = "asdasdasdasd" should return true.
pattern = "aabb", str = "xyzabcxzyabc" should return false.
*/

// Hash + BackTracking
class Solution {
public:
    unordered_map<char, string> pDict;
    unordered_map<string, char> sDict;
    bool wordPatternMatch(string pattern, string str) {
        return match(pattern, 0, str, 0);
    }

    bool match(string &pattern, int i, string &str, int j) {
        int m = pattern.size();
        int n = str.size();

        if(i==m && j==n) return true;
        if(i==m && j!=n) return false;
        if(i!=m && j==n) return false;

        bool inserted = false; //是否插入新值
        for (int k=j; k<n; k++) {
            string s = str.substr(j, k - j + 1);
            if (pDict.find(pattern[i]) != pDict.end()) {
                if (pDict[pattern[i]] != s) continue;
            } else if (sDict.find(s) != sDict.end()) {
                if (sDict[s] != pattern[i]) continue;
            } else {
                pDict[pattern[i]] = s;
                sDict[s] = pattern[i];
                inserted = true;
            }

            if (match(pattern, i + 1, str, k + 1)) return true;

            if (inserted) {
                pDict.erase(pattern[i]);
                sDict.erase(s);
            }
        }
        return false;
    }
};
