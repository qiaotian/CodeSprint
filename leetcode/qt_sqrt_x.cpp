/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/

class Solution {
public:
    int mySqrt(int x) {
        return (int)(sqrt(x));
    }
};

class Solution {
public:
    int mySqrt(int x) {
        long r = x;
        while (r*r > x)
            r = (r + x/r) / 2;
        return r;
    }
}
