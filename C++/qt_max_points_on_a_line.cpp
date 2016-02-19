/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
    unordered_map<double, int> slope2count; // map a line to the amount of points on it
public:
    int maxPoints(vector<Point>& points) {
        if(points.size() < 3) return points.size();
        
        int maxlen = 0;
        for(int i = 0; i < points.size(); i++) {
            int duplicated = 1; // the number of points with the same positions of point i
            slope2count.clear();
            for(int j = i+1; j < points.size(); j++) {
                if(points[i].x == points[j].x && points[i].y == points[j].y) { 
                    duplicated++;
                    continue;
                }
                double slope = (points[i].x == points[j].x) ? INT32_MAX : 
                               (double)(points[i].y - points[j].y)/(points[i].x - points[j].x); // must transit to double
                slope2count[slope]++;
            }
            maxlen = max(maxlen, duplicated);
            for(auto slope:slope2count) {
                if(slope.second + duplicated > maxlen) maxlen = slope.second + duplicated;
            }
        }
        return maxlen;
    }
};

/**
 * This problem has a naive idea, which is to traverse all possible pairs of two points 
 * and see how many other points fall in the line determined by them. 
 * This idea is of O(n^3) time complexity and will meet TLE.
 * 
 * Well, let's focus on lines instead of pairs of points. 
 * Could we just find out how many points fall in all possible lines? 
 * The answer is yes. 
 * Remember that a line is determined by its slope and intercept. 
 * In fact, if two lines with the same slope share a common point, 
 * then they are just the same line. So to determine a line, we need its slope and a point.
 * 
 * Now comes the idea to solve this problem. 
 * We start from a specific point p, and compute all the slopes of the lines between p and the remaining points. 
 * Then those with the same slopes will be the same line.
 * We can find out the maximum number of points fall on a line containing p. 
 * We exhaust all possible p's and record the largest number we have seen. This number is just answer.
 * 
 * WARNING
 * 1. pay attention to the duplicated element
 * 2. (double)(int/int) is not equal to (double)(int)/int
 * 
 * REFERENCE
 * https://leetcode.com/discuss/45105/16ms-28ms-c-solutions-with-explanations
 * 
 * /
