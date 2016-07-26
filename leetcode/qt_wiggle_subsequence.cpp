/**
* @Author: Tian Qiao
* @Date:   2016-07-26T12:18:46+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-26T12:18:50+08:00
* @Difficulty: Medium
* @Tag: DP, Greedy
*/



/*
A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a wiggle sequence.

For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first two differences are positive and the second because its last difference is zero.

Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the remaining elements in their original order.

Examples:
Input: [1,7,4,9,2,5]
Output: 6
The entire sequence is a wiggle sequence.

Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].

Input: [1,2,3,4,5,6,7,8,9]
Output: 2
Follow up:
Can you do it in O(n) time?
*/


// 注意：
// 1. 可能重复元素
// 2. nums.size()=1, 返回1

// Greedy But not elegant
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2) return nums.size();

        vector<int> ans;
        ans.push_back(nums[0]);

        bool up = nums[0]<nums[1]; // 下一步找(局部)极大值
        for(int i=0; i<nums.size();) {
            int old_i = i;
            if(up) {
                while(i<nums.size()-1 && nums[i] <= nums[i+1]) i++;
                if(nums[i]>nums[old_i]) ans.push_back(i);
                else break;
            } else {
                while(i<nums.size()-1 && nums[i] >= nums[i+1]) i++;
                if(nums[i]<nums[old_i]) ans.push_back(i);
            }
            up=!up;
        }
        return ans.size();
    }
};

// Greedy:
// https://discuss.leetcode.com/topic/51893/two-solutions-one-is-dp-the-other-is-greedy-8-lines
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size=nums.size(), f=1, d=1;
        for(int i=1; i<size; ++i){
            if(nums[i]>nums[i-1]) f=d+1;
            else if(nums[i]<nums[i-1]) d=f+1;
            else continue;
        }
        return min(size, max(f, d));
    }
};

// DP:
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size=nums.size();
        if(size==0) return 0;
        vector<int> f(size, 1);
        vector<int> d(size, 1);
        for(int i=1; i<size; ++i){
            for(int j=0; j<i; ++j){
                if(nums[j]<nums[i]){
                    f[i]=max(f[i], d[j]+1);
                }
                else if(nums[j]>nums[i]){
                    d[i]=max(d[i], f[j]+1);
                }
            }
        }
        return max(d.back(), f.back());
    }
};
