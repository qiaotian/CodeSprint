// ! This solution will result in overflow
class Solution {
public:
    int solution(vector<int> nums) {
        int n = nums.size();
        long long target = (1+n+1)*(n+1)/2;
        long long sum = 0;
        for(auto num:nums) {
            sum+=num;
        }
        return (int)(target-sum);
    }
};

//
class Solution {
public:
    int solution(vector<int> nums) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            ans = ans ^ nums[i] ^ (i+1);
        }
        return ans^(nums.size()+1);
    }
}
