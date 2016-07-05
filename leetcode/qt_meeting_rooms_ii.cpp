/**
* @Author: Tian Qiao
* @Date:   2016-07-05T14:34:51+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-05T16:14:57+08:00
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
 /**
  * Definition for an interval.
  * struct Interval {
  *     int start;
  *     int end;
  *     Interval() : start(0), end(0) {}
  *     Interval(int s, int e) : start(s), end(e) {}
  * };
  */

 //方案一
 class Solution {
 public:
     static bool cmp(Interval& a, Interval& b) {
         return a.start < b.start;
     }
     int minMeetingRooms(vector<Interval>& intervals) {
         sort(intervals.begin(), intervals.end(), cmp);
         vector<vector<Interval>> rooms;
         for(auto i:intervals) {
             bool flag = true; //是否需要新房间
             for(auto &j:rooms) {
                 Interval &tmp = j[j.size()-1];
                 if(min(i.end, tmp.end)>max(i.start, tmp.start)) {
                     continue;
                 } else {
                     j.push_back(i);
                     flag = false;
                     break; //一旦找到可以安排的房间，则停止查找
                 }
             }
             if(flag) {
                 vector<Interval> room;
                 room.push_back(i);
                 rooms.push_back(room);
             }
         }
         return rooms.size();
     }
 };

 //方案二
 class Solution {
public:
    static bool cmp(Interval& a, Interval& b) {
        return a.start < b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> changes;
        for (auto i : intervals) {
            changes[i.start] += 1;
            changes[i.end] -= 1;
        }
        int rooms = 0, maxrooms = 0;
        for (auto change : changes)
            maxrooms = max(maxrooms, rooms += change.second);
        return maxrooms;
    }
};

 /**
  * 如果新的安排与多个房间日程均无冲突，那么应该安排在哪个房间？
  * 只要房间可用即可，因为后续会议开始的时间一定晚于之前的会议
  * /
