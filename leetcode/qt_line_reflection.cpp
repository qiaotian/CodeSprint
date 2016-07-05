/**
* @Author: Tian Qiao
* @Date:   2016-07-05T14:17:59+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-05T14:32:38+08:00
* @Inc: Google
* @Difficulty: Medium
*/

_______________________________________________________________________________
Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points.

Example 1:
Given points = [[1,1],[-1,1]], return true.
Example 2:
Given points = [[1,1],[-1,-1]], return false.
Follow up:
Could you do better than O(n2)?

Hint:

Find the smallest and largest x-value for all points.
If there is a line then it should be at y = (minX + maxX) / 2.
For each point, make sure that it has a reflected point in the opposite side.
_______________________________________________________________________________

/*struct hashfunc {
	template<typename T, typename U>
	size_t operator()(const pair<T, U> &i) const {
		return hash<T>()(i.first) ^ hash<U>()(i.second);
	}
};*/
/*
class Solution {
public:
    //unordered_set<pair<int, int>, int, hashfunc> m;
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        if(a.first < b.first) return true;
        if(a.first==b.first && a.second < b.second) return true;
        return false;
    }
    bool isReflected(vector<pair<int, int>>& points) {
        if(points.size()<2) return true;
        sort(points.begin(), points.end(), cmp);
        int pivot = points[0].first+points[points.size()-1].first;
        for(int i=0; i<points.size(); i++) {
            if(points[i].first+points[points.size()-1-i].first == pivot &&\
               points[i].second == points[points.size()-1-i].second){
                   continue;
               }
            return false;
        }
        return true;
    }
};*/

class Solution {
    set<pair<int, int>> s; //使用set，不要使用unordered_set，自定义cmp函数复杂，易出错
public:
    bool isReflected(vector<pair<int, int>>& points) {
        if(points.empty()) return true;
        int n = (int)points.size();

        int minX = INT32_MAX, maxX = INT32_MIN;
        for(int i = 0; i < n; ++i) {
            s.insert(points[i]); //去重
            minX = min(minX, points[i].first);
            maxX = max(maxX, points[i].first);
        }

        int center = minX+maxX; //中心一定是横坐标的最小值与最大值的中心
        for(int i = 0; i < n; ++i) {
            if(s.find({center - points[i].first, points[i].second}) == s.end()) {
                return false;
            }
        }
        return true;
    }
};

// 注意重复点的问题，也就是说，A和B点对称，与B点同位置的点有多个，那么对称轴仍然是A和B的对称轴
