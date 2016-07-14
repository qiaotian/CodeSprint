/**
* @Author: Tian Qiao
* @Date:   2016-07-14T23:44:48+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-14T23:44:56+08:00
* @Inc: LinkedIn
* @Difficulty: Medium
* @Hash Table, Bit Manipulation
*/



/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,
Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
Return: ["AAAAACCCCC", "CCCCCAAAAA"].
 */

// Wrong: 不能直接使用<string>作为unordered_set的成员
/*class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_set<string> s;
        if(s.size()<11) return ans;
        for(int i=0; i<s.size()-9; i++) {
            string tmp = s.substr(i,10);
            if(tmp!=s.end()) ans.push_back(tmp);
            else s.insert(tmp);
        }
        return ans;
    }
};*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> m;
        vector<string> r;
        int t = 0, i = 0, ss = s.size();
        while (i < 9)
            t = t << 3 | s[i++] & 7;
        while (i < ss)
            if (m[t = t << 3 & 0x3FFFFFFF | s[i++] & 7]++ == 1)
                r.push_back(s.substr(i - 10, 10));
        return r;
    }
};
