// 思路：
// 只要统计数组中‘0...1’的个数即可
// 由左至右统计零的个数，遇到1就在返回结果上加零的个数
int solution(vector<int>& A) {
    long ans = 0;
    long zerocount = 0;
    for(auto i:A) {
        zerocount+=(i==0);
        if(i==1) ans+=zerocount;
    }
    if(ans>1000000000) return -1;
    return (int)ans;
}

// 注意整数加和溢出的问题
