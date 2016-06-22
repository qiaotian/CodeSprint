/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-06-19T23:54:19+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-06-22T16:01:14+08:00
* @License: Free License
*/

/**
For a given source string and a target string, you should output the first index(from 0) of target string in source string.
If target does not exist in source, just return -1.

**Clarification**
Do I need to implement KMP Algorithm in a real interview?
Not necessary. When you meet this problem in a real interview, the interviewer may just want to test your basic implementation ability. But make sure your confirm with the interviewer first.

**Example**
If source = "source" and target = "target", return -1.
If source = "abcdabcdefg" and target = "bcd", return 1.

**Challenge**
O(n2) is acceptable. Can you implement an O(n) algorithm? (hint: KMP)
*/

class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        int len_s = strlen(source);
        int len_t = strlen(target);

        return -1;
    }
};
