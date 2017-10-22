/**
* @Author: Tian Qiao
* @Date:   2016-08-05T01:37:58+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-05T01:38:00+08:00
* @Inc: Facebook
* @Difficulty: Medium
* @Tag: String
*/

/*
The API: int read4(char *buf) reads 4 characters at a time from a file.
The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.
By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
Note:
The read function will only be called once for each test case.
*/

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer (reads content and store in the buf)
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int i = 0;
        while (i < n && (i4 < n4 || (i4 = 0) < (n4 = read4(buf4))))
            buf[i++] = buf4[i4++];
        return i;
    }
    char buf4[4];
    int i4 = 0, n4 = 0;
};

// https://discuss.leetcode.com/topic/32780/simple-short-java-c
