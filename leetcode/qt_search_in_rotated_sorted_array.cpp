class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        // find the first element's index in sorted array
        while(low < high) {
            int mid = (low+high)/2;
            if(nums[mid] > nums[high]) low = mid+1;
            else high = mid;
        }
        int rot = low;
        low = 0, high = nums.size()-1;

        // relocate the low and high
        if(nums[high] == target) return high;
        else if(nums[high] > target) low = rot;
        else high = rot-1;

        // find the target using dichotomizing search
        while(low < high) {
            int mid = (low+high)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) high = mid-1;
            else low = mid+1;
        }
        return nums[low]==target?low:-1;
    }
};

/**
 * 主要步骤如下：
 * 1. 用二分搜索找到sorted数组的第一个元素下标
 * 2. 将target于rotated后的数组最后一个元素比较，从而将target定位在单调递增区间内
 * 3. 在单调递增区间内再次用二分搜索查找target
 *
 * 注意：
 * 1. 在第一步中，使用二分查找的上界条件是high=mid而非high=mid-1，这样做是因为mid总是趋向于偏向low这一边，因此，当nums[mid] > nums[high]时，第一个元素一定在mid的右侧; 而当nums[mid] <= nums[high]时，mid出于第一个元素和high之间的某处，并有可能在第一个元素处，所以保险起见，high = mid; 最终目标是要让low和high同时指向第一个元素然后退出。
 */
