/*
Description
小Hi在虚拟世界中有一只小宠物小P。小P有K种属性，每种属性的初始值为Ai。小Ho送给了小Hi若干颗药丸，每颗药丸可以提高小P指定属性1点。通过属性值，我们可以计算小P的强力值=(C1(1/B1))*(C2(1/B2))*...*(CK(1/BK))，其中Ci为小P第i项属性的最终值（Ai+药丸增加的属性）。 已知小Ho送给小Hi的药丸一共有N颗，问小P的强力值最高能够达到多少？

Input
第一行包含两个整数N，K，分别表示药丸数和属性种数。
第二行为K个整数A1 - AK，意义如前文所述。
第三行为K个整数B1 - BK，意义如前文所述。
对于30%的数据，满足1<=N<=10, 1<=K<=3
对于100%的数据，满足1<=N<=100000, 1<=K<=10
对于100%的数据，满足1<=Ai<=100, 1<=Bi<=10

Output
输出小P能够达到的最高的强力值。

只要你的结果与正确答案之间的相对或绝对误差不超过千分之一，都被是为正确的输出。

Sample Input
5 2
1 1
3 2
Sample Output
2.88
*/


#include <iostream>
#include <vector>

using namespace std;

double calVal(vector<int>& base, vector<int>& exp) {
    double ans = 1.0;
    for(int i=0; i<base.size(); i++) {
        ans*=(pow(base[i], 1.0/exp[i]));
    }
    return ans;
}

int calMaxPower(vector<int>& base, vector<int>& exp, int N) {
    // maxval[i] 是第i颗药丸分配给K种属性以后得到的最强力
    // base表示当前各项属性值
    // exp表示各项属性值的指数倒数，即B1,B2,B3...
    vector<double> maxval(N+1, 0);
	if(N<=0) return 0;
    maxval[0] = calVal(base, exp);
    for(int i=1; i<N+1; i++) {
        
    }
}

int main(void) {
    
    return 0;
}
