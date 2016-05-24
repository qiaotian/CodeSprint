// 1st Solution
/*
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        long sum = 2147483647; // max value of sum of the three int elements
        
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue; // ignore the same value
            long localsum = 2147483647;

            int l=i+1, r=nums.size()-1;
            while(l<r) {
                long newlocalsum = nums[i]+nums[l]+nums[r];

                if(newlocalsum-target == 0) return newlocalsum;
                if(newlocalsum-target < 0) l++; else r--;
                if(abs(newlocalsum-target) <= abs(localsum-target)) // error
                    localsum = newlocalsum;
                else 
                    break;
            }
            if(abs(localsum-target) < abs(sum-target) || i==0) {
                sum = localsum;
            }
        }
        return sum;
    }
};
*/

// 2nd Solution
// https://leetcode.com/discuss/42432/c-solution-o-n-2-using-sort
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) return 0;
        int closest = nums[0]+nums[1]+nums[2];
        sort(nums.begin(), nums.end());
        for(int first = 0 ; first < nums.size()-2 ; ++first) {
            if(first > 0 && nums[first] == nums[first-1]) continue; // ignore the same value
            int second = first+1;
            int third = nums.size()-1;            
            while(second < third) {
                int curSum = nums[first]+nums[second]+nums[third];
                if(curSum == target) return curSum;
                if(abs(target-curSum)<abs(target-closest)) {
                    closest = curSum;
                }
                if(curSum > target) {
                    --third;
                } else {
                    ++second;
                }
            }
        }
        return closest;
    }
};


/****
 * Warning:
 * if int localsum = 2147483647 and int target = -1
 * (localsum - target) will overflow
 * therefore, the sum of int should be initialized with type long
 * 
 * 1. 去重（跳过数值相同的值）
 * 2. 初始化整形极限值时防范出现越界
 * 3. 特里判定
 * 4. 命名规范
 * /
