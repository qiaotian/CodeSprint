class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty()) return 0;
        sort(citations.begin(), citations.end());
        int res = 1;
        for(int i = citations.size()-1; i >= 0; i--) {
            if(res <= citations[i]) res++;
            else return res-1;
        }
        return res-1;
    }
};
