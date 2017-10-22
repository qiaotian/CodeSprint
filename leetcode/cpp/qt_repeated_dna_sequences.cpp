/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/

/*class Solution {
public:
    bool cmp(string& a, string& b) {
        return a<b;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_set<string, cmp> uset(cmp);
        if(s.size()<11) return ans;
        for(int i=0; i<s.size()-9; i++) {
            string tmp = s.substr(i,10);
            if(tmp!=uset.end()) ans.push_back(tmp);
            else uset.insert(tmp);
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
