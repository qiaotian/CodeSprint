// 1st solution (16ms, beats 42%) 
/*
class Solution {
    vector<vector<int>> res;
    void util(vector<int>& candidates, vector<int>&comb, int target, int minidx) {
        // minidx: 可用candidates中的最小下角标
        if(target == 0) {
            res.push_back(comb); 
            return;
        }
        if(target < 0 || minidx >= candidates.size()) return;
        for(int i = minidx; i < candidates.size();) {
            int tmp = candidates[i];
            comb.push_back(candidates[i]);
            util(candidates, comb, target - candidates[i], i+1);
            comb.pop_back();
            i++;
            while(candidates[i] == tmp) i++;
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> comb;
        sort(candidates.begin(), candidates.end());
        util(candidates, comb, target, 0);
        return res;
    }
};
*/

// 2nd solution (8ms, beats 76%)
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backTracking(candidates.begin(), current, res, candidates, target);
        return res;
    }
    void backTracking(vector<int>::iterator n, vector<int>& current,vector<vector<int>>& res, const vector<int>& candidates, int target){
        if(!target) res.push_back(current);
        else if(target > 0){
            for(; n != candidates.end() && *n <= target; ++n){
                current.push_back(*n);
                backTracking(n + 1, current, res, candidates, target - *n);
                current.pop_back();
                while(n+1!=candidates.end() && *(n+1)==*n) ++n; //跳过重复元素，本题的关键
            }
        }
    }
};

/**
 * WARNING
 * 1. candidates里面包含重复值
 * 2. 跳过重复元素是解题关键
 * /