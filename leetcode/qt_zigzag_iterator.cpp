/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-06T23:12:36+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-06T23:45:16+08:00
* @Inc: Google
* @Difficulty: Medium
*/



Given two 1d vectors, implement an iterator to return their elements alternately.
For example, given two 1d vectors:
v1 = [1, 2]
v2 = [3, 4, 5, 6]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].

Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?
The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example, given the following input:
[1,2,3]
[4,5,6,7]
[8,9]
It should return [1,4,8,2,5,9,3,6,7].


class ZigzagIterator {
private:
    int len = 0; // 合并后数组长度
    int cnt = 0; // 当前元素的下标
    vector<int> vec; // 合并后的数组
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        len = v1.size()+v2.size();
        int minlen = min(v1.size(), v2.size());
        int maxlen = max(v1.size(), v2.size());

        for(int i=0; i<minlen; i++) {
            vec.push_back(v1[i]);
            vec.push_back(v2[i]);
        }
        for(int i=0; i<maxlen-minlen; i++) {
            vec.push_back(v1.size()>=v2.size()?v1[minlen+i]:v2[minlen+i]);
        }
    }

    int next() {
        return vec[cnt++];
    }

    bool hasNext() {
        return cnt<len;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
