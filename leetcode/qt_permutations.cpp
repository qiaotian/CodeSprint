/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-06T10:41:54+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-06T20:13:56+08:00
* @Inc: LinkedIn, Microsoft
* @Difficulty: Medium
*/



_______________________________________________________________________________

Given a collection of "distinct" numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
_______________________________________________________________________________

//该方法无法应对有重复的情况
class Solution {
private:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, int pos) {
        if(pos == nums.size()-1) {
            res.push_back(nums);
            return;
        }
        for(int i = pos; i < nums.size(); i++) {
            if (i != pos && nums[i] == nums[pos]) continue;
            swap(nums[pos], nums[i]);
            dfs(nums, pos+1);
            swap(nums[pos], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<int> num;
        dfs(nums, 0);
        return res;
    }
};
