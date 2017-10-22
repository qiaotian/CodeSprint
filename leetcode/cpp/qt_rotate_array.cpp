/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Hint:
Could you do it in-place with O(1) extra space?
Related problem: Reverse Words in a String II
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Solution 0
        // Time complexity: O(n). Space complexity: O(n).
        k = k%nums.size();
        vector<int> cnums(nums.size()); // copy of vector nums
        for(int i=0; i<nums.size(); ++i) cnums[i] = nums[i];
        for(int i=0; i<nums.size(); ++i) nums[(i+k)%nums.size()] = cnums[i];
        
        // Solution 1
        // Time complexity: O(n). Space complexity: O(1).
        /*
        k = k%nums.size();
        reverse(nums.begin(), nums.end());     // rotate all elements
        reverse(nums.begin(), nums.begin()+k); // rotate the left k%n elements
        reverse(nums.begin()+k, nums.end());   // rotate the right n-k%n elements
        */
        // Solution 2
        
    }
};
/***
 * Solutin 1:
 * divide the array into two parts left and right
 * the left side moves to right and vice verse
 * 
 * /
