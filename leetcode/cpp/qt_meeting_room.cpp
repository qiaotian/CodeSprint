/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-03T10:25:04+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-03T10:26:01+08:00
* @License: Free License
* @Inc: Facebook
* @Difficulty: Easy
*/


/**
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return false.
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
    static bool compare(Interval& a, Interval& b) {
        return a.start < b.start;
    }

    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int n = intervals.size();
        for(int i=0; i<n-1; i++) {
            int len1 = intervals[i].end-intervals[i].start;
            int len2 = intervals[i+1].end-intervals[i+1].start;
            int lenT = max(intervals[i+1].end, intervals[i].end)-min(intervals[i+1].start, intervals[i].start);
            if(len1+len2 > lenT) return false;
        }
        return true;
    }
};

// Overlap Condition:
/**
boolean overlap(Interval i1, Interval i2) {
    return (min(i1.end, i2.end) > max(i1.start, i2.start));
}
 * /
