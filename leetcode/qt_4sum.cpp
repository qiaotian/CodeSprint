// 1st solution (136ms, beats 20%, bad)
/*
class Solution {
    vector<vector<int>> res;
    void threeSum(vector<int>& nums, vector<int>& mediate, int pos, int target) {
        for(int i = pos; i < nums.size()-2; ) {
            mediate.push_back(nums[i]);
            // two sum
            int l = i+1, r = nums.size()-1;
            while(l < r) {
                if(nums[l] + nums[r] == target-nums[i]) {
                    mediate.push_back(nums[l]);
                    mediate.push_back(nums[r]);
                    res.push_back(mediate);
                    mediate.pop_back();
                    mediate.pop_back();
                    int tmp = nums[l++];
                    while(nums[l] == tmp && l < r) l++;
                } else if(nums[l] + nums[r] < target-nums[i]) {
                    l++;
                    // 去重
                } else {
                    r--;
                    // 去重
                }
            }
            mediate.pop_back();
            // 去重
            i++;
            while(i < nums.size()-2 && nums[i] == nums[i-1]) i++;
        }
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) return res;
        
        sort(nums.begin(), nums.end());
        
        vector<int> mediate;
        for(int i = 0; i < nums.size()-3;) {
            mediate.push_back(nums[i]);
            threeSum(nums, mediate, i+1, target-nums[i]);
            mediate.pop_back();
            i++;
            while(i < nums.size()-3 && nums[i] == nums[i-1]) i++;
        }
        return res;
    }
};
*/

// 2nd solution(20ms, beats 87%)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n < 4) return res;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n-3; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target) break;
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
            
            for(int j = i+1; j < n-2; j++) {
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[i+1]+nums[i+2]>target) break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
                
                int l = j+1, r = n-1;
                while(l < r) {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if(sum == target) {
                        res.push_back(vector<int>{nums[i], nums[j], nums[l], nums[r]});
                        while(++l>j+1 && l < r && nums[l]==nums[l-1]);
                        while(--r<n-1 && l < r && nums[r]==nums[r+1]);
                    } else if(sum < target) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }
        return res;
    }
};
