/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/


/*class NumArray {
    vector<int> localnums;
public:
    NumArray(vector<int> &nums) {
        vector<int>::iterator iter;
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0) {localnums.push_back(nums[0]); continue;}
            int tmp = localnums[i-1] + nums[i];
            localnums.push_back(tmp);
        }
    }

    int sumRange(int i, int j) {
        if(i==0) return localnums[j];
        return localnums[j]-localnums[i-1];
    }
};*/

/*
class NumArray {
public:
    NumArray(vector<int> &nums) {
        accu.push_back(0);
        for (int num : nums)
            accu.push_back(accu.back() + num);
    }

    int sumRange(int i, int j) {
        return accu[j + 1] - accu[i];
    }
private:
    vector<int> accu;
};
*/

// 3rd Solution
class NumArray {
public:
    NumArray(vector<int> &nums) : psum(nums.size()+1, 0) {
        partial_sum( nums.begin(), nums.end(), psum.begin()+1); //
    }

    int sumRange(int i, int j) {
        return psum[j+1] - psum[i];
    }
private:
    vector<int> psum;    
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

/****
 * 1st Solution
 *   beats 10%
 * 2nd Solution
 *   beats 11%
 * 3rd Solution
 *   beats 82%
 * /
