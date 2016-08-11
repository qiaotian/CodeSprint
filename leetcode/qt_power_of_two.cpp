/*
Given an integer, write a function to determine if it is a power of two.
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        /* Sln 1
        if(n<1) return false;
        while(n%2==0) n/=2;
        return n==1;
        */
        /* Sln 2
        if(n<=0) return false;
        return !(n&(n-1));
        */
        // Sln 3
        return n>0 && !(n&(n-1));
    }
};

/**
 * NOTICE
 * Power of 2 means only one bit of n is '1', 
 * so use the trick n&(n-1)==0 to judge whether that is the case
 * 
 * /
