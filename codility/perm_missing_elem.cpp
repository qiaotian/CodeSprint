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
