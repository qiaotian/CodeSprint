/*
Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.

Hint:

Try two pointers.
Did you use the property of "the order of elements can be changed"?
What happens when the elements to remove are rare?
*/


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        /* my sln
        int len = nums.size(); // the len is the length of all non-val elements
        for(int i=0; i<len; ++i) {
            while(nums[i]==val && i<len) {
                swap(nums[i], nums[--len]);
                nums.pop_back();
            }
        }
        return len;
        */
        
        int begin=0;
        for(int i=0;i<nums.size();i++) if(nums[i]!=val) nums[begin++]=nums[i];
        return begin;
    }
};

/**
 * my sln:
 *  the loop conditions must put 'i<len' before 'nums[i]==val'
 *  the len will be changed during looping, so 'i<len' could not be ignored
 * sln 2:
 *  does not delete the duplicated elements
 * /
