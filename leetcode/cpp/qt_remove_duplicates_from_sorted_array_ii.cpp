/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 3) return nums.size(); 
        int triple = 1;
        int res = 1;
        for(auto it = nums.begin()+1; it != nums.end();) {
            if(*it == *(it-1)) triple++;
            else triple = 1;
            
            if(triple >= 3) {
                nums.erase(it);
                triple = 2;
                continue;
            } 
            res++;  
            it++;
        }
        return res;
    }
};
