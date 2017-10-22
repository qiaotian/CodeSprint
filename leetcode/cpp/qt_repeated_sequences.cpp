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

/*
The main idea is to store the substring as int in map to bypass the memory limits.
There are only four possible character A, C, G, and T, but I want to use 3 bits per letter instead of 2.
Why? It's easier to code.
A is 0x41, C is 0x43, G is 0x47, T is 0x54. Still don't see it? Let me write it in octal.
A is 0101, C is 0103, G is 0107, T is 0124. The last digit in octal are different for all four letters. That's all we need!
We can simply use s[i] & 7 to get the last digit which are just the last 3 bits, it's much easier than lookup table or switch or a bunch of if and else, right?
We don't really need to generate the substring from the int. While counting the number of occurrences, we can push the substring into result as soon as the count becomes 2, so there won't be any duplicates in the result.
*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> m;
        vector<string> ret;
        int t = 0, i = 0, ss = s.size();
        while (i < 9)
            t = t << 3 | s[i++] & 7;
        while (i < ss)
            if (m[t = t << 3 & 0x3FFFFFFF | s[i++] & 7]++ == 1)
                ret.push_back(s.substr(i - 10, 10));
        return ret;
    }
};
