/*
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        //Sln 1
        //if(n==0) return false;
        //while(n%3==0) n/=3;
        //return n==1;
        
        // Sln 2
        //return (n == 1 || n == 3 || n == 9 || n == 27 || n == 81 || n == 243 || n == 729 || n == 2187 || n == 6561 || n == 19683 || n == 59049 || n == 177147 || n == 531441 || n == 1594323 || n == 4782969 || n == 14348907 || n == 43046721 || n == 129140163 || n == 387420489 || n == 1162261467);
        // Sln 3
        return n>0?!(1162261467 % n):0; //most fast
        
        // Sln 4
        //return n>0?(1162261467 / n == 1162261467 / (double)n):0;
        
        // Sln 5
        //return n>0 && (n==1 || (n%3==0 && isPowerOfThree(n/3)));// recursive solution
        
        // There are still lots of methods in 
        // https://leetcode.com/discuss/78532/summary-all-solutions-new-method-included-at-15-30pm-jan-8th
    }
};
/**
 * NOTICE
 * for int a and b,
 * a/b is alse int type, which equals int not bigger 
 * than (float)a/(float)b.
 * but for
 * float a,
 * a/a is 1.0 float value
 * /
