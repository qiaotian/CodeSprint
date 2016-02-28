// 1st solution TLE
/*
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(i > 0 && height[i-1] >= height[i]) continue;
            for(int j = n-1; j > i; j--) {
                if(j < n-1 && height[j] <= height[j+1]) continue;
                res = max(res, min(height[i], height[j]) * (j-i));
            }
        }
        return res;
    }
};
*/

// 2nd solution
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int res = 0, i = 0, j = n-1;
        while(i < j) {
            res = max(res, min(height[i], height[j])*(j-i));
            if(height[i] < height[j]) i++;
            else j--;
        }
        return res;
    }
};
/**
 * 1st solution
 * min(ai, aj)*abs(aj-ai)
 * 
 * 2nd solution
 * https://leetcode.com/discuss/11482/yet-another-way-to-see-what-happens-in-the-o-n-algorithm
 * https://leetcode.com/discuss/14610/very-simple-o-n-solution
 * /
