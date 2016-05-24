vector<int> solution(int n, vector<int>& ops) {
    // n: is the number of counters
    // ops: is the operation list
    vector<int> ans(n, 0);
    int cur_max = 0;
    for(auto op:ops) {
        if(op>n) ans.assign(n, cur_max);
        ans[op-1]++;
        if(ans[op-1]>cur_max) cur_max = ans[op-1];
    }
    return ans;
}

// solution1 时间消耗略高
// 对于同时将所有位置cur_max的操作，可以优化
// 即用变量存储并更新上一次的cur_max，在最后统一更新

vector<int> solution(int n, vector<int>& ops) {
    vector<int> ans(n, 0);
    int cur_max = 0;
    int last_max = 0;
    for(auto op:ops) {
        if(op>n) last_max = cur_max;
        ans[op-1] = max(ans[op-1]+1, last_max+1);
        cur_max = max(ans[op-1], cur_max);
    }
    for(auto num:ans) {
        num = max(num, last_max);
    }
    return ans;
}
