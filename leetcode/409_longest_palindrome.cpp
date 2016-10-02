/*
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/

class Solution {
public:
    int longestPalindrome(string s) {
        if(s.empty()) return 0;

        vector<int> cnt(52, 0);
        for(auto c:s) cnt[c>=97?(c-'a'+26):(c-'A')]++;

        int even = 0, odd = 0;
        for(auto n:cnt) {
            even += n/2*2;
            odd += n%2;
        }
        return even + (odd>0);
    }
};
