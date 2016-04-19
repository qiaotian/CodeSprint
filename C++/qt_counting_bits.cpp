// 不难总结出如下规律：
// num[even] = num[even/2]
// num[even+1] = num[even]+1
/*
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        res[0] = 0;
        res[1] = 1;
        for(int i = 2; i <= num; i++) {
            if(i%2==0) res[i] = res[i/2];
            else res[i] = res[i-1]+1;
        }
        return res;
    }
};
*/
// shorter version
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        for(int i = 0; i <= num; i++) {
            res[i] = res[i/2]+i%2;
        }
        return res;
    }
};
