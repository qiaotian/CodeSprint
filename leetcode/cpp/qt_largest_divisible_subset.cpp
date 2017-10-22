/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-06-29T15:27:41+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-09T15:16:28+08:00
* @License: Free License
*/


/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.
If there are multiple solutions, return any subset is fine.

Example 1:
nums: [1,2,3]
Result: [1,2] (of course, [1,3] will also be ok)

Example 2:
nums: [1,2,4,8]
Result: [1,2,4,8]
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return vector<int>();
        sort(nums.begin(), nums.end());

        // dp[i]: 截止到第i个元素，最大子集长度和当前节点在最大子集中的上一节点
        vector<pair<int, int>> dp(nums.size(), make_pair(1, -1));
        // len:最大整除子集长度
        // tail:及最大整除子集的末尾元素索引
        int len = 1, tail = 0;

        for (int i = 1; i < nums.size(); i++) {
            int largest = 1, parentIdx = -1;
            // 针对nums[i]，遍历nums[i]之前的因子，找到
            // 以nums[i]结尾的最大整除子集长度 largest
            // 和父节点parent
            for (int j = i - 1; j > - 1; j--) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j].first + 1 > largest) {
                        parentIdx = j;
                        largest = dp[j].first + 1;
                    }
                }
            }
            dp[i].first = largest;
            dp[i].second = parentIdx;

            if (largest > globalLargest) {
                tail = i;
                len = largest;
            }
        }
        vector<int> ret;
        for (int idx = globalLargestIdx; idx != -1; idx = dp[idx].second) {
            //ret.push_back(nums[idx]);
            ret.insert(ret.begin(), nums[idx]);
        }
        return ret;
    }
};
