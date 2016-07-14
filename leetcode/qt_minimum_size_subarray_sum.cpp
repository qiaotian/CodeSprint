/**
* @Author: Tian Qiao
* @Date:   2016-07-13T17:54:56+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-13T17:55:37+08:00
* @Inc: Facebook
* @Difficulty: Medium
*/

/*
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

More practice:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
*/

2974,1094,6733,5177,4975,5421,8190,8255,9112,8651,2797,335,8677,3754,893,1818,8479,5875,1695,8295,7993,7037,8546,7906,4102,7279,1407,2462,4425,2148,2925,3903,5447,5893,3534,3663,8307,8679,8474,1202,3474,2961,1149,7451,4279,7875,5692,6186,8109,7763,7798,2250,2969,7974,9781,7741,4914,5446,1861,8914,2544,5683,8952,6745,4870,1848,7887,6448,7873,128,3281,794,1965,7036,8094,1211,9450,6981,4244,2418,8610,8681,2402,2904,7712,3252,5029,3004,5526,6965,8866,2764,600,631,9075,2631,3411,2737,2328,652,494,6556,9391,4517,8934,8892,4561,9331,1386,4636,9627,5435,9272,110,413,9706,5470,5008,1706,7045,9648,7505,6968,7509,3120,7869,6776,6434,7994,5441

2974,1094,6733,5177,4975,5421,8190,8255,9112,8651,2797,335,8677,3754,893,1818,8479,5875,1695,8295,7993,7037,8546,7906,4102,7279,1407,2462,4425,2148,2925,3903,5447,5893,3534,3663,8307,8679,8679,8474,1202,3474,2961,1149,7451,4279,7875,5692,6186,8109,7763,7798,2250,2969,7974,9781,7741,4914,5446,1861,8914,2544,5683,8952,6745,4870,1848,7887,6448,7873,128,3281,794,1965,7036,8094,1211,9450,6981,4244,2418,8610,8681,2402,2904,7712,3252,5029,3004,5526,6965,8866,2764,600,631,9075,2631,3411,2737,2328,652,494,6556,9391,4517,8934,8892,4561,9331,1386,4636,9627,5435,9272,110,413,9706,5470,5008,1706,7045,9648,7505,6968,7509,3120,7869,6776,6434,7994,5441

// beats 0.8%
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return 0;

        int ans = nums.size(), sum = 0, i = 0;
        deque<int> dq;

        while(i<nums.size()) {
            sum += nums[i];
            dq.push_back(nums[i]);
            if(sum >= s) break;
            i++;
        }

        if(sum<s && dq.size()==nums.size()) return 0;

        while(sum-dq.front()>=s) {
            sum-=dq.front();
            dq.pop_front();
            ans = dq.size();
        }

        cout << sum << endl;
        cout << i << endl;
        cout << dq.size() << endl;

        // if(i>=nums.size()) return dq.size()
        // 上面存在出队过程，所以dq的大小不是下一个未访问节点的下标
        // 所以下一行 i=dq.size() 初始化错误
        ans = min(ans, (int)dq.size());
        for(/*i=dq.size()*/ i=i+1; i<nums.size(); i++) {
            dq.push_back(nums[i]);
            sum += (nums[i]-dq.front());
            dq.pop_front();

            cout << i << endl;
            cout << dq.size() << endl;

            while(sum-dq.front()>=s) {
                sum-=dq.front();
                dq.pop_front();
                ans = min(ans, (int)dq.size());
            }
        }
        return ans;
    }
};

// O(N)
/*
The problem statement has stated that there are both O(n) and O(nlogn) solutions to this problem. Let's see the O(n) solution first (taken from this link), which is pretty clever and short.
*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(), start = 0, sum = 0, minlen = INT_MAX;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            while (sum >= s) {
                minlen = min(minlen, i - start + 1);
                sum -= nums[start++];
            }
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};

// O(N)
/*
Well, you may wonder how can it be O(n) since it contains an inner while loop. Well, the key is that the while loop executes at most once for each starting position start. Then start is increased by 1 and the while loop moves to the next element. Thus the inner while loop runs at most O(n) times during the whole for loop from 0 to n - 1. Thus both the for loop and while loop has O(n) time complexity in total and the overall running time is O(n).

There is another O(n) solution in this link, which is easier to understand and prove it is O(n). I have rewritten it below.
*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0, sum = 0, minlen = INT_MAX;
        while (right < n) {
            do sum += nums[right++];
            while (right < n && sum < s);
            while (left < right && sum - nums[left] >= s)
                sum -= nums[left++];
            if (sum >= s) minlen = min(minlen, right - left);
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};

// O(N*logN)
/*
Now let's move on to the O(nlogn) solution. Well, this less efficient solution is far more difficult to come up with. The idea is to first maintain an array of accumulated summations of elements in nums. Specifically, for nums = [2, 3, 1, 2, 4, 3] in the problem statement, sums = [0, 2, 5, 6, 8, 12, 15]. Then for each element in sums, if it is not less than s, we search for the first element that is greater than sums[i] - s (in fact, this is just what the upper_bound function does) in sums using binary search.

Let's do an example. Suppose we reach 12 in sums, which is greater than s = 7. We then search for the first element in sums that is greater than sums[i] - s = 12 - 7 = 5 and we find 6. Then we know that the elements in nums that correspond to 6, 8, 12 sum to a number 12 - 5 = 7 which is not less than s = 7. Let's check for that: 6 in sums corresponds to 1 in nums, 8 in sums corresponds to 2 in nums, 12 in sums corresponds to 4 in nums. 1, 2, 4 sum to 7, which is 12 in sums minus 5 in sums.

We add a 0 in the first position of sums to account for cases like nums = [3], s = 3.

The code is as follows.
*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        vector<int> sums = accumulate(nums);
        int n = nums.size(), minlen = INT_MAX;
        for (int i = 1; i <= n; i++) {
            if (sums[i] >= s) {
                int p = upper_bound(sums, 0, i, sums[i] - s);
                if (p != -1) minlen = min(minlen, i - p + 1);
            }
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
private:
    vector<int> accumulate(vector<int>& nums) {
        int n = nums.size();
        vector<int> sums(n + 1, 0);
        for (int i = 1; i <= n; i++)
            sums[i] = nums[i - 1] + sums[i - 1];
        return sums;
    }
    int upper_bound(vector<int>& sums, int left, int right, int target) {
        int l = left, r = right;
        while (l < r) {
            int m = l + ((r - l) >> 1);
            if (sums[m] <= target) l = m + 1;
            else r = m;
        }
        return sums[r] > target ? r : -1;
    }
};
