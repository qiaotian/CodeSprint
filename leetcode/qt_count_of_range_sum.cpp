/**
* @Author: Tian Qiao
* @Date:   2016-07-27T13:54:08+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-03T15:36:21+08:00
* @Inc: Google
* @Difficulty: Hard
* @Tag: Divide Conquer and Binary Search Tree
*/

/*
Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

Note:
A naive algorithm of O(n2) is trivial. You MUST do better than that.

Example:
Given nums = [-2, 5, -1], lower = -2, upper = 2,
Return 3.
The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.
*/


// Kadane Algo
/*
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int cnt = 0, cursum = 0;
        int le = 0, ri = 0;
        set<int> s; // 错误，不能去重

        for(int i=0; i<nums.size(); i++) {
            cout << i << endl;
            cursum+=nums[i];
            if(cursum<=upper && cursum>=lower) cnt++;

            auto liter = lower_bound(s.begin(), s.end(), cursum-upper);
            auto riter = upper_bound(s.begin(), s.end(), cursum-lower);

            if(liter==s.end() && riter==s.end()) {
                s.insert(cursum);
                continue;
            }
            else if(liter!=s.end()) {
                le = distance(liter, s.begin());
                ri = s.size()-1;
            }
            else if(riter!=s.end()) {
                //该情况不存在
                s.insert(cursum);
                continue;
            }
            else {
                le = distance(liter, s.begin());
                ri = distance(riter, s.begin());
            }

            cnt += (ri-le);

            s.insert(cursum);
        }

        return cnt;
    }
};*/

// Kadane Algorithm(sum is not more than lower and upper)
// O(N^2) beats 20%
// 缺点：使用STL中set或者multiset(红黑树)，不能用O(1)的时间计算两个iterator的距离
// 解决方案只能是自建BST
// 计算前i个数的和，同时维护前0,1,2...i-1个元素的和所组成的有序集合
// The basic idea is to use a multiset to save sum, where sum at i = nums[0]+...+ nums[i]. At each i, only those sum[j] that satisfies lower=< sum[i]-sum[j]<= upper can generate a valid range[j,i]. so we only need to calculate how many j (0=< j< i) satisfy sum[i]-upper=< sum[j]<=-sum[i]-lower. The STL multiset can take care of sort and find upper_bound, lower_bound j. Since the multiset is usually implemented with Red-black tree, so those operations should have complexity of O(logN). So in total, the complexity is O(NlogN) (except the distance part). At least it looks neat
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int res = 0;
        long long sum=0;

        multiset<long long> pSum;
        pSum.insert(0); // add a dummy sum element
        for(int i=0; i<nums.size(); ++i) {
            sum +=nums[i];
            // distance is a linear function, whose time complexity is O(N).
            res += std::distance(pSum.lower_bound(sum-upper), pSum.upper_bound(sum-lower));
            pSum.insert(sum);
        }
        return res;
    }
};


// MergerSort (Divide and Conquer)
// O(N*logN) beat 91%
class Solution {
private:
    int mergeSort(vector<long long>&sum, int left, int right, int lower, int upper)
    {
        int mid, i, res, j, k;
        if(left>right) return 0;
        if(left==right) return ( (sum[left]>=lower) && (sum[left]<=upper) )?1:0;
        else
        {
            vector<long long> temp(right-left+1,0);
            mid = (left+right)/2;
            // merge sort two halfs first, be careful about how to divide [left, mid] and [mid+1, right]
            res = mergeSort(sum, left,mid, lower, upper) + mergeSort(sum, mid+1,right, lower, upper);
            for(i=left, j=k=mid+1; i<=mid; ++i) {
                // count the valid ranges [i,j], where i is in the first half and j is in the second half
                while(j<=right && sum[j]-sum[i]<lower)  ++j;
                while(k<=right && sum[k]-sum[i]<=upper) ++k;
                res +=k-j;
            }
            for(i=k=left, j=mid+1; k<=right; ++k) //merge the sorted two halfs
                temp[k-left] = (i<=mid) && (j>right || sum[i]<sum[j])?sum[i++]:sum[j++];
            for(k=left; k<=right; ++k) // copy the sorted results back to sum
                sum[k] = temp[k-left];
            return res;
        }
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
         int len = nums.size();
         vector<long long> sum(len+1, 0);
         for(int i=1; i<=len; ++i) sum[i] = sum[i-1]+nums[i-1];
         return mergeSort(sum, 1, len, lower, upper);
    }
};
