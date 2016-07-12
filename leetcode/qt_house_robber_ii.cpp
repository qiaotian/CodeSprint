/**
* @Author: Tian Qiao <root>
* @Date:   2016-07-12T14:25:25+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   root
* @Last modified time: 2016-07-12T15:36:33+08:00
* @Inc: Microsoft
* @Difficulty: Medium
*/

/*
After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int helper(vector<int>& nums, int start, int end) {
        int n = nums.size();
        if((end+n-start)%n==0) return nums[start];

        int pre = 0, cur = nums[start];
        for(int i = 1; i < (end-start+1+n)%n; i++) {//注意：从1开始
            int tmp = cur;
            cur = max(pre+nums[(start+i)%n], cur);
            pre = tmp;
        }
        return cur>pre?cur:pre;
    }
    int rob(vector<int>& nums) {
        int ans = 0;
        if(nums.empty()) return 0;
        if(nums.size()==1) return nums[0];
        int n = nums.size();

        for(int i=0; i<min(n,3); i++) { // 最多看3个点，无需从环中每个点开始遍历
            int start = (i+2)%n;
            int end = (i+n-2)%n;
            cout << start << " " << end << endl;
            int income = n<4?0:helper(nums, start, end);
            ans = max(ans, nums[i]+income);
        }
        return ans;
    }
};

// 优化
/*This problem is a little tricky at first glance. However, if you have finished the House Robber problem, this problem can simply be decomposed into two House Robber problems.
Suppose there are n houses, since house 0 and n - 1 are now neighbors, we cannot rob them together and thus the solution is now the maximum of

Rob houses 0 to n - 2;
Rob houses 1 to n - 1.
The code is as follows. Some edge cases (n < 2) are handled explicitly.*/

class Solution2 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n ? nums[0] : 0;
        return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
    }
private:
    int robber(vector<int>& nums, int l, int r) {
        int pre = 0, cur = 0;
        for (int i = l; i <= r; i++) {
            int temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};

int main() {
    vector<int> nums = {2,7,9,3,1};
    Solution *sln = new Solution();
    int ans = sln->rob(nums);
    cout << ans << endl;
    return 0;
}
