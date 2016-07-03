/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-06-30T21:28:03+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-06-30T21:28:28+08:00
* @License: Free License
*/



/*******
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example:
Given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
For this problem, return the maximum sum.
*/

int Solution::maxSubArray(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int ans = INT32_MIN;
    int tmp = 0;
    for(auto i:A) {
        tmp+=i;
        ans = max(ans, tmp);
        tmp = max(0, tmp);
    }
    return ans;
}
