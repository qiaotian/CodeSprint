/**
* @Author: Tian Qiao
* @Date:   2016-07-03T23:54:52+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-04T00:11:14+08:00
* @Inc: Facebook
* @Difficulty: Easy
*/

_______________________________________________________________________________

/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

_______________________________________________________________________________

class Solution {
public:
    string addBinary(string a, string b) {
        // Solution One
        int carry = 0;
        int digit = 0;
        int count = max(a.size(), b.size());
        string result;
        for(int i=0; i<count; ++i) {
            int dig_a = ((int)a.size()-1-i)<0?0:(a[a.size()-1-i]-'0');
            int dig_b = ((int)b.size()-1-i)<0?0:(b[b.size()-1-i]-'0');
            digit = (dig_a+dig_b+carry)%2;
            carry = (dig_a+dig_b+carry)/2;
            result = to_string(digit) + result;
        }
        if(carry==1) result = to_string(1)+result;
        return result;

        // Solution Two
    }
};

// Optimise
class Solution
{
public:
    string addBinary(string a, string b)
    {
        string s = "";

        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1) {
            c += i >= 0 ? a[i--]-'0' : 0;
            c += j >= 0 ? b[j--]-'0' : 0;
            s = char(c % 2 + '0') + s;
            c /= 2; // carry
        }

        return s;
    }
};
/***
 * The return type of string.size() is unsigned int, so
 * "a.size()-1-i" will never be a negative value.
 * Therefore, we should convert a.size() from unsigned type to int type
 * /
