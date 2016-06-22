/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-06-22T22:00:09+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-06-23T01:01:36+08:00
* @License: Free License
*/


/* Problem:
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
Try to solve it in linear time/space.
Return 0 if the array contains less than 2 elements.
You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/

/* Solution:
Suppose there are N elements in the array, the min value is min and the max value is max. Then the maximum gap will be no smaller than ceiling[(max - min ) / (N - 1)].

Let gap = ceiling[(max - min ) / (N - 1)]. We divide all numbers in the array into n-1 buckets, where k-th bucket contains all numbers in [min + (k-1)gap, min + k*gap). Since there are n-2 numbers that are not equal ***min*** or ***max*** and there are n-1 buckets, at least one of the buckets are empty. We only need to store the largest number and the smallest number in each bucket.

After we put all the numbers into the buckets. We can scan the buckets sequentially and get the max gap.
*/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int ans = INT32_MIN;

        if(nums.size()<2) return 0;

        // find the min and max value of nums
        int minValue = INT32_MAX;
        int maxValue = INT32_MIN;
        for(auto i:nums) {
            minValue = min(minValue, i);
            maxValue = max(maxValue, i);
        }

        // find the gap value
        int gap = ceil((double)(maxValue-minValue)/(nums.size()-1));
        if(gap==0) return 0;
        // int gap = (maxValue-minValue)/(nums.size()-1)+1;

        // define a bucket to store all data
        vector<vector<int>> bucket(nums.size());

        // defien the min and max values for each bucket cell
        vector<pair<int, int>> minmax(nums.size(),\
              {INT32_MAX, INT32_MIN});

        // fill the bucket according to nums
        for(auto i:nums) {
            int index = (i-minValue)/gap;
            bucket[index].push_back(i);
            minmax[index].first = min(minmax[index].first, i);
            minmax[index].second = max(minmax[index].second, i);
        }

        //
        int pre = 0, tail = 0;
        for(int i=1; i<bucket.size(); i++) {
            if(!bucket[i].empty() && pre==i-1) pre = i;
            if(bucket[i-1].empty() && !bucket[i].empty()) {
                tail = i;
                ans = max(ans, minmax[tail].first-minmax[pre].second);
                pre = tail;
            }
        }
        // 如果没有一个cell为空，也就是所有元素等距，均落在每个cell的下边界处，
        // eg [1, 10000000]，两个cell，分别包含1和10000000
        if(ans == INT32_MIN) return gap;

        return ans;
    }
};

// jianchao.li.fighter's solution
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        auto lu = minmax_element(nums.begin(), nums.end()); // good choice
        int l = *lu.first, u = *lu.second;
        int gap = max((u - l) / (n - 1), 1);
        int m = (u - l) / gap + 1;
        vector<vector<int>> buckets(m, {INT_MAX, INT_MIN}); // 根据min和max来判定是否为空
        for (int num : nums) {
            int k = (num - l) / gap;
            if (num < buckets[k][0]) buckets[k][0] = num;
            if (num > buckets[k][1]) buckets[k][1] = num;
        }
        int i = 0, j;
        gap = buckets[0][1] - buckets[0][0];
        while (i < m) {
            j = i + 1;
            while (j < m && buckets[j][0] == INT_MAX && buckets[j][1] == INT_MIN)
                j++;
            if (j == m) break;
            gap = max(gap, buckets[j][0] - buckets[i][1]);
            i = j;
        }
        return gap;
    }
};
