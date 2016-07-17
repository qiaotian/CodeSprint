/**
* @Author: Tian Qiao
* @Date:   2016-07-17T13:39:07+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-17T13:39:49+08:00
* @Inc: Google
* @Difficulty: Medium
* @Tag: KMP
*/



/*Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.
For example:
Given "aacecaaa", return "aaacecaaa".
Given "abcd", return "dcbabcd".
Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases. Thanks to @Freezen for additional test cases.
*/

// 输入"aacecaaa"，长度为n，转化为
// "_a_a_c_e_c_a_a_a_"，长度为2n+1，对称轴线位于下划线或者字母处
// 中间位置正好是n
// 对称轴线左侧有n/2个字符

// Test Case: TLE
// 对于10000个a的字符串超时
/*
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if(s.size()<=1) return s;
        for(int i=n; i>=0; i--) {
            string ll = s.substr(0, i/2);
            string rr = s.substr((i+1)/2, i/2);
            reverse(rr.begin(), rr.end());
            if(ll==rr) {
                string rightmost = s.substr((2*i+1)/2, n-(2*i+1)/2);
                reverse(rightmost.begin(), rightmost.end());
                return rightmost+s;
            }
        }
        string ans = s;
        reverse(s.begin(), s.end());
        ans+=s;
        return ans;
    }
};
*/
//https://discuss.leetcode.com/topic/14526/c-8-ms-kmp-based-o-n-time-o-n-memory-solution/2
/*
We can construct the following string and run KMP algorithm on it:
(s) + (some symbol not present in s) + (reversed string)

After running KMP on that string as result we get a vector p with values of a prefix function for each character (for definition of a prefix function see KMP algorithm description). We are only interested in the last value because it shows us the largest suffix of the reversed string that matches the prefix of the original string. So basically all we left to do is to add the first k characters of the reversed string to the original string, where k is a difference between original string size and the prefix function for the last character of a constructed string.
*/

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string l = s + "#" + rev_s;

        vector<int> p(l.size(), 0);
        for (int i = 1; i < l.size(); i++) {
            int j = p[i - 1];
            while (j > 0 && l[i] != l[j])
                j = p[j - 1];
            p[i] = (j += l[i] == l[j]);
        }

        return rev_s.substr(0, s.size() - p[l.size() - 1]) + s;
    }
};
