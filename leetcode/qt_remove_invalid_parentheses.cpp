/**
* @Author: Tian Qiao
* @Date:   2016-07-24T10:02:16+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-24T10:05:43+08:00
* @Inc: Facebook
* @Difficulty: Hard
*/



/*
Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.
Note: The input string may contain letters other than the parentheses ( and ).

Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]
*/




// https://discuss.leetcode.com/topic/34875/easy-short-concise-and-fast-java-dfs-3-ms-solution/2
/*
Key Points:

Generate unique answer once and only once, do not rely on Set.
Do not need preprocess.
Runtime 3 ms.
Explanation:
We all know how to check a string of parentheses is valid using a stack. Or even simpler use a counter.
The counter will increase when it is ‘(‘ and decrease when it is ‘)’. Whenever the counter is negative, we have more ‘)’ than ‘(‘ in the prefix.

To make the prefix valid, we need to remove a ‘)’. The problem is: which one? The answer is any one in the prefix. However, if we remove any one, we will generate duplicate results, for example: s = ()), we can remove s[1] or s[2] but the result is the same (). Thus, we restrict ourself to remove the first ) in a series of concecutive )s.

After the removal, the prefix is then valid. We then call the function recursively to solve the rest of the string. However, we need to keep another information: the last removal position. If we do not have this position, we will generate duplicate by removing two ‘)’ in two steps only with a different order.
For this, we keep tracking the last removal position and only remove ‘)’ after that.

Now one may ask. What about ‘(‘? What if s = ‘(()(()’ in which we need remove ‘(‘?
The answer is: do the same from right to left.
However a cleverer idea is: reverse the string and reuse the code!
Here is the final implement in Java.
*/


class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        vector<char> par = {'(', ')'};
        remove(s, ans, 0, 0, par);
        return ans;
    }
    void remove(string s, vector<string>& ans, int last_i, int last_j, vector<char>& par) {
        for(int stack=0, i=last_i; i<s.size(); i++) {
            if(s[i]==par[0]) stack++;
            if(s[i]==par[1]) stack--;
            if(stack >= 0) continue;
            for(int j=last_j; j<=i; ++j) {
                if(s[j]==par[1] && (j==last_j || s[j-1]!=par[1])){
                    remove(s.substr(0,j)+s.substr(j+1,s.size()), ans, i, j, par);
                }
            }
            return;
        }
        string cp = s;
        reverse(cp.begin(), cp.end());
        vector<char> tmp = {')','('};
        if(par[0]=='(') remove(cp, ans, 0, 0, tmp);
        else ans.push_back(cp);
    }
};
