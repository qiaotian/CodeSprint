/*
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 * For "(()", the longest valid parentheses substring is "()", which has length = 2.
 * Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 */


/* Wrong Solution
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int delta = 0; // 子串中'('数目减去')'数目
        int cur = 0;   // 当前子串中最大有效长度
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='(') delta++;
            else if(s[i]==')') {
                delta--;
                if(delta < 0) {
                    ans = max(ans, cur); // start到i-1
                    delta = cur = 0;
                } else if(delta > 0) {
                    cur=2; // "()(()"
                    ans = max(ans, cur);
                } else {
                    cur+=2; // "()()"
                    ans = max(ans, cur);
                }
            }
            else continue;
        }
        return ans;
    }
};*/


/* 解题思路
https://discuss.leetcode.com/topic/2426/my-dp-o-n-solution-without-using-stack
DP Solution:
The main idea is as follows: I construct a array longest[], for any longest[i], it stores the longest length of valid parentheses which is end at i.


if s[i] is '(':
    set longest[i] to 0,because any string end with '(' cannot be a valid one.
else if s[i] is ')':
    if s[i-1] is '(', longest[i] = longest[i-2] + 2
    else if s[i-1] is ')' and s[i-longest[i-1]-1] == '(', longest[i] = longest[i-1] + 2 + longest[i-longest[i-1]-2]

For example, input "()(())", at i = 5, longest array is [0,2,0,0,2,0], longest[5] = longest[4] + 2 + longest[1] = 6.
*/


class Solution {
public:
    int longestValidParentheses(string s) {
        
    }
};
