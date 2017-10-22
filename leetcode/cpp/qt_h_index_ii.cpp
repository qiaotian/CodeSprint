// 二分法
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(citations.empty()) return 0;

        int left = 0, right = n-1;
        while(left <= right) {
            int mid = (left+right)/2;
            if(citations[mid] >= n-mid) {
                if(n-mid+1 > citations[mid-1] || mid < 1) return n-mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return 0;
    }
};
