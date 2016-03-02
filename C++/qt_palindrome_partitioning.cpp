// Backtracking (12ms, beats 78%)
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> tmp;
        getPartition(s, 0, tmp, res);
        return res;
    }
private: 
    void getPartition(string& s, int idx, vector<string>& tmp, vector<vector<string>>& res) {
        // idx: 当前全文搜索的起始位置
        // tmp: 回文容器
        if(idx == s.size()) {
            // res入栈的唯一条件：s全文搜索完毕
            res.push_back(tmp);
            return;
        }
        for(int i = idx, n = s.size(); i < n; i++) {
            // 遍历s全文
            int l = idx, r = i;
            while(l < r && s[l] == s[r]) l++, r--;
            if(l >= r) {
                // s[idx]到s[i]是回文
                tmp.push_back(s.substr(idx, i-idx+1));
                getPartition(s, i+1, tmp, res);
                tmp.pop_back(); // 与tmp.push_back对应
            }
        }
    }
};

/*
REFERENCE:
https://leetcode.com/discuss/38715/12ms-14-lines-c

The problem has a nice structure that backtracking naturally fits in. The structure is, given a starting position idx, we search from idx till the end of the string s.length() - 1. Once we reach a position i such that the sub-string from idx to i (s.substr(idx, i - idx + 1)) is a palindrome, we add it to a temporary tmp. Then we recursively call the same function to process the remaining sub-string. Once we reach the end of the string, we add tmp into the result res of all the possible partitioning.

Then, backtracking happens! Remember that at position i, we find s.substr(idx, i - idx + 1) to be a palindrome and we immediately add it to tmp. It is obvious that there may be some position j such that j > i and s.substr(idx, j - idx + 1) is also a palindrome. So we need to recover to the state before adding s.substr(idx, i - idx + 1) to tmp and continue to find the next palindrome position after i. And we simply need to pop s.substr(idx, i - idx + 1) out of tmp to make things work.
 * /
