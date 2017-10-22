/**
* @Author: Tian Qiao
* @Date:   2016-07-24T20:28:10+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-24T20:28:28+08:00
* @Inc: Google, Airbnb, Facebook, Snapchat
* @Difficulty: Hard
* @Tag: Graph, Topological Sort
*/



/*
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

For example,
Given the following words in dictionary,
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]
The correct order is: "wertf".

Note:
You may assume all letters are in lowercase.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.
*/

// 题目大意：
// 给定words中的单词按升序排列，从左到右第一个字符不同的字符对决定了单词的先后次序

// https://discuss.leetcode.com/topic/22476/16-18-lines-python-30-lines-c/2
// Keys:
// 1. construct two directed graphs:
//    one is the from previous to successive node
//    the other one is from successive node to previous node
// 2. store all occuring chars into the unordered_set
class Solution {
private:
    unordered_map<char, unordered_set<char>> pre;
    unordered_map<char, unordered_set<char>> suc;
    unordered_set<char> chars;

public:
    string alienOrder(vector<string>& words) {
        string ans = "";
        string s;
        for(auto t:words) {
            chars.insert(t.begin(), t.end()); //
            int len = min(s.size(), t.size());
            for(int i=0; i<len; i++) {
                char a = s[i], b = t[i];
                if(a!=b) {
                    suc[a].insert(b);
                    pre[b].insert(a);
                    break;
                }
            }
            s = t;
        }
        // 2.
        unordered_set<char> nodes = chars;
        for(auto i:pre) nodes.erase(i.first);

        while(!nodes.empty()) {
            char c = *nodes.begin();
            ans += c;
            nodes.erase(c);
            for(auto j:suc[c]) {
                pre[j].erase(c);
                if(pre[j].empty()) nodes.insert(j);
            }
        }
        return ans.size()==chars.size()?ans:"";
    }
};

// For BFS and DFS solutions, we can find them below:
// https://discuss.leetcode.com/topic/22407/straightforward-c-solution
