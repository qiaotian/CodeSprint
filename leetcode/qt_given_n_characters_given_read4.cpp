/**
* @Author: Tian Qiao
* @Date:   2016-07-03T19:32:22+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-03T19:42:55+08:00
* @Inc: Facebook
* @Difficulty: Easy
*/



/*
The API: int read4(char *buf) reads 4 characters at a time from a file.
The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.
By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
Note:
The read function will only be called once for each test case.
*/

________________________________________________________________________________

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int ans = 0;
        int x = 1; //只要初始化为非0值即可
        while(x && ans<=n) {
            int x = read4(buf);
            ans += x;
        }
        return min(ans, n);
    }
};
