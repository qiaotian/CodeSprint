class Solution {
    void util(vector<vector<int>>& res, vector<int>& nums, vector<int>& comb, int pos) {
        res.push_back(comb);
        for(int i = pos; i < nums.size(); i++) {
            comb.push_back(nums[i]);
            util(res, nums, comb, i+1); // 把i错写成pos
            comb.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> comb;
        sort(nums.begin(), nums.end());
        util(res, nums, comb, 0);
        return res;
    }
};