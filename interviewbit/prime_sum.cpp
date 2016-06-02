/*

Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.
NOTE A solution will always exist. read Goldbach’s conjecture

Example:
Input : 4
Output: 2 + 2 = 4

If there are more than one solutions possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b,
and [c,d] is another solution with c <= d, then

[a, b] < [c, d] 

If a < c OR a==c AND b < d. 

*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> primesum(int A) {
    vector<int> ans;
    vector<bool> flag(A+1, false);
    flag[2] = true;
    flag[3] = true;
    for(int i=4; i<A+1; i++) {
        int tmp = sqrt(i);
        int j=2;
        for( ; j<=tmp; j++) {
            if(i%j==0) break;
            else {
                if(j==tmp) flag[i] = true;
            }
        }
        //if(j==tmp && i%j!=0) flag[i] = true;
    }
    for(int i=2; i<=(A+1)/2; i++) {
        if(flag[i] && flag[A-i]) {
            ans.push_back(i);
            ans.push_back(A-i);
            break;
        }
    }
    return ans;
}

int main(void) {
	int test = 0;
    cin >> test;
    vector<int> ans = primesum(test);
    for(auto num:ans) cout << num << " " << endl;
	return 0;
}




