// 1st solution (36ms, beats 23%)
/*class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int more = 0, less = 0;
        for(int i = 0; i < nums.size()+1; i++) more ^= i;
        for(int i = 0; i < nums.size(); i++) less ^= nums[i];
        return more^less;
    }
};*/

// 2nd solution (34ms, beats 84%)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            res ^= i+1;
            res ^= nums[i];
        }
        return res;
    }
};
