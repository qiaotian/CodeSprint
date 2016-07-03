/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-02T12:03:42+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-02T12:09:04+08:00
* @License: Free License
* @Inc: Google
* @Time: 52 mins/73mins
*/



/**
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
Make sure the returned intervals are also sorted.
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

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    /*
    int n = intervals.size();
    if(intervals.empty()) {
        intervals.push_back(newInterval);
        return intervals;
    }
    if(newInterval.start > intervals[n-1].end) {
        intervals.push_back(newInterval);
        return intervals;
    }
    if(newInterval.end < intervals[0].start) {
        intervals.insert(intervals.begin()+0, newInterval);
        return intervals;
    }*/
    newInterval.start = min(newInterval.start, newInterval.end);
    newInterval.end = max(newInterval.start, newInterval.end); //将end错写成start，耽误近半个小时

    vector<Interval> ans;
    for(auto i:intervals) { //逐一检测newInterval与所有区间是否相交
        int len1 = i.end - i.start;
        int len2 = newInterval.end - newInterval.start;
        int lenSum = max(newInterval.end, i.end) - min(newInterval.start, i.start);
        if(len1 + len2 < lenSum) { // 没有相交
            if(newInterval.start < i.start){
                ans.push_back(newInterval);
                newInterval.start = i.start;
                newInterval.end = i.end;
            } else {
                ans.push_back(i);
            }
        } else { // 相交
            newInterval.start = min(newInterval.start, i.start);
            newInterval.end = max(newInterval.end, i.end);
        }
    }
    ans.push_back(newInterval);
    return ans; // 将ans错写成intervals，耽误10分钟
}

// 注意 newInterval.start可能大于newInterval.end
