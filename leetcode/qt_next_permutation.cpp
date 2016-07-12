/**
* @Author: Tian Qiao <root>
* @Date:   2016-07-12T20:39:42+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   root
* @Last modified time: 2016-07-12T23:48:54+08:00
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

c/*
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
            //sort(nums.begin(), nums.end());
            for(int i=0; i<n/2; i++) {
                swap(nums[i], nums[n-1-i]);
            }
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
*/

// 解法一样，貌似reverse函数更快一些
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	int k = -1;
    	for (int i = nums.size() - 2; i >= 0; i--) {
    		if (nums[i] < nums[i + 1]) {k = i; break;}
    	}
    	if (k == -1) {
    	    reverse(nums.begin(), nums.end());
    	    return;
    	}
    	int l = -1;
    	for (int i = nums.size() - 1; i > k; i--) {
    		if (nums[i] > nums[k]) {
    			l = i;
    			break;
    		}
    	}
    	swap(nums[k], nums[l]);
    	reverse(nums.begin() + k + 1, nums.end());
    }
}; 
