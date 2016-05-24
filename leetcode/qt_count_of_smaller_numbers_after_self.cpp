// 1st solution (TLE)
/*
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> count(nums.size(), 0);
        int n = nums.size();
        for(int i = n-1; i >= 0; i--) {
            for(int j = i+1; j < n; j++) {
                if(nums[i] > nums[j]) {
                    count[i]++;
                }
            }
        }
        return count;
    }
};
*/

// 2nd solution
class Solution {
protected:
    void merge_countSmaller(vector<int>& indices, int first, int last, 
                            vector<int>& results, vector<int>& nums) {
        int count = last - first;
        if (count > 1) {
            int step = count / 2;
            int mid = first + step;
            merge_countSmaller(indices, first, mid, results, nums);
            merge_countSmaller(indices, mid, last, results, nums);
            vector<int> tmp;
            tmp.reserve(count);
            int idx1 = first;
            int idx2 = mid;
            int semicount = 0;
            while ((idx1 < mid) || (idx2 < last)) {
                if ((idx2 == last) || ((idx1 < mid) &&
                       (nums[indices[idx1]] <= nums[indices[idx2]]))) {
                    tmp.push_back(indices[idx1]);
                    results[indices[idx1]] += semicount;
                    ++idx1;
                } else {
                    tmp.push_back(indices[idx2]);
                    ++semicount;
                    ++idx2;
                }
            }
            move(tmp.begin(), tmp.end(), indices.begin()+first);
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> results(n, 0);
        vector<int> indices(n, 0);
        iota(indices.begin(), indices.end(), 0);
        merge_countSmaller(indices, 0, n, results, nums);
        return results;
    }
};

/**
 * REFERENCE
 * https://leetcode.com/discuss/73509/nlogn-time-space-mergesort-solution-with-detail-explanation
 * 
 * /
