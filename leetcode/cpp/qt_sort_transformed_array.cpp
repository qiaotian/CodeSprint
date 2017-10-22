/**
* @Author: Tian Qiao
* @Date:   2016-07-05T17:04:24+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-05T17:36:25+08:00
* @Inc:
*/



_______________________________________________________________________________

Given a sorted array of integers nums and integer values a, b and c. Apply a function of the form f(x) = ax2 + bx + c to each element x in the array.

The returned array must be in sorted order.
Expected time complexity: O(n)

Example:
nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,
Result: [3, 9, 15, 33]

nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5
Result: [-23, -5, 1, 7]
_______________________________________________________________________________

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        vector<int> val(n, 0);
        vector<int> ans(n, 0);

        for(int i=0; i<n; i++)
            val[i] = a*nums[i]*nums[i]+b*nums[i]+c;

        if(a>0) {
            float axis = -b/(2.0*a);
            for(int i=n-1, l=0, r=n-1; i>=0; i--) {
                ans[i] = (abs(nums[l]-axis)>abs(nums[r]-axis))?val[l++]:val[r--];
            }
        } else if(a<0) {
            float axis = -b/(2.0*a);
            for(int i=0, l=0, r=n-1; i<n; i++) {
                ans[i] = (abs(nums[l]-axis)>abs(nums[r]-axis))?val[l++]:val[r--];
            }
        } else {
            for(int i=0; i<n; i++) {
                ans[i] = b>0?val[i]:val[nums.size()-1-i];
            }
        }
        return ans;
    }
};
