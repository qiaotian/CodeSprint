// 1st solution (160ms, beats 40%)
/*
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> uglys(n, 1);
        vector<int> pointers(primes.size(), 0); // all primes point to the first ugly number
        for(int i = 1; i < n; i++) {
            int minidx = 0;
            for(int j = 1; j < primes.size(); j++) {
                // for the jth prime
                if(primes[j] * uglys[pointers[j]] < primes[minidx] * uglys[pointers[minidx]]) 
                    minidx = j;
            }
            
            uglys[i] = primes[minidx] * uglys[pointers[minidx]];

            for(int j = 0; j < primes.size(); j++) {
                // move all min indexes to next ugly number
                if(primes[j] * uglys[pointers[j]] == uglys[i]) pointers[j]++;
            }
        }
        return uglys[n-1];
    }
};
*/

// 2nd solution (40ms, beats %98)
class Solution {
public:
    int min(int *factor,int len){
        int minNum = factor[0];
        for(int i = 1; i < len; i++)
            if(factor[i] < minNum)
               minNum=factor[i];
        return minNum;
    }
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int len = primes.size();
        int *index=new int[len];
        int *factor=new int[len];
        int *ugly=new int[n];
        ugly[0]=1;
        int minNum;
        // init factor and index
        for(int i=0; i<len; i++) {
            factor[i] = primes[i];
            index[i] = 0;
        }
        // find all minnum
        for(int i=1; i<n; i++) {
            minNum = min(factor, len);
            ugly[i] = minNum;
            for(int i = 0; i < len; i++) {
                if(minNum==factor[i]) {
                    factor[i] = primes[i]*ugly[++index[i]];
                }
            }
        }
        return ugly[n-1];
    }
};
/**
 * The first solution is inspired by the "ugly number II"
 * The second solution is similiar to the fisrt one, while uses less STL and more memeory.
 * 
 * REFERENCE
 * https://leetcode.com/discuss/87319/c-code-beats-98%25
 * /

