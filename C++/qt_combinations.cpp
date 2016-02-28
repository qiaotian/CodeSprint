class Solution {
private:
    vector<vector<int>> res;
    void helper(int n, int k, int minval, vector<int>& comb) {
        if(k == 0) { res.push_back(comb); return; }
        if(minval == n && k > 1) return;
        for(int i = minval; i <= n; i++) {
            comb.push_back(i);
            helper(n, k-1, i+1, comb);
            comb.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> comb;
        helper(n, k, 1, comb);
        return res;
    }
};
