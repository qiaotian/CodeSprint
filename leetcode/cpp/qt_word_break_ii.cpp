/**
* @Author: Tian Qiao
* @Date:   2016-07-28T17:41:15+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-28T17:41:16+08:00
* @Inc: Dropbox, Google
* @Difficulty: Hard
* @Tag: DP, Backtracking
*/



/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/


//TLE for aaaaaa...aaaaaaaaaa
class Solution {
private:
    vector<string> ans;
public:
    void util(string& s, int start, unordered_set<string>& wordDict, string res) {
        if(start==s.size()) ans.push_back(res);
        for(auto w:wordDict) {
            int wlen = w.size();
            if(start+wlen-1>=s.size()) continue;
            string tmp = s.substr(start, wlen);
            if(tmp==w) {
                util(s, start+wlen, wordDict, res+(res.empty()?"":" ")+tmp);
            }
        }
    }

    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        string res = "";
        util(s, 0, wordDict, res);
        return ans;
    }
};

//
class Solution {
private:
    unordered_map<string, vector<string>> m;
    vector<string> combine(vector<string>& prev, string word) {
        for(int i=0; i<prev.size(); i++) prev[i]+=(" "+word);
        return prev;
    }
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        if(m.count(s)) return m[s];
        vector<string> ans;
        if(wordDict.count(s)) ans.push_back(s);
        for(int i=1; i<s.size(); i++) {
            string word = s.substr(i);//s除去前i位字符后剩余的字符串
            if(wordDict.count(word)) {
                string remain = s.substr(0, i);
                vector<string> tmp = wordBreak(remain, wordDict);
                tmp = combine(tmp, word);
                ans.insert(ans.end(), tmp.begin(), tmp.end());
            }
        }
        m[s] = ans;
        return ans;
    }
};


// https://discuss.leetcode.com/topic/35762/9-lines-python-10-lines-c
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        unordered_map<int, vector<string>> memo {{s.size(), {""}}};
        function<vector<string>(int)> sentences = [&](int i) {
            if (!memo.count(i)) {
                for (int j=i+1; j<=s.size(); j++)
                    if (wordDict.count(s.substr(i, j-i)))
                for (string tail : sentences(j))
                    memo[i].push_back(s.substr(i, j-i) + (tail=="" ? "" : ' ' + tail));
            }
            return memo[i];
        };
        return sentences(0);
    }
};
