/**

Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

*/

/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
    var ans = false;
    if (p.length == 0)
        return s.length == 0

    if(p[1] == '*') {
        // if s[0] != p[0], then try match(s, p[2:])
        // el try match(s[1:], p[1:]) or match(s, p[1:])
        return isMatch(s, p.slice(2)) || (s.length != 0 && (s[0]==p[0] || p[0]=='.')) && isMatch(s.slice(1), p);
    } else {
        return s.length != 0 && (s[0]==p[0] || p[0]=='.') && isMatch(s.slice(1), p.slice(1));
    }
};

console.log(isMatch('abc', 'a*'))
