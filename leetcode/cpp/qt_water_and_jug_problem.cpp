// Difficulty: Medium

/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-06-29T19:52:25+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-06-29T20:34:31+08:00
* @License: Free License
*/

/*
You are given two jugs with capacities x and y litres. There is an infinite amount of water supply available. You need to determine whether it is possible to measure exactly z litres using these two jugs.

If z liters of water is measurable, you must have z liters of water contained within one or both buckets by the end.

Operations allowed:

Fill any of the jugs completely with water.
Empty any of the jugs.
Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.
Example 1: (From the famous "Die Hard" example)

Input: x = 3, y = 5, z = 4
Output: True
Example 2:

Input: x = 2, y = 6, z = 5
Output: False
*/

class Solution {
public:
    int gcd(int a, int b) {
        if(b==0) return a;
        return gcd(b, a%b);
    }
    bool canMeasureWater(int x, int y, int z) {
        if(x==0 || y==0) return z==x||z==y; // for cases like x=0, y=0, z=0

        int c = gcd(x,y);
        x = x/c;
        y = y/c;
        if(z%c) return false;
        z = z/c;
        if(z<0 || z>x+y) return false;
        else return true;
    }
};

// 结论：如果a、b互质，那么[0, a+b]范围内的任何整数都可得到
// 如果a和b不是互质，那么倒水操作本身就是加减运算，符合结合
// 率，因此a、b及[0, a+b]同除公约数，不影响结果。最后，如果
// 如果c不能整除a和b的公约数，那么一定无法得到c；否则，再判
// 断c与公约数的商是否在范围内，
