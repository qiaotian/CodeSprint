/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-07T01:35:24+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-07T01:43:02+08:00
* @Inc: Google, Airbnb, Twitter
* @Difficulty: Medium
*/



Implement an iterator to flatten a 2d vector.
For example,
Given 2d vector =
[
  [1,2],
  [3],
  [4,5,6]
]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6].



class Vector2D {
private:
    vector<int> vec1d;
    int len = 0;
    int cnt = 0;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        for(auto i:vec2d) {
            for(auto j:i) {
                vec1d.push_back(j);
                len++;
            }
        }/*
        for(int i=0; i<vec2d.size(); i++) {
            for(int j=0; j<vec2d[i].size(); j++) {
                vec1d.push_back(vec2d[i][j]);
                len++;
            }
        }*/
    }

    int next() {
        return vec1d[cnt++];
    }

    bool hasNext() {
        return cnt<len;
    }
};
/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
