/**
* @Author: Tian Qiao
* @Date:   2016-07-03T14:25:34+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-03T14:44:39+08:00
* @Inc: Google
* @Difficulty: Easy
*/

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
Write a function to determine if a number is strobogrammatic. The number is represented as a string.
For example, the numbers "69", "88", and "818" are all strobogrammatic.

________________________________________________________________________________

class Solution {
public:
    bool isStrobogrammatic(string num) {
        //vector<int> dict={true, true, false, false, false, false, true, false, true, true};
        int n = num.size();
        for(int i=0; i<=(n-1)/2; i++) {
            // 如果出现2,3,4,5,7则直接返回false
            // if(!dict[num[i]-'0'] || !dict[num[n-1-i]-'0']) return false;
            if(num[i]=='6' && num[n-1-i]=='9') continue;
            if(num[i]=='9' && num[n-1-i]=='6') continue;
            if(num[i]=='0' && num[n-1-i]=='0') continue;
            if(num[i]=='8' && num[n-1-i]=='8') continue;
            if(num[i]=='1' && num[n-1-i]=='1') continue;
            return false;
        }
        return true;
    }
};
