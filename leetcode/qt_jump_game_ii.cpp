/**
* @Author: Tian Qiao
* @Date:   2016-08-01T17:00:29+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-01T17:00:32+08:00
* @Inc: Unknown
* @Tag: Greedy
*/

/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
For example:
Given array A = [2,3,1,1,4]
The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
Note:
You can assume that you can always reach the last index.
*/


// BFS
// 传统基于队列的BFS实现在这里需要解决
// 重复入队的问题
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int level = 0;              //
        int curmax = 0;             // 当前层的最大下标
        int i = 0;                  // nums的游标
        int nexmax = 0;             // 下一层的最大下标

        while(curmax-i+1 > 0) {
            // nodes count of current level
            level++;
            for(; i <= curmax; i++) {
                nexmax = max(nexmax, nums[i]+i);
                // if last element is in level+1
                // then the min jump=level
                if(nexmax >= nums.size()-1) return level; // 最后节点可达
            }
            curmax = nexmax;
        }
        return 0; // 基本无用, 只是为了编译能过
    }
};
