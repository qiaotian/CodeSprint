/**
* @Author: Tian Qiao <root>
* @Date:   2016-07-12T15:39:08+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   root
* @Last modified time: 2016-07-12T17:04:40+08:00
* @Inc: Goolge
* @Difficulty: Medium
*/

/*
Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.

For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
*/

// 由于审题错误，误以为数组元素和[lower, upper]范围无关，走了一些弯路，在更为宽松的条件下仍然给出了解法一。该算法不仅能够应付本题。而且，当[lower, upper]与数组无关时，也能给出正确解。我认为，原题难度只能称得上easy【杂记】

class Solution {
public:
    string cvtStr(int start, int end) {
        if(start==end) return to_string(start);
        else to_string(start)+"->"+to_string(end);
    }

    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<pair<int, int>> vec;
        vector<string> ans;
        // [lower, upper] 与 nums不相交
        int n = nums.size();

        if(nums.empty() || upper < nums[0] || lower > nums[n-1])
            return vector<string>(1, cvtStr(lower, upper));
        /*
        // find the missing part left to nums
        if(lower < nums[0]) ans.push_back(cvtStr(lower, nums[0]-1));
        // find the missing part inner nums
        */


        vec.push_back({INT32_MIN, nums[0]-1}); // 将负无穷到nums[0]-1作为missing part
        for(int i=1; i<n; i++) {
            if(nums[i]-nums[i-1]>1)
                vec.push_back({nums[i-1]+1, nums[i]-1});
        }
        vec.push_back(nums[n-1]+1, INT32_MAX); // 将nums[n-1]+1到正无穷作为missing part

        for(auto i:vec) {
            if(min(i.second, upper)>=max(i.first, lower)) {
                ans.push_back(cvtStr(max(i.first, lower), min(i.second, upper)));
            }
        }
        return ans;
        /*
        // 在nums中找到第一个>=lower的数字下标
        // 在nums中找到走后一个<=upper的数字下标
        int l1 = 0, r1 = nums.size()-1;
        while(l1 < r1) {
            int m1 = (l1+r1)/2;
            if(nums[m1] < lower) l1 = m1+1;
            else r1 = m1;
        }
        int l2 = 0, r2 = nums.size()-1;
        while(l2 < r2) {
            int m2 = (l2+r2)/2+1;
            if(nums[m2] > upper) r2 = m2-1;
            else l2 = m2;
        }
        if(nums[r1]-lower>1) ans.push_back(cvtStr(nums[r1]+1, ))
*/

        // fine the missing part right to nums
    }
};


// https://discuss.leetcode.com/category/171/missing-ranges
// 更为简单，一次遍历即可，和方案1的速度几乎没有差别
// 注意：第一种解法适用于任意[lower, upper]的情况，也就是说array中的元素可以超出定义域，使用范围更为广泛。而下面这种解法只适用于数组元素来自定义域的情况，该解法太过简单。
class Solution {
public:
    string get_range(int start, int end) {
        return start==end?to_string(start):to_string(start)+"->"+to_string(end);
    }
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        int pre = lower-1;
        for(int i = 0; i <= nums.size(); i++) {
           int cur = (i==nums.size()? upper+1:nums[i]);
           if(cur-pre>=2)
            result.push_back(get_range(pre+1,cur-1));
            pre = cur;
        }
        return result;
    }
};
