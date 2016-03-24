/*
everse digits of an integer.

Example1:

x = 123,

return 321
Example2:

x = -123,

return -321

Return 0 if the result overflows and does not fit in a 32 bit signed integer
*/


int Solution::reverse(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    bool isPositive = A>=0;
    A = abs(A);
    string astr = to_string(A);
    int n = astr.size()/2-1;
    for(int i=0; i<=n; i++) {
        swap(astr[i], astr[astr.size()-i-1]);
    }
    
    long ans = stol(astr);
    if(ans>INT_MAX) return 0;
    if(!isPositive && -1*ans<INT_MIN) return 0;
    
    return isPositive?ans:-1*ans;
}
