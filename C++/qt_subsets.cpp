// Recursion
// O(N^2)
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

// Nonrecursion
// O(N^2)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        int vecsize = nums.size();
        int setsize = 1 << vecsize;

        sort(nums.begin(), nums.end());

        for(int i=0; i<setsize; i++) {
            // find all set element
            for(int j=0; j<vecsize; j++) {
                // determine which number could be included
                if(i & (1<<j)) tmp.push_back(nums[j]);
            }
            ans.push_back(tmp);
            tmp.clear();
        }
        return ans;
    }
};
