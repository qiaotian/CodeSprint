/**
* @Author: Tian Qiao
* @Date:   2016-07-03T15:28:16+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-03T15:42:02+08:00
* @Difficulty: Medium
*/

Input array is sorted!!!

Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

________________________________________________________________________________

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int l = 0, r = (int)numbers.size()-1;
        while(l<r) {
            if(numbers[l]+numers[r] > target) r--;
            else if(numbers[l]+numers[r] < target) l++;
            else {
                ans.push_back(l+1); // one-based address
                ans.push_back(r+1);
                return ans;
            }
        }
        return ans;
    }
};
