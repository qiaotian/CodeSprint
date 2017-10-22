/**
* @Author: Tian Qiao
* @Date:   2016-07-04T14:40:46+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-04T17:07:08+08:00
* @Inc: Google, Dropbox
* @Difficulty: Medium
*/

———————————————————————————————————————————————————————————————————————————————
Design a hit counter which counts the number of hits received in the past 5 minutes.

Each function accepts a timestamp parameter (in seconds granularity) and you may assume that calls are being made to the system in chronological order (ie, the timestamp is monotonically increasing). You may assume that the earliest timestamp starts at 1.

It is possible that several hits arrive roughly at the same time.

Example:
HitCounter counter = new HitCounter();

// hit at timestamp 1.
counter.hit(1);
// hit at timestamp 2.
counter.hit(2);
// hit at timestamp 3.
counter.hit(3);
// get hits at timestamp 4, should return 3.
counter.getHits(4);
// hit at timestamp 300.
counter.hit(300);
// get hits at timestamp 300, should return 4.
counter.getHits(300);
// get hits at timestamp 301, should return 3.
counter.getHits(301);
Follow up:
What if the number of hits per second could be very large? Does your design scale?

Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.

Hide Company Tags
———————————————————————————————————————————————————————————————————————————————

class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {

    }

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        vec.push_back(timestamp);
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int boundary = timestamp-300;
        // find the left most element whose
        // timestamp is bigger than boundary
        if(vec.empty() || vec[vec.size()-1]<=boundary) return 0;
        int l = 0, r = vec.size()-1;
        while(l<r) {
            int mid = (l+r)/2;
            if(vec[mid]<=boundary) l=mid+1;
            else r = mid;
        }
        return vec.size()-l;
    }
    
private:
    vector<int> vec; //
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
