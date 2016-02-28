class Solution {
private:
    vector<vector<int>> res;
    void dfs(int k, int n, int minval, vector<int>& comb) {
        if(k == 0 && n == 0) {
            res.push_back(comb);
            return;
        }
        for(int i = minval; i<10; i++) {
            comb.push_back(i);
            dfs(k-1, n-i, i+1, comb);
            comb.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> comb;
        dfs(k, n, 1, comb);
        return res;
    }
};
