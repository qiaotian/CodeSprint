/*
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        /* //Sln 1
        int count = 0;
        int hamming = 0;
        while(count++<32) {
            hamming+=n%2;
            n=n>>1;
        }
        return hamming;
        */
        
        // Sln 2
        int count = 0;
        while (n) {
            n &= (n - 1); //n & (n - 1) drops the lowest set bit.
            count++;
        }
        return count;
    }
};

// NOTICE
/**
 * Solution 2 
 * only loop as many times as the number of 1 bits whereas 
 * the solutions shifting the bits of n will loop also for 
 * every 0 bit in between.
 * /
