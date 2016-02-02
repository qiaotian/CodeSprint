/*
Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0. A and P both should be integers.
Example
Input : 4
Output : True
as 2^2 = 4.
*/

#include <cmath>
#include <iostream>

int gcd(int a, int b) {
    if(a<b) return gcd(b, a);
    if(b==0) return a;
    return gcd(b, a%b);
}

bool Solution::isPower(int A) {
    if(A<=3) return false;

	int maxfactor = sqrt(A);
	vector<bool> isPrime(A+1, true);//标记1到A是否为质数
    vector<int> numExp; // 按质数分解A，个质数的指数记录在该数组中

    // 求出特定范围内的所有质数
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i=2; i<=A; i++) {
        if(!isPrime[i]) continue;
        if(i*i > A) break;
        for(int j=i*i; j<=A; j+=i) {
            isPrime[j] = false;
        }
    }
    // 按质数分解整数A
    for(int i=2; i<=A; i++) {
        if(!isPrime[i]) continue;
        int num = 0;
        while(A%i==0) {
            num++;
            A/=i;
        }
        if(num) numExp.push_back(num);
    }

    // 计算所有质数的指数的最大公约数
    int max_common_divsor = numExp[0];

    for(int i=0; i<numExp.size(); i++) {
        if(numExp[i]==1) return false;
        max_common_divsor = gcd(max_common_divsor, numExp[i]);
    }
    
    return max_common_divsor>1;
}


