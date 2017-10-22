// 1st solution (O(N*logN): 48ms, beats 30%)
/*
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> window;
        for(int i = 0; i < nums.size(); i++) {
            if(i > k) window.erase(nums[i-k-1]);
            auto index = window.lower_bound(nums[i]-t); // Time:(logN)
            if(index != window.end() && *index - nums[i] <= t) return true;
            window.insert(nums[i]);
        }
        return false;
    }
};
*/

// 2nd solution (16ms, beats 95%)
bool cmpptr(int *a, int *b){
    return *a < *b; 
}
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        const int N = nums.size();
        vector<int*> numptrs(N);
        for(int i = 0; i < N; ++i){
             numptrs[i] = &nums[i];
        }
        sort(numptrs.begin(), numptrs.end(), cmpptr);
        if(0 == k) return false;
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
               //nums[i] and nums[j] is at most t
                if((*numptrs[j]) > (*numptrs[i]) + t) break;
               //the difference between i and j is at most k
               if(abs(numptrs[j] - numptrs[i]) <= k) return true;
            }
        }
        return false;
    }
};