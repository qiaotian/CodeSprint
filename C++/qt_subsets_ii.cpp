class Solution {
    void util(vector<vector<int>>& res, vector<int>& sub, vector<int> nums, int pos) {
        res.push_back(sub);
        for(int i = pos; i < nums.size();) {
            sub.push_back(nums[i]);
            util(res, sub, nums, i+1);
            sub.pop_back();
            i++;
            while(i > pos && i<nums.size() && nums[i] == nums[i-1]) i++;
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> sub;
        util(res, sub, nums, 0);
        return res;
    }
};