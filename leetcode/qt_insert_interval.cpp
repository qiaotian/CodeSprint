/**
* @Author: Tian Qiao
* @Date:   2016-07-16T15:07:08+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-16T15:07:14+08:00
* @Google, Facebook, LinkedIn
* @Difficulty: Hard
*/



/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times
Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;
        for(auto i:intervals) {
            if(min(i.end, newInterval.end)>=max(i.start, newInterval.start)) {
                    //Interval cur(min(i.start, newInterval.start), max(i.end, newInterval,end));
                    //ans.push_back(cur);
                    newInterval.start = min(i.start, newInterval.start);
                    newInterval.end = max(i.end, newInterval.end);
            } else {
                if(newInterval.start > i.start) {
                    ans.push_bakc(i);
                } else {
                    ans.push_back(newInterval);
                    newInterval.start = i.start;
                    newInterval.end = i.end;
                }
            }
        }
        ans.push_back(newInterval);
    }
};
