// 求交集
// 12ms for 60 tests
// O(M*logM + N*logN + M + N)
// 这道题没有足够提交，无法比较
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> temp;
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i=0, j=0;
        while(i<nums1.size() && j<nums2.size()) {
            if(nums1[i] < nums2[j]) {
                i++;
            } else if(nums1[i] > nums2[j]) {
                j++;
            } else {
                temp.insert(nums1[i]);
                i++;
                j++;
            }
        }

        for(auto i:temp) ans.push_back(i);

        return ans;
    }
};
