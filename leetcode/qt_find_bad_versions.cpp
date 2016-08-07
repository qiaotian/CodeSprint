/**
* @Author: Tian Qiao
* @Date:   2016-08-07T23:52:26+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-07T23:52:27+08:00
* @Tag: Binary Search
*/



/*
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
*/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n, mid;
        while(left<right) {
            mid = (int)(((long)left+(long)right)/2);
            if(isBadVersion(mid)) right = mid;
            else left = mid+1;
        }
        return left;
    }
};

/***
 * Pay attention to the range integer could represent, which
 * means (left+right) could be out of range of int
 * /
