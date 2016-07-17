/**
* @Author: Tian Qiao
* @Date:   2016-07-16T15:28:28+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-16T15:28:47+08:00
* @Inc: Goolge, Facebook, Uber, Airbnb
* @Difficulty: Hard
*/

/*
Implement regular expression matching with support for '.' and '*'.
'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).
The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa", "a")      → false
isMatch("aaa", "aa")    → false
isMatch("aa", "aa")     → true
isMatch("aa", "a*")     → true
isMatch("aa", ".*")     → true
isMatch("ab", ".*")     → true
isMatch("aab", "c*a*b") → true
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        if(s==p) return true;
        int slen = s.size();
        int plen = p.size();
        bool match[slen+1][plen+1] = {true};
        for(int i=1; i<slen+1; i++) {
            for(int j=1; j<plen+1; j++) {
                if(s[i]!='*' && s[i]!='.' && p[j]!='*' && p[j]!='.'){
                    if(s[i]==p[j]) match[i][j] = match[i-1][j-1];
                    else match[i][j] = false;
                    break;
                }
                if(s[i]=='*') {
                    bool re = false;
                    for(int k=i-1; k>=0; k--) {
                        re |= match[k][j];
                        if(re) break;
                    }
                    match[i][j] = re;
                    break;
                }
                if(p[j]=='*') {
                    bool re = false;
                    for(int k=j-1; k>=0; k--) {
                        re |= match[j][k];
                        if(re) break;
                    }
                    match[i][j] = re;
                    break;
                }
                if(s[i]=='.') { match[i][j] = match[i-1][j-1]; break; }
                if(p[j]=='.') {match[i][j] = match[i-1][j-1]; break; }
            }
        }
        return match[slen][plen];
    }
};
