/**
允许重复元素，则A[m]<=A[h]，那么[m,h]为递增序列的假设就不能成立了，比如[1,1,1,3,1]。
如果A[m]<=A[h]不能确定区间[m,h]一定递增，那么久把它拆为两个条件：
1. 若A[m]<A[h]，则区间[m, h]一定递增
2. 若A[m]==A[h]，确定不了，那就h--，再往下看一步
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1;
        int mid = 0;
        while(lo < hi){
            mid = (lo + hi) / 2;
            if(nums[mid]==target) return true;

            if(nums[mid] > nums[hi]){
                if(nums[mid] > target && nums[lo] <= target) hi = mid;
                else lo = mid + 1;
            } else if(nums[mid] < nums[hi]){
                if(nums[mid] < target && nums[hi] >= target) lo = mid + 1;
                else hi = mid;
            } else {
                hi--;
            }
        }
        return nums[lo] == target ? true : false;
    }
};

/**
允许重复元素，则A[m]>=A[l]，那么[1,m]为递增序列的假设就不能成立了，比如[1,3,1,1,1]。
如果A[m]>A[l]不能确定区间[l,m]一定递增，那么久把它拆为两个条件：
1. 若A[m]>A[l]，则区间[1, m]一定递增
2. 若A[m]==A[l]，确定不了，那就l++，再往下看一步
*/
class Solution {
public:
    bool search(const vector<int>& nums, int target) {
        int first = 0, last = nums.size();
        while(first != last) {
            const int mid = first + (last - first) / 2;
            if(nums[mid] == target) return true;
            if(nums[first] < nums[mid]) {
                if(nums[first] <= target && target < nums[mid]) last = mid;
                else first = mid + 1;
            } else if(nums[first] > nums[mid]) {
                if(nums[mid] < target && target <nums[last-1]) first = mid+1;
                else last = mid;
            } else {
                //skip the duplicates
                first++;
            }
        }
        return false;
    }
};
