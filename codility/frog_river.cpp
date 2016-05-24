class Solution {
public:
    int solution(vector<int> nums, int x) {
        int uncovered = x;
        vector<bool> flags(x, false);
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<0 || nums[i]>x) return -1; //exception
            if(!flags[x]) {
                uncovered--;
                flags[x] = true;
            }
            if(uncovered==0) return i;
        }
        return -1;
    }
}
