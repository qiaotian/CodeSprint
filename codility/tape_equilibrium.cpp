// Author : Tian Q
// Date   : 2016-05-24

// Problem
// Minimize the value |(A[0]+A[1]+...+A[P-1])-(A[P]+A[P+1]+...+A[N-1])|

// Complexity
// Worst-case O(N) for time, O(N) for space

// Solution
class Solution{
public:
    int tape_equilibrium(vector<int> nums) {
        if(nums.size() < 2) return 0;
        long long sum = 0;
        for(auto num:nums) sum+=num;
        long long left = 0;
        int minidx = 0; // 分割线在第0个元素之前
        long long delta = abs(sum);
        for(int i = 1; i<nums.size(); i++) {
            left += nums[i];
            right -= nums[i];
            long long newdelta = abs(left-right);
            if(newdelta < delta) {
                delta = newdelta;
                minidx = i;
            }
        }
        return minidx;
    }
};
