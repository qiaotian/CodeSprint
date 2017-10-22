/**
* @Author: Tian Qiao
* @Date:   2016-08-07T23:10:40+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-07T23:10:42+08:00
* @Difficulty: easy
* @Tag: DP
* @Inc: Adobe, Apple
*/

/*
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/


class Solution {
public:
    int climbStairs(int n) {
        int steps[n];
        steps[0] = 1;
        steps[1] = 2;
        for(int i=2; i<n; ++i){
            steps[i] = steps[i-1]+steps[i-2];
        }
        return steps[n-1];
    }
};

// NOTICE
/**
 * Dynamic Programming
 * It's a fibonacci
 * Base cases:
    if n <= 0, then the number of ways should be zero. if n == 1, then there is only way to climb the stair. if n == 2, then there are two ways to climb the stairs. One solution is one step by another; the other one is two steps at one time.

    The key intuition to solve the problem is that given a number of stairs n, if we know the number ways to get to the points [n-1] and [n-2] respectively, denoted as n1 and n2 , then the total ways to get to the point [n] is n1 + n2. Because from the [n-1] point, we can take one single step to reach [n]. And from the [n-2] point, we could take two steps to get there. There is NO overlapping between these two solution sets, because we differ in the final step.
 * /
