/**
* @Author: Tian Qiao
* @Date:   2016-07-03T18:33:57+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-03T19:31:26+08:00
* @Inc: Google
* @Difficulty: Easy
*/


/*There is a fence(栅栏) with n posts, each post can be painted with one of the k colors.
You have to paint all the posts such that no more than two adjacent fence posts have the same color.
Return the total number of ways you can paint the fence.

Note:
n and k are non-negative integers.*/

________________________________________________________________________________

// 方案一：内存消耗略多
class Solution {
public:
    int numWays(int n, int k) {
        vector<int> same(n+1, 0); // 第i位与第i-1位相同 的方案数目
        vector<int> diff(n+1, 0); // 第i位于第i-1位不同 的方案数目
        same[1] = 0;
        diff[1] = k;
        for(int i=2; i<=n; i++) {
            same[i] = diff[i-1];
            diff[i] = (k-1)*(same[i-1]+diff[i-1]);
        }
        return same[n]+diff[n];
    }
};

// 方案二：改进
class Solution {
public:
    int numWays(int n, int k) {
        if(n<=0 || k<=0) return 0;
        int same = 0;
        int diff = k;
        for(int i=2; i<=n; i++) {
            int tmp = same;
            same = diff;
            diff = (k-1)*(tmp+diff);
        }
        return same+diff;
    }
};
