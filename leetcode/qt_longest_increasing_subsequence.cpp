// 1st solution (Time: O(N^2) Space: O(N))
/*
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        vector<int> cout(nums.size(), 1);

        int maxlen = 1;
        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j]<nums[i]) {
                    cout[i] = max(cout[i], cout[j]+1);
                    maxlen = max(maxlen, cout[i]);
                }
            }
        }
        return maxlen;
    }
};
*/

// 2nd solution (Time: O(N*logN), Space:O(N))
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for (int a : nums)
            if (ans.size() == 0 || a > ans.back()) ans.push_back(a);
            else *lower_bound(ans.begin(), ans.end(), a) = a;
        return ans.size();
    }
};

// 3rd solution(Time: O(N*logN), Space:O(N))
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> ends{nums[0]};
        for (int num : nums) {
            if (num > ends.back()) ends.push_back(num);
            else {
                // 手动实现lower_bound
                int l = 0, r = ends.size() - 1;
                while (l < r) {
                    // int m = l + (r - l) / 2; or
                    int m = (l+r)/2;
                    if (ends[m] < num) l = m + 1;
                    else r = m;
                }
                ends[r] = num;
            }
        }
        return ends.size();
    }
};


/**
 * 1st solution
 * http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
 *
 * 3rd solution
 * https://leetcode.com/discuss/67533/c-typical-dp-2-solution-and-nlogn-solution-from-geekforgeek
 */
