/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-06-21T15:24:03+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-06-21T16:38:31+08:00
* @License: Free License
*/

/**
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
The largest rectangle is shown in the shaded area, which has area = 10 unit.

@Example
Given height = [2,1,5,6,2,3],
return 10.
*/

/**
* Time Complecxity: O(N^2)
* Calculate the correspondent width for every height
*/
class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        // write your code here
        int ans = 0;
        vector<int> width(height.size(), 1);
        for(int i=0; i<height.size();i++) {
            for(int fly=i-1; fly>=0 && height[fly]>=height[i]; fly--) {
                if(height[fly]>=height[i])
                    width[i]++;
                else
                    break;
            }
            for(int fly=i+1; fly<height.size(); fly++) {
                if(height[fly]>=height[i])
                    width[i]++;
                else
                    break;
            }
        }
        for(int i=0; i<height.size(); i++) {
            ans = max(ans, height[i]*width[i]);
        }
        return ans;
    }
};

// O(N^2)
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Create an empty stack. The stack holds indexes of hist[] array
        // The bars stored in stack are always in increasing order of their
        // heights.
        stack<int> s;

        int max_area = 0; // Initalize max area
        int cur_area = 0; // To store area with top bar as the "smallest" bar

        // Run through all bars of given histogram
        int i = 0;
        while (i < n) {
            // If this bar is higher than the bar on top stack, push it to stack
            if (s.empty() || hist[s.top()] <= hist[i]) {
                s.push(i++);
            } else {
                // If this bar is lower than top of stack, then calculate area of rectangle
                // with stack top as the smallest (or minimum height) bar. 'i' is
                // 'right index' for the top and element before top in stack is 'left index'
                int tp = s.top();  // store the top index
                s.pop(); // pop the top

                // Calculate the area with hist[tp] stack as smallest bar
                cur_area = hist[tp] * (s.empty() ? i : i - s.top() - 1);

                // update max area, if needed
                max_area = max(max_area, cur_area);
            }
        }

        // Now pop the remaining bars from stack and calculate area with every
        // popped bar as the smallest bar
        while (s.empty() == false) {
            int tp = s.top();
            s.pop();
            cur_area = hist[tp] * (s.empty() ? i : i - s.top() - 1);
            max_area = max(max_area, cur_area);

        }
        return max_area;
    }
};
