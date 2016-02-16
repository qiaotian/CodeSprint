// 1st solution (good)
/*
class Solution {
public:
    bool isNumber(string s) {
        if(s.size() == 0) return false;
        
        int left = 0, right = s.size()-1;
        
        while(s[left]==' ') left++;
        while(s[right]==' ') right--;
        
        if(left > right) return false;
        
        // skip the positive or negative symbol
        if(s[left]=='+' || s[left]=='-') left++;
        
        // check the amount of numbers and dots before 'e'
        int num_cnt = 0, dot_cnt = 0; // the amount of numbers and dots
        for(; (s[left]<='9' && s[left]>='0')||(s[left]=='.') && left <=right; left++) {
            if(s[left]=='.') dot_cnt++; 
            else num_cnt++;
        }
        if(dot_cnt>1 || num_cnt==0) return false;
        
        // check the exponent
        if(s[left]=='e') {
            left++;
            if(s[left]=='+' || s[left]=='-') left++;
            for(num_cnt = 0; s[left]<='9' && s[left]>='0' && left<=right ; left++) num_cnt++;
            if(num_cnt==0) return false;
        }
        return left==right+1;
    }
};
*/

// 2nd solution (better)
class Solution {
public:
    bool isNumber(string s) {
        // "1 1"is not valid, "0x11" is not valid, 
        // "." is not valid, "2e3.1" is not valid, 
        // "2e" is not valid,"1a" is not valid,
        // "++1" is not valid
        int n = s.size();
        if(n == 0) return false;
        int i = 0;
        int count_num = 0, count_point = 0;
        while(s[i] == ' ') i++;
        if(s[i] == '+' || s[i] == '-') i++;
        while(isdigit(s[i]) || s[i] == '.') s[i++] == '.'?count_point++:count_num++;
        if(count_point > 1 || count_num < 1) return false;
        if(s[i] == 'e'){
            i++;
            count_num = 0;count_point = 0;
            if(s[i] == '+' || s[i] == '-') i++;
            while(isdigit(s[i]) || s[i] == '.') s[i++] == '.'?count_point++:count_num++;
            if(count_point > 0 || count_num < 1) return false;
        }
        while(s[i] == ' ') i++;
        return i == n;
    }
};

/**
 * WARNING
 * In test cases: ".1" is valid, "00" is valid, "1e.0", "1e+3.5e+3.5" is unvalid!!!
 * the number behind e should be integer.
 * a number should never contain two or more e!
 * 
 * __1st solution__
 * The idea is pretty straightforward. 
 * A valid number is composed of the significand(术语：有效数) and the exponent (optional). 
 * As we go through the string, do the following things one by one:
 * 1. skip the leading and trailling whitespaces
 * 2. check if the significand is valid. To do so, simply skip the leading sign and count the number of digits and the number of points. A valid significand has no more than one point and at least one digit.
 * 3. check if the exponent part is valid. We do this if the significand is followed by 'e'. Simply skip the leading sign and count the number of digits. A valid exponent contain at least one digit.
 * 4. check if the index left has reached the index right
 * 
 * __2nd solution__
 * The idea is same, but use integer i instead of integer left and right;
 * 
 * 
 * REFERENCE
 * https://leetcode.com/discuss/9013/a-simple-solution-in-cpp
 * https://leetcode.com/discuss/44047/c-12-ms-give-some-invalid-examples-easily-understand
 * /
