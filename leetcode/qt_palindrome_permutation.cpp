/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-03T11:17:52+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-03T11:19:50+08:00
* @License: Free License
* @Inc: Google, Uber
* @Easy
*/

Given a string, determine if a permutation of the string could form a palindrome.
For example,
"code" -> False, "aab" -> True, "carerac" -> True.

Hint:
1. Consider the palindromes of odd vs even length. What difference do you notice?
2. Count the frequency of each character.
3. If each character occurs even number of times, then it must be a palindrome. How about character which occurs odd number of times?

________________________________________________________________________________

class Solution {
public:
    /*
    bool canPermutePalindrome(string s) {
        int xnor = 0;
        for(auto i:s) {
            xnor^=i;
        }
        if(xnor==0) return true;
        int count = 0; // the times s occurs
        for(auto i:s) count+=(i==xnor);
        return count!=0;
    }
    */
    bool canPermutePalindrome(string s) {
        vector<int> dict(256, 0);

        for(auto i:s) dict[i]++;
        int odd = 0; // the count of odd letter
        for(auto i:dict) {
            if(i%2) odd++;
        }
        return odd<=1; // 出现奇数次的字符不存在或者仅有一个
    }
};
