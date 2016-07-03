/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-02T08:11:16+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-02T10:45:05+08:00
* @License: Free License
*/

/**
You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN. In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters SL, SL+1, …, SR. By flipping, we mean change character 0 to 1 and vice-versa.

You aim is to perform ATMOST one operation such that in final string number of 1s is maximised. If you don’t want to perform the operation, return an empty array. Else, return an array consisting of two elements denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.

Notes:
- Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == b, then b < d.

For example,
S = 010
Pair of [L, R] | Final string
_______________|_____________
[1 1]          | 110
[1 2]          | 100
[1 3]          | 101
[2 2]          | 000
[2 3]          | 001

We see that two pairs [1, 1] and [1, 3] give same number of 1s in final string. So, we return [1, 1].
Another example,

If S = 111

No operation can give us more than three 1s in final string. So, we return empty array [].
*/

// 给定a^b和b-a的值，不足以确定a和b
// 当数组元素很多的时候，容易产生错误值
/* 该解法错误
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> ans;

    long long delta = 0; // B-A
    long long xnor = 0; // A^B
    for(int i=0; i<A.size(); i++) {
        delta += i+1-A[i];
        xnor ^= (i+1)^A[i];
    }

    for(auto i:A) {
        if((i^(i+delta))==xnor) {
            int a = i;
            int b = a+delta;
            ans.push_back(a);
            ans.push_back(b);
            break;
        }
    }
    return ans;
}
*/
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> ans;

    int xnor = 0; // A xor B
    for(int i=0; i<A.size(); i++) {
        xnor = xnor^(i+1)^A[i];
    }

    int a = 0, b = 0;

    int mask = xnor&(-xnor); // 保留最后一位1

    for(int i=0; i<A.size(); i++) {
        if((A[i]&mask)==mask) a^=A[i]; // 这里“A[i]&mask”外层一定要加括号
        else b^=A[i];

        if(((i+1)&mask)==mask) a^=(i+1);
        else b^=(i+1);
    }

    // 确定a和b之间哪个是遗漏值，哪个是重复值
    for(auto i:A) {
        if(i==b) {
            swap(a, b);
            break;
        }
    }

    ans.push_back(a);
    ans.push_back(b);
    return ans;
}
