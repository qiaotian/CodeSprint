/*
Given an integer, convert it to a roman numeral.
Input is guaranteed to be within the range from 1 to 3999.
*/


class Solution {
public:
    int mp[100];
    int val[13]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    string molecule[13]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    void init() {
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
    }
    string n2r(int num) {
        init();
        int cp = num;
        string result = "";
        int i=0;
        while(cp>0){
            while(cp>=val[i]){
                result+=molecule[i];
                cp-=val[i];
            }
            i++;
        }
        return result;
    }
    int r2n(string roman) {
        init();
        int result = 0;
        for(int i=roman.size()-1; i>=0; --i) {
            if(i==roman.size()-1) {
                result+=mp[roman.at(i)];
                continue;
            }
            result+=mp[roman.at(i)]>=mp[roman.at(i-1)]?mp[roman.at(i)]:-mp[roman.at(i)];
        }
        return result;
    }
    string intToRoman(int num) {
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int cp = num;
        string result = "";
        int i=0;
        while(cp>0){
            while(cp>=val[i]){
                result+=molecule[i];
                cp-=val[i];
            }
            i++;
        }
        return result;
    }
};

// NOTICE
/*
(1)基本数字Ⅰ、X 、C中的任何一个，自身连用构成数目，或者放在大数的右边连用构成数目，都不能超过三个；放在大数的左边只能用一个。
(2)不能把基本数字V、L、D中的任何一个作为小数放在大数的左边采用相减的方法构成数目；放在大数的右边采用相加的方式构成数目，只能使用一个。
(3)V 和 X 左边的小数字只能用Ⅰ。
(4)L 和 C 左边的小数字只能用×。
(5)D 和 M 左 边的小数字只能用 C 。
 */
