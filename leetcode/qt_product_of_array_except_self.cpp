/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
Solve it without division and in O(n).
For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int first = 1, last = 1;
        int n = nums.size();
        vector<int> res(n, 1);
        for(int i = 0; i < n; i++) {
            res[i] *= first;
            first *= nums[i];
            res[n-i-1] *= last;
            last *= nums[n-1-i];
        }
        return res;
    }
};
/**
 * first: 1->1*2->1*2*3->1*2*3*4
 * last : 4->4*3->4*3*2->4*3*2*1
 * /
