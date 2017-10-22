/* Problem

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.

Hint:

The naive approach is to call isUgly for every number until you reach the nth one. Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.

An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.

*/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(1, 1); // the first valid ugly number is 1
        int i3 = 0, i5 = 0, i7 = 0; // every one in res will be multiplied by 3, 5, 7 respectly.
        while (res.size() < k) {
            int m3 = res[i3] * 3, m5 = res[i5] * 5, m7 = res[i7] * 7;
            int mn = min(m3, min(m5, m7));
            if (mn == m3) ++i3;
            if (mn == m5) ++i5;
            if (mn == m7) ++i7;
            res.push_back(mn);
        }
        return res.back();
    }
};
