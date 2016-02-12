class Solution {
public:
    
    int minPatches(vector<int>& nums, int n) {
        //
        long miss = 1, count = 0, i = 0; // long type is for fear of TLE
        while(miss <= n) {
            if(i < nums.size() && nums[i] <= miss) { // the first condition is for the case nums is empty
                miss += nums[i++];
            } else {
                count++;
                miss += miss;
            }
        }
        return count;
        
        // short version
        // int count = 0, i = 0;
        // for(int miss = 1; miss <=n; count++) {
        //     miss += (i < nums.size() && nums[i] <= miss) ? nums[i++] : miss;
        // }
        // return count;
    }
};

/**
 * Explanation: 
 * https://leetcode.com/discuss/82822/solution-explanation
 * 
 * /
