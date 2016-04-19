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

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int n : nums)
            if (i < 2 || n > nums[i-2])
                nums[i++] = n;
        return i;
    }
};
