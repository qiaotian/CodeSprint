/**
* @Author: Tian Qiao
* @Date:   2016-07-25T05:04:35+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-25T05:05:05+08:00
* @Inc: Google
* @Difficulty: Hard
*/


/*
An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.
For example, given the following image:
[
  "0010",
  "0110",
  "0100"
]
and x = 0, y = 2,
Return 6.
*/

// BFS TLE
/*
class Solution {
public:
    vector<pair<int, int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    int minArea(vector<vector<char>>& image, int x, int y) {
        if(image.empty() || image[0].empty()) return 0;
        int m = image.size();
        int n = image[0].size();

        int l = x, r = x, u = y, d = y;

        bool visited[m][n] = {false};
        queue<pair<int, int>> que;
        que.push({x, y});
        while(!que.empty()) {
            pair<int, int> pos = que.front();
            que.pop();
            l = min(l, pos.first);
            r = max(r, pos.first);
            u = min(u, pos.second);
            d = max(d, pos.second);
            visited[pos.first][pos.second] = true;

            for(auto dir:dirs) {
                int xx = pos.first+dir.first;
                int yy = pos.second+dir.second;
                if(xx>=0 && xx<m && yy>=0 && yy<n && image[xx][yy]=='1' && !visited[xx][yy]) {
                    que.push({xx,yy});
                }
            }
        }
        return (r-l+1)*(d-u+1);
    }
};
*/

/* https://discuss.leetcode.com/topic/29006/c-java-python-binary-search-solution-with-explanation
This means we can do a binary search in each half to find the boundaries, if we know one black pixel's position. And we do know that.
To find the left boundary, do the binary search in the [0, y) range and find the first column vector who has any black pixel.
To determine if a column vector has a black pixel is O(m) so the search in total is O(m log n)
We can do the same for the other boundaries. The area is then calculated by the boundaries.
Thus the algorithm runs in O(m log n + n log m)
*/

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size();
        int n = m==0?0:image[0].size();

        int l = searchLeft(image, 0, y, 0, m-1);
        int r = searchRight(image, y, n-1, 0, m-1);
        int u = searchUp(image, 0, n-1, 0, x);
        int d = searchDown(image, 0, n-1, x, m-1);

        return (r-l+1)*(d-u+1);
    }
    int searchDown(vector<vector<char>>& image, int le, int ri, int up, int dw) {
        int low = up, hgh = dw;
        while(low<hgh) {
            int mid = (low+hgh)/2+1;
            bool hasBlack = false;
            for(int i=le; i<=ri; i++) {
                if(image[mid][i]=='1') { hasBlack = true; break; }
            }
            if(hasBlack) low = mid;
            else hgh = mid-1;
        }
        return low;
    }
    int searchUp(vector<vector<char>>& image, int le, int ri, int up, int dw) {
        int low = up, hgh = dw;
        while(low<hgh) {
            int mid = (low+hgh)/2;
            bool hasBlack = false;
            for(int i=le; i<=ri; i++) {
                if(image[mid][i]=='1') { hasBlack = true; break; }
            }
            if(hasBlack) hgh = mid;
            else low = mid+1;
        }
        return hgh;
    }
    int searchLeft(vector<vector<char>>& image, int le, int ri, int up, int dw) {
        int ll = le, rr = ri;
        while(ll < rr) {
            int mid = (ll+rr)/2;
            bool hasBlack = false;
            for(int i=up; i<=dw; i++) {
                if(image[i][mid]=='1') { hasBlack = true; break; }
            }
            if(hasBlack) rr = mid;
            else ll = mid+1;
        }
        return rr;
    }
    int searchRight(vector<vector<char>>& image, int le, int ri, int up, int dw) {
        int ll = le, rr = ri;
        while(ll < rr) {
            int mid = (ll+rr)/2+1;
            bool hasBlack = false;
            for(int i=up; i<=dw; i++) {
                if(image[i][mid]=='1') { hasBlack = true; break; }
            }
            if(hasBlack) ll = mid;
            else rr = mid-1;
        }
        return ll;
    }
};
