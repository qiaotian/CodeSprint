/**
* @Author: Tian Qiao
* @Date:   2016-08-07T23:26:03+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-07T23:26:05+08:00
* @Tag: String
* @Difficulty: Easy
*/

/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/


class Solution {
public:
    string countAndSay(int n) {
        string curr = "1";

        for(int i=1; i<n; i++) {
            string next;
            int count = 0;
            char start = curr[0];
            for(int j = 0; j < curr.size(); j++) {
                if(curr[j] == start) {
                    // same digit occurs
                    count++;
                } else {
                    // different digit occurs
                    next += (to_string(count) + start); // update next string
                    start = curr[j];
                    count = 1; // notice that the count is not 0
                }

                if(j == curr.size()-1) next += (to_string(count) + curr[j]); // update next string
            }
            curr = next;
        }
        return curr;
    }
};

/***
 * There two types conditions that I should update 'next' string
 * 1. the later digit differs with the former one
 * 2. the current digit is the last digit of the objective string
 *
 */
