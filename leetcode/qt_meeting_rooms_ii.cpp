/**
* @Author: Tian Qiao
* @Date:   2016-07-05T14:34:51+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-05T15:00:21+08:00
* @Inc: Google, Facebook
* @Difficulty: Medium
*/

_______________________________________________________________________________

Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.
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

    static bool cmp(Interval& a, Interval& b) {
        return a.start < b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<Intervals>> vv;
        for(auto i:intervals) {
            bool flag = true; //是否需要新房间
            for(auto j:vv) {
                int n = j.size();
                if(min(i.end, j[n-1].end)>max(i.start, j[n-1].start)) {
                    continue;
                } else {
                    j.push_back(i);
                    flag = false;
                }
            }

            if(flag) {
                vector<Interval> room;
                room.push_back(i);
                vv.push_back(room);
            }
        }
        return vv.size();
    }
};
