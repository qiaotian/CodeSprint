/**
* @Author: Tian Qiao
* @Date:   2016-07-04T09:07:16+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-06T20:23:18+08:00
* @Inc: Google, LinkedIn, FB, Microsoft
* @Difficulty: Hard
*/

_______________________________________________________________________________

Given a collection of intervals, merge all overlapping intervals.
For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
_______________________________________________________________________________
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
    bool overlap(Interval& a, Interval& b) {
        return min(a.end, b.end) >= max(a.start, b.start);
    }
    static bool cmp(Interval& a, Interval& b) {
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        if(intervals.empty()) return ans;
        sort(intervals.begin(), intervals.end(), cmp);
        Interval benchmark = intervals[0];
        int n=intervals.size();
        for(int i=1; i<n; i++) {
            if(overlap(benchmark, intervals[i]))  {
                //benchmark.start = min(benchmark.start, intervals[i].start);
                benchmark.end = max(benchmark.end, intervals[i].end);
            } else {
                ans.push_back(benchmark);
                benchmark = intervals[i];
            }
        }
        ans.push_back(benchmark);
        return ans;
    }
};
