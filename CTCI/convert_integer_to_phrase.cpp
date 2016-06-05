/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-06-05T23:25:42+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-06-06T00:06:44+08:00
* @License: DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
*/

/**
Given an integer between 0 and 999,999, print an English phrase that describes the integer (eg. "One Thousand, Two Hundredd and Thirty Four").
*/
vector<string> str1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
vector<string> str11 = {"", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"}
vector<string> str10 = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"}
vector<string> str100 = {"", "Hundred", "Thousand"}

class Solution {
public:
    string num2string(int x) {
        if(x==0) return "Zero";
        int low = x%1000;
        int hight = x/1000;

        if(low<10)  return str1[low];
        if(low==10) return "Ten";
        if(low<20)  return str11[low%10];
        if(low<100) return str10[low/10]+" "+str1[low%10];

        if(low%100==0) return str1[low/100] + " " + str100[1];
        else return str1[low/100] + " and " + num2string(low%100);

        string lowStr = num2string(low);
        string highStr = num2string(high);

        return highStr=="Zero"?lowStr:(highStr+" Thousand "+lowStr);
    }
};
