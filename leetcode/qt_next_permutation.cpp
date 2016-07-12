/**
* @Author: Tian Qiao <root>
* @Date:   2016-07-12T20:39:42+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   root
* @Last modified time: 2016-07-12T21:07:30+08:00
* @Inc: Google
* @Difficulty: Medium
*/



/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place, do not allocate extra memory.
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/



// From Right to Left, find the first digit (partition number) which violate the increase trend;
// From Right to Left, find the first digit which is larger than the partition number, call it changing number.
// Swap the partition number and changing number.
// Rerverse all the digit on the right of partition index.

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.empty() || nums.size()==1) return;
        int n = nums.size();
        int partitionIdx = INT32_MAX;
        int changingIdx = INT32_MAX;
        for(int i=n-2; i>=0; i--) {
            if(nums[i]<nums[i+1]) {
                partitionIdx = i;
                break;
            }
        }

        if(partitionIdx==INT32_MAX) {
            //如果没找到，说明当前数字已经是最大序数，
            //按照题意，需要将nums置为最小序数
            sort(nums.begin(), nums.end());
            return;
        }

        for(int i=n-1; i>=0; i--) {
            if(nums[i]>nums[partitionIdx]) {
                changingIdx = i;
                break;
            }
        }
        cout << partitionIdx  << endl;
        cout << changingIdx << endl;
        swap(nums[changingIdx], nums[partitionIdx]);
        for(int i=0; i<(n-partitionIdx-1)/2; i++) {
            swap(nums[i+partitionIdx+1], nums[n-i-1]);
        }
    }
};
