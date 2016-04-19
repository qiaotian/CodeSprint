/*
class Solution {
public:
    int findMin(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[0];
    }
};
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[i-1]) return nums[i];
        }
        return res;
    }
};
