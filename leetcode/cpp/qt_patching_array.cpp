/**
* @Author: Tian Qiao <root>
* @Date:   2016-02-12T14:22:23+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   root
* @Last modified time: 2016-06-25T23:51:03+08:00
* @License: Free License
*/

/*
Given a sorted positive integer array nums and an integer n, add/patch elements to the array such that any number in range [1, n] inclusive can be formed by the sum of some elements in the array. Return the minimum number of patches required.

Example 1:
nums = [1, 3], n = 6
Return 1.

Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
So we only need 1 patch.

Example 2:
nums = [1, 5, 10], n = 20
Return 2.
The two patches can be [2, 4].

Example 3:
nums = [1, 2, 2], n = 5
Return 0.

*/

class Solution {
public:

    int minPatches(vector<int>& nums, int n) {
        //
        long miss = 1, count = 0, i = 0; // long type is for fear of TLE
        while(miss <= n) {
            if(i < nums.size() && nums[i] <= miss) { // the first condition is for the case nums is empty
                miss += nums[i++];
            } else {
                count++;
                miss += miss;
            }
        }
        return count;

        // short version
        // int count = 0, i = 0;
        // for(int miss = 1; miss <=n; count++) {
        //     miss += (i < nums.size() && nums[i] <= miss) ? nums[i++] : miss;
        // }
        // return count;
    }
};

/**
 * Explanation:
 * https://leetcode.com/discuss/82822/solution-explanation
 *
 * /
