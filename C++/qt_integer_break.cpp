// 3^x 一定大于 x^3易证
// 5拆成2和3
// 4和2不必拆

class Solution {
public:
    int integerBreak(int n) {
        int ret = 1;
        if(n==2) return 1;
        if(n==3) return 2;
        if(n==4) return 4;

        while(n>=5) {
            ret*=3;
            n-=3;
        }
        return ret*n;
    }
};

class Solution {
public:
    int integerBreak(int n) {
        const vector<int> ref{1,1,1,2,4};
        if(n<=4) return ref[n];
        if(n%3==0) return pow(3, n/3);
        if(n%3==1) return 4*pow(3, n/3-1);
        if(n%3==2) return 2*pow(3, n/3);
    }
};
