/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-06-30T21:56:19+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-06-30T21:56:55+08:00
* @License: Free License
*/



/******
Given a non-negative number represented as an array of digits,
add 1 to the number ( increment the number represented by the digits ).
The digits are stored such that the most significant digit is at the head of the list.

Example:
If the vector has [1, 2, 3]
the returned vector should be [1, 2, 4]
as 123 + 1 = 124.

NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer.
For example, for this problem, following are some good questions to ask :
Q : Can the input have 0’s before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
A : For the purpose of this question, YES
Q : Can the output have 0’s before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.
*/

vector<int> Solution::plusOne(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> ans;
    int carry = 1;
    for(int i=A.size()-1; i>=0; i--) {
        A[i] += carry;
        carry = A[i]/10;
        A[i] = A[i]%10;
        ans.push_back(A[i]);
    }
    if(carry) ans.push_back(carry);
    for(int i=0; i<ans.size()/2; i++)
        swap(ans[i], ans[ans.size()-1-i]);
    // count the leading zeros
    int count = 0;
    for(int i=0; i<ans.size(); i++) {
        if(ans[i]==0) count++;
        else break;
    }
    // delete the leading zeros
    for(int i=count; i<ans.size(); i++) ans[i-count] = ans[i];
    for(int i=0; i<count; i++) ans.pop_back();

    return ans;
}
