/**
* @Author: Tian Qiao
* @Date:   2016-07-05T21:56:26+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-05T22:33:34+08:00
* @Inc: Google
*/


/*

Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

For example, given nums = [-2, 0, 1, 3], and target = 2.
Return 2. Because there are two triplets which sums are less than 2:
[-2, 0, 1]
[-2, 0, 3]
Follow up:
Could you solve it in O(n2) runtime?

*/

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int ans = 0;
        if(nums.size()<3) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<n-2; i++) {
            int l = i+1, r = n-1;
            while(l < r) {
                int sum = nums[l]+nums[r];
                if(sum<target-nums[i]) {
                    ans+=(r-l);
                    l++;
                } else {
                    r--;
                }
            }
        }
        return ans;
    }
};
