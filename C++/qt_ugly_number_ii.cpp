// 1st solution (TLE)
/*
class Solution {
public:
    int nthUglyNumber(int n) {
        int i = 1;
        for(int count = 0; count < n; i++) {
            int cur = i;
            while(cur % 5 == 0) cur /= 5;
            while(cur % 3 == 0) cur /= 3;
            while(cur % 2 == 0) cur /= 2;
            if(cur == 1) count++;
        }
        return i;
    }
};
*/

// 2nd solution 
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 0) return false; // get rid of corner cases 
        if(n == 1) return true; // base case
        int t2 = 0, t3 = 0, t5 = 0; //pointers for 2, 3, 5
        vector<int> k(n);
        k[0] = 1;
        for(int i  = 1; i < n ; i ++)
        {
            k[i] = min(k[t2]*2,min(k[t3]*3,k[t5]*5));
            if(k[i] == k[t2]*2) t2++; 
            if(k[i] == k[t3]*3) t3++;
            if(k[i] == k[t5]*5) t5++;
        }
        return k[n-1];
    }
};

/**
 * WARNING
 * 1st solution:
 * The bigger n is, the more useless calculation executed. 
 * For example, 1352 is time limit exceeded! We can decompose 1352 into 169 * 2 * 2 * 2, then
 * we need to check all number from 1 to 1352, which could be optimized.
 * 
 * 2nd solution:
 * Use DP to solve this problem. The idea is that any ugly number (except the beginning) 
 * could be decomposed into a number (2, 3, or 5) and a ugly number. 
 * Therefore, if we take down all n-1 ugly numbers and the multipliers' positions. Then we could make it.
 * 
 * For each time, 
 * 1. Gives three pointers to point three ugly numbers seperately.
 * 2. Find the min value among 2*pointer2, 3*pointer3 and 5*pointer5. 
 * 3. Then moves the min pointer to next ugly number.
 * 4. Repeat 2~3
 * /
