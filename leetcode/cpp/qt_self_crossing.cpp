class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int len = x.size(),i;
        for(i=3; i<len;++i)
        {
            if(x[i]>=x[i-2] && x[i-1] <= x[i-3]) return true; // case 1, the consecutive four lines form a cross
            if(i>3 && x[i-1]==x[i-3] && x[i]+x[i-4]>=x[i-2]) return true; // case 2, the consecutive five lines form a cross
            if(i>4 && x[i-2]>=x[i-4] && x[i-4]+x[i]>=x[i-2] && x[i-1]<=x[i-3] && x[i-5] + x[i-1]>=x[i-3]) return true;// case 3, the consecutive six lines form a cross
        }
        return false;
    }
};
