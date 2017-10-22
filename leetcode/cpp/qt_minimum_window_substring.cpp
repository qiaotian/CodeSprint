/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

// 1. Use two pointers: start and end to represent a window.
// 2. Move end to find a valid window.
// 3. When a valid window is found, move start to find a smaller window.

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> count(128,0);
        for(auto c: t) count[c]++;
        // counter represents the number of chars of t to be found in s.
        size_t start = 0, end = 0, counter = t.size(), minStart = 0, minLen = INT_MAX;
        size_t size = s.size();

        // Move end to find a valid window.
        while (end < size) {
            // If char in s exists in t, decrease counter
            if (count[s[end]] > 0) counter--;
            // Decrease m[s[end]]. If char does not exist in t, m[s[end]] will be negative.
            count[s[end]]--;
            end++;
            // When we found a valid window, move start to find smaller window.
            while (counter == 0) {
                if (end - start < minLen) {
                    minStart = start;
                    minLen = end - start;
                }
                count[s[start]]++;
                // When char exists in t, increase counter.
                if (count[s[start]] > 0)
                    counter++;
                start++;
            }
        }
        if (minLen != INT_MAX)
            return s.substr(minStart, minLen);
        return "";
    }
};

/**
 * 该问题属于子字符串问题
 *     该类问题有通用模板
 * /

