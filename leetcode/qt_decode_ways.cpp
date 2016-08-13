/**
* @Author: Tian Qiao
* @Date:   2016-08-07T23:36:46+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-07T23:36:47+08:00
* @Inc: Uber
* @Tag: DP, String
*/

/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/


/*class Solution {
    // 超时
    void util(string s, int& count) {
        int n = s.size();
        if(n == 0 || n == 1) {
            count++;
            return;
        }
        if(s[0]>'2' || (s[0]=='2' && s[1]>'6')) {
            util(s.substr(1), count);
        } else {
            util(s.substr(2), count);
        }
    }
    */

    // 只处理s的长度不小于2的情况
    /*
    int util(string& s, int pos) {
        if(pos == s.size()-1 || pos == s.size()) return 1;
        while(s[pos]>'2' || (pos<s.size()-1 && s[pos]=='2' && s[pos+1]>'6')) pos++;
        if(pos == s.size()-1) return 1;
        if(s[pos+1]=='0') return util(s, pos+2);
        return util(s, pos+1) + util(s, pos+2);
    }
public:
    int numDecodings(string s) {
        if(s.size() == 0) return 0;
        if(s.size() == 1) return 1;
        return util(s, 0);
    }

};
 */

class Solution {
public:
    int numDecodings(string s) {
    if (!s.size() || s.front() == '0') return 0;
    // r2: decode ways of s[i-2] , r1: decode ways of s[i-1]
    int r1 = 1, r2 = 1;

    for (int i = 1; i < s.size(); i++) {
        // zero voids ways of the last because zero cannot be used separately
        if (s[i] == '0') r1 = 0;

        // possible two-digit letter, so new r1 is sum of both while new r2 is the old r1
        if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
            r1 = r2 + r1;
            r2 = r1 - r2;
        }

        // one-digit letter, no new way added
        else {
            r2 = r1;
        }
    }

    return r1;
}
};
// 分情况考虑简直疯了。。。
// 需要别的考量
