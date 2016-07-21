/**
* @Author: Tian Qiao
* @Date:   2016-07-22T00:48:30+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-22T00:48:58+08:00
* @Inc: Unkown
* @Difficulty: Hard
*/

/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
*图略*
Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
The largest rectangle is shown in the shaded area, which has area = 10 unit.
*图略*
For example,
Given heights = [2,1,5,6,2,3],
return 10.
*/

// 超时
// 维护一个单调递增的栈
/*
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        if(heights.empty()) return ans;
        vector<pair<int, int>> dict; // value to its index;
        for(int i=0; i<n; i++) {
            while(!dict.empty() && heights[i] < dict.back().first) {
                dict.pop_back();
            }
            dict.push_back({heights[i], i});
            ans = max(heights[i], ans);
            for(int i=0; i<dict.size(); i++) {
                if(i==0) ans = max(ans, dict[i].first*(dict.back().second-dict[0].second+1));
                else ans = max(ans, dict[i].first*(dict.back().second-dict[i-1].second));
            }
            ans = max(ans, (i+1)*dict[0].first);
        }
        return ans;
    }
};*/
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int ret = 0;
        height.push_back(0);
        vector<int> index;

        for(int i = 0; i < height.size(); i++) {
            while(index.size() > 0 && height[index.back()] >= height[i]) {
                int h = height[index.back()];
                index.pop_back();

                int start = index.size()>0?index.back():-1;
                ret = max(ret, h*(i-start-1));
            }
            index.push_back(i);
        }
        return ret;
    }
};
