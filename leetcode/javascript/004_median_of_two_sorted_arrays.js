/***
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
***/

/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    var m = num1.length;
    var n = num2.length;

    if (m > n) return findMedianSortedArrays(nums2, nums1);

    var i, j;
    var imin = 0, imax = m;

    int num1, num2 = 0;
    while(imin <= imax) {
        i = (imin + imax) / 2;
        j = (m + n + 1) / 2 - i; // i + j = ( m + n + 1 ) / 2
        
        if (i > 0 && j < n && nums1[i - 1] > nums2[j]) imax = i - 1; // i is too big, must decrease it
        else if (j > 0 && i < m && nums2[j - 1] > nums1[i]) imin = i + 1; // i is too small, must increase it
        else break; // i is perfeat
    }
};
