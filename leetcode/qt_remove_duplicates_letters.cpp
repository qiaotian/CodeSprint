/*
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"
*/


// 1st solution (Slow)
/*
class Solution {
public:
    string removeDuplicateLetters(string s) {
        if(s.length() == 0) return "";
        
        vector<int> cnt(26, 0);
        int pos = 0; // the position for the smallest s[i]
        
        for (int i = 0; i < s.length(); i++) cnt[s[i] - 'a']++;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] < s[pos]) pos = i;
            if (--cnt[s[i] - 'a'] == 0) break;
        }
        
        for(int i = pos + 1; i < s.size();) {
            if(s[i] == s[pos]) s.replace(i, 1, "");
            else i++; // pay attention to the prerequisition of i++
        }
        
        return s[pos] + removeDuplicateLetters(s.substr(pos + 1));
    }
};
*/

// 2nd solution (best)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(256, 0);
        vector<bool> inresult(256, false);
        
        for (char c : s) count[c]++;
        
        // In ASCII, space is 32, 
        // all digits and letters are bigger than space
        string result = " ";

        for (char c : s) {
            count[c]--;
            if (inresult[c]) continue;
            // the smaller char should be put left as far as possible
            // only if the last char of result exists in the substring after c
            while (c < result.back() && count[result.back()]) {
                inresult[result.back()] = false;
                result.pop_back();
            }
            result += c;
            inresult[c] = true;
        }

        return result.substr(1);
    }
};

/**
 * 1st solution (16ms)
 * Given the string s, the greedy choice (i.e., the leftmost letter in the answer) is the smallest s[i], s.t. the suffix s[i .. ] contains all the unique letters. (Note that, when there are more than one smallest s[i]'s, we choose the leftmost one. Why? Simply consider the example: "abcacb".)

 * After determining the greedy choice s[i], we get a new string s' from s by
 * 1. removing all letters to the left of s[i], 
 * 2. removing all s[i]'s from s.
 * We then recursively solve the problem w.r.t. s'.
 * The runtime is O(26 * n) = O(n).
 * 
 * 2nd solution (4ms)
 * Maintaining a stack and put the smaller
 * character left lower as far as possible until
 * the last character of the stack is the last occurence
 * of remaining substring
 * /
