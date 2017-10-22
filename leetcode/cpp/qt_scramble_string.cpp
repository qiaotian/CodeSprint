/**
* @Author: Tian Qiao
* @Date:   2016-07-19T20:43:31+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-19T20:44:26+08:00
*/


/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/


// https://discuss.leetcode.com/topic/14337/share-my-4ms-c-recursive-solution/2
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1==s2) return true;

        int len = s1.length();
        int count[26] = {0};
        for(int i=0; i<len; i++) {
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }

        for(int i=0; i<26; i++) {
            if(count[i]!=0) return false;
        }

        for(int i=1; i<=len-1; i++) {
            if( isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if( isScramble(s1.substr(0,i), s2.substr(len-i)) && isScramble(s1.substr(i), s2.substr(0,len-i)))
                return true;
        }
        return false;
    }
};

class Solution {
public:
    vector<int> collectSeperator(string s1, string s2) {
        vector<pair<int, bool>> ans; // seperators and reverted

        return ans;
    }
    bool isScramble(string s1, string s2) {
        int n = s1.size(); // s1和s2等长
        vector<pair<int, bool>> seps = collectSeperator(s1, s2);
        if(sep.empty()) return false;
        for(auto i:seps) {
            string ll = s1.substr(0, i.first);
            string lr = s1.substr(i.first, n-1);
            string rl = i.second?s2.substr(0, i.first):s2.substr(n-i.first, i.first);
            string rr = i.second?s2.substr(i.first, n-1):s2.substr(0, n-i.first);
            bool templ = isScramble(ll, rl);
            bool tempr = isScramble(lr, rr);
            if(templ&&tempr) return true;
        }
        return false;
    }
};
