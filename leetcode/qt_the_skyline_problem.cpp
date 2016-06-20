/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-05-07T10:41:27+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-06-20T22:25:14+08:00
* @License: Free License
*/



/**
 * https://briangordon.github.io/2014/08/the-skyline-problem.html
 * When we encounter the left edge of a rectangle, we add that rectangle to the heap with its height as the key. When we encounter the right edge of a rectangle, we remove that rectangle from the heap.
 * 注意：
 * 1. priority_queue中放入pair的比较操作
 */

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res;
        int cur = 0, cur_X, cur_H = -1, len = buildings.size();
        priority_queue< pair<int, int>> liveBlg; // first: height, second, end time
        while(cur<len || !liveBlg.empty()) {
            // if either some new building is not processed or live building queue is not empty
            cur_X = liveBlg.empty()? buildings[cur][0]:liveBlg.top().second; // next timing point to process

            if(cur>=len || buildings[cur][0] > cur_X) {
                // first check if the current tallest building will end before the next timing point
                // pop up the processed buildings, i.e. those  have height no larger than cur_H and end before the top one
                while(!liveBlg.empty() && ( liveBlg.top().second <= cur_X) ) liveBlg.pop();
            } else {
                // if the next new building starts before the top one ends, process the new building in the vector
                cur_X = buildings[cur][0];
                // go through all the new buildings that starts at the same point
                while(cur<len && buildings[cur][0]== cur_X) {
                    // just push them in the queue
                    liveBlg.push(make_pair(buildings[cur][2], buildings[cur][1]));
                    cur++;
                }
            }
            cur_H = liveBlg.empty()?0:liveBlg.top().first; // outut the top one
            if(res.empty() || (res.back().second != cur_H) ) res.push_back(make_pair(cur_X, cur_H));
        }
        return res;
    }
};
