/**
* @Author: Tian Qiao
* @Date:   2016-07-03T19:32:22+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-03T19:58:30+08:00
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
        int res = 0;
        while (n > 0) {
            int tmp = min(read4(buf), n);
            res += tmp;
            buf += tmp; //将缓冲区指针指向未读字符
            if (tmp < 4) break;
            n -= 4;
        }
        return res;
    }
};
// PS: buf指向字符数组的某个位置，并不一定是数组的开头。该题目希望给定任意一个位置，从该位置开始读取最多n个字符，将buf指针指向未读字符的开始。并返回已读字符数目。
