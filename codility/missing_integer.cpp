int solution(vector<int> &A) {
    vector<bool> flags(INT_MAX, false);
    for(auto num:A) {
        if(num<1) continue;
        flags[num-1] = true;
    }
    int i = 1;
    while(1) {
        if(!flags[i-1]) return i;
        i++;
    }
    return -1;
}

// 陷阱
// 分配过多空间给flags
// 仅需要简单思考，就可以判定结果一定在A.size()+1以内
// 应当注意for循环中的边界问题
int solution(vector<int>& A) {
    vector<bool> flags(A.size()+1, false);
    for(auto num:A) {
        if(num>0 && num<=A.size()) flags[num] = true;
    }
    for(int i=1; i<=flags.size(); i++) {
        if(!flags[i]) return i;
    }
    return A.size()+1;
}
