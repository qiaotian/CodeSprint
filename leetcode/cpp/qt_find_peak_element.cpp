// 4ms, beat 94%
class Solution {
private:
    int helper(const vector<int> &num, int low, int high) {
        if(low == high) return low;
        
        int mid = (low + high)/2;
        int nxt = mid + 1;
        
        if(num[mid] > num[nxt]) {
            return helper(num, low, mid);
        } else {
            return helper(num, nxt, high);
        }
    }
public:
    int findPeakElement(const vector<int> &num) {
        return helper(num, 0, num.size()-1);
    }
};
/**
 * 1st solution
 * logarithmic complexity
 * Consider that each local maximum is one valid peak. 
 * My solution is to find one local maximum with binary search.
 * /
