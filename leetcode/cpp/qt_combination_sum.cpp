// DFS + Recursion (16ms, beats 68%)
class Solution {
private:
    vector<vector<int>> res;
    void util(vector<int>& candidates, vector<int>& comb, int minidx, int target) {
        // params:
        // candidates: 排序后的候选数字
        // minidx: 当前可选数字的最小下标
        if(target == 0) res.push_back(comb);
        if(target < 0) return;
        for(int i = minidx; i < candidates.size(); i++) {
            if(candidates[i] > target) break; //遇到大于target的数字，那么该数字大的所有数均跳过不访问
            comb.push_back(candidates[i]);
            util(candidates, comb, i, target-candidates[i]);
            comb.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        sort(candidates.begin(), candidates.end());
        util(candidates, comb, 0, target);
        return res;
    }
};
