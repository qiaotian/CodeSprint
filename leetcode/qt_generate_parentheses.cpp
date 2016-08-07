/**
* @Author: Tian Qiao
* @Date:   2016-08-07T23:58:39+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-07T23:58:40+08:00
*/




/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/


class Solution {
public:
    void util(int n, vector<string> &vec, int lcount, int rcount, string s) {
        if(lcount==n && rcount==n) {
            vec.push_back(s);
            return;
        }
        if(lcount+1 >= rcount && lcount < n) util(n, vec, lcount+1, rcount, s+"(");
        if(lcount >= rcount+1 && rcount < n) util(n, vec, lcount, rcount+1, s+")");
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ret;

        util(n, ret, 0, 0, "");

        return ret;
     }
};
