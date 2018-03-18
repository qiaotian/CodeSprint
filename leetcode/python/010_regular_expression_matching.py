'''
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a")   -> false
isMatch("aa","aa")  -> true
isMatch("aaa","aa") -> false
isMatch("aa", "a*") -> true
isMatch("aa", ".*") -> true
isMatch("ab", ".*") -> true
isMatch("aab", "c*a*b") -> true
'''

class Solution:
    def isMatch1(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        print(s, p)
        if len(p) == 0 or len(s) == 0:
            return len(s) == len(p) or (len(p) == 2 and p[1] == '*')
        if len(p) == 1:
            return len(s) == 1 and (s[0] == p[0] or p[0] == '.')
        if p[1] == '*':
            if self.isMatch(s[0], p[0]): # at least one preceding letter is matched
                return self.isMatch(s[1:], p[2:]) or self.isMatch(s[1:], p) or self.isMatch(s, p[2:])
            else: # no preceding letter is matched
                return self.isMatch(s, p[2:])
        else:
            return self.isMatch(s[0], p[0]) and self.isMatch(s[1:], p[1:])

    def isMatch2(self, s, p):
        if not p:
            return not s

        first_match = bool(s) and p[0] in {s[0], '.'}
        if len(p) >= 2 and p[1] == '*':
            return first_match and self.isMatch(s[1:], p) or self.isMatch(s, p[2:])
        else:
            return first_match and self.isMatch(s[1:], p[1:])


    def isMatch(self, s, p):
        memo = {}
        memo[-1, -1] = True
        def dp(i, j):
            if (i, j) in memo: return memo[i, j]
            if j > 1 and p[j] == '*':
                memo[i, j] = memo[i, j-2] or memo[i-1, j]
            if i >=1 and j >= 1:
                dp[i, j] = dp[i-1, j-1]

        return dp(0, 0)



if __name__ == '__main__':
    sln = Solution()
    assert sln.isMatch('a', 'a*') == True
    assert sln.isMatch('aa', 'a') == False
    assert sln.isMatch('aa', 'aa') == True
    assert sln.isMatch('aaa', 'aa') == False
    assert sln.isMatch('aaa', 'aaaa') == False
    assert sln.isMatch('aa', '.*') == True
    assert sln.isMatch('ab', '.*') == True      # 'ab' matches '..*', so it's True
    assert sln.isMatch('aab', 'c*a*b') == True
    assert sln.isMatch('ab', '.*c') == False    # 'ab' doesn't match '..c', since 'ab' has no 'c'
    assert sln.isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c") == False
