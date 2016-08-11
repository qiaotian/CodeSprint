/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

// My Fault Solution
/*
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
};*/

// 一个比较好的算法是贪心算法（greedy）: whenever encounter ‘*’ in p, 
// keep record of the current position of ‘*’ in p and the current index in s. 
// Try to match the stuff behind this ‘*’ in p with s, if not matched, 
// just s++ and then try to match again.

// Notes:
// 1. s里面不会存在'？'和'*', 只有p（模板）中才有
// 2. 
class Solution {
public:
    bool isMatch(string s, string p) {
        int sIdx = 0, pIdx = 0, match = 0, starIdx = -1;            
        while (sIdx < s.size()){
            // advancing both pointers
            if (pIdx < p.size()  && (p[pIdx] == '?' || s[sIdx] == p[pIdx])){
                sIdx++;
                pIdx++;
            }
            // * found, only advancing pattern pointer
            else if (pIdx < p.size() && p[pIdx] == '*'){
                starIdx = pIdx;
                match = sIdx;
                pIdx++;
            }
            // last pattern pointer was *, advancing string pointer
            else if (starIdx != -1){
                pIdx = starIdx + 1; // put pIdx back to the next to '*'
                match++;
                sIdx = match;
            }
            //current pattern pointer is not star, last patter pointer was not *
            //characters do not match
            else return false;
        }
        
        //check for remaining characters in pattern
        while (pIdx < p.size() && p[pIdx] == '*') pIdx++;
        
        return pIdx == p.size();
    }  
};
