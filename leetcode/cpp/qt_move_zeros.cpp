/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /*vector<int>::iterator it;
        int zeros = 0;
        for(it=nums.begin(); it!=nums.end();){
            if(*it==0){
                nums.erase(it);
                zeros++;
            } else {
                it++;
            }
        }
        for(int i=0; i<zeros; ++i) {
            nums.push_back(0);
        }
        */ //20ms
        int last = 0, cur = 0;

        while(cur < nums.size()) {
            if(nums[cur] != 0) {
                swap(nums[last++], nums[cur]);
            }
            cur++;
        } //20ms
    }
};
