/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-06-29T23:47:32+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-06-30T00:47:27+08:00
* @License: Free License
*/



/*
Assume you have an array of length n initialized with all 0's and are given k update operations.
Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.
Return the modified array after all k operations were executed.

Example:
Given:
    length = 5,
    updates = [
        [1,  3,  2],
        [2,  4,  3],
        [0,  2, -2]
    ]

Output:
    [-2, 0, 3, 5, 3]

Explanation:
Initial state:
[ 0, 0, 0, 0, 0 ]
After applying operation [1, 3, 2]:
[ 0, 2, 2, 2, 0 ]
After applying operation [2, 4, 3]:
[ 0, 2, 5, 5, 3 ]
After applying operation [0, 2, -2]:
[-2, 0, 3, 5, 3 ]
*/

The traditional method is TLE

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> mask(length+1, 0); // 放止 i[1]+1越界
        vector<int> ans(length, 0);
        for(auto i:updates) {
            mask[i[0]] += i[2];
            mask[i[1]+1] -= i[2]; // i[1]+1可能越界
        }
        vector<int> ans;
        int sum = 0;
        for(int i=0; i<length; i++) {
            sum += mask[i];
            ans[i] = sum;
        }
        return ans;
    }
};
