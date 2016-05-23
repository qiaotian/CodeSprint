/**
* @Author: Tian Qiao
* @Date:   2016-07-14T03:25:19+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-14T03:25:29+08:00
* @Inc: Google, Uber, FB, Amazon, Yahoo, Bloomberg
*/


/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

// DFS太慢
// 以下test case无法正确通过，因为超时
// "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
// ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
/*
class Solution {
public:
    bool helper(string s, unordered_set<string>& wordDict, int pos) {
        if(pos >= s.size()) return true;

        for(int i=pos; i<s.size(); i++) {
            string tmp = s.substr(pos, i-pos+1);
            auto search = wordDict.find(tmp);
            if(search==wordDict.end()) continue;
            else {
                if(helper(s, wordDict, i+1)) return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, unordered_set<string>& wordDict) {

        return helper(s, wordDict, 0);
    }
};*/



//一个DP问题。定义possible[i]为S字符串上[0,i]的子串是否可以被segmented by dictionary.
//那么
//possible[i] = true   if S[0,i]在dictionary里面
//            = true   if possible[k] == true 并且 S[k+1,j]在dictionary里面， 0<k<i
//            = false  if no such k exist.

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        string s2 = '#' + s;
        int len = s2.size();
        vector<bool> possible(len, 0);
        possible[0] = true;
        for(int i =1; i< len; ++i) {
            for(int k=0; k<i; ++k) {
                possible[i] = possible[k] &&
                dict.find(s2.substr(k+1, i-k)) != dict.end();
                if(possible[i]) break;
            }
        }
        return possible[len-1];
    }
}

// My solution 不添加dummy节点
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        //vector<bool> flag(s.size(), false);
        bool flag[s.size()] = {false};
        flag[0] = true;
        int len = s.size();
        for(int i=0; i<len; i++) {
            for(int j=-1; j<i; j++) {
                if(j==-1) {
                    flag[i] = wordDict.find(s.substr(0, i+1))!=wordDict.end();
                } else {
                    flag[i] = flag[j] && (wordDict.find(s.substr(j+1, i-j))!=wordDict.end());
                }
                if(flag[i]) break;
            }
        }
        return flag[len-1];
    }
};
