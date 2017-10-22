/*

Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
// int[] nums = {1,2,3};
// Solution solution = new Solution(nums);
//
// // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
// solution.shuffle();
//
// // Resets the array back to its original configuration [1,2,3].
// solution.reset();
//
// // Returns the random shuffling of array [1,2,3].
// solution.shuffle();))))
//
*/

// 本题的测试案例要求相同的操作序列得到相同的结果，
// 因此无需srand(time(0))
class Solution {
private:
    vector<int> bkp;
    vector<int> ans;
public:
    Solution(vector<int> nums) {
        bkp = nums;
        ans = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        ans = bkp;
        return ans;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        // 1st solution: build-in function
        // random_shuffle(ans.begin(), ans.end());
        
        // 2nd solution: fisher-yates shuffle
        ans = reset();
        for(int i=ans.size()-1; i>0; i--) {
            //srand(time(0)); ////use current time as seed for random generator, should include <ctime> <cstdlib>
            int rd = rand();
            swap(ans[i], ans[rd%(i+1)]);
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
