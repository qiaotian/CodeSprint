class Solution {
public:
    int bulbSwitch(int n) {
        int count = 0;
        for(int i = 1; i*i <= n; i++) {
            count++;
        }
        return count;
    }
};

/**
 * WARNING
 * Time: O(N^2) will lead to TLE
 * 
 * Tricky:
 * A light will be toggled only during the round of its factors, 
 * e.g. number 6 light will be toggled at 1,2,3,6 and light 12 
 * will be toggled at 1,2,3,4,6,12. The final state of a light 
 * is on and off only depends on if the number of its factor is 
 * odd or even. If odd, the light is on and if even the light is 
 * off. The number of one number's factor is odd if and only if 
 * it is a perfect square! So we will only need to loop to find 
 * all the perfect squares that are smaller than n!
 * 
 * REFERNCE
 * https://leetcode.com/discuss/75808/my-0-ms-c-solution-with-explanation
 * /
