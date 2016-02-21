// 1st solution (Time: O(N^2) Space: O(N)) 
/*
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        vector<int> cout(nums.size(), 1);
        
        int maxlen = 1;
        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j]<nums[i]) {
                    cout[i] = max(cout[i], cout[j]+1);
                    maxlen = max(maxlen, cout[i]);
                }
            }
        }
        return maxlen;
    }
};
*/

// 2nd solution (Time: O(N*logN), Space:O(N))
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for (int a : nums)
            if (ans.size() == 0 || a > ans.back()) ans.push_back(a);
            else *lower_bound(ans.begin(), ans.end(), a) = a;
        return ans.size();
    }
};


/**
 * 1st solution
 * http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
 * 
 */
