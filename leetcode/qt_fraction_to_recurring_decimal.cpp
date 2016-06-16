/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-06-16T18:17:43+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-06-16T20:20:36+08:00
* @License: Free License
*/

/**
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
Hint:

No scary math, just apply elementary math knowledge. Still remember how to perform a long division?
*/

/*
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
    bool flag = (numerator>=0)==(denominator>=0);

    long up = abs((long)numerator);
    long down = abs((long)denominator);

    string ans;
    vector<bool> hash(down, false); // 超出内存限制

    ans += flag?"":"-";

    if(up==0) return "0";
    if(down==0) return ""; // error

    long integer = up/down; // 整数部分
    long remainder = up%down;
    hash[remainder] = true;

    if(remainder==0) return to_string(integer);
    ans += to_string(integer);
    ans += '.';
    string decimal; // 小数点以后的部分
    while(remainder!=0) {
        bool flag = true; // 标记第一次不要填‘0’
        while(remainder<down) {
            remainder*=10;
            if(!flag) decimal+='0';
            flag = false;
        }
        decimal += to_string(remainder/down);
        remainder %= down;
        if(hash[remainder]) break;
        hash[remainder] = true;
    }
    return remainder==0?(ans+=decimal):(ans+='('+decimal+')');
    }
};

// If denominator is -2147483648, overflow will occurs when convert it to positive integer.
// Therefore, long type should be used.

*/
class Solution{
public:
string fractionToDecimal(int numerator, int denominator) {
    // zero numerator
    if (numerator == 0) return "0";

    string res;
    // determine the sign
    if (numerator<0 ^ denominator<0) res += '-';

    // remove sign of operands
    long n = (long)abs((long)numerator), d = (long)abs((long)denominator);

    // append integral part
    res += to_string(n / d);

    // in case no fractional part
    if (n % d == 0) return res;

    res += '.';

    unordered_map<long, long> map; // map the remainder to location

    // simulate the division process
    for (long r = n % d; r; r %= d) {

        // meet a known remainder
        // so we reach the end of the repeating part
        if (map.count(r) > 0) {
            res.insert(map[r], 1, '(');
            res += ')';
            break;
        }

        // the remainder is first seen
        // remember the current position for it
        map[r] = res.size();

        r *= 10;

        // append the quotient digit
        res += to_string(r / d);
    }

    return res;
}
};
