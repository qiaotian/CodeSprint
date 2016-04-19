class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int count1=0, count2=0, candidate1=0, candidate2=1;
        for(auto i:nums) {
            if(i == candidate1) count1++;
            else if(i == candidate2) count2++;
            else if(count1 == 0) {candidate1 = i; count1 = 1;}
            else if(count2 == 0) {candidate2 = i; count2 = 1;}
            else {
                count1--;
                count2--;
            }
        }

        count1 = count2 = 0;
        for(auto i:nums) {
            if(candidate1 == i) count1++;
            else if(candidate2 == i) count2++;
        }

        if(count1 > nums.size()/3) res.push_back(candidate1);
        if(count2 > nums.size()/3) res.push_back(candidate2);

        return res;
    }
};
