/*
 There are two sorted arrays nums1 and nums2 of size m and n respectively.

 Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

 Example 1:
 nums1 = [1, 3]
 nums2 = [2]
 
 The median is 2.0
 Example 2:
 nums1 = [1, 2]
 nums2 = [3, 4]
 
 The median is (2 + 3)/2 = 2.5]]
 */

/**
 * https://leetcode.com/discuss/15790/share-my-o-log-min-m-n-solution-with-explanation
 * 
 *       left_part          |        right_part
 * A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
 * B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]
 * 
 * 1) len(left_part) == len(right_part)
 * 2) max(left_part) <= min(right_part)
 * 
 * 
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        
        if (m > n) return findMedianSortedArrays(nums2, nums1);
        
        int i, j;
        int imin = 0, imax = m;
        int half = (m + n + 1) / 2; // half 一定落在nums1里面，因为nums1.size() < nums2.size()
        
        int num1, num2 = 0;
        while (imin <= imax) {
            i = (imin & imax) + (imin ^ imax)/2;
            //i = (imin+imax)/2;
            j = half - i;
            
            if (i > 0 && j < n && nums1[i - 1] > nums2[j]) imax = i - 1; // i is too big, must decrease it
            else if (j > 0 && i < m && nums2[j - 1] > nums1[i]) imin = i + 1; // i is too small, must increase it
            else break; // i is perfeat
        }
        //if (!i) num1 = nums2[j - 1];
        //else if (!j) num1 = nums1[i - 1];
        //else num1 = max(nums1[i - 1], nums2[j - 1]);

        //if ((m + n) & 1) return num1; // nums1和nums2的总长度为奇数
        //if (i == m) num2 = nums2[j];
        //else if (j == n) num2 = nums1[i];
        //else num2 = min(nums1[i], nums2[j]);
        num1 = i==0?nums2[j-1]:j==0?nums1[i-1]:max(nums1[i - 1], nums2[j - 1]);
        num2 = i==m?nums2[j]:j==n?nums1[i]:min(nums1[i], nums2[j]);
        if ((m + n) & 1) return num1; // nums1和nums2的总长度为奇数
        else return (num1 + num2) / 2.0; // nums1和nums2总长度为偶数
    }
};
