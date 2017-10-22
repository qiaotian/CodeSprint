/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        if(nums1.empty() || nums2.empty()) return ans;
        if(nums1.size() < nums2.size()) swap(nums1, nums2);
        
        unordered_map<int, int> hash1;
        unordered_map<int, int> hash2;
        for(auto i:nums1) {
            if(hash1.find(i)==hash1.end()) hash1[i]=1;
            else hash1[i]++;
        }
        for(auto i:nums2) {
            if(hash2.find(i)==hash2.end()) hash2[i]=1;
            else hash2[i]++;
        }
        
        for(auto i:hash2) {
            auto j = hash1.find(i.first);
            if(j != hash1.end()) {
                for(int k=0; k<i.second && k<j->second; k++) ans.push_back(i.first);
            }
        }
        return ans;
    }
};
