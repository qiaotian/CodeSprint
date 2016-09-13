/*
Given an array of integers with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.

Note:
The array size can be very large. Solution that uses too much extra space will not pass the judge.

Example:

int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
solution.pick(3);

// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(1);
*/


// 我的方法是将数组看作是一个循环数组,
// 在数组中随机选择一个位置作为起始搜索
// 位置，从该点出发找到的第一个target的
// 位置作为最终结果返回
// 但结果显示错误，Why?
class Solution {
private:
    vector<int> cp;
public:
    Solution(vector<int> nums) {
        //dict.resize(10, vector<int>(0));
        //for(int i=0; i<nums.size(); i++) 
        //    dict[nums[i]].push_back(i);
        cp = nums;
        srand(time(NULL));
        //cout << cp.size() << endl;
    }
    
    int pick(int target) {
        //int rd = rand()%dict[target].size();
        //return dict[target][rd];
        int start = rand()%(cp.size());
        //cout << start << endl;
        //cout << cp.size() << endl;
        for(int i=start; i<start+cp.size(); i++) {
            if(cp[i%cp.size()]==target) return i%cp.size();
        }
        return 0;
    }
};

// 网友解法，类似，但是结果验证正确
// https://discuss.leetcode.com/topic/58474/c-most-obvious-solution/2
class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
        srand(time(NULL));
    }
    
    int pick(int target) {
        while(true) {
            int i = rand() % nums.size();
            if(nums[i] == target) return i;
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
