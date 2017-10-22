// 1st solution (8ms, beats 76%, good)

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2) return s;
        
        int start = 0, length = 1; // 初始化回文起点为0 长度为1
        // int n = s.size();
        for(int i = 0; i < s.size();) {
            // 如果回文只有一半（左半边）在s中，那么出错，返回
            // 实际上这句对于执行速度有一定影响，删除此举会慢3到4ms
            // if(s.size() - i <= length / 2) break;
            int l = i, r = i; // l is start and r is end of the palindrome
            // 对称中心只可能在
            // 1. 同文字符串的正中心，绝不会偏向任何一方;
            // 2. 两个同文字符串关于某个相异字符对称；
            // 通过跳过同文字符串
            // r points to the last char of palindrome while l points to first char
            while(r+1<s.size() && s[r]==s[r+1]) r++;
            i = r+1;
            while(r+1<s.size() && l-1>=0 && s[l-1]==s[r+1]) {l--; r++;}
            if(r-l+1 > length) {
                length = r-l+1; 
                start = l;
            }
        }
        return s.substr(start, length);
    }
};


// 2nd solution (4ms, beats 92%, better)
/*
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.size() < 2) return s;
        int n = s.size(), start = 0, length = 1, left, right;
        for (int i = 0; i < n && n-i > length/2;) {
            left = right = i;
            while (right+1 < n && s[right+1] == s[right]) ++right;
            i = right+1;
            while (right+1 < n && left > 0 && s[right+1] == s[left-1]) {
                ++right;
                --left;
            }
            if (length < right-left+1) {
                start = left;
                length = right-left+1;
            }
        }
        return s.substr(start, length);
    }
};
*/