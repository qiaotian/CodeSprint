/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int start = 0, end = 0;
        //if(nums.size()==0) return res; it's redundant for this line

        for(int i=0; i<nums.size(); i++) {
            if(i==nums.size()-1) {
                res.push_back(start==end?to_string(nums[start]):(to_string(nums[start])+"->"+to_string(nums[end])));
                continue;
            }

            if(nums[i]==nums[i+1]-1) end++;
            else {
                res.push_back(start==end?to_string(nums[start]):(to_string(nums[start])+"->"+to_string(nums[end])));
                start = i+1;
                end = i+1;
            }
        }
        return res;
    }
};
