// 1st solution
// 通过将target减去0.1和加上0.1得到新的目标值，
// 根据新的目标值计算出开始和结束的position
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int n = nums.size();
        float target1 = target - 0.1;
        float target2 = target + 0.1;
        
        int l = 0, r = n-1;
        while(l < r) {
            int m = (l + r)/2;
            if(nums[m] > target1) r = m-1;
            if(nums[m] < target1) l = m+1;
        }
        if(l+1>=0 && l+1<=n-1  && nums[l+1] == target) res[0] = l+1;
        if(l>=0   && l<=n-1    && nums[l] == target) res[0] = l;
        if(l-1>=0 && l-1 <=n-1 && nums[l-1] == target) res[0] = l-1;
        
        l = 0; r = n-1;
        while(l < r) {
            int m = (l + r)/2;
            if(nums[m] > target2) r = m-1;
            if(nums[m] < target2) l = m+1;
        }
        if(l-1>=0 && l-1 <=n-1 && nums[l-1] == target) res[1] = l-1;
        if(l>=0   && l<=n-1    && nums[l] == target) res[1] = l;
        if(l+1>=0 && l+1<=n-1  && nums[l+1] == target) res[1] = l+1;

        return res;
    }
};

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int i = 0, j = n - 1;
        vector<int> ret(2, -1);
        // Search for the left one
        while (i < j)
        {
            int mid = (i + j) /2;
            if (A[mid] < target) i = mid + 1;
            else j = mid;
        }
        if (A[i]!=target) return ret;
        else ret[0] = i;

        // Search for the right one
        j = n-1;  // We don't have to set i to 0 the second time.
        while (i < j)
        {
            int mid = (i + j) /2 + 1;   // Make mid biased to the right
            if (A[mid] > target) j = mid - 1;  
            else i = mid;               // So that this won't make the search range stuck.
        }
        ret[1] = j;
        return ret; 
    }    
};

/** 
 *https://leetcode.com/discuss/18242/clean-iterative-solution-binary-searches-with-explanation
 * */
