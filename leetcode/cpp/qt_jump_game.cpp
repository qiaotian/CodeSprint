class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        int first = n-2;
        while(first >= 0) {
            //找到非末位的第一个0节点
            while(nums[first] != 0 && first >= 0) {
                first--;
            }
            if(first < 0) return true; //全部非0，那么返回true
            //找到可以跳过第一个0的节点
            int second = first-1;
            while(nums[second] < first - second + 1 && second >= 0) {
                second--;
            }
            if(second < 0) return false;
            first = second;
        }
        return false;
    }
};

/**
 * 从后往前遍历，发现0，则需要找到能够跳过该0的数字
 * 5--1--0--4：要跳过0，则0左边的数字从右向左依次至少为2，3
 * 我们发现1 < 2不满足, 5 > 3满足条件，所以5的存在使得可以跳过0
 */
